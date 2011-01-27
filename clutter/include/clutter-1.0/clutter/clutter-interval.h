/*
 * Clutter.
 *
 * An OpenGL based 'interactive canvas' library.
 *
 * Copyright (C) 2008  Intel Corporation.
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

#ifndef __CLUTTER_INTERVAL_H__
#define __CLUTTER_INTERVAL_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define CLUTTER_TYPE_INTERVAL                   (clutter_interval_get_type ())
#define CLUTTER_INTERVAL(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLUTTER_TYPE_INTERVAL, ClutterInterval))
#define CLUTTER_IS_INTERVAL(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLUTTER_TYPE_INTERVAL))
#define CLUTTER_INTERVAL_CLASS(klass)           (G_TYPE_CHECK_CLASS_CAST ((klass), CLUTTER_TYPE_INTERVAL, ClutterIntervalClass))
#define CLUTTER_IS_INTERVAL_CLASS(klass)        (G_TYPE_CHECK_CLASS_TYPE ((klass), CLUTTER_TYPE_INTERVAL))
#define CLUTTER_INTERVAL_GET_CLASS(obj)         (G_TYPE_INSTANCE_GET_CLASS ((obj), CLUTTER_TYPE_INTERVAL, ClutterIntervalClass))

typedef struct _ClutterInterval                 ClutterInterval;
typedef struct _ClutterIntervalPrivate          ClutterIntervalPrivate;
typedef struct _ClutterIntervalClass            ClutterIntervalClass;

/**
 * ClutterProgressFunc:
 * @a: the initial value of an interval
 * @b: the final value of an interval
 * @progress: the progress factor, between 0 and 1
 * @retval: the value used to store the progress
 *
 * Prototype of the progress function used to compute the value
 * between the two ends @a and @b of an interval depending on
 * the value of @progress.
 *
 * The #GValue in @retval is already initialized with the same
 * type as @a and @b.
 *
 * This function will be called by #ClutterInterval if the
 * type of the values of the interval was registered using
 * clutter_interval_register_progress_func().
 *
 * Return value: %TRUE if the function successfully computed
 *   the value and stored it inside @retval
 *
 * Since: 1.0
 */
typedef gboolean (* ClutterProgressFunc) (const GValue *a,
                                          const GValue *b,
                                          gdouble       progress,
                                          GValue       *retval);

/**
 * ClutterInterval:
 *
 * The #ClutterInterval structure contains only private data and should
 * be accessed using the provided functions.
 *
 * Since: 1.0
 */
struct _ClutterInterval
{
  /*< private >*/
  GInitiallyUnowned parent_instance;

  ClutterIntervalPrivate *priv;
};

/**
 * ClutterIntervalClass:
 * @validate: virtual function for validating an interval
 *   using a #GParamSpec
 * @compute_value: virtual function for computing the value
 *   inside an interval using an adimensional factor between 0 and 1
 *
 * The #ClutterIntervalClass contains only private data.
 *
 * Since: 1.0
 */
struct _ClutterIntervalClass
{
  /*< private >*/
  GInitiallyUnownedClass parent_class;

  /*< public >*/
  gboolean (* validate)      (ClutterInterval *interval,
                              GParamSpec      *pspec);
  gboolean (* compute_value) (ClutterInterval *interval,
                              gdouble          factor,
                              GValue          *value);

  /*< private >*/
  /* padding for future expansion */
  void (*_clutter_reserved1) (void);
  void (*_clutter_reserved2) (void);
  void (*_clutter_reserved3) (void);
  void (*_clutter_reserved4) (void);
  void (*_clutter_reserved5) (void);
  void (*_clutter_reserved6) (void);
};

GType            clutter_interval_get_type           (void) G_GNUC_CONST;

ClutterInterval *clutter_interval_new                (GType            gtype,
                                                      ...);
ClutterInterval *clutter_interval_new_with_values    (GType            gtype,
                                                      const GValue    *initial,
                                                      const GValue    *final);

ClutterInterval *clutter_interval_clone              (ClutterInterval *interval);

GType            clutter_interval_get_value_type     (ClutterInterval *interval);
void             clutter_interval_set_initial_value  (ClutterInterval *interval,
                                                      const GValue    *value);
void             clutter_interval_get_initial_value  (ClutterInterval *interval,
                                                      GValue          *value);
GValue *         clutter_interval_peek_initial_value (ClutterInterval *interval);
void             clutter_interval_set_final_value    (ClutterInterval *interval,
                                                      const GValue    *value);
void             clutter_interval_get_final_value    (ClutterInterval *interval,
                                                      GValue          *value);
GValue *         clutter_interval_peek_final_value   (ClutterInterval *interval);

void             clutter_interval_set_interval       (ClutterInterval *interval,
                                                      ...);
void             clutter_interval_get_interval       (ClutterInterval *interval,
                                                      ...);

gboolean         clutter_interval_validate           (ClutterInterval *interval,
                                                      GParamSpec      *pspec);
gboolean         clutter_interval_compute_value      (ClutterInterval *interval,
                                                      gdouble          factor,
                                                      GValue          *value);

G_CONST_RETURN GValue *clutter_interval_compute      (ClutterInterval *interval,
                                                      gdouble          factor);

void clutter_interval_register_progress_func (GType               value_type,
                                              ClutterProgressFunc func);

G_END_DECLS

#endif /* __CLUTTER_INTERVAL_H__ */
