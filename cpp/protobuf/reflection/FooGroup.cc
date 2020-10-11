// 一个简单的动态获取pb部分字段的测试
// https://liam.page/2020/06/29/Dynamic-Get-Fields-in-Protobuf-by-Their-Name-in-Cpp/
// g++ FooGroup.cc FooGroup.pb.cc -I. -I/usr/local/protobuf/include
// -L/usr/local/protobuf/lib -lprotobuf

#include <iostream>
#include <string>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

#include <FooGroup.pb.h>

using namespace tutorial;

const Feature& get_feature(const FooGroup& group, const std::string& name) {
  const google::protobuf::Descriptor* des = group.GetDescriptor();
  const google::protobuf::FieldDescriptor* fdes = des->FindFieldByName(name);
  // fdes = nullptr;
  assert(fdes != nullptr);  // in case of typo or something.
  const google::protobuf::Reflection* ref = group.GetReflection();
  return dynamic_cast<const Feature&>(ref->GetMessage(group, fdes));
}

int main() {
  FooGroup foo_group;
  foo_group.mutable_foo()->set_key("k1");
  foo_group.mutable_foo()->set_val("v1");
  foo_group.mutable_bar()->set_key("k2");
  foo_group.mutable_bar()->set_val("v2");
  foo_group.mutable_baz()->set_key("k3");
  foo_group.mutable_baz()->set_val("v3");

  const Feature& feature = get_feature(foo_group, "baz");
  std::cout << feature.DebugString() << std::endl;

  return 0;
}
