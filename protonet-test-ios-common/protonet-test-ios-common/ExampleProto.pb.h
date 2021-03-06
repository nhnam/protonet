// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ExampleProto.proto

#ifndef PROTOBUF_ExampleProto_2eproto__INCLUDED
#define PROTOBUF_ExampleProto_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace com {
namespace github {
namespace axet {
namespace protonet {
namespace test {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_ExampleProto_2eproto();
void protobuf_AssignDesc_ExampleProto_2eproto();
void protobuf_ShutdownFile_ExampleProto_2eproto();

class Card;
class HandRequest;
class HandRespond;
class SeatTakeRequest;
class SeatTakeRespond;

enum Card_Suits {
  Card_Suits_CLUBS = 0,
  Card_Suits_DIAMONDS = 1,
  Card_Suits_HEARTS = 2,
  Card_Suits_SPADES = 3
};
bool Card_Suits_IsValid(int value);
const Card_Suits Card_Suits_Suits_MIN = Card_Suits_CLUBS;
const Card_Suits Card_Suits_Suits_MAX = Card_Suits_SPADES;
const int Card_Suits_Suits_ARRAYSIZE = Card_Suits_Suits_MAX + 1;

const ::google::protobuf::EnumDescriptor* Card_Suits_descriptor();
inline const ::std::string& Card_Suits_Name(Card_Suits value) {
  return ::google::protobuf::internal::NameOfEnum(
    Card_Suits_descriptor(), value);
}
inline bool Card_Suits_Parse(
    const ::std::string& name, Card_Suits* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Card_Suits>(
    Card_Suits_descriptor(), name, value);
}
enum Card_Types {
  Card_Types_CARD2 = 2,
  Card_Types_CARD3 = 3,
  Card_Types_CARD4 = 4,
  Card_Types_CARD5 = 5,
  Card_Types_CARD6 = 6,
  Card_Types_CARD7 = 7,
  Card_Types_CARD8 = 8,
  Card_Types_CARD9 = 9,
  Card_Types_CARD10 = 10,
  Card_Types_JACK = 11,
  Card_Types_QUEEN = 12,
  Card_Types_KING = 13,
  Card_Types_ACE = 14
};
bool Card_Types_IsValid(int value);
const Card_Types Card_Types_Types_MIN = Card_Types_CARD2;
const Card_Types Card_Types_Types_MAX = Card_Types_ACE;
const int Card_Types_Types_ARRAYSIZE = Card_Types_Types_MAX + 1;

const ::google::protobuf::EnumDescriptor* Card_Types_descriptor();
inline const ::std::string& Card_Types_Name(Card_Types value) {
  return ::google::protobuf::internal::NameOfEnum(
    Card_Types_descriptor(), value);
}
inline bool Card_Types_Parse(
    const ::std::string& name, Card_Types* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Card_Types>(
    Card_Types_descriptor(), name, value);
}
// ===================================================================

class Card : public ::google::protobuf::Message {
 public:
  Card();
  virtual ~Card();

  Card(const Card& from);

  inline Card& operator=(const Card& from) {
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
  static const Card& default_instance();

  void Swap(Card* other);

  // implements Message ----------------------------------------------

  Card* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Card& from);
  void MergeFrom(const Card& from);
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

  typedef Card_Suits Suits;
  static const Suits CLUBS = Card_Suits_CLUBS;
  static const Suits DIAMONDS = Card_Suits_DIAMONDS;
  static const Suits HEARTS = Card_Suits_HEARTS;
  static const Suits SPADES = Card_Suits_SPADES;
  static inline bool Suits_IsValid(int value) {
    return Card_Suits_IsValid(value);
  }
  static const Suits Suits_MIN =
    Card_Suits_Suits_MIN;
  static const Suits Suits_MAX =
    Card_Suits_Suits_MAX;
  static const int Suits_ARRAYSIZE =
    Card_Suits_Suits_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Suits_descriptor() {
    return Card_Suits_descriptor();
  }
  static inline const ::std::string& Suits_Name(Suits value) {
    return Card_Suits_Name(value);
  }
  static inline bool Suits_Parse(const ::std::string& name,
      Suits* value) {
    return Card_Suits_Parse(name, value);
  }

  typedef Card_Types Types;
  static const Types CARD2 = Card_Types_CARD2;
  static const Types CARD3 = Card_Types_CARD3;
  static const Types CARD4 = Card_Types_CARD4;
  static const Types CARD5 = Card_Types_CARD5;
  static const Types CARD6 = Card_Types_CARD6;
  static const Types CARD7 = Card_Types_CARD7;
  static const Types CARD8 = Card_Types_CARD8;
  static const Types CARD9 = Card_Types_CARD9;
  static const Types CARD10 = Card_Types_CARD10;
  static const Types JACK = Card_Types_JACK;
  static const Types QUEEN = Card_Types_QUEEN;
  static const Types KING = Card_Types_KING;
  static const Types ACE = Card_Types_ACE;
  static inline bool Types_IsValid(int value) {
    return Card_Types_IsValid(value);
  }
  static const Types Types_MIN =
    Card_Types_Types_MIN;
  static const Types Types_MAX =
    Card_Types_Types_MAX;
  static const int Types_ARRAYSIZE =
    Card_Types_Types_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Types_descriptor() {
    return Card_Types_descriptor();
  }
  static inline const ::std::string& Types_Name(Types value) {
    return Card_Types_Name(value);
  }
  static inline bool Types_Parse(const ::std::string& name,
      Types* value) {
    return Card_Types_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .com.github.axet.protonet.test.Card.Suits suit = 1;
  inline bool has_suit() const;
  inline void clear_suit();
  static const int kSuitFieldNumber = 1;
  inline ::com::github::axet::protonet::test::Card_Suits suit() const;
  inline void set_suit(::com::github::axet::protonet::test::Card_Suits value);

  // required .com.github.axet.protonet.test.Card.Types type = 2;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 2;
  inline ::com::github::axet::protonet::test::Card_Types type() const;
  inline void set_type(::com::github::axet::protonet::test::Card_Types value);

  // @@protoc_insertion_point(class_scope:com.github.axet.protonet.test.Card)
 private:
  inline void set_has_suit();
  inline void clear_has_suit();
  inline void set_has_type();
  inline void clear_has_type();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  int suit_;
  int type_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_ExampleProto_2eproto();
  friend void protobuf_AssignDesc_ExampleProto_2eproto();
  friend void protobuf_ShutdownFile_ExampleProto_2eproto();

  void InitAsDefaultInstance();
  static Card* default_instance_;
};
// -------------------------------------------------------------------

class HandRequest : public ::google::protobuf::Message {
 public:
  HandRequest();
  virtual ~HandRequest();

  HandRequest(const HandRequest& from);

  inline HandRequest& operator=(const HandRequest& from) {
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
  static const HandRequest& default_instance();

  void Swap(HandRequest* other);

  // implements Message ----------------------------------------------

  HandRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HandRequest& from);
  void MergeFrom(const HandRequest& from);
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

  // repeated .com.github.axet.protonet.test.Card cards = 1;
  inline int cards_size() const;
  inline void clear_cards();
  static const int kCardsFieldNumber = 1;
  inline const ::com::github::axet::protonet::test::Card& cards(int index) const;
  inline ::com::github::axet::protonet::test::Card* mutable_cards(int index);
  inline ::com::github::axet::protonet::test::Card* add_cards();
  inline const ::google::protobuf::RepeatedPtrField< ::com::github::axet::protonet::test::Card >&
      cards() const;
  inline ::google::protobuf::RepeatedPtrField< ::com::github::axet::protonet::test::Card >*
      mutable_cards();

  // required bool show = 2;
  inline bool has_show() const;
  inline void clear_show();
  static const int kShowFieldNumber = 2;
  inline bool show() const;
  inline void set_show(bool value);

  // @@protoc_insertion_point(class_scope:com.github.axet.protonet.test.HandRequest)
 private:
  inline void set_has_show();
  inline void clear_has_show();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::com::github::axet::protonet::test::Card > cards_;
  bool show_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_ExampleProto_2eproto();
  friend void protobuf_AssignDesc_ExampleProto_2eproto();
  friend void protobuf_ShutdownFile_ExampleProto_2eproto();

  void InitAsDefaultInstance();
  static HandRequest* default_instance_;
};
// -------------------------------------------------------------------

class HandRespond : public ::google::protobuf::Message {
 public:
  HandRespond();
  virtual ~HandRespond();

  HandRespond(const HandRespond& from);

  inline HandRespond& operator=(const HandRespond& from) {
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
  static const HandRespond& default_instance();

  void Swap(HandRespond* other);

  // implements Message ----------------------------------------------

  HandRespond* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HandRespond& from);
  void MergeFrom(const HandRespond& from);
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

  // @@protoc_insertion_point(class_scope:com.github.axet.protonet.test.HandRespond)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_ExampleProto_2eproto();
  friend void protobuf_AssignDesc_ExampleProto_2eproto();
  friend void protobuf_ShutdownFile_ExampleProto_2eproto();

  void InitAsDefaultInstance();
  static HandRespond* default_instance_;
};
// -------------------------------------------------------------------

class SeatTakeRequest : public ::google::protobuf::Message {
 public:
  SeatTakeRequest();
  virtual ~SeatTakeRequest();

  SeatTakeRequest(const SeatTakeRequest& from);

  inline SeatTakeRequest& operator=(const SeatTakeRequest& from) {
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
  static const SeatTakeRequest& default_instance();

  void Swap(SeatTakeRequest* other);

  // implements Message ----------------------------------------------

  SeatTakeRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SeatTakeRequest& from);
  void MergeFrom(const SeatTakeRequest& from);
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

  // required bool take = 1;
  inline bool has_take() const;
  inline void clear_take();
  static const int kTakeFieldNumber = 1;
  inline bool take() const;
  inline void set_take(bool value);

  // @@protoc_insertion_point(class_scope:com.github.axet.protonet.test.SeatTakeRequest)
 private:
  inline void set_has_take();
  inline void clear_has_take();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  bool take_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_ExampleProto_2eproto();
  friend void protobuf_AssignDesc_ExampleProto_2eproto();
  friend void protobuf_ShutdownFile_ExampleProto_2eproto();

  void InitAsDefaultInstance();
  static SeatTakeRequest* default_instance_;
};
// -------------------------------------------------------------------

class SeatTakeRespond : public ::google::protobuf::Message {
 public:
  SeatTakeRespond();
  virtual ~SeatTakeRespond();

  SeatTakeRespond(const SeatTakeRespond& from);

  inline SeatTakeRespond& operator=(const SeatTakeRespond& from) {
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
  static const SeatTakeRespond& default_instance();

  void Swap(SeatTakeRespond* other);

  // implements Message ----------------------------------------------

  SeatTakeRespond* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SeatTakeRespond& from);
  void MergeFrom(const SeatTakeRespond& from);
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

  // required bool taken = 1;
  inline bool has_taken() const;
  inline void clear_taken();
  static const int kTakenFieldNumber = 1;
  inline bool taken() const;
  inline void set_taken(bool value);

  // @@protoc_insertion_point(class_scope:com.github.axet.protonet.test.SeatTakeRespond)
 private:
  inline void set_has_taken();
  inline void clear_has_taken();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  bool taken_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_ExampleProto_2eproto();
  friend void protobuf_AssignDesc_ExampleProto_2eproto();
  friend void protobuf_ShutdownFile_ExampleProto_2eproto();

  void InitAsDefaultInstance();
  static SeatTakeRespond* default_instance_;
};
// ===================================================================


// ===================================================================

// Card

// required .com.github.axet.protonet.test.Card.Suits suit = 1;
inline bool Card::has_suit() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Card::set_has_suit() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Card::clear_has_suit() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Card::clear_suit() {
  suit_ = 0;
  clear_has_suit();
}
inline ::com::github::axet::protonet::test::Card_Suits Card::suit() const {
  return static_cast< ::com::github::axet::protonet::test::Card_Suits >(suit_);
}
inline void Card::set_suit(::com::github::axet::protonet::test::Card_Suits value) {
  assert(::com::github::axet::protonet::test::Card_Suits_IsValid(value));
  set_has_suit();
  suit_ = value;
}

// required .com.github.axet.protonet.test.Card.Types type = 2;
inline bool Card::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Card::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Card::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Card::clear_type() {
  type_ = 2;
  clear_has_type();
}
inline ::com::github::axet::protonet::test::Card_Types Card::type() const {
  return static_cast< ::com::github::axet::protonet::test::Card_Types >(type_);
}
inline void Card::set_type(::com::github::axet::protonet::test::Card_Types value) {
  assert(::com::github::axet::protonet::test::Card_Types_IsValid(value));
  set_has_type();
  type_ = value;
}

// -------------------------------------------------------------------

// HandRequest

// repeated .com.github.axet.protonet.test.Card cards = 1;
inline int HandRequest::cards_size() const {
  return cards_.size();
}
inline void HandRequest::clear_cards() {
  cards_.Clear();
}
inline const ::com::github::axet::protonet::test::Card& HandRequest::cards(int index) const {
  return cards_.Get(index);
}
inline ::com::github::axet::protonet::test::Card* HandRequest::mutable_cards(int index) {
  return cards_.Mutable(index);
}
inline ::com::github::axet::protonet::test::Card* HandRequest::add_cards() {
  return cards_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::com::github::axet::protonet::test::Card >&
HandRequest::cards() const {
  return cards_;
}
inline ::google::protobuf::RepeatedPtrField< ::com::github::axet::protonet::test::Card >*
HandRequest::mutable_cards() {
  return &cards_;
}

// required bool show = 2;
inline bool HandRequest::has_show() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void HandRequest::set_has_show() {
  _has_bits_[0] |= 0x00000002u;
}
inline void HandRequest::clear_has_show() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void HandRequest::clear_show() {
  show_ = false;
  clear_has_show();
}
inline bool HandRequest::show() const {
  return show_;
}
inline void HandRequest::set_show(bool value) {
  set_has_show();
  show_ = value;
}

// -------------------------------------------------------------------

// HandRespond

// -------------------------------------------------------------------

// SeatTakeRequest

// required bool take = 1;
inline bool SeatTakeRequest::has_take() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SeatTakeRequest::set_has_take() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SeatTakeRequest::clear_has_take() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SeatTakeRequest::clear_take() {
  take_ = false;
  clear_has_take();
}
inline bool SeatTakeRequest::take() const {
  return take_;
}
inline void SeatTakeRequest::set_take(bool value) {
  set_has_take();
  take_ = value;
}

// -------------------------------------------------------------------

// SeatTakeRespond

// required bool taken = 1;
inline bool SeatTakeRespond::has_taken() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SeatTakeRespond::set_has_taken() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SeatTakeRespond::clear_has_taken() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SeatTakeRespond::clear_taken() {
  taken_ = false;
  clear_has_taken();
}
inline bool SeatTakeRespond::taken() const {
  return taken_;
}
inline void SeatTakeRespond::set_taken(bool value) {
  set_has_taken();
  taken_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace test
}  // namespace protonet
}  // namespace axet
}  // namespace github
}  // namespace com

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::com::github::axet::protonet::test::Card_Suits>() {
  return ::com::github::axet::protonet::test::Card_Suits_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::com::github::axet::protonet::test::Card_Types>() {
  return ::com::github::axet::protonet::test::Card_Types_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ExampleProto_2eproto__INCLUDED
