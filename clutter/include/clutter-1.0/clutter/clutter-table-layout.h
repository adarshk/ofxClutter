/*
 * Clutter.
 *
 * An OpenGL based 'interactive canvas' library.
 *
 * Copyright (C) 2010  Intel Corporation.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
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
 *   Jose Dapena Paz <jdapena@igalia.com>
 *
 * Based on the MX MxTable actor by:
 *   Thomas Wood <thomas.wood@intel.com>
 */

#if !defined(__CLUTTER_H_INSIDE__) && !defined(CLUTTER_COMPILATION)
#error "Only <clutter/clutter.h> can be included directly."
#endif

#ifndef __CLUTTER_TABLE_LAYOUT_H__
#define __CLUTTER_TABLE_LAYOUT_H__

#include <clutter/clutter-layout-manager.h>

G_BEGIN_DECLS

#define CLUTTER_TYPE_TABLE_LAYOUT                 (clutter_table_layout_get_type ())
#define CLUTTER_TABLE_LAYOUT(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLUTTER_TYPE_TABLE_LAYOUT, ClutterTableLayout))
#define CLUTTER_IS_TABLE_LAYOUT(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLUTTER_TYPE_TABLE_LAYOUT))
#define CLUTTER_TABLE_LAYOUT_CLASS(klass)         (G_TYPE_CHECK_CLASS_CAST ((klass), CLUTTER_TYPE_TABLE_LAYOUT, ClutterTableLayoutClass))
#define CLUTTER_IS_TABLE_LAYOUT_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), CLUTTER_TYPE_TABLE_LAYOUT))
#define CLUTTER_TABLE_LAYOUT_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), CLUTTER_TYPE_TABLE_LAYOUT, ClutterTableLayoutClass))

typedef struct _ClutterTableLayout                ClutterTableLayout;
typedef struct _ClutterTableLayoutPrivate         ClutterTableLayoutPrivate;
typedef struct _ClutterTableLayoutClass           ClutterTableLayoutClass;

/**
 * ClutterTableAlignment:
 * @CLUTTER_TABLE_ALIGNMENT_START: Align the child to the top or to the
 *   left of a cell in the table, depending on the axis
 * @CLUTTER_TABLE_ALIGNMENT_CENTER: Align the child to the center of
 *   a cell in the table
 * @CLUTTER_TABLE_ALIGNMENT_END: Align the child to the bottom or to the
 *   right of a cell in the table, depending on the axis
 *
 * The alignment policies available on each axis of the #ClutterTableLayout
 *
 * Since: 1.4
 */
typedef enum {
  CLUTTER_TABLE_ALIGNMENT_START,
  CLUTTER_TABLE_ALIGNMENT_CENTER,
  CLUTTER_TABLE_ALIGNMENT_END
} ClutterTableAlignment;

/**
 * ClutterTableLayout:
 *
 * The #ClutterTableLayout structure contains only private data
 * and should be accessed using the provided API
 *
 * Since: 1.4
 */
struct _ClutterTableLayout
{
  /*< private >*/
  ClutterLayoutManager parent_instance;

  ClutterTableLayoutPrivate *priv;
};

/**
 * ClutterTableLayoutClass:
 *
 * The #ClutterTableLayoutClass structure contains only private
 * data and should be accessed using the provided API
 *
 * Since: 1.4
 */
struct _ClutterTableLayoutClass
{
  /*< private >*/
  ClutterLayoutManagerClass parent_class;
};

GType clutter_table_layout_get_type (void) G_GNUC_CONST;

ClutterLayoutManager *clutter_table_layout_new                 (void);

void                  clutter_table_layout_pack                (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                gint                   column,
                                                                gint                   row);

void                  clutter_table_layout_set_column_spacing  (ClutterTableLayout    *layout,
                                                                guint                  spacing);
void                  clutter_table_layout_set_row_spacing     (ClutterTableLayout    *layout,
                                                                guint                  spacing);
guint                 clutter_table_layout_get_column_spacing  (ClutterTableLayout    *layout);
guint                 clutter_table_layout_get_row_spacing     (ClutterTableLayout    *layout);

void                  clutter_table_layout_set_span            (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                gint                   column_span,
                                                                gint                   row_span);
void                  clutter_table_layout_get_span            (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                gint                  *column_span,
                                                                gint                  *row_span);
void                  clutter_table_layout_set_alignment       (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                ClutterTableAlignment  x_align,
                                                                ClutterTableAlignment  y_align);
void                  clutter_table_layout_get_alignment       (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                ClutterTableAlignment *x_align,
                                                                ClutterTableAlignment *y_align);
void                  clutter_table_layout_set_fill            (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                gboolean               x_fill,
                                                                gboolean               y_fill);
void                  clutter_table_layout_get_fill            (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                gboolean              *x_fill,
                                                                gboolean              *y_fill);
void                  clutter_table_layout_set_expand          (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                gboolean               x_expand,
                                                                gboolean               y_expand);
void                  clutter_table_layout_get_expand          (ClutterTableLayout    *layout,
                                                                ClutterActor          *actor,
                                                                gboolean              *x_expand,
                                                                gboolean              *y_expand);

gint                  clutter_table_layout_get_row_count       (ClutterTableLayout    *layout);
gint                  clutter_table_layout_get_column_count    (ClutterTableLayout    *layout);

void                  clutter_table_layout_set_use_animations  (ClutterTableLayout    *layout,
                                                                gboolean               animate);
gboolean              clutter_table_layout_get_use_animations  (ClutterTableLayout    *layout);
void                  clutter_table_layout_set_easing_mode     (ClutterTableLayout    *layout,
                                                                gulong                 mode);
gulong                clutter_table_layout_get_easing_mode     (ClutterTableLayout    *layout);
void                  clutter_table_layout_set_easing_duration (ClutterTableLayout    *layout,
                                                                guint                  msecs);
guint                 clutter_table_layout_get_easing_duration (ClutterTableLayout    *layout);

G_END_DECLS

#endif /* __CLUTTER_TABLE_LAYOUT_H__ */
