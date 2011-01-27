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

#ifndef __CLUTTER_SHADER_EFFECT_H__
#define __CLUTTER_SHADER_EFFECT_H__

#include <clutter/clutter-offscreen-effect.h>

G_BEGIN_DECLS

#define CLUTTER_TYPE_SHADER_EFFECT              (clutter_shader_effect_get_type ())
#define CLUTTER_SHADER_EFFECT(obj)              (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLUTTER_TYPE_SHADER_EFFECT, ClutterShaderEffect))
#define CLUTTER_IS_SHADER_EFFECT(obj)           (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLUTTER_TYPE_SHADER_EFFECT))
#define CLUTTER_SHADER_EFFECT_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), CLUTTER_TYPE_SHADER_EFFECT, ClutterShaderEffectClass))
#define CLUTTER_IS_SHADER_EFFECT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), CLUTTER_TYPE_SHADER_EFFECT))
#define CLUTTER_SHADER_EFFECT_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), CLUTTER_TYPE_SHADER_EFFECT, ClutterShaderEffectClass))

typedef struct _ClutterShaderEffect             ClutterShaderEffect;
typedef struct _ClutterShaderEffectPrivate      ClutterShaderEffectPrivate;
typedef struct _ClutterShaderEffectClass        ClutterShaderEffectClass;

/**
 * ClutterShaderEffect:
 *
 * The <structname>ClutterShaderEffect</structname> structure contains
 * only private data and should be accessed using the provided API
 *
 * Since: 1.4
 */
struct _ClutterShaderEffect
{
  /*< private >*/
  ClutterOffscreenEffect parent_instance;

  ClutterShaderEffectPrivate *priv;
};

/**
 * ClutterShaderEffectClass:
 *
 * The <structname>ClutterShaderEffectClass</structname> structure contains
 * only private data
 *
 * Since: 1.4
 */
struct _ClutterShaderEffectClass
{
  /*< private >*/
  ClutterOffscreenEffectClass parent_class;

  /* padding */
  void (*_clutter_shader1) (void);
  void (*_clutter_shader2) (void);
  void (*_clutter_shader3) (void);
  void (*_clutter_shader4) (void);
  void (*_clutter_shader5) (void);
  void (*_clutter_shader6) (void);
};

GType clutter_shader_effect_get_type (void) G_GNUC_CONST;

gboolean   clutter_shader_effect_set_shader_source (ClutterShaderEffect *effect,
                                                    const gchar         *source);

void       clutter_shader_effect_set_uniform       (ClutterShaderEffect *effect,
                                                    const gchar         *name,
                                                    GType                gtype,
                                                    gsize                n_values,
                                                    ...);
void       clutter_shader_effect_set_uniform_value (ClutterShaderEffect *effect,
                                                    const gchar         *name,
                                                    const GValue        *value);

CoglHandle clutter_shader_effect_get_shader        (ClutterShaderEffect *effect);
CoglHandle clutter_shader_effect_get_program       (ClutterShaderEffect *effect);

G_END_DECLS

#endif /* __CLUTTER_SHADER_EFFECT_H__ */
