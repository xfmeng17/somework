// 咋通过名字find到message的，需要理解，message是什么使用放在DescriptorPool中的
// https://originlee.com/2015/03/14/analysis-google-protobuf-reflection/

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

#include <iostream>
#include <string>

#include "FooGroup.pb.h"
#include "person.pb.h"

google::protobuf::Message* createMessage(const std::string& type_name) {
  google::protobuf::Message* message = NULL;
  const google::protobuf::Descriptor* descriptor =
      google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(
          type_name);
  if (descriptor) {
    const google::protobuf::Message* prototype =
        google::protobuf::MessageFactory::generated_factory()->GetPrototype(
            descriptor);
    if (prototype) {
      message = prototype->New();
    }
  }
  return message;
}

int main() {
  google::protobuf::Message* message = createMessage("tutorial.Person");
  if (message != NULL) {
    tutorial::Person* person = dynamic_cast<tutorial::Person*>(message);
    person->set_name("xxx");
    std::cout << person->DebugString();
  } else {
    std::cout << "tutorial.Person nullptr\n";
  }

  message = createMessage("tutorial.Feature");
  if (message != NULL) {
    tutorial::Feature* feature = dynamic_cast<tutorial::Feature*>(message);
    feature->set_key("key");
    feature->set_val("val");
    std::cout << feature->DebugString();
  } else {
  }
  return 0;
}
