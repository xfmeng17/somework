// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef PROTOBUF_test_2eproto__INCLUDED
#define PROTOBUF_test_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace tutorial {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_test_2eproto();
void protobuf_AssignDesc_test_2eproto();
void protobuf_ShutdownFile_test_2eproto();

class AddressBook;

// ===================================================================

class AddressBook : public ::google::protobuf::Message {
 public:
  AddressBook();
  virtual ~AddressBook();

  AddressBook(const AddressBook& from);

  inline AddressBook& operator=(const AddressBook& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const AddressBook& default_instance();

  void Swap(AddressBook* other);

  // implements Message ----------------------------------------------

  AddressBook* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AddressBook& from);
  void MergeFrom(const AddressBook& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 a = 1;
  inline bool has_a() const;
  inline void clear_a();
  static const int kAFieldNumber = 1;
  inline ::google::protobuf::uint32 a() const;
  inline void set_a(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:tutorial.AddressBook)
 private:
  inline void set_has_a();
  inline void clear_has_a();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 a_;
  friend void  protobuf_AddDesc_test_2eproto();
  friend void protobuf_AssignDesc_test_2eproto();
  friend void protobuf_ShutdownFile_test_2eproto();

  void InitAsDefaultInstance();
  static AddressBook* default_instance_;
};
// ===================================================================


// ===================================================================

// AddressBook

// optional uint32 a = 1;
inline bool AddressBook::has_a() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AddressBook::set_has_a() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AddressBook::clear_has_a() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AddressBook::clear_a() {
  a_ = 0u;
  clear_has_a();
}
inline ::google::protobuf::uint32 AddressBook::a() const {
  // @@protoc_insertion_point(field_get:tutorial.AddressBook.a)
  return a_;
}
inline void AddressBook::set_a(::google::protobuf::uint32 value) {
  set_has_a();
  a_ = value;
  // @@protoc_insertion_point(field_set:tutorial.AddressBook.a)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace tutorial

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_test_2eproto__INCLUDED