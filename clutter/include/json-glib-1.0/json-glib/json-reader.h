/* json-reader.h - JSON cursor parser
 * 
 * This file is part of JSON-GLib
 * Copyright (C) 2010  Intel Corp.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author:
 *   Emmanuele Bassi  <ebassi@linux.intel.com>
 */

#if !defined(__JSON_GLIB_INSIDE__) && !defined(JSON_COMPILATION)
#error "Only <json-glib/json-glib.h> can be included directly."
#endif

#ifndef __JSON_READER_H__
#define __JSON_READER_H__

#include <json-glib/json-types.h>

G_BEGIN_DECLS

#define JSON_TYPE_READER                (json_reader_get_type ())
#define JSON_READER(obj)                (G_TYPE_CHECK_INSTANCE_CAST ((obj), JSON_TYPE_READER, JsonReader))
#define JSON_IS_READER(obj)             (G_TYPE_CHECK_INSTANCE_TYPE ((obj), JSON_TYPE_READER))
#define JSON_READER_CLASS(klass)        (G_TYPE_CHECK_CLASS_CAST ((klass), JSON_TYPE_READER, JsonReaderClass))
#define JSON_IS_READER_CLASS(klass)     (G_TYPE_CHECK_CLASS_TYPE ((klass), JSON_TYPE_READER))
#define JSON_READER_GET_CLASS(obj)      (G_TYPE_INSTANCE_GET_CLASS ((obj), JSON_TYPE_READER, JsonReaderClass))

/**
 * JSON_READER_ERROR:
 *
 * Error domain for #JsonReader errors
 *
 * Since: 0.12
 */
#define JSON_READER_ERROR               (json_reader_error_quark ())

typedef struct _JsonReader              JsonReader;
typedef struct _JsonReaderPrivate       JsonReaderPrivate;
typedef struct _JsonReaderClass         JsonReaderClass;

/**
 * JsonReaderError:
 * @JSON_READER_ERROR_NO_ARRAY: No array found at the current position
 * @JSON_READER_ERROR_INVALID_INDEX: Index out of bounds
 * @JSON_READER_ERROR_NO_OBJECT: No object found at the current position
 * @JSON_READER_ERROR_INVALID_MEMBER: Member not found
 *
 * Error codes enumeration for #JsonReader errors
 *
 * Since: 0.12
 */
typedef enum {
  JSON_READER_ERROR_NO_ARRAY,
  JSON_READER_ERROR_INVALID_INDEX,
  JSON_READER_ERROR_NO_OBJECT,
  JSON_READER_ERROR_INVALID_MEMBER
} JsonReaderError;

/**
 * JsonReader:
 *
 * The <structname>JsonReader</structname> structure contains only
 * private data and should only be accessed using the provided API
 *
 * Since: 0.12
 */
struct _JsonReader
{
  /*< private >*/
  GObject parent_instance;

  JsonReaderPrivate *priv;
};

/**
 * JsonReaderClass:
 *
 * The <structname>JsonReaderClass</structname> structure contains only
 * private data
 *
 * Since: 0.12
 */
struct _JsonReaderClass
{
  /*< private >*/
  GObjectClass parent_class;

  void (*_json_padding0) (void);
  void (*_json_padding1) (void);
  void (*_json_padding2) (void);
  void (*_json_padding3) (void);
  void (*_json_padding4) (void);
};

GQuark json_reader_error_quark (void);
GType json_reader_get_type (void) G_GNUC_CONST;

JsonReader *           json_reader_new               (JsonNode     *node);

void                   json_reader_set_root          (JsonReader   *reader,
                                                      JsonNode     *root);

G_CONST_RETURN GError *json_reader_get_error         (JsonReader   *reader);

gboolean               json_reader_is_array          (JsonReader   *reader);
gboolean               json_reader_read_element      (JsonReader   *reader,
                                                      guint         index_);
void                   json_reader_end_element       (JsonReader   *reader);
gint                   json_reader_count_elements    (JsonReader   *reader);

gboolean               json_reader_is_object         (JsonReader   *reader);
gboolean               json_reader_read_member       (JsonReader   *reader,
                                                      const gchar  *member_name);
void                   json_reader_end_member        (JsonReader   *reader);
gint                   json_reader_count_members     (JsonReader   *reader);

gboolean               json_reader_is_value          (JsonReader   *reader);
JsonNode *             json_reader_get_value         (JsonReader   *reader);
gint64                 json_reader_get_int_value     (JsonReader   *reader);
gdouble                json_reader_get_double_value  (JsonReader   *reader);
G_CONST_RETURN gchar * json_reader_get_string_value  (JsonReader   *reader);
gboolean               json_reader_get_boolean_value (JsonReader   *reader);
gboolean               json_reader_get_null_value    (JsonReader   *reader);

G_END_DECLS

#endif /* __JSON_READER_H__ */
