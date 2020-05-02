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
    bool has_field = reflection->HasField(message, field);
    // cout << has_field << endl;
    if (!has_field) {
      continue;
    }

    cout << "field->cpp_type()=" << field->cpp_type() << endl;
	switch (field->cpp_type()) {
		case google::protobuf::FieldDescriptor::CPPTYPE_INT32: {
			cout << "field->name()=" << field->name() << endl;
			int value = reflection->GetInt32(message, field);
			cout << "field_value=" << value << endl;
			int wsize = field->name().size();
			serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));
			serialized_string->append(field->name().c_str(), field->name().size());
			wsize = sizeof(value);
			serialized_string->append(reinterpret_cast<char*>(&wsize), sizeof(wsize));
			serialized_string->append(reinterpret_cast<char*>(&value), sizeof(value));
		}
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
    // parse_message(serialized_string, &person);
  }

  return 0;
}
