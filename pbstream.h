/*
 * pbstream - a stream-oriented implementation of protocol buffers.
 *
 * Copyright (c) 2008 Joshua Haberman.  See LICENSE for details.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dynarray.h"

/* A list of types as they can appear in a .proto file. */
typedef enum pbstream_type {
  PBSTREAM_TYPE_DOUBLE,
  PBSTREAM_TYPE_FLOAT,
  PBSTREAM_TYPE_INT32,
  PBSTREAM_TYPE_INT64,
  PBSTREAM_TYPE_UINT32,
  PBSTREAM_TYPE_UINT64,
  PBSTREAM_TYPE_SINT32,
  PBSTREAM_TYPE_SINT64,
  PBSTREAM_TYPE_FIXED32,
  PBSTREAM_TYPE_FIXED64,
  PBSTREAM_TYPE_SFIXED32,
  PBSTREAM_TYPE_SFIXED64,
  PBSTREAM_TYPE_BOOL,
  PBSTREAM_TYPE_STRING,
  PBSTREAM_TYPE_BYTES,
  PBSTREAM_TYPE_ENUM,
  PBSTREAM_TYPE_MESSAGE
} pbstream_type_t;

/* A list of types as they are encoded on-the-wire. */
typedef enum pbstream_wire_type {
  PBSTREAM_WIRE_TYPE_VARINT      = 0,
  PBSTREAM_WIRE_TYPE_64BIT       = 1,
  PBSTREAM_WIRE_TYPE_DELIMITED   = 2,
  PBSTREAM_WIRE_TYPE_START_GROUP = 3,
  PBSTREAM_WIRE_TYPE_END_GROUP   = 4,
  PBSTREAM_WIRE_TYPE_32BIT       = 5,
} pbstream_wire_type_t;

typedef int32_t pbstream_field_number_t;

/* A deserialized value as described in a .proto file. */
struct pbstream_field_descriptor;
struct pbstream_value {
  struct pbstream_field_descriptor *field_descriptor;
  union {
    double _double;
    float  _float;
    int32_t int32;
    int64_t int64;
    uint32_t uint32;
    uint64_t uint64;
    bool _bool;
    struct pbstream_delimited {
      size_t offset;  /* relative to the beginning of the stream. */
      uint32_t len;
    } delimited;
    int32_t _enum;
  } v;
};

struct pbstream_tag {
  pbstream_field_number_t field_number;
  pbstream_wire_type_t wire_type;
};

/* A value as it is encoded on-the-wire */
struct pbstream_wire_value {
  pbstream_wire_type_t type;
  union {
    uint64_t varint;
    uint64_t _64bit;
    struct {
      size_t offset;  /* relative to the beginning of the stream. */
      uint32_t len;
    } delimited;
    uint32_t _32bit;
  } v;
};

/* The definition of a field as defined in a pbstream (within a message).
 * For example:
 *   required int32 a = 1;
 */
struct pbstream_field_descriptor {
  pbstream_field_number_t field_number;
  pbstream_type_t type;
  struct pbstream_message_descriptor *message;  /* if type == MESSAGE */
};

/* A message as defined by the "message" construct in a .proto file. */
typedef int pbstream_fieldset_t;  /* TODO */
struct pbstream_message_descriptor {
  pbstream_fieldset_t fieldset;
};

/* Callback for when an error occurred.
 * The description is a static buffer which the client must not free.  The
 * offset is the location in the input where the error was detected (this
 * offset is relative to the beginning of the stream).  If is_fatal is true,
 * parsing cannot continue. */
typedef enum pbstream_status {
  PBSTREAM_STATUS_OK = 0,
  PBSTREAM_STATUS_SUBMESSAGE_END = 1,

  /** FATAL ERRORS: these indicate corruption, and cannot be recovered. */

  // A varint did not terminate before hitting 64 bits.
  PBSTREAM_ERROR_UNTERMINATED_VARINT = -1,

  // A submessage ended in the middle of data.
  PBSTREAM_ERROR_BAD_SUBMESSAGE_END = -2,

  // Encountered a "group" on the wire (deprecated and unsupported).
  PBSTREAM_ERROR_GROUP = -3,

  /** NONFATAL ERRORS: the input was invalid, but we can continue if desired. */

  // A value was encountered that was not defined in the .proto file.
  PBSTREAM_ERROR_UNKNOWN_VALUE = 2,

  // A field was encoded with the wrong wire type.
  PBSTREAM_ERROR_MISMATCHED_TYPE = 3,
} pbstream_status_t;
struct pbstream_parse_state;

struct pbstream_parse_stack_frame {
  struct pbstream_message_descriptor *message_descriptor;
  int end_offset;  /* unknown for the top frame, so we set to INT_MAX */
};

/* The stream parser's state. */
struct pbstream_parse_state {
  size_t offset;
  void *user_data;
  DEFINE_DYNARRAY(stack, struct pbstream_parse_stack_frame);
};

/* Call this once before parsing to initialize the data structures.
 * message_type can be NULL, in which case all fields will be reported as
 * unknown. */
void pbstream_init_parser(
    struct pbstream_parse_state *state,
    struct pbstream_message_descriptor *message_descriptor,
    void *user_data);

/* Call this to parse as much of buf as possible, calling callbacks as
 * appropriate.  buf need not be a complete pbstream.  Returns the number of
 * bytes consumed.  In subsequent calls, buf should point to the first byte not
 * consumed by previous calls.
 *
 * If need_more_bytes is non-zero when parse() returns, this indicates that the
 * beginning of a string or sub-message was recognized, but not all bytes of
 * the string were in memory.  The string will not be successfully parsed (and
 * thus parsing of the pbstream cannot proceed) unless need_more_bytes more
 * data is available upon the next call to parse.  The caller may need to
 * increase its buffer size. */

pbstream_status_t pbstream_parse(struct pbstream_parse_state *state,
                                 char *buf, int buf_len, int buf_offset);
