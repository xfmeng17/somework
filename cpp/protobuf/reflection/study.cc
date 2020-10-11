// g++ study.cc FooGroup.pb.cc person.pb.cc -I. -lprotobuf

// https://blog.csdn.net/cchd0001/article/details/52452204

//! 利用类型名字构造对象.
/*!
 * @Param type_name 类型名字，比如 "Test.TestMessage".
 * @Return 对象指针，new 出来的，使用者负责释放.
 */
#include <iostream>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

#include "person.pb.h"  // 这是protoc给你生成的文件

int test01() {
  // 先获得类型的Descriptor .
  auto descriptor =
      google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(
          "tutorial.Person");
  if (nullptr == descriptor) {
    return 0;
  }
  // 利用Descriptor拿到类型注册的instance. 这个是不可修改的.
  auto prototype =
      google::protobuf::MessageFactory::generated_factory()->GetPrototype(
          descriptor);
  if (nullptr == descriptor) {
    return 0;
  }
  // 构造一个可用的消息.
  auto message = prototype->New();
  // 只有当我们预先编译了test消息并且正确链接才能这么干.
  auto test = dynamic_cast<tutorial::Person*>(message);
  // 直接调用message的具体接口
  // 其实这些接口是语法糖接口.所以并没有对应的反射机制来对应调用.
  // 反射机制实现了的Set/Get
  // XXX系列接口，是属于Reflection的接口，接收Message作为参数.
  test->set_name("name");
  std::cout << test->Utf8DebugString();
  delete message;
  return 0;
}

#include <google/protobuf/compiler/importer.h>  // compiler::Importer
#include <google/protobuf/dynamic_message.h>    // DynamicMessageFactory

int test02() {
  // 准备配置好文件系统
  google::protobuf::compiler::DiskSourceTree sourceTree;
  // 将当前路径映射为项目根目录 ， project_root
  // 仅仅是个名字，你可以你想要的合法名字.
  sourceTree.MapPath("project_root", "./");
  // 配置动态编译器.
  google::protobuf::compiler::Importer importer(&sourceTree, NULL);
  // 动态编译proto源文件。 源文件在./source/proto/test.proto .
  importer.Import("project_root/person.proto");
  // 现在可以从编译器中提取类型的描述信息.
  auto descriptor1 = importer.pool()->FindMessageTypeByName("tutorial.Person");
  // 创建一个动态的消息工厂.
  google::protobuf::DynamicMessageFactory factory;
  // 从消息工厂中创建出一个类型原型.
  auto proto1 = factory.GetPrototype(descriptor1);
  // 构造一个可用的消息.
  auto message1 = proto1->New();
  // 下面是通过反射接口给字段赋值.
  auto reflection1 = message1->GetReflection();
  auto field1 = descriptor1->FindFieldByName("id");
  reflection1->SetInt32(message1, field1, 1);
  auto field2 = descriptor1->FindFieldByName("name");
  reflection1->SetString(message1, field2, "the_name");
  // 打印看看
  std::cout << message1->DebugString();
  // 删除消息.
  delete message1;
  return 0;
}

int main() {
  std::cout << "test01=" << test01() << std::endl;
  std::cout << "test02=" << test02() << std::endl;
  return 0;
}
