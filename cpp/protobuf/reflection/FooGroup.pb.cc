// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FooGroup.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "FooGroup.pb.h"

#include <algorithm>
#include <iostream>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/wire_format.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace tutorial {

namespace {

const ::google::protobuf::Descriptor* Feature_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
    Feature_reflection_ = NULL;
const ::google::protobuf::Descriptor* FooGroup_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
    FooGroup_reflection_ = NULL;

}  // namespace

void protobuf_AssignDesc_FooGroup_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_FooGroup_2eproto() {
  protobuf_AddDesc_FooGroup_2eproto();
  const ::google::protobuf::FileDescriptor* file =
      ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
          "FooGroup.proto");
  GOOGLE_CHECK(file != NULL);
  Feature_descriptor_ = file->message_type(0);
  static const int Feature_offsets_[2] = {
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Feature, key_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Feature, val_),
  };
  Feature_reflection_ = ::google::protobuf::internal::
      GeneratedMessageReflection::NewGeneratedMessageReflection(
          Feature_descriptor_, Feature::default_instance_, Feature_offsets_, -1,
          -1, -1, sizeof(Feature),
          GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Feature,
                                                         _internal_metadata_),
          GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(
              Feature, _is_default_instance_));
  FooGroup_descriptor_ = file->message_type(1);
  static const int FooGroup_offsets_[3] = {
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FooGroup, foo_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FooGroup, bar_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FooGroup, baz_),
  };
  FooGroup_reflection_ = ::google::protobuf::internal::
      GeneratedMessageReflection::NewGeneratedMessageReflection(
          FooGroup_descriptor_, FooGroup::default_instance_, FooGroup_offsets_,
          -1, -1, -1, sizeof(FooGroup),
          GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FooGroup,
                                                         _internal_metadata_),
          GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(
              FooGroup, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                                     &protobuf_AssignDesc_FooGroup_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Feature_descriptor_, &Feature::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      FooGroup_descriptor_, &FooGroup::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_FooGroup_2eproto() {
  delete Feature::default_instance_;
  delete Feature_reflection_;
  delete FooGroup::default_instance_;
  delete FooGroup_reflection_;
  std::cout << "protobuf_ShutdownFile_FooGroup_2eproto!!! " << std::endl;
}

void protobuf_AddDesc_FooGroup_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_FooGroup_2eproto() {
  std::cout << "protobuf_AddDesc_FooGroup_2eproto!!! " << std::endl;
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      "\n\016FooGroup.proto\022\010tutorial\"#\n\007Feature\022\013\n"
      "\003key\030\001 \001(\t\022\013\n\003val\030\002 "
      "\001(\t\"j\n\010FooGroup\022\036\n\003f"
      "oo\030\001 \001(\0132\021.tutorial.Feature\022\036\n\003bar\030\002 "
      "\001(\013"
      "2\021.tutorial.Feature\022\036\n\003baz\030\003 \001(\0132\021.tutor"
      "ial.Featureb\006proto3",
      179);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
      "FooGroup.proto", &protobuf_RegisterTypes);
  Feature::default_instance_ = new Feature();
  FooGroup::default_instance_ = new FooGroup();
  Feature::default_instance_->InitAsDefaultInstance();
  FooGroup::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(
      &protobuf_ShutdownFile_FooGroup_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_FooGroup_2eproto {
  StaticDescriptorInitializer_FooGroup_2eproto() {
    protobuf_AddDesc_FooGroup_2eproto();
  }
} static_descriptor_initializer_FooGroup_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Feature::kKeyFieldNumber;
const int Feature::kValFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Feature::Feature() : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tutorial.Feature)
}

void Feature::InitAsDefaultInstance() { _is_default_instance_ = true; }

Feature::Feature(const Feature& from)
    : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:tutorial.Feature)
}

void Feature::SharedCtor() {
  _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  key_.UnsafeSetDefault(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  val_.UnsafeSetDefault(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

Feature::~Feature() {
  // @@protoc_insertion_point(destructor:tutorial.Feature)
  SharedDtor();
}

void Feature::SharedDtor() {
  key_.DestroyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  val_.DestroyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void Feature::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Feature::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Feature_descriptor_;
}

const Feature& Feature::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FooGroup_2eproto();
  return *default_instance_;
}

Feature* Feature::default_instance_ = NULL;

Feature* Feature::New(::google::protobuf::Arena* arena) const {
  Feature* n = new Feature;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Feature::Clear() {
  // @@protoc_insertion_point(message_clear_start:tutorial.Feature)
  key_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
  val_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool Feature::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) \
  if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tutorial.Feature)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p =
        input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (
        ::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string key = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
              input, this->mutable_key()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
              this->key().data(), this->key().length(),
              ::google::protobuf::internal::WireFormatLite::PARSE,
              "tutorial.Feature.key"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_val;
        break;
      }

      // optional string val = 2;
      case 2: {
        if (tag == 18) {
        parse_val:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
              input, this->mutable_val()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
              this->val().data(), this->val().length(),
              ::google::protobuf::internal::WireFormatLite::PARSE,
              "tutorial.Feature.val"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
                ::google::protobuf::internal::WireFormatLite::
                    WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input,
                                                                    tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tutorial.Feature)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tutorial.Feature)
  return false;
#undef DO_
}

void Feature::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tutorial.Feature)
  // optional string key = 1;
  if (this->key().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        this->key().data(), this->key().length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "tutorial.Feature.key");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
        1, this->key(), output);
  }

  // optional string val = 2;
  if (this->val().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        this->val().data(), this->val().length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "tutorial.Feature.val");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
        2, this->val(), output);
  }

  // @@protoc_insertion_point(serialize_end:tutorial.Feature)
}

::google::protobuf::uint8* Feature::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.Feature)
  // optional string key = 1;
  if (this->key().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        this->key().data(), this->key().length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "tutorial.Feature.key");
    target = ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->key(), target);
  }

  // optional string val = 2;
  if (this->val().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        this->val().data(), this->val().length(),
        ::google::protobuf::internal::WireFormatLite::SERIALIZE,
        "tutorial.Feature.val");
    target = ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->val(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:tutorial.Feature)
  return target;
}

int Feature::ByteSize() const {
  // @@protoc_insertion_point(message_byte_size_start:tutorial.Feature)
  int total_size = 0;

  // optional string key = 1;
  if (this->key().size() > 0) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                          this->key());
  }

  // optional string val = 2;
  if (this->val().size() > 0) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                          this->val());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Feature::MergeFrom(const ::google::protobuf::Message& from) {
  // @@protoc_insertion_point(generalized_merge_from_start:tutorial.Feature)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const Feature* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Feature>(
          &from);
  if (source == NULL) {
    // @@protoc_insertion_point(generalized_merge_from_cast_fail:tutorial.Feature)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    // @@protoc_insertion_point(generalized_merge_from_cast_success:tutorial.Feature)
    MergeFrom(*source);
  }
}

void Feature::MergeFrom(const Feature& from) {
  // @@protoc_insertion_point(class_specific_merge_from_start:tutorial.Feature)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.key().size() > 0) {
    key_.AssignWithDefault(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        from.key_);
  }
  if (from.val().size() > 0) {
    val_.AssignWithDefault(
        &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
        from.val_);
  }
}

void Feature::CopyFrom(const ::google::protobuf::Message& from) {
  // @@protoc_insertion_point(generalized_copy_from_start:tutorial.Feature)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Feature::CopyFrom(const Feature& from) {
  // @@protoc_insertion_point(class_specific_copy_from_start:tutorial.Feature)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Feature::IsInitialized() const { return true; }

void Feature::Swap(Feature* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Feature::InternalSwap(Feature* other) {
  key_.Swap(&other->key_);
  val_.Swap(&other->val_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Feature::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Feature_descriptor_;
  metadata.reflection = Feature_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Feature

// optional string key = 1;
void Feature::clear_key() {
  key_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& Feature::key() const {
  // @@protoc_insertion_point(field_get:tutorial.Feature.key)
  return key_.GetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Feature::set_key(const ::std::string& value) {
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
                  value);
  // @@protoc_insertion_point(field_set:tutorial.Feature.key)
}
void Feature::set_key(const char* value) {
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
                  ::std::string(value));
  // @@protoc_insertion_point(field_set_char:tutorial.Feature.key)
}
void Feature::set_key(const char* value, size_t size) {
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
                  ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:tutorial.Feature.key)
}
::std::string* Feature::mutable_key() {
  // @@protoc_insertion_point(field_mutable:tutorial.Feature.key)
  return key_.MutableNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* Feature::release_key() {
  // @@protoc_insertion_point(field_release:tutorial.Feature.key)

  return key_.ReleaseNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Feature::set_allocated_key(::std::string* key) {
  if (key != NULL) {
  } else {
  }
  key_.SetAllocatedNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:tutorial.Feature.key)
}

// optional string val = 2;
void Feature::clear_val() {
  val_.ClearToEmptyNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& Feature::val() const {
  // @@protoc_insertion_point(field_get:tutorial.Feature.val)
  return val_.GetNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Feature::set_val(const ::std::string& value) {
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
                  value);
  // @@protoc_insertion_point(field_set:tutorial.Feature.val)
}
void Feature::set_val(const char* value) {
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
                  ::std::string(value));
  // @@protoc_insertion_point(field_set_char:tutorial.Feature.val)
}
void Feature::set_val(const char* value, size_t size) {
  val_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
                  ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:tutorial.Feature.val)
}
::std::string* Feature::mutable_val() {
  // @@protoc_insertion_point(field_mutable:tutorial.Feature.val)
  return val_.MutableNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* Feature::release_val() {
  // @@protoc_insertion_point(field_release:tutorial.Feature.val)

  return val_.ReleaseNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Feature::set_allocated_val(::std::string* val) {
  if (val != NULL) {
  } else {
  }
  val_.SetAllocatedNoArena(
      &::google::protobuf::internal::GetEmptyStringAlreadyInited(), val);
  // @@protoc_insertion_point(field_set_allocated:tutorial.Feature.val)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int FooGroup::kFooFieldNumber;
const int FooGroup::kBarFieldNumber;
const int FooGroup::kBazFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

FooGroup::FooGroup()
    : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tutorial.FooGroup)
}

void FooGroup::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  foo_ = const_cast< ::tutorial::Feature*>(
      &::tutorial::Feature::default_instance());
  bar_ = const_cast< ::tutorial::Feature*>(
      &::tutorial::Feature::default_instance());
  baz_ = const_cast< ::tutorial::Feature*>(
      &::tutorial::Feature::default_instance());
}

FooGroup::FooGroup(const FooGroup& from)
    : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:tutorial.FooGroup)
}

void FooGroup::SharedCtor() {
  _is_default_instance_ = false;
  _cached_size_ = 0;
  foo_ = NULL;
  bar_ = NULL;
  baz_ = NULL;
}

FooGroup::~FooGroup() {
  // @@protoc_insertion_point(destructor:tutorial.FooGroup)
  SharedDtor();
}

void FooGroup::SharedDtor() {
  if (this != default_instance_) {
    delete foo_;
    delete bar_;
    delete baz_;
  }
}

void FooGroup::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FooGroup::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FooGroup_descriptor_;
}

const FooGroup& FooGroup::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_FooGroup_2eproto();
  return *default_instance_;
}

FooGroup* FooGroup::default_instance_ = NULL;

FooGroup* FooGroup::New(::google::protobuf::Arena* arena) const {
  FooGroup* n = new FooGroup;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void FooGroup::Clear() {
  // @@protoc_insertion_point(message_clear_start:tutorial.FooGroup)
  if (GetArenaNoVirtual() == NULL && foo_ != NULL) delete foo_;
  foo_ = NULL;
  if (GetArenaNoVirtual() == NULL && bar_ != NULL) delete bar_;
  bar_ = NULL;
  if (GetArenaNoVirtual() == NULL && baz_ != NULL) delete baz_;
  baz_ = NULL;
}

bool FooGroup::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) \
  if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tutorial.FooGroup)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p =
        input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (
        ::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .tutorial.Feature foo = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::
                  ReadMessageNoVirtual(input, mutable_foo()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_bar;
        break;
      }

      // optional .tutorial.Feature bar = 2;
      case 2: {
        if (tag == 18) {
        parse_bar:
          DO_(::google::protobuf::internal::WireFormatLite::
                  ReadMessageNoVirtual(input, mutable_bar()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_baz;
        break;
      }

      // optional .tutorial.Feature baz = 3;
      case 3: {
        if (tag == 26) {
        parse_baz:
          DO_(::google::protobuf::internal::WireFormatLite::
                  ReadMessageNoVirtual(input, mutable_baz()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
                ::google::protobuf::internal::WireFormatLite::
                    WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input,
                                                                    tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tutorial.FooGroup)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tutorial.FooGroup)
  return false;
#undef DO_
}

void FooGroup::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tutorial.FooGroup)
  // optional .tutorial.Feature foo = 1;
  if (this->has_foo()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
        1, *this->foo_, output);
  }

  // optional .tutorial.Feature bar = 2;
  if (this->has_bar()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
        2, *this->bar_, output);
  }

  // optional .tutorial.Feature baz = 3;
  if (this->has_baz()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
        3, *this->baz_, output);
  }

  // @@protoc_insertion_point(serialize_end:tutorial.FooGroup)
}

::google::protobuf::uint8* FooGroup::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tutorial.FooGroup)
  // optional .tutorial.Feature foo = 1;
  if (this->has_foo()) {
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessageNoVirtualToArray(1, *this->foo_, false, target);
  }

  // optional .tutorial.Feature bar = 2;
  if (this->has_bar()) {
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessageNoVirtualToArray(2, *this->bar_, false, target);
  }

  // optional .tutorial.Feature baz = 3;
  if (this->has_baz()) {
    target = ::google::protobuf::internal::WireFormatLite::
        InternalWriteMessageNoVirtualToArray(3, *this->baz_, false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:tutorial.FooGroup)
  return target;
}

int FooGroup::ByteSize() const {
  // @@protoc_insertion_point(message_byte_size_start:tutorial.FooGroup)
  int total_size = 0;

  // optional .tutorial.Feature foo = 1;
  if (this->has_foo()) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
                *this->foo_);
  }

  // optional .tutorial.Feature bar = 2;
  if (this->has_bar()) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
                *this->bar_);
  }

  // optional .tutorial.Feature baz = 3;
  if (this->has_baz()) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
                *this->baz_);
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void FooGroup::MergeFrom(const ::google::protobuf::Message& from) {
  // @@protoc_insertion_point(generalized_merge_from_start:tutorial.FooGroup)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const FooGroup* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const FooGroup>(
          &from);
  if (source == NULL) {
    // @@protoc_insertion_point(generalized_merge_from_cast_fail:tutorial.FooGroup)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    // @@protoc_insertion_point(generalized_merge_from_cast_success:tutorial.FooGroup)
    MergeFrom(*source);
  }
}

void FooGroup::MergeFrom(const FooGroup& from) {
  // @@protoc_insertion_point(class_specific_merge_from_start:tutorial.FooGroup)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.has_foo()) {
    mutable_foo()->::tutorial::Feature::MergeFrom(from.foo());
  }
  if (from.has_bar()) {
    mutable_bar()->::tutorial::Feature::MergeFrom(from.bar());
  }
  if (from.has_baz()) {
    mutable_baz()->::tutorial::Feature::MergeFrom(from.baz());
  }
}

void FooGroup::CopyFrom(const ::google::protobuf::Message& from) {
  // @@protoc_insertion_point(generalized_copy_from_start:tutorial.FooGroup)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FooGroup::CopyFrom(const FooGroup& from) {
  // @@protoc_insertion_point(class_specific_copy_from_start:tutorial.FooGroup)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FooGroup::IsInitialized() const { return true; }

void FooGroup::Swap(FooGroup* other) {
  if (other == this) return;
  InternalSwap(other);
}
void FooGroup::InternalSwap(FooGroup* other) {
  std::swap(foo_, other->foo_);
  std::swap(bar_, other->bar_);
  std::swap(baz_, other->baz_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata FooGroup::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FooGroup_descriptor_;
  metadata.reflection = FooGroup_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// FooGroup

// optional .tutorial.Feature foo = 1;
bool FooGroup::has_foo() const {
  return !_is_default_instance_ && foo_ != NULL;
}
void FooGroup::clear_foo() {
  if (GetArenaNoVirtual() == NULL && foo_ != NULL) delete foo_;
  foo_ = NULL;
}
const ::tutorial::Feature& FooGroup::foo() const {
  // @@protoc_insertion_point(field_get:tutorial.FooGroup.foo)
  return foo_ != NULL ? *foo_ : *default_instance_->foo_;
}
::tutorial::Feature* FooGroup::mutable_foo() {
  if (foo_ == NULL) {
    foo_ = new ::tutorial::Feature;
  }
  // @@protoc_insertion_point(field_mutable:tutorial.FooGroup.foo)
  return foo_;
}
::tutorial::Feature* FooGroup::release_foo() {
  // @@protoc_insertion_point(field_release:tutorial.FooGroup.foo)

  ::tutorial::Feature* temp = foo_;
  foo_ = NULL;
  return temp;
}
void FooGroup::set_allocated_foo(::tutorial::Feature* foo) {
  delete foo_;
  foo_ = foo;
  if (foo) {
  } else {
  }
  // @@protoc_insertion_point(field_set_allocated:tutorial.FooGroup.foo)
}

// optional .tutorial.Feature bar = 2;
bool FooGroup::has_bar() const {
  return !_is_default_instance_ && bar_ != NULL;
}
void FooGroup::clear_bar() {
  if (GetArenaNoVirtual() == NULL && bar_ != NULL) delete bar_;
  bar_ = NULL;
}
const ::tutorial::Feature& FooGroup::bar() const {
  // @@protoc_insertion_point(field_get:tutorial.FooGroup.bar)
  return bar_ != NULL ? *bar_ : *default_instance_->bar_;
}
::tutorial::Feature* FooGroup::mutable_bar() {
  if (bar_ == NULL) {
    bar_ = new ::tutorial::Feature;
  }
  // @@protoc_insertion_point(field_mutable:tutorial.FooGroup.bar)
  return bar_;
}
::tutorial::Feature* FooGroup::release_bar() {
  // @@protoc_insertion_point(field_release:tutorial.FooGroup.bar)

  ::tutorial::Feature* temp = bar_;
  bar_ = NULL;
  return temp;
}
void FooGroup::set_allocated_bar(::tutorial::Feature* bar) {
  delete bar_;
  bar_ = bar;
  if (bar) {
  } else {
  }
  // @@protoc_insertion_point(field_set_allocated:tutorial.FooGroup.bar)
}

// optional .tutorial.Feature baz = 3;
bool FooGroup::has_baz() const {
  return !_is_default_instance_ && baz_ != NULL;
}
void FooGroup::clear_baz() {
  if (GetArenaNoVirtual() == NULL && baz_ != NULL) delete baz_;
  baz_ = NULL;
}
const ::tutorial::Feature& FooGroup::baz() const {
  // @@protoc_insertion_point(field_get:tutorial.FooGroup.baz)
  return baz_ != NULL ? *baz_ : *default_instance_->baz_;
}
::tutorial::Feature* FooGroup::mutable_baz() {
  if (baz_ == NULL) {
    baz_ = new ::tutorial::Feature;
  }
  // @@protoc_insertion_point(field_mutable:tutorial.FooGroup.baz)
  return baz_;
}
::tutorial::Feature* FooGroup::release_baz() {
  // @@protoc_insertion_point(field_release:tutorial.FooGroup.baz)

  ::tutorial::Feature* temp = baz_;
  baz_ = NULL;
  return temp;
}
void FooGroup::set_allocated_baz(::tutorial::Feature* baz) {
  delete baz_;
  baz_ = baz;
  if (baz) {
  } else {
  }
  // @@protoc_insertion_point(field_set_allocated:tutorial.FooGroup.baz)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace tutorial

// @@protoc_insertion_point(global_scope)