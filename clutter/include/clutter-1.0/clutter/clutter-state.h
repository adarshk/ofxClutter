/*
 * Clutter.
 *
 * An OpenGL based 'interactive canvas' library.
 *
 * Authored By Øyvind Kolås <pippin@linux.intel.com>
 *
 * Copyright (C) 2009 Intel Corporation
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
 */

#ifndef __CLUTTER_STATE_H__
#define __CLUTTER_STATE_H__

#include <clutter/clutter-types.h>
#include <clutter/clutter-timeline.h>

G_BEGIN_DECLS

#define CLUTTER_TYPE_STATE              (clutter_state_get_type ())
#define CLUTTER_STATE(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLUTTER_TYPE_STATE, ClutterState))
#define CLUTTER_STATE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), CLUTTER_TYPE_STATE, ClutterStateClass))
#define CLUTTER_IS_STATE(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLUTTER_TYPE_STATE))
#define CLUTTER_IS_STATE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), CLUTTER_TYPE_STATE))
#define CLUTTER_STATE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), CLUTTER_TYPE_STATE, ClutterStateClass))

typedef struct _ClutterState        ClutterState;
typedef struct _ClutterStatePrivate ClutterStatePrivate;
typedef struct _ClutterStateClass   ClutterStateClass;

/**
 * ClutterStateKey:
 *
 * <structname>ClutterStateKey</structname> is an opaque structure whose
 * members cannot be accessed directly
 *
 * Since: 1.4
 */
typedef struct _ClutterStateKey     ClutterStateKey;

/**
 * ClutterState:
 *
 * The <structname>ClutterState</structname> structure contains only
 * private data and should be accessed using the provided API
 *
 * Since: 1.4
 */
struct _ClutterState
{
  /*< private >*/
  GObject        parent;
  ClutterStatePrivate *priv;
};

/**
 * ClutterStateClass:
 * @completed: class handler for the #ClutterState::completed signal
 *
 * The <structname>ClutterStateClass</structname> structure contains
 * only private data
 *
 * Since: 1.4
 */
struct _ClutterStateClass
{
  /*< private >*/
  GObjectClass parent_class;

  /*< public >*/
  void (* completed) (ClutterState *state);

  /*< private >*/
  /* padding for future expansion */
  gpointer _padding_dummy[8];
};

GType clutter_state_get_type (void) G_GNUC_CONST;
ClutterState    *clutter_state_new            (void);


ClutterTimeline * clutter_state_set_state     (ClutterState    *state,
                                               const gchar     *target_state_name);
ClutterTimeline * clutter_state_warp_to_state (ClutterState    *state,
                                               const gchar     *target_state_name);
ClutterState *    clutter_state_set_key       (ClutterState    *state,
                                               const gchar     *source_state_name,
                                               const gchar     *target_state_name,
                                               GObject         *object,
                                               const gchar     *property_name,
                                               guint            mode,
                                               const GValue    *value,
                                               gdouble          pre_delay,
                                               gdouble          post_delay);
void              clutter_state_set_duration  (ClutterState    *state,
                                               const gchar     *source_state_name,
                                               const gchar     *target_state_name,
                                               guint            duration);
guint             clutter_state_get_duration  (ClutterState    *state,
                                               const gchar     *source_state_name,
                                               const gchar     *target_state_name);
void              clutter_state_set           (ClutterState    *state,
                                               const gchar     *source_state_name,
                                               const gchar     *target_state_name,
                                               gpointer         first_object,
                                               const gchar     *first_property_name,
                                               gulong           first_mode,
                                                ...) G_GNUC_NULL_TERMINATED;
GList           * clutter_state_get_states    (ClutterState    *state);
GList           * clutter_state_get_keys      (ClutterState    *state,
                                               const gchar     *source_state_name,
                                               const gchar     *target_state_name,
                                               GObject         *object,
                                               const gchar     *property_name);
void              clutter_state_remove_key    (ClutterState    *state,
                                               const gchar     *source_state_name,
                                               const gchar     *target_state_name,
                                               GObject         *object,
                                               const gchar     *property_name);
ClutterTimeline * clutter_state_get_timeline  (ClutterState    *state);
void              clutter_state_set_animator  (ClutterState    *state,
                                               const gchar     *source_state_name,
                                               const gchar     *target_state_name,
                                               ClutterAnimator *animator);
ClutterAnimator * clutter_state_get_animator  (ClutterState    *state,
                                               const gchar     *source_state_name,
                                               const gchar     *target_state_name);
G_CONST_RETURN gchar *clutter_state_get_state (ClutterState    *state);

/*
 * ClutterStateKey
 */

GType                 clutter_state_key_get_type              (void) G_GNUC_CONST;
gdouble               clutter_state_key_get_pre_delay         (const ClutterStateKey *state_key);
gdouble               clutter_state_key_get_post_delay        (const ClutterStateKey *state_key);
gulong                clutter_state_key_get_mode              (const ClutterStateKey *state_key);
gboolean              clutter_state_key_get_value             (const ClutterStateKey *state_key,
                                                               GValue                *value);
GType                 clutter_state_key_get_property_type     (const ClutterStateKey *key);
GObject *             clutter_state_key_get_object            (const ClutterStateKey *state_key);
G_CONST_RETURN gchar *clutter_state_key_get_property_name     (const ClutterStateKey *state_key);
G_CONST_RETURN gchar *clutter_state_key_get_source_state_name (const ClutterStateKey *state_key);
G_CONST_RETURN gchar *clutter_state_key_get_target_state_name (const ClutterStateKey *state_key);

G_END_DECLS

#endif /* __CLUTTER_STATE_H__ */
