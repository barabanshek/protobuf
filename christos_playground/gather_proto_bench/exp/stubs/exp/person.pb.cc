// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: exp/person.proto
// Protobuf C++ Version: 5.27.0-dev

#include "exp/person.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr M::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        f1_{0},
        f2_{0},
        f3_{0},
        f4_{0},
        f5_{0},
        f6_{0},
        f7_{0},
        f8_{0},
        f9_{0},
        f10_{0} {}

template <typename>
PROTOBUF_CONSTEXPR M::M(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct MDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~MDefaultTypeInternal() {}
  union {
    M _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MDefaultTypeInternal _M_default_instance_;
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_exp_2fperson_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_exp_2fperson_2eproto = nullptr;
const ::uint32_t
    TableStruct_exp_2fperson_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::M, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::M, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f1_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f2_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f3_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f4_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f5_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f6_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f7_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f8_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f9_),
        PROTOBUF_FIELD_OFFSET(::M, _impl_.f10_),
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 18, -1, sizeof(::M)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_M_default_instance_._instance,
};
const char descriptor_table_protodef_exp_2fperson_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\020exp/person.proto\"\365\001\n\001M\022\017\n\002f1\030\001 \001(\005H\000\210\001"
    "\001\022\017\n\002f2\030\002 \001(\005H\001\210\001\001\022\017\n\002f3\030\003 \001(\005H\002\210\001\001\022\017\n\002f"
    "4\030\004 \001(\005H\003\210\001\001\022\017\n\002f5\030\005 \001(\005H\004\210\001\001\022\017\n\002f6\030\006 \001("
    "\005H\005\210\001\001\022\017\n\002f7\030\007 \001(\005H\006\210\001\001\022\017\n\002f8\030\010 \001(\005H\007\210\001\001"
    "\022\017\n\002f9\030\t \001(\005H\010\210\001\001\022\020\n\003f10\030\n \001(\005H\t\210\001\001B\005\n\003_"
    "f1B\005\n\003_f2B\005\n\003_f3B\005\n\003_f4B\005\n\003_f5B\005\n\003_f6B\005\n"
    "\003_f7B\005\n\003_f8B\005\n\003_f9B\006\n\004_f10b\006proto3"
};
static ::absl::once_flag descriptor_table_exp_2fperson_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_exp_2fperson_2eproto = {
    false,
    false,
    274,
    descriptor_table_protodef_exp_2fperson_2eproto,
    "exp/person.proto",
    &descriptor_table_exp_2fperson_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_exp_2fperson_2eproto::offsets,
    file_level_enum_descriptors_exp_2fperson_2eproto,
    file_level_service_descriptors_exp_2fperson_2eproto,
};
// ===================================================================

class M::_Internal {
 public:
  using HasBits = decltype(std::declval<M>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(M, _impl_._has_bits_);
};

M::M(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:M)
}
M::M(
    ::google::protobuf::Arena* arena, const M& from)
    : M(arena) {
  MergeFrom(from);
}
inline PROTOBUF_NDEBUG_INLINE M::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0} {}

inline void M::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, f1_),
           0,
           offsetof(Impl_, f10_) -
               offsetof(Impl_, f1_) +
               sizeof(Impl_::f10_));
}
M::~M() {
  // @@protoc_insertion_point(destructor:M)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void M::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
M::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              nullptr,  // OnDemandRegisterArenaDtor
              PROTOBUF_FIELD_OFFSET(M, _impl_._cached_size_),
              false,
          },
          &M::MergeImpl,
          &M::kDescriptorMethods,
          &descriptor_table_exp_2fperson_2eproto,
          nullptr,  // tracker
      };
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<4, 10, 0, 0, 2> M::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(M, _impl_._has_bits_),
    0, // no _extensions_
    10, 120,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294966272,  // skipmap
    offsetof(decltype(_table_), field_entries),
    10,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_M_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::M>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // optional int32 f1 = 1;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f1_), 0>(),
     {8, 0, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f1_)}},
    // optional int32 f2 = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f2_), 1>(),
     {16, 1, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f2_)}},
    // optional int32 f3 = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f3_), 2>(),
     {24, 2, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f3_)}},
    // optional int32 f4 = 4;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f4_), 3>(),
     {32, 3, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f4_)}},
    // optional int32 f5 = 5;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f5_), 4>(),
     {40, 4, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f5_)}},
    // optional int32 f6 = 6;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f6_), 5>(),
     {48, 5, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f6_)}},
    // optional int32 f7 = 7;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f7_), 6>(),
     {56, 6, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f7_)}},
    // optional int32 f8 = 8;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f8_), 7>(),
     {64, 7, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f8_)}},
    // optional int32 f9 = 9;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f9_), 8>(),
     {72, 8, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f9_)}},
    // optional int32 f10 = 10;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(M, _impl_.f10_), 9>(),
     {80, 9, 0, PROTOBUF_FIELD_OFFSET(M, _impl_.f10_)}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // optional int32 f1 = 1;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f1_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f2 = 2;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f2_), _Internal::kHasBitsOffset + 1, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f3 = 3;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f3_), _Internal::kHasBitsOffset + 2, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f4 = 4;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f4_), _Internal::kHasBitsOffset + 3, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f5 = 5;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f5_), _Internal::kHasBitsOffset + 4, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f6 = 6;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f6_), _Internal::kHasBitsOffset + 5, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f7 = 7;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f7_), _Internal::kHasBitsOffset + 6, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f8 = 8;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f8_), _Internal::kHasBitsOffset + 7, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f9 = 9;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f9_), _Internal::kHasBitsOffset + 8, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
    // optional int32 f10 = 10;
    {PROTOBUF_FIELD_OFFSET(M, _impl_.f10_), _Internal::kHasBitsOffset + 9, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kInt32)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void M::Clear() {
// @@protoc_insertion_point(message_clear_start:M)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    ::memset(&_impl_.f1_, 0, static_cast<::size_t>(
        reinterpret_cast<char*>(&_impl_.f8_) -
        reinterpret_cast<char*>(&_impl_.f1_)) + sizeof(_impl_.f8_));
  }
  if (cached_has_bits & 0x00000300u) {
    ::memset(&_impl_.f9_, 0, static_cast<::size_t>(
        reinterpret_cast<char*>(&_impl_.f10_) -
        reinterpret_cast<char*>(&_impl_.f9_)) + sizeof(_impl_.f10_));
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* M::_InternalParse(const char* ptr,
                                        ::_pbi::ParseContext* ctx) {
  return ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
}

::uint8_t* M::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:M)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // optional int32 f1 = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<1>(
            stream, this->_internal_f1(), target);
  }

  // optional int32 f2 = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<2>(
            stream, this->_internal_f2(), target);
  }

  // optional int32 f3 = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<3>(
            stream, this->_internal_f3(), target);
  }

  // optional int32 f4 = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<4>(
            stream, this->_internal_f4(), target);
  }

  // optional int32 f5 = 5;
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<5>(
            stream, this->_internal_f5(), target);
  }

  // optional int32 f6 = 6;
  if (cached_has_bits & 0x00000020u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<6>(
            stream, this->_internal_f6(), target);
  }

  // optional int32 f7 = 7;
  if (cached_has_bits & 0x00000040u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<7>(
            stream, this->_internal_f7(), target);
  }

  // optional int32 f8 = 8;
  if (cached_has_bits & 0x00000080u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<8>(
            stream, this->_internal_f8(), target);
  }

  // optional int32 f9 = 9;
  if (cached_has_bits & 0x00000100u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<9>(
            stream, this->_internal_f9(), target);
  }

  // optional int32 f10 = 10;
  if (cached_has_bits & 0x00000200u) {
    target = ::google::protobuf::internal::WireFormatLite::
        WriteInt32ToArrayWithField<10>(
            stream, this->_internal_f10(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:M)
  return target;
}

::size_t M::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:M)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    // optional int32 f1 = 1;
    if (cached_has_bits & 0x00000001u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f1());
    }

    // optional int32 f2 = 2;
    if (cached_has_bits & 0x00000002u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f2());
    }

    // optional int32 f3 = 3;
    if (cached_has_bits & 0x00000004u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f3());
    }

    // optional int32 f4 = 4;
    if (cached_has_bits & 0x00000008u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f4());
    }

    // optional int32 f5 = 5;
    if (cached_has_bits & 0x00000010u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f5());
    }

    // optional int32 f6 = 6;
    if (cached_has_bits & 0x00000020u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f6());
    }

    // optional int32 f7 = 7;
    if (cached_has_bits & 0x00000040u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f7());
    }

    // optional int32 f8 = 8;
    if (cached_has_bits & 0x00000080u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f8());
    }

  }
  if (cached_has_bits & 0x00000300u) {
    // optional int32 f9 = 9;
    if (cached_has_bits & 0x00000100u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f9());
    }

    // optional int32 f10 = 10;
    if (cached_has_bits & 0x00000200u) {
      total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
          this->_internal_f10());
    }

  }
  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void M::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<M*>(&to_msg);
  auto& from = static_cast<const M&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:M)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x000000ffu) {
    if (cached_has_bits & 0x00000001u) {
      _this->_impl_.f1_ = from._impl_.f1_;
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_impl_.f2_ = from._impl_.f2_;
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.f3_ = from._impl_.f3_;
    }
    if (cached_has_bits & 0x00000008u) {
      _this->_impl_.f4_ = from._impl_.f4_;
    }
    if (cached_has_bits & 0x00000010u) {
      _this->_impl_.f5_ = from._impl_.f5_;
    }
    if (cached_has_bits & 0x00000020u) {
      _this->_impl_.f6_ = from._impl_.f6_;
    }
    if (cached_has_bits & 0x00000040u) {
      _this->_impl_.f7_ = from._impl_.f7_;
    }
    if (cached_has_bits & 0x00000080u) {
      _this->_impl_.f8_ = from._impl_.f8_;
    }
  }
  if (cached_has_bits & 0x00000300u) {
    if (cached_has_bits & 0x00000100u) {
      _this->_impl_.f9_ = from._impl_.f9_;
    }
    if (cached_has_bits & 0x00000200u) {
      _this->_impl_.f10_ = from._impl_.f10_;
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void M::CopyFrom(const M& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:M)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool M::IsInitialized() const {
  return true;
}

void M::InternalSwap(M* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(M, _impl_.f10_)
      + sizeof(M::_impl_.f10_)
      - PROTOBUF_FIELD_OFFSET(M, _impl_.f1_)>(
          reinterpret_cast<char*>(&_impl_.f1_),
          reinterpret_cast<char*>(&other->_impl_.f1_));
}

::google::protobuf::Metadata M::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::std::false_type _static_init_ PROTOBUF_UNUSED =
    (::_pbi::AddDescriptors(&descriptor_table_exp_2fperson_2eproto),
     ::std::false_type{});
#include "google/protobuf/port_undef.inc"
