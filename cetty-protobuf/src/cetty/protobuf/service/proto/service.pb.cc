// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "service.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace cetty {
namespace protobuf {
namespace service {
namespace proto {

namespace {

const ::google::protobuf::Descriptor* ServiceMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ServiceMessage_reflection_ = NULL;
const ::google::protobuf::Descriptor* Empty_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Empty_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* MessageType_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* ErrorCode_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_service_2eproto() {
  protobuf_AddDesc_service_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "service.proto");
  GOOGLE_CHECK(file != NULL);
  ServiceMessage_descriptor_ = file->message_type(0);
  static const int ServiceMessage_offsets_[7] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, service_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, method_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, error_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, request_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, response_),
  };
  ServiceMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ServiceMessage_descriptor_,
      ServiceMessage::default_instance_,
      ServiceMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ServiceMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ServiceMessage));
  Empty_descriptor_ = file->message_type(1);
  static const int Empty_offsets_[1] = {
  };
  Empty_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Empty_descriptor_,
      Empty::default_instance_,
      Empty_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Empty, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Empty, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Empty));
  MessageType_descriptor_ = file->enum_type(0);
  ErrorCode_descriptor_ = file->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_service_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ServiceMessage_descriptor_, &ServiceMessage::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Empty_descriptor_, &Empty::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_service_2eproto() {
  delete ServiceMessage::default_instance_;
  delete ServiceMessage_reflection_;
  delete Empty::default_instance_;
  delete Empty_reflection_;
}

void protobuf_AddDesc_service_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::protobuf_AddDesc_google_2fprotobuf_2fdescriptor_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rservice.proto\022\034cetty.protobuf.service."
    "proto\032 google/protobuf/descriptor.proto\""
    "\321\001\n\016ServiceMessage\0227\n\004type\030\001 \002(\0162).cetty"
    ".protobuf.service.proto.MessageType\022\n\n\002i"
    "d\030\002 \002(\006\022\017\n\007service\030\003 \001(\t\022\016\n\006method\030\004 \001(\t"
    "\0226\n\005error\030\005 \001(\0162\'.cetty.protobuf.service"
    ".proto.ErrorCode\022\017\n\007request\030\006 \001(\014\022\020\n\010res"
    "ponse\030\007 \001(\014\"\007\n\005Empty*3\n\013MessageType\022\013\n\007R"
    "EQUEST\020\001\022\014\n\010RESPONSE\020\002\022\t\n\005ERROR\020\003*f\n\tErr"
    "orCode\022\017\n\013WRONG_PROTO\020\001\022\016\n\nNO_SERVICE\020\002\022"
    "\r\n\tNO_METHOD\020\003\022\023\n\017INVALID_REQUEST\020\004\022\024\n\020I"
    "NVALID_RESPONSE\020\005:3\n\nidempotent\022\036.google"
    ".protobuf.MethodOptions\030\327\010 \001(\010:2\n\tno_ret"
    "urn\022\036.google.protobuf.MethodOptions\030\330\010 \001"
    "(\010B,\n\034cetty.protobuf.service.protoB\014Serv"
    "iceProto", 608);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "service.proto", &protobuf_RegisterTypes);
  ServiceMessage::default_instance_ = new ServiceMessage();
  Empty::default_instance_ = new Empty();
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::google::protobuf::MethodOptions::default_instance(),
    1111, 8, false, false);
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::google::protobuf::MethodOptions::default_instance(),
    1112, 8, false, false);
  ServiceMessage::default_instance_->InitAsDefaultInstance();
  Empty::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_service_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_service_2eproto {
  StaticDescriptorInitializer_service_2eproto() {
    protobuf_AddDesc_service_2eproto();
  }
} static_descriptor_initializer_service_2eproto_;

const ::google::protobuf::EnumDescriptor* MessageType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MessageType_descriptor_;
}
bool MessageType_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* ErrorCode_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ErrorCode_descriptor_;
}
bool ErrorCode_IsValid(int value) {
  switch(value) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int ServiceMessage::kTypeFieldNumber;
const int ServiceMessage::kIdFieldNumber;
const int ServiceMessage::kServiceFieldNumber;
const int ServiceMessage::kMethodFieldNumber;
const int ServiceMessage::kErrorFieldNumber;
const int ServiceMessage::kRequestFieldNumber;
const int ServiceMessage::kResponseFieldNumber;
#endif  // !_MSC_VER

ServiceMessage::ServiceMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ServiceMessage::InitAsDefaultInstance() {
}

ServiceMessage::ServiceMessage(const ServiceMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ServiceMessage::SharedCtor() {
  _cached_size_ = 0;
  type_ = 1;
  id_ = GOOGLE_ULONGLONG(0);
  service_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  method_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  error_ = 1;
  request_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  response_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ServiceMessage::~ServiceMessage() {
  SharedDtor();
}

void ServiceMessage::SharedDtor() {
  if (service_ != &::google::protobuf::internal::kEmptyString) {
    delete service_;
  }
  if (method_ != &::google::protobuf::internal::kEmptyString) {
    delete method_;
  }
  if (request_ != &::google::protobuf::internal::kEmptyString) {
    delete request_;
  }
  if (response_ != &::google::protobuf::internal::kEmptyString) {
    delete response_;
  }
  if (this != default_instance_) {
  }
}

void ServiceMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ServiceMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ServiceMessage_descriptor_;
}

const ServiceMessage& ServiceMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_service_2eproto();  return *default_instance_;
}

ServiceMessage* ServiceMessage::default_instance_ = NULL;

ServiceMessage* ServiceMessage::New() const {
  return new ServiceMessage;
}

void ServiceMessage::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    type_ = 1;
    id_ = GOOGLE_ULONGLONG(0);
    if (has_service()) {
      if (service_ != &::google::protobuf::internal::kEmptyString) {
        service_->clear();
      }
    }
    if (has_method()) {
      if (method_ != &::google::protobuf::internal::kEmptyString) {
        method_->clear();
      }
    }
    error_ = 1;
    if (has_request()) {
      if (request_ != &::google::protobuf::internal::kEmptyString) {
        request_->clear();
      }
    }
    if (has_response()) {
      if (response_ != &::google::protobuf::internal::kEmptyString) {
        response_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ServiceMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .cetty.protobuf.service.proto.MessageType type = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (cetty::protobuf::service::proto::MessageType_IsValid(value)) {
            set_type(static_cast< cetty::protobuf::service::proto::MessageType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(17)) goto parse_id;
        break;
      }
      
      // required fixed64 id = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_service;
        break;
      }
      
      // optional string service = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_service:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_service()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->service().data(), this->service().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_method;
        break;
      }
      
      // optional string method = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_method:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_method()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->method().data(), this->method().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_error;
        break;
      }
      
      // optional .cetty.protobuf.service.proto.ErrorCode error = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_error:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (cetty::protobuf::service::proto::ErrorCode_IsValid(value)) {
            set_error(static_cast< cetty::protobuf::service::proto::ErrorCode >(value));
          } else {
            mutable_unknown_fields()->AddVarint(5, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_request;
        break;
      }
      
      // optional bytes request = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_request:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_request()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_response;
        break;
      }
      
      // optional bytes response = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_response:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_response()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ServiceMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required .cetty.protobuf.service.proto.MessageType type = 1;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }
  
  // required fixed64 id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(2, this->id(), output);
  }
  
  // optional string service = 3;
  if (has_service()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->service().data(), this->service().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      3, this->service(), output);
  }
  
  // optional string method = 4;
  if (has_method()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->method().data(), this->method().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->method(), output);
  }
  
  // optional .cetty.protobuf.service.proto.ErrorCode error = 5;
  if (has_error()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->error(), output);
  }
  
  // optional bytes request = 6;
  if (has_request()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      6, this->request(), output);
  }
  
  // optional bytes response = 7;
  if (has_response()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      7, this->response(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ServiceMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required .cetty.protobuf.service.proto.MessageType type = 1;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }
  
  // required fixed64 id = 2;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(2, this->id(), target);
  }
  
  // optional string service = 3;
  if (has_service()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->service().data(), this->service().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->service(), target);
  }
  
  // optional string method = 4;
  if (has_method()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->method().data(), this->method().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->method(), target);
  }
  
  // optional .cetty.protobuf.service.proto.ErrorCode error = 5;
  if (has_error()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      5, this->error(), target);
  }
  
  // optional bytes request = 6;
  if (has_request()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        6, this->request(), target);
  }
  
  // optional bytes response = 7;
  if (has_response()) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        7, this->response(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ServiceMessage::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .cetty.protobuf.service.proto.MessageType type = 1;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }
    
    // required fixed64 id = 2;
    if (has_id()) {
      total_size += 1 + 8;
    }
    
    // optional string service = 3;
    if (has_service()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->service());
    }
    
    // optional string method = 4;
    if (has_method()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->method());
    }
    
    // optional .cetty.protobuf.service.proto.ErrorCode error = 5;
    if (has_error()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->error());
    }
    
    // optional bytes request = 6;
    if (has_request()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->request());
    }
    
    // optional bytes response = 7;
    if (has_response()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->response());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ServiceMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ServiceMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ServiceMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ServiceMessage::MergeFrom(const ServiceMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_service()) {
      set_service(from.service());
    }
    if (from.has_method()) {
      set_method(from.method());
    }
    if (from.has_error()) {
      set_error(from.error());
    }
    if (from.has_request()) {
      set_request(from.request());
    }
    if (from.has_response()) {
      set_response(from.response());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ServiceMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ServiceMessage::CopyFrom(const ServiceMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ServiceMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  
  return true;
}

void ServiceMessage::Swap(ServiceMessage* other) {
  if (other != this) {
    std::swap(type_, other->type_);
    std::swap(id_, other->id_);
    std::swap(service_, other->service_);
    std::swap(method_, other->method_);
    std::swap(error_, other->error_);
    std::swap(request_, other->request_);
    std::swap(response_, other->response_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ServiceMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ServiceMessage_descriptor_;
  metadata.reflection = ServiceMessage_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

Empty::Empty()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Empty::InitAsDefaultInstance() {
}

Empty::Empty(const Empty& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Empty::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Empty::~Empty() {
  SharedDtor();
}

void Empty::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Empty::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Empty::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Empty_descriptor_;
}

const Empty& Empty::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_service_2eproto();  return *default_instance_;
}

Empty* Empty::default_instance_ = NULL;

Empty* Empty::New() const {
  return new Empty;
}

void Empty::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Empty::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      return true;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
  return true;
#undef DO_
}

void Empty::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Empty::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Empty::ByteSize() const {
  int total_size = 0;
  
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Empty::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Empty* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Empty*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Empty::MergeFrom(const Empty& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Empty::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Empty::CopyFrom(const Empty& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Empty::IsInitialized() const {
  
  return true;
}

void Empty::Swap(Empty* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Empty::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Empty_descriptor_;
  metadata.reflection = Empty_reflection_;
  return metadata;
}

::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::google::protobuf::internal::PrimitiveTypeTraits< bool >, 8, false >
  idempotent(kIdempotentFieldNumber, false);
::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::MethodOptions,
    ::google::protobuf::internal::PrimitiveTypeTraits< bool >, 8, false >
  no_return(kNoReturnFieldNumber, false);

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace service
}  // namespace protobuf
}  // namespace cetty

// @@protoc_insertion_point(global_scope)