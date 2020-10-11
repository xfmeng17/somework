#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <iostream>
#include "person.pb.h"

using namespace std;

void serialize_message(const google::protobuf::Message& message,
                       std::string* serialized_string) {
  const google::protobuf::Descriptor* descriptor = message.GetDescriptor();
  const google::protobuf::Reflection* reflection = message.GetReflection();

  cout << "descriptor->field_count()=" << descriptor->field_count() << endl;
  for (int i = 0; i < descriptor->field_count(); i++) {
    const google::protobuf::FieldDescriptor* field = descriptor->field(i);
    cout << "field->name=" << field->number() << endl;
    cout << "field->full_name=" << field->full_name() << endl;
    cout << "field->json_name=" << field->json_name() << endl;
    cout << "field->is_extension=" << field->is_extension() << endl;
    cout << "field->number=" << field->number() << endl;
    cout << "field->lowercase_name=" << field->lowercase_name() << endl;
    cout << "field->camelcase_name=" << field->camelcase_name() << endl;
    cout << "field->type=" << field->type() << endl;
    cout << "field->type_name=" << field->type_name() << endl;
    cout << "field->cpp_type=" << field->cpp_type() << endl;
    cout << "field->cpp_type_name=" << field->cpp_type_name() << endl;
    cout << "field->label=" << field->label() << endl;
    cout << "field->index=" << field->index() << endl;
    cout << "======" << endl << endl;

    bool has_field = reflection->HasField(message, field);
    // cout << has_field << endl;
    if (!has_field) {
      continue;
    }
    assert(!field->is_repeated());

    switch (field->cpp_type()) {
#define CASE_FIELD_TYPE(cpptype, method, valuetype)                            \
  case google::protobuf::FieldDescriptor::CPPTYPE_##cpptype: {                 \
    valuetype value = reflection->Get##method(message, field);                 \
    int wsize = field->name().size();                                          \
    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize)); \
    serialized_string->append(field->name().c_str(), field->name().size());    \
    wsize = sizeof(value);                                                     \
    serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize)); \
    serialized_string->append(reinterpret_cast<char*>(&value), sizeof(value)); \
    break;                                                                     \
  }
      CASE_FIELD_TYPE(INT32, Int32, int);
      CASE_FIELD_TYPE(UINT32, UInt32, uint32_t);
      CASE_FIELD_TYPE(FLOAT, Float, float);
      CASE_FIELD_TYPE(DOUBLE, Double, double);
      CASE_FIELD_TYPE(BOOL, Bool, bool);
      CASE_FIELD_TYPE(INT64, Int64, int64_t);
      CASE_FIELD_TYPE(UINT64, UInt64, uint64_t);
#undef CASE_FIELD_TYPE
      case google::protobuf::FieldDescriptor::CPPTYPE_ENUM: {
        int value = reflection->GetEnum(message, field)->number();
        int wsize = field->name().size();
        //写入name占用字节数
        serialized_string->append(reinterpret_cast<char*>(&wsize),
                                  sizeof(wsize));
        //写入name
        serialized_string->append(field->name().c_str(), field->name().size());
        wsize = sizeof(value);
        //写入value占用字节数
        serialized_string->append(reinterpret_cast<char*>(&wsize),
                                  sizeof(wsize));
        //写入value
        serialized_string->append(reinterpret_cast<char*>(&value),
                                  sizeof(value));
        break;
      }
      case google::protobuf::FieldDescriptor::CPPTYPE_STRING: {
        std::string value = reflection->GetString(message, field);
        int wsize = field->name().size();
        serialized_string->append(reinterpret_cast<char*>(&wsize),
                                  sizeof(wsize));
        serialized_string->append(field->name().c_str(), field->name().size());
        wsize = value.size();
        serialized_string->append(reinterpret_cast<char*>(&wsize),
                                  sizeof(wsize));
        serialized_string->append(value.c_str(), value.size());
        break;
      }
      case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE: {
        std::string value;
        int wsize = field->name().size();
        serialized_string->append(reinterpret_cast<char*>(&wsize),
                                  sizeof(wsize));
        serialized_string->append(field->name().c_str(), field->name().size());
        const google::protobuf::Message& submessage =
            reflection->GetMessage(message, field);
        serialize_message(submessage, &value);
        wsize = value.size();
        serialized_string->append(reinterpret_cast<char*>(&wsize),
                                  sizeof(wsize));
        serialized_string->append(value.c_str(), value.size());
        break;
      }
    }
  }
}

void parse_message(const std::string& serialized_string,
                   google::protobuf::Message* message) {
  const google::protobuf::Descriptor* descriptor = message->GetDescriptor();
  const google::protobuf::Reflection* reflection = message->GetReflection();
  std::map<std::string, const google::protobuf::FieldDescriptor*> field_map;

  for (int i = 0; i < descriptor->field_count(); ++i) {
    const google::protobuf::FieldDescriptor* field = descriptor->field(i);
    field_map[field->name()] = field;
  }

  const google::protobuf::FieldDescriptor* field = NULL;
  size_t pos = 0;
  while (pos < serialized_string.size()) {
    int name_size = *(reinterpret_cast<const int*>(
        serialized_string.substr(pos, sizeof(int)).c_str()));
    pos += sizeof(int);
    std::string name = serialized_string.substr(pos, name_size);
    pos += name_size;

    int value_size = *(reinterpret_cast<const int*>(
        serialized_string.substr(pos, sizeof(int)).c_str()));
    pos += sizeof(int);
    std::string value = serialized_string.substr(pos, value_size);
    pos += value_size;

    std::map<std::string, const google::protobuf::FieldDescriptor*>::iterator
        iter = field_map.find(name);
    if (iter == field_map.end()) {
      fprintf(stderr, "no field found.\n");
      continue;
    } else {
      field = iter->second;
    }

    assert(!field->is_repeated());
    switch (field->cpp_type()) {
#define CASE_FIELD_TYPE(cpptype, method, valuetype)                            \
  case google::protobuf::FieldDescriptor::CPPTYPE_##cpptype: {                 \
    reflection->Set##method(                                                   \
        message, field, *(reinterpret_cast<const valuetype*>(value.c_str()))); \
    std::cout << field->name() << "\t"                                         \
              << *(reinterpret_cast<const valuetype*>(value.c_str()))          \
              << std::endl;                                                    \
    break;                                                                     \
  }
      CASE_FIELD_TYPE(INT32, Int32, int);
      CASE_FIELD_TYPE(UINT32, UInt32, uint32_t);
      CASE_FIELD_TYPE(FLOAT, Float, float);
      CASE_FIELD_TYPE(DOUBLE, Double, double);
      CASE_FIELD_TYPE(BOOL, Bool, bool);
      CASE_FIELD_TYPE(INT64, Int64, int64_t);
      CASE_FIELD_TYPE(UINT64, UInt64, uint64_t);
#undef CASE_FIELD_TYPE
      case google::protobuf::FieldDescriptor::CPPTYPE_ENUM: {
        const google::protobuf::EnumValueDescriptor* enum_value_descriptor =
            field->enum_type()->FindValueByNumber(
                *(reinterpret_cast<const int*>(value.c_str())));
        reflection->SetEnum(message, field, enum_value_descriptor);
        std::cout << field->name() << "\t"
                  << *(reinterpret_cast<const int*>(value.c_str()))
                  << std::endl;
        break;
      }
      case google::protobuf::FieldDescriptor::CPPTYPE_STRING: {
        reflection->SetString(message, field, value);
        std::cout << field->name() << "\t" << value << std::endl;
        break;
      }
      case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE: {
        google::protobuf::Message* submessage =
            reflection->MutableMessage(message, field);
        parse_message(value, submessage);
        break;
      }
      default: { break; }
    }
  }
}

int main() {
  std::string serialized_string;

  {
    tutorial::Person person;
    person.set_name("yingshin");
    person.set_id(123456789);
    person.set_email("zhy198606@gmail.com");
    tutorial::Person_PhoneNumber* phone = person.mutable_phone();
    phone->set_type(tutorial::Person::WORK);
    phone->set_number("13266666666");

    serialize_message(person, &serialized_string);

    cout << "serialized_string=" << serialized_string << endl;
  }

  {
    tutorial::Person person;
    parse_message(serialized_string, &person);
    cout << endl;
    cout << "person.DebugString():\n" << person.DebugString() << endl;
  }

  return 0;
}
