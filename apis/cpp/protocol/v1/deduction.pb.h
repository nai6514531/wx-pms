// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: deduction.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_deduction_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_deduction_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011001 < PROTOBUF_MIN_PROTOC_VERSION
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
#define PROTOBUF_INTERNAL_EXPORT_deduction_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_deduction_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_deduction_2eproto;
namespace protocol {
namespace payment {
namespace deduction {
namespace v1 {
class DeductionAdminReq;
class DeductionAdminReqDefaultTypeInternal;
extern DeductionAdminReqDefaultTypeInternal _DeductionAdminReq_default_instance_;
class DeductionAdminResp;
class DeductionAdminRespDefaultTypeInternal;
extern DeductionAdminRespDefaultTypeInternal _DeductionAdminResp_default_instance_;
class DeductionStruct;
class DeductionStructDefaultTypeInternal;
extern DeductionStructDefaultTypeInternal _DeductionStruct_default_instance_;
}  // namespace v1
}  // namespace deduction
}  // namespace payment
}  // namespace protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::protocol::payment::deduction::v1::DeductionAdminReq* Arena::CreateMaybeMessage<::protocol::payment::deduction::v1::DeductionAdminReq>(Arena*);
template<> ::protocol::payment::deduction::v1::DeductionAdminResp* Arena::CreateMaybeMessage<::protocol::payment::deduction::v1::DeductionAdminResp>(Arena*);
template<> ::protocol::payment::deduction::v1::DeductionStruct* Arena::CreateMaybeMessage<::protocol::payment::deduction::v1::DeductionStruct>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace protocol {
namespace payment {
namespace deduction {
namespace v1 {

// ===================================================================

class DeductionStruct :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.payment.deduction.v1.DeductionStruct) */ {
 public:
  DeductionStruct();
  virtual ~DeductionStruct();

  DeductionStruct(const DeductionStruct& from);
  DeductionStruct(DeductionStruct&& from) noexcept
    : DeductionStruct() {
    *this = ::std::move(from);
  }

  inline DeductionStruct& operator=(const DeductionStruct& from) {
    CopyFrom(from);
    return *this;
  }
  inline DeductionStruct& operator=(DeductionStruct&& from) noexcept {
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
  static const DeductionStruct& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DeductionStruct* internal_default_instance() {
    return reinterpret_cast<const DeductionStruct*>(
               &_DeductionStruct_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(DeductionStruct& a, DeductionStruct& b) {
    a.Swap(&b);
  }
  inline void Swap(DeductionStruct* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline DeductionStruct* New() const final {
    return CreateMaybeMessage<DeductionStruct>(nullptr);
  }

  DeductionStruct* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<DeductionStruct>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const DeductionStruct& from);
  void MergeFrom(const DeductionStruct& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DeductionStruct* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.payment.deduction.v1.DeductionStruct";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_deduction_2eproto);
    return ::descriptor_table_deduction_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTitleFieldNumber = 1,
    kDescFieldNumber = 2,
    kStatusFieldNumber = 3,
  };
  // string title = 1;
  void clear_title();
  const std::string& title() const;
  void set_title(const std::string& value);
  void set_title(std::string&& value);
  void set_title(const char* value);
  void set_title(const char* value, size_t size);
  std::string* mutable_title();
  std::string* release_title();
  void set_allocated_title(std::string* title);
  private:
  const std::string& _internal_title() const;
  void _internal_set_title(const std::string& value);
  std::string* _internal_mutable_title();
  public:

  // string desc = 2;
  void clear_desc();
  const std::string& desc() const;
  void set_desc(const std::string& value);
  void set_desc(std::string&& value);
  void set_desc(const char* value);
  void set_desc(const char* value, size_t size);
  std::string* mutable_desc();
  std::string* release_desc();
  void set_allocated_desc(std::string* desc);
  private:
  const std::string& _internal_desc() const;
  void _internal_set_desc(const std::string& value);
  std::string* _internal_mutable_desc();
  public:

  // uint32 status = 3;
  void clear_status();
  ::PROTOBUF_NAMESPACE_ID::uint32 status() const;
  void set_status(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_status() const;
  void _internal_set_status(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:protocol.payment.deduction.v1.DeductionStruct)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr title_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr desc_;
  ::PROTOBUF_NAMESPACE_ID::uint32 status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_deduction_2eproto;
};
// -------------------------------------------------------------------

class DeductionAdminResp :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.payment.deduction.v1.DeductionAdminResp) */ {
 public:
  DeductionAdminResp();
  virtual ~DeductionAdminResp();

  DeductionAdminResp(const DeductionAdminResp& from);
  DeductionAdminResp(DeductionAdminResp&& from) noexcept
    : DeductionAdminResp() {
    *this = ::std::move(from);
  }

  inline DeductionAdminResp& operator=(const DeductionAdminResp& from) {
    CopyFrom(from);
    return *this;
  }
  inline DeductionAdminResp& operator=(DeductionAdminResp&& from) noexcept {
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
  static const DeductionAdminResp& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DeductionAdminResp* internal_default_instance() {
    return reinterpret_cast<const DeductionAdminResp*>(
               &_DeductionAdminResp_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(DeductionAdminResp& a, DeductionAdminResp& b) {
    a.Swap(&b);
  }
  inline void Swap(DeductionAdminResp* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline DeductionAdminResp* New() const final {
    return CreateMaybeMessage<DeductionAdminResp>(nullptr);
  }

  DeductionAdminResp* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<DeductionAdminResp>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const DeductionAdminResp& from);
  void MergeFrom(const DeductionAdminResp& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DeductionAdminResp* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.payment.deduction.v1.DeductionAdminResp";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_deduction_2eproto);
    return ::descriptor_table_deduction_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDataFieldNumber = 2,
    kHeaderFieldNumber = 1,
  };
  // repeated .protocol.payment.deduction.v1.DeductionStruct data = 2;
  int data_size() const;
  private:
  int _internal_data_size() const;
  public:
  void clear_data();
  ::protocol::payment::deduction::v1::DeductionStruct* mutable_data(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::protocol::payment::deduction::v1::DeductionStruct >*
      mutable_data();
  private:
  const ::protocol::payment::deduction::v1::DeductionStruct& _internal_data(int index) const;
  ::protocol::payment::deduction::v1::DeductionStruct* _internal_add_data();
  public:
  const ::protocol::payment::deduction::v1::DeductionStruct& data(int index) const;
  ::protocol::payment::deduction::v1::DeductionStruct* add_data();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::protocol::payment::deduction::v1::DeductionStruct >&
      data() const;

  // string header = 1;
  void clear_header();
  const std::string& header() const;
  void set_header(const std::string& value);
  void set_header(std::string&& value);
  void set_header(const char* value);
  void set_header(const char* value, size_t size);
  std::string* mutable_header();
  std::string* release_header();
  void set_allocated_header(std::string* header);
  private:
  const std::string& _internal_header() const;
  void _internal_set_header(const std::string& value);
  std::string* _internal_mutable_header();
  public:

  // @@protoc_insertion_point(class_scope:protocol.payment.deduction.v1.DeductionAdminResp)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::protocol::payment::deduction::v1::DeductionStruct > data_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr header_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_deduction_2eproto;
};
// -------------------------------------------------------------------

class DeductionAdminReq :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protocol.payment.deduction.v1.DeductionAdminReq) */ {
 public:
  DeductionAdminReq();
  virtual ~DeductionAdminReq();

  DeductionAdminReq(const DeductionAdminReq& from);
  DeductionAdminReq(DeductionAdminReq&& from) noexcept
    : DeductionAdminReq() {
    *this = ::std::move(from);
  }

  inline DeductionAdminReq& operator=(const DeductionAdminReq& from) {
    CopyFrom(from);
    return *this;
  }
  inline DeductionAdminReq& operator=(DeductionAdminReq&& from) noexcept {
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
  static const DeductionAdminReq& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DeductionAdminReq* internal_default_instance() {
    return reinterpret_cast<const DeductionAdminReq*>(
               &_DeductionAdminReq_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(DeductionAdminReq& a, DeductionAdminReq& b) {
    a.Swap(&b);
  }
  inline void Swap(DeductionAdminReq* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline DeductionAdminReq* New() const final {
    return CreateMaybeMessage<DeductionAdminReq>(nullptr);
  }

  DeductionAdminReq* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<DeductionAdminReq>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const DeductionAdminReq& from);
  void MergeFrom(const DeductionAdminReq& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DeductionAdminReq* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protocol.payment.deduction.v1.DeductionAdminReq";
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
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_deduction_2eproto);
    return ::descriptor_table_deduction_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kHeaderFieldNumber = 1,
  };
  // string header = 1;
  void clear_header();
  const std::string& header() const;
  void set_header(const std::string& value);
  void set_header(std::string&& value);
  void set_header(const char* value);
  void set_header(const char* value, size_t size);
  std::string* mutable_header();
  std::string* release_header();
  void set_allocated_header(std::string* header);
  private:
  const std::string& _internal_header() const;
  void _internal_set_header(const std::string& value);
  std::string* _internal_mutable_header();
  public:

  // @@protoc_insertion_point(class_scope:protocol.payment.deduction.v1.DeductionAdminReq)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr header_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_deduction_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DeductionStruct

// string title = 1;
inline void DeductionStruct::clear_title() {
  title_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& DeductionStruct::title() const {
  // @@protoc_insertion_point(field_get:protocol.payment.deduction.v1.DeductionStruct.title)
  return _internal_title();
}
inline void DeductionStruct::set_title(const std::string& value) {
  _internal_set_title(value);
  // @@protoc_insertion_point(field_set:protocol.payment.deduction.v1.DeductionStruct.title)
}
inline std::string* DeductionStruct::mutable_title() {
  // @@protoc_insertion_point(field_mutable:protocol.payment.deduction.v1.DeductionStruct.title)
  return _internal_mutable_title();
}
inline const std::string& DeductionStruct::_internal_title() const {
  return title_.GetNoArena();
}
inline void DeductionStruct::_internal_set_title(const std::string& value) {
  
  title_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DeductionStruct::set_title(std::string&& value) {
  
  title_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.payment.deduction.v1.DeductionStruct.title)
}
inline void DeductionStruct::set_title(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  title_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.payment.deduction.v1.DeductionStruct.title)
}
inline void DeductionStruct::set_title(const char* value, size_t size) {
  
  title_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.payment.deduction.v1.DeductionStruct.title)
}
inline std::string* DeductionStruct::_internal_mutable_title() {
  
  return title_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DeductionStruct::release_title() {
  // @@protoc_insertion_point(field_release:protocol.payment.deduction.v1.DeductionStruct.title)
  
  return title_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DeductionStruct::set_allocated_title(std::string* title) {
  if (title != nullptr) {
    
  } else {
    
  }
  title_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), title);
  // @@protoc_insertion_point(field_set_allocated:protocol.payment.deduction.v1.DeductionStruct.title)
}

// string desc = 2;
inline void DeductionStruct::clear_desc() {
  desc_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& DeductionStruct::desc() const {
  // @@protoc_insertion_point(field_get:protocol.payment.deduction.v1.DeductionStruct.desc)
  return _internal_desc();
}
inline void DeductionStruct::set_desc(const std::string& value) {
  _internal_set_desc(value);
  // @@protoc_insertion_point(field_set:protocol.payment.deduction.v1.DeductionStruct.desc)
}
inline std::string* DeductionStruct::mutable_desc() {
  // @@protoc_insertion_point(field_mutable:protocol.payment.deduction.v1.DeductionStruct.desc)
  return _internal_mutable_desc();
}
inline const std::string& DeductionStruct::_internal_desc() const {
  return desc_.GetNoArena();
}
inline void DeductionStruct::_internal_set_desc(const std::string& value) {
  
  desc_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DeductionStruct::set_desc(std::string&& value) {
  
  desc_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.payment.deduction.v1.DeductionStruct.desc)
}
inline void DeductionStruct::set_desc(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  desc_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.payment.deduction.v1.DeductionStruct.desc)
}
inline void DeductionStruct::set_desc(const char* value, size_t size) {
  
  desc_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.payment.deduction.v1.DeductionStruct.desc)
}
inline std::string* DeductionStruct::_internal_mutable_desc() {
  
  return desc_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DeductionStruct::release_desc() {
  // @@protoc_insertion_point(field_release:protocol.payment.deduction.v1.DeductionStruct.desc)
  
  return desc_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DeductionStruct::set_allocated_desc(std::string* desc) {
  if (desc != nullptr) {
    
  } else {
    
  }
  desc_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), desc);
  // @@protoc_insertion_point(field_set_allocated:protocol.payment.deduction.v1.DeductionStruct.desc)
}

// uint32 status = 3;
inline void DeductionStruct::clear_status() {
  status_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 DeductionStruct::_internal_status() const {
  return status_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 DeductionStruct::status() const {
  // @@protoc_insertion_point(field_get:protocol.payment.deduction.v1.DeductionStruct.status)
  return _internal_status();
}
inline void DeductionStruct::_internal_set_status(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  status_ = value;
}
inline void DeductionStruct::set_status(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_status(value);
  // @@protoc_insertion_point(field_set:protocol.payment.deduction.v1.DeductionStruct.status)
}

// -------------------------------------------------------------------

// DeductionAdminResp

// string header = 1;
inline void DeductionAdminResp::clear_header() {
  header_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& DeductionAdminResp::header() const {
  // @@protoc_insertion_point(field_get:protocol.payment.deduction.v1.DeductionAdminResp.header)
  return _internal_header();
}
inline void DeductionAdminResp::set_header(const std::string& value) {
  _internal_set_header(value);
  // @@protoc_insertion_point(field_set:protocol.payment.deduction.v1.DeductionAdminResp.header)
}
inline std::string* DeductionAdminResp::mutable_header() {
  // @@protoc_insertion_point(field_mutable:protocol.payment.deduction.v1.DeductionAdminResp.header)
  return _internal_mutable_header();
}
inline const std::string& DeductionAdminResp::_internal_header() const {
  return header_.GetNoArena();
}
inline void DeductionAdminResp::_internal_set_header(const std::string& value) {
  
  header_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DeductionAdminResp::set_header(std::string&& value) {
  
  header_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.payment.deduction.v1.DeductionAdminResp.header)
}
inline void DeductionAdminResp::set_header(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  header_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.payment.deduction.v1.DeductionAdminResp.header)
}
inline void DeductionAdminResp::set_header(const char* value, size_t size) {
  
  header_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.payment.deduction.v1.DeductionAdminResp.header)
}
inline std::string* DeductionAdminResp::_internal_mutable_header() {
  
  return header_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DeductionAdminResp::release_header() {
  // @@protoc_insertion_point(field_release:protocol.payment.deduction.v1.DeductionAdminResp.header)
  
  return header_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DeductionAdminResp::set_allocated_header(std::string* header) {
  if (header != nullptr) {
    
  } else {
    
  }
  header_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), header);
  // @@protoc_insertion_point(field_set_allocated:protocol.payment.deduction.v1.DeductionAdminResp.header)
}

// repeated .protocol.payment.deduction.v1.DeductionStruct data = 2;
inline int DeductionAdminResp::_internal_data_size() const {
  return data_.size();
}
inline int DeductionAdminResp::data_size() const {
  return _internal_data_size();
}
inline void DeductionAdminResp::clear_data() {
  data_.Clear();
}
inline ::protocol::payment::deduction::v1::DeductionStruct* DeductionAdminResp::mutable_data(int index) {
  // @@protoc_insertion_point(field_mutable:protocol.payment.deduction.v1.DeductionAdminResp.data)
  return data_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::protocol::payment::deduction::v1::DeductionStruct >*
DeductionAdminResp::mutable_data() {
  // @@protoc_insertion_point(field_mutable_list:protocol.payment.deduction.v1.DeductionAdminResp.data)
  return &data_;
}
inline const ::protocol::payment::deduction::v1::DeductionStruct& DeductionAdminResp::_internal_data(int index) const {
  return data_.Get(index);
}
inline const ::protocol::payment::deduction::v1::DeductionStruct& DeductionAdminResp::data(int index) const {
  // @@protoc_insertion_point(field_get:protocol.payment.deduction.v1.DeductionAdminResp.data)
  return _internal_data(index);
}
inline ::protocol::payment::deduction::v1::DeductionStruct* DeductionAdminResp::_internal_add_data() {
  return data_.Add();
}
inline ::protocol::payment::deduction::v1::DeductionStruct* DeductionAdminResp::add_data() {
  // @@protoc_insertion_point(field_add:protocol.payment.deduction.v1.DeductionAdminResp.data)
  return _internal_add_data();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::protocol::payment::deduction::v1::DeductionStruct >&
DeductionAdminResp::data() const {
  // @@protoc_insertion_point(field_list:protocol.payment.deduction.v1.DeductionAdminResp.data)
  return data_;
}

// -------------------------------------------------------------------

// DeductionAdminReq

// string header = 1;
inline void DeductionAdminReq::clear_header() {
  header_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& DeductionAdminReq::header() const {
  // @@protoc_insertion_point(field_get:protocol.payment.deduction.v1.DeductionAdminReq.header)
  return _internal_header();
}
inline void DeductionAdminReq::set_header(const std::string& value) {
  _internal_set_header(value);
  // @@protoc_insertion_point(field_set:protocol.payment.deduction.v1.DeductionAdminReq.header)
}
inline std::string* DeductionAdminReq::mutable_header() {
  // @@protoc_insertion_point(field_mutable:protocol.payment.deduction.v1.DeductionAdminReq.header)
  return _internal_mutable_header();
}
inline const std::string& DeductionAdminReq::_internal_header() const {
  return header_.GetNoArena();
}
inline void DeductionAdminReq::_internal_set_header(const std::string& value) {
  
  header_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void DeductionAdminReq::set_header(std::string&& value) {
  
  header_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:protocol.payment.deduction.v1.DeductionAdminReq.header)
}
inline void DeductionAdminReq::set_header(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  header_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:protocol.payment.deduction.v1.DeductionAdminReq.header)
}
inline void DeductionAdminReq::set_header(const char* value, size_t size) {
  
  header_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:protocol.payment.deduction.v1.DeductionAdminReq.header)
}
inline std::string* DeductionAdminReq::_internal_mutable_header() {
  
  return header_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* DeductionAdminReq::release_header() {
  // @@protoc_insertion_point(field_release:protocol.payment.deduction.v1.DeductionAdminReq.header)
  
  return header_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void DeductionAdminReq::set_allocated_header(std::string* header) {
  if (header != nullptr) {
    
  } else {
    
  }
  header_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), header);
  // @@protoc_insertion_point(field_set_allocated:protocol.payment.deduction.v1.DeductionAdminReq.header)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace v1
}  // namespace deduction
}  // namespace payment
}  // namespace protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_deduction_2eproto
