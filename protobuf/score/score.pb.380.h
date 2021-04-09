// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: score.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_score_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_score_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3008000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3008000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_score_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_score_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_score_2eproto;
namespace antpath {
namespace predictor {
class ItemRankScore;
class ItemRankScoreDefaultTypeInternal;
extern ItemRankScoreDefaultTypeInternal _ItemRankScore_default_instance_;
class Scores;
class ScoresDefaultTypeInternal;
extern ScoresDefaultTypeInternal _Scores_default_instance_;
}  // namespace predictor
}  // namespace antpath
PROTOBUF_NAMESPACE_OPEN
template<> ::antpath::predictor::ItemRankScore* Arena::CreateMaybeMessage<::antpath::predictor::ItemRankScore>(Arena*);
template<> ::antpath::predictor::Scores* Arena::CreateMaybeMessage<::antpath::predictor::Scores>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace antpath {
namespace predictor {

// ===================================================================

class Scores :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:antpath.predictor.Scores) */ {
 public:
  Scores();
  virtual ~Scores();

  Scores(const Scores& from);
  Scores(Scores&& from) noexcept
    : Scores() {
    *this = ::std::move(from);
  }

  inline Scores& operator=(const Scores& from) {
    CopyFrom(from);
    return *this;
  }
  inline Scores& operator=(Scores&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Scores& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Scores* internal_default_instance() {
    return reinterpret_cast<const Scores*>(
               &_Scores_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Scores* other);
  friend void swap(Scores& a, Scores& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Scores* New() const final {
    return CreateMaybeMessage<Scores>(nullptr);
  }

  Scores* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Scores>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Scores& from);
  void MergeFrom(const Scores& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Scores* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "antpath.predictor.Scores";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_score_2eproto);
    return ::descriptor_table_score_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated float embedx = 1;
  int embedx_size() const;
  void clear_embedx();
  static const int kEmbedxFieldNumber = 1;
  float embedx(int index) const;
  void set_embedx(int index, float value);
  void add_embedx(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
      embedx() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
      mutable_embedx();

  // @@protoc_insertion_point(class_scope:antpath.predictor.Scores)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float > embedx_;
  mutable std::atomic<int> _embedx_cached_byte_size_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_score_2eproto;
};
// -------------------------------------------------------------------

class ItemRankScore :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:antpath.predictor.ItemRankScore) */ {
 public:
  ItemRankScore();
  virtual ~ItemRankScore();

  ItemRankScore(const ItemRankScore& from);
  ItemRankScore(ItemRankScore&& from) noexcept
    : ItemRankScore() {
    *this = ::std::move(from);
  }

  inline ItemRankScore& operator=(const ItemRankScore& from) {
    CopyFrom(from);
    return *this;
  }
  inline ItemRankScore& operator=(ItemRankScore&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ItemRankScore& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ItemRankScore* internal_default_instance() {
    return reinterpret_cast<const ItemRankScore*>(
               &_ItemRankScore_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(ItemRankScore* other);
  friend void swap(ItemRankScore& a, ItemRankScore& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ItemRankScore* New() const final {
    return CreateMaybeMessage<ItemRankScore>(nullptr);
  }

  ItemRankScore* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ItemRankScore>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ItemRankScore& from);
  void MergeFrom(const ItemRankScore& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ItemRankScore* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "antpath.predictor.ItemRankScore";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_score_2eproto);
    return ::descriptor_table_score_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated float rank_score = 2;
  int rank_score_size() const;
  void clear_rank_score();
  static const int kRankScoreFieldNumber = 2;
  float rank_score(int index) const;
  void set_rank_score(int index, float value);
  void add_rank_score(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
      rank_score() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
      mutable_rank_score();

  // repeated .antpath.predictor.Scores mlt_rank_scores = 4;
  int mlt_rank_scores_size() const;
  void clear_mlt_rank_scores();
  static const int kMltRankScoresFieldNumber = 4;
  ::antpath::predictor::Scores* mutable_mlt_rank_scores(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::antpath::predictor::Scores >*
      mutable_mlt_rank_scores();
  const ::antpath::predictor::Scores& mlt_rank_scores(int index) const;
  ::antpath::predictor::Scores* add_mlt_rank_scores();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::antpath::predictor::Scores >&
      mlt_rank_scores() const;

  // string item_id = 1;
  void clear_item_id();
  static const int kItemIdFieldNumber = 1;
  const std::string& item_id() const;
  void set_item_id(const std::string& value);
  void set_item_id(std::string&& value);
  void set_item_id(const char* value);
  void set_item_id(const char* value, size_t size);
  std::string* mutable_item_id();
  std::string* release_item_id();
  void set_allocated_item_id(std::string* item_id);

  // uint64 uniq_id = 3;
  void clear_uniq_id();
  static const int kUniqIdFieldNumber = 3;
  ::PROTOBUF_NAMESPACE_ID::uint64 uniq_id() const;
  void set_uniq_id(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // @@protoc_insertion_point(class_scope:antpath.predictor.ItemRankScore)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float > rank_score_;
  mutable std::atomic<int> _rank_score_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::antpath::predictor::Scores > mlt_rank_scores_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr item_id_;
  ::PROTOBUF_NAMESPACE_ID::uint64 uniq_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_score_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Scores

// repeated float embedx = 1;
inline int Scores::embedx_size() const {
  return embedx_.size();
}
inline void Scores::clear_embedx() {
  embedx_.Clear();
}
inline float Scores::embedx(int index) const {
  // @@protoc_insertion_point(field_get:antpath.predictor.Scores.embedx)
  return embedx_.Get(index);
}
inline void Scores::set_embedx(int index, float value) {
  embedx_.Set(index, value);
  // @@protoc_insertion_point(field_set:antpath.predictor.Scores.embedx)
}
inline void Scores::add_embedx(float value) {
  embedx_.Add(value);
  // @@protoc_insertion_point(field_add:antpath.predictor.Scores.embedx)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
Scores::embedx() const {
  // @@protoc_insertion_point(field_list:antpath.predictor.Scores.embedx)
  return embedx_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
Scores::mutable_embedx() {
  // @@protoc_insertion_point(field_mutable_list:antpath.predictor.Scores.embedx)
  return &embedx_;
}

// -------------------------------------------------------------------

// ItemRankScore

// string item_id = 1;
inline void ItemRankScore::clear_item_id() {
  item_id_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ItemRankScore::item_id() const {
  // @@protoc_insertion_point(field_get:antpath.predictor.ItemRankScore.item_id)
  return item_id_.GetNoArena();
}
inline void ItemRankScore::set_item_id(const std::string& value) {
  
  item_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:antpath.predictor.ItemRankScore.item_id)
}
inline void ItemRankScore::set_item_id(std::string&& value) {
  
  item_id_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:antpath.predictor.ItemRankScore.item_id)
}
inline void ItemRankScore::set_item_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  item_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:antpath.predictor.ItemRankScore.item_id)
}
inline void ItemRankScore::set_item_id(const char* value, size_t size) {
  
  item_id_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:antpath.predictor.ItemRankScore.item_id)
}
inline std::string* ItemRankScore::mutable_item_id() {
  
  // @@protoc_insertion_point(field_mutable:antpath.predictor.ItemRankScore.item_id)
  return item_id_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ItemRankScore::release_item_id() {
  // @@protoc_insertion_point(field_release:antpath.predictor.ItemRankScore.item_id)
  
  return item_id_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ItemRankScore::set_allocated_item_id(std::string* item_id) {
  if (item_id != nullptr) {
    
  } else {
    
  }
  item_id_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), item_id);
  // @@protoc_insertion_point(field_set_allocated:antpath.predictor.ItemRankScore.item_id)
}

// repeated float rank_score = 2;
inline int ItemRankScore::rank_score_size() const {
  return rank_score_.size();
}
inline void ItemRankScore::clear_rank_score() {
  rank_score_.Clear();
}
inline float ItemRankScore::rank_score(int index) const {
  // @@protoc_insertion_point(field_get:antpath.predictor.ItemRankScore.rank_score)
  return rank_score_.Get(index);
}
inline void ItemRankScore::set_rank_score(int index, float value) {
  rank_score_.Set(index, value);
  // @@protoc_insertion_point(field_set:antpath.predictor.ItemRankScore.rank_score)
}
inline void ItemRankScore::add_rank_score(float value) {
  rank_score_.Add(value);
  // @@protoc_insertion_point(field_add:antpath.predictor.ItemRankScore.rank_score)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
ItemRankScore::rank_score() const {
  // @@protoc_insertion_point(field_list:antpath.predictor.ItemRankScore.rank_score)
  return rank_score_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
ItemRankScore::mutable_rank_score() {
  // @@protoc_insertion_point(field_mutable_list:antpath.predictor.ItemRankScore.rank_score)
  return &rank_score_;
}

// uint64 uniq_id = 3;
inline void ItemRankScore::clear_uniq_id() {
  uniq_id_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 ItemRankScore::uniq_id() const {
  // @@protoc_insertion_point(field_get:antpath.predictor.ItemRankScore.uniq_id)
  return uniq_id_;
}
inline void ItemRankScore::set_uniq_id(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  uniq_id_ = value;
  // @@protoc_insertion_point(field_set:antpath.predictor.ItemRankScore.uniq_id)
}

// repeated .antpath.predictor.Scores mlt_rank_scores = 4;
inline int ItemRankScore::mlt_rank_scores_size() const {
  return mlt_rank_scores_.size();
}
inline void ItemRankScore::clear_mlt_rank_scores() {
  mlt_rank_scores_.Clear();
}
inline ::antpath::predictor::Scores* ItemRankScore::mutable_mlt_rank_scores(int index) {
  // @@protoc_insertion_point(field_mutable:antpath.predictor.ItemRankScore.mlt_rank_scores)
  return mlt_rank_scores_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::antpath::predictor::Scores >*
ItemRankScore::mutable_mlt_rank_scores() {
  // @@protoc_insertion_point(field_mutable_list:antpath.predictor.ItemRankScore.mlt_rank_scores)
  return &mlt_rank_scores_;
}
inline const ::antpath::predictor::Scores& ItemRankScore::mlt_rank_scores(int index) const {
  // @@protoc_insertion_point(field_get:antpath.predictor.ItemRankScore.mlt_rank_scores)
  return mlt_rank_scores_.Get(index);
}
inline ::antpath::predictor::Scores* ItemRankScore::add_mlt_rank_scores() {
  // @@protoc_insertion_point(field_add:antpath.predictor.ItemRankScore.mlt_rank_scores)
  return mlt_rank_scores_.Add();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::antpath::predictor::Scores >&
ItemRankScore::mlt_rank_scores() const {
  // @@protoc_insertion_point(field_list:antpath.predictor.ItemRankScore.mlt_rank_scores)
  return mlt_rank_scores_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace predictor
}  // namespace antpath

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_score_2eproto
