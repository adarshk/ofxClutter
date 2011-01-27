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
 *   Emmanuele Bassi <ebassi@linux.intel.com>
 */

#if !defined(__CLUTTER_H_INSIDE__) && !defined(CLUTTER_COMPILATION)
#error "Only <clutter/clutter.h> can be included directly."
#endif

#ifndef __CLUTTER_DRAG_ACTION_H__
#define __CLUTTER_DRAG_ACTION_H__

#include <clutter/clutter-action.h>
#include <clutter/clutter-event.h>

G_BEGIN_DECLS

#define CLUTTER_TYPE_DRAG_ACTION                (clutter_drag_action_get_type ())
#define CLUTTER_DRAG_ACTION(obj)                (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLUTTER_TYPE_DRAG_ACTION, ClutterDragAction))
#define CLUTTER_IS_DRAG_ACTION(obj)             (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLUTTER_TYPE_DRAG_ACTION))
#define CLUTTER_DRAG_ACTION_CLASS(klass)        (G_TYPE_CHECK_CLASS_CAST ((klass), CLUTTER_TYPE_DRAG_ACTION, ClutterDragActionClass))
#define CLUTTER_IS_DRAG_ACTION_CLASS(klass)     (G_TYPE_CHECK_CLASS_TYPE ((klass), CLUTTER_TYPE_DRAG_ACTION))
#define CLUTTER_DRAG_ACTION_GET_CLASS(obj)      (G_TYPE_INSTANCE_GET_CLASS ((obj), CLUTTER_TYPE_DRAG_ACTION, ClutterDragActionClass))

typedef struct _ClutterDragAction               ClutterDragAction;
typedef struct _ClutterDragActionPrivate        ClutterDragActionPrivate;
typedef struct _ClutterDragActionClass          ClutterDragActionClass;

/**
 * ClutterDragAxis:
 * @CLUTTER_DRAG_AXIS_NONE: No constraint
 * @CLUTTER_DRAG_X_AXIS: Set a constraint on the X axis
 * @CLUTTER_DRAG_Y_AXIS: Set a constraint on the Y axis
 *
 * The axis of the constraint that should be applied on the
 * dragging action
 *
 * Since: 1.4
 */
typedef enum { /*< prefix=CLUTTER_DRAG >*/
  CLUTTER_DRAG_AXIS_NONE = 0,

  CLUTTER_DRAG_X_AXIS,
  CLUTTER_DRAG_Y_AXIS
} ClutterDragAxis;

/**
 * ClutterDragAction:
 *
 * The <structname>ClutterDragAction</structname> structure contains only
 * private data and should be accessed using the provided API
 *
 * Since: 1.4
 */
struct _ClutterDragAction
{
  /*< private >*/
  ClutterAction parent_instance;

  ClutterDragActionPrivate *priv;
};

/**
 * ClutterDragActionClass:
 * @drag_begin: class handler of the #ClutterDragAction::drag-begin signal
 * @drag_motion: class handler of the #ClutterDragAction::drag-motion signal
 * @drag_end: class handler of the #ClutterDragAction::drag-end signal
 *
 * The <structname>ClutterDragActionClass</structname> structure contains
 * only private data
 *
 * Since: 1.4
 */
struct _ClutterDragActionClass
{
  /*< private >*/
  ClutterActionClass parent_class;

  /*< public >*/
  void (* drag_begin)  (ClutterDragAction   *action,
                        ClutterActor        *actor,
                        gfloat               event_x,
                        gfloat               event_y,
                        ClutterModifierType  modifiers);
  void (* drag_motion) (ClutterDragAction   *action,
                        ClutterActor        *actor,
                        gfloat               delta_x,
                        gfloat               delta_y);
  void (* drag_end)    (ClutterDragAction   *action,
                        ClutterActor        *actor,
                        gfloat               event_x,
                        gfloat               event_y,
                        ClutterModifierType  modifiers);

  /*< private >*/
  void (* _clutter_drag_action1) (void);
  void (* _clutter_drag_action2) (void);
  void (* _clutter_drag_action3) (void);
  void (* _clutter_drag_action4) (void);
  void (* _clutter_drag_action5) (void);
};

GType clutter_drag_action_get_type (void) G_GNUC_CONST;

ClutterAction * clutter_drag_action_new                   (void);

void            clutter_drag_action_set_drag_threshold (ClutterDragAction *action,
                                                        guint              x_threshold,
                                                        guint              y_threshold);
void            clutter_drag_action_get_drag_threshold (ClutterDragAction *action,
                                                        guint             *x_threshold,
                                                        guint             *y_threshold);
void            clutter_drag_action_set_drag_handle    (ClutterDragAction *action,
                                                        ClutterActor      *handle);
ClutterActor *  clutter_drag_action_get_drag_handle    (ClutterDragAction *action);
void            clutter_drag_action_set_drag_axis      (ClutterDragAction *action,
                                                        ClutterDragAxis    axis);
ClutterDragAxis clutter_drag_action_get_drag_axis      (ClutterDragAction *action);

void            clutter_drag_action_get_press_coords   (ClutterDragAction *action,
                                                        gfloat            *press_x,
                                                        gfloat            *press_y);
void            clutter_drag_action_get_motion_coords  (ClutterDragAction *action,
                                                        gfloat            *motion_x,
                                                        gfloat            *motion_y);

G_END_DECLS

#endif /* __CLUTTER_DRAG_ACTION_H__ */
