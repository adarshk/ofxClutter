/*
 * Cogl
 *
 * An object oriented GL/GLES Abstraction/Utility Layer
 *
 * Copyright (C) 2008,2009 Intel Corporation.
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
 *
 */

#if !defined(__COGL_H_INSIDE__) && !defined(CLUTTER_COMPILATION)
#error "Only <cogl/cogl.h> can be included directly."
#endif

#ifndef __COGL_TYPES_H__
#define __COGL_TYPES_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* Some structures are meant to be opaque but they have public
   definitions because we want the size to be public so they can be
   allocated on the stack. This macro is used to ensure that users
   don't accidentally access private members */
#ifdef CLUTTER_COMPILATION
#define COGL_PRIVATE(x) x
#else
#define COGL_PRIVATE(x) private_member_ ## x
#endif

/**
 * CoglHandle:
 *
 * Type used for storing references to cogl objects, the CoglHandle is
 * a fully opaque type without any public data members.
 */
typedef gpointer CoglHandle;

/**
 * COGL_INVALID_HANDLE:
 *
 * A COGL handle that is not valid, used for unitialized handles as well as
 * error conditions.
 */
#define COGL_INVALID_HANDLE NULL

#define COGL_TYPE_HANDLE        (cogl_handle_get_type ())
GType
cogl_handle_get_type (void) G_GNUC_CONST;

/**
 * cogl_handle_ref:
 * @handle: a #CoglHandle
 *
 * Increases the reference count of @handle by 1
 *
 * Return value: (transfer none): the handle, with its reference count increased
 */
CoglHandle
cogl_handle_ref (CoglHandle handle);

/**
 * cogl_handle_unref:
 * @handle: a #CoglHandle
 *
 * Drecreases the reference count of @handle by 1; if the reference
 * count reaches 0, the resources allocated by @handle will be freed
 */
void
cogl_handle_unref (CoglHandle handle);

/**
 * cogl_object_ref:
 * @object: a #CoglObject
 *
 * Increases the reference count of @handle by 1
 *
 * Returns: the @object, with its reference count increased
 */
void *
cogl_object_ref (void *object);

/**
 * cogl_object_unref:
 * @object: a #CoglObject
 *
 * Drecreases the reference count of @object by 1; if the reference
 * count reaches 0, the resources allocated by @object will be freed
 */
void
cogl_object_unref (void *object);

/**
 * CoglFuncPtr:
 *
 * The type used by cogl for function pointers, note that this type
 * is used as a generic catch-all cast for function pointers and the
 * actual arguments and return type may be different.
 */
typedef void (* CoglFuncPtr) (void);

/**
 * CoglFixed:
 *
 * Fixed point number using a (16.16) notation.
 */
typedef gint32 CoglFixed;

#define COGL_TYPE_FIXED         (cogl_fixed_get_type ())
GType
cogl_fixed_get_type (void) G_GNUC_CONST;

/**
 * CoglAngle:
 *
 * Integer representation of an angle such that 1024 corresponds to
 * full circle (i.e., 2 * pi).
 *
 * Since: 1.0
 */
typedef gint32 CoglAngle;

typedef struct _CoglColor               CoglColor;
typedef struct _CoglTextureVertex       CoglTextureVertex;

/* Enum declarations */

#define COGL_PIXEL_FORMAT_24    2
#define COGL_PIXEL_FORMAT_32    3
#define COGL_A_BIT              (1 << 4)
#define COGL_BGR_BIT            (1 << 5)
#define COGL_AFIRST_BIT         (1 << 6)
#define COGL_PREMULT_BIT        (1 << 7)
#define COGL_UNORDERED_MASK     0x0F
#define COGL_UNPREMULT_MASK     0x7F

/**
 * CoglPixelFormat:
 * @COGL_PIXEL_FORMAT_ANY: Any format
 * @COGL_PIXEL_FORMAT_A_8: 8 bits alpha mask
 * @COGL_PIXEL_FORMAT_RGB_565: RGB, 16 bits
 * @COGL_PIXEL_FORMAT_RGBA_4444: RGBA, 16 bits
 * @COGL_PIXEL_FORMAT_RGBA_5551: RGBA, 16 bits
 * @COGL_PIXEL_FORMAT_YUV: Not currently supported
 * @COGL_PIXEL_FORMAT_G_8: Single luminance component
 * @COGL_PIXEL_FORMAT_RGB_888: RGB, 24 bits
 * @COGL_PIXEL_FORMAT_BGR_888: BGR, 24 bits
 * @COGL_PIXEL_FORMAT_RGBA_8888: RGBA, 32 bits
 * @COGL_PIXEL_FORMAT_BGRA_8888: BGRA, 32 bits
 * @COGL_PIXEL_FORMAT_ARGB_8888: ARGB, 32 bits
 * @COGL_PIXEL_FORMAT_ABGR_8888: ABGR, 32 bits
 * @COGL_PIXEL_FORMAT_RGBA_8888_PRE: Premultiplied RGBA, 32 bits
 * @COGL_PIXEL_FORMAT_BGRA_8888_PRE: Premultiplied BGRA, 32 bits
 * @COGL_PIXEL_FORMAT_ARGB_8888_PRE: Premultiplied ARGB, 32 bits
 * @COGL_PIXEL_FORMAT_ABGR_8888_PRE: Premultiplied ABGR, 32 bits
 * @COGL_PIXEL_FORMAT_RGBA_4444_PRE: Premultiplied RGBA, 16 bits
 * @COGL_PIXEL_FORMAT_RGBA_5551_PRE: Premultiplied RGBA, 16 bits
 *
 * Pixel formats used by COGL. For the formats with a byte per
 * component, the order of the components specify the order in
 * increasing memory addresses. So for example
 * %COGL_PIXEL_FORMAT_RGB_888 would have the red component in the
 * lowest address, green in the next address and blue after that
 * regardless of the endinanness of the system.
 *
 * For the 16-bit formats the component order specifies the order
 * within a 16-bit number from most significant bit to least
 * significant. So for %COGL_PIXEL_FORMAT_RGB_565, the red component
 * would be in bits 11-15, the green component would be in 6-11 and
 * the blue component would be in 1-5. Therefore the order in memory
 * depends on the endianness of the system.
 *
 * When uploading a texture %COGL_PIXEL_FORMAT_ANY can be used as the
 * internal format. Cogl will try to pick the best format to use
 * internally and convert the texture data if necessary.
 *
 * Since: 0.8
 */
typedef enum { /*< prefix=COGL_PIXEL_FORMAT >*/
  COGL_PIXEL_FORMAT_ANY           = 0,
  COGL_PIXEL_FORMAT_A_8           = 1 | COGL_A_BIT,

  COGL_PIXEL_FORMAT_RGB_565       = 4,
  COGL_PIXEL_FORMAT_RGBA_4444     = 5 | COGL_A_BIT,
  COGL_PIXEL_FORMAT_RGBA_5551     = 6 | COGL_A_BIT,
  COGL_PIXEL_FORMAT_YUV           = 7,
  COGL_PIXEL_FORMAT_G_8           = 8,

  COGL_PIXEL_FORMAT_RGB_888       =  COGL_PIXEL_FORMAT_24,
  COGL_PIXEL_FORMAT_BGR_888       = (COGL_PIXEL_FORMAT_24 | COGL_BGR_BIT),

  COGL_PIXEL_FORMAT_RGBA_8888     = (COGL_PIXEL_FORMAT_32 | COGL_A_BIT),
  COGL_PIXEL_FORMAT_BGRA_8888     = (COGL_PIXEL_FORMAT_32 | COGL_A_BIT | COGL_BGR_BIT),
  COGL_PIXEL_FORMAT_ARGB_8888     = (COGL_PIXEL_FORMAT_32 | COGL_A_BIT | COGL_AFIRST_BIT),
  COGL_PIXEL_FORMAT_ABGR_8888     = (COGL_PIXEL_FORMAT_32 | COGL_A_BIT | COGL_BGR_BIT | COGL_AFIRST_BIT),

  COGL_PIXEL_FORMAT_RGBA_8888_PRE = (COGL_PIXEL_FORMAT_32 | COGL_A_BIT | COGL_PREMULT_BIT),
  COGL_PIXEL_FORMAT_BGRA_8888_PRE = (COGL_PIXEL_FORMAT_32 | COGL_A_BIT | COGL_PREMULT_BIT | COGL_BGR_BIT),
  COGL_PIXEL_FORMAT_ARGB_8888_PRE = (COGL_PIXEL_FORMAT_32 | COGL_A_BIT | COGL_PREMULT_BIT | COGL_AFIRST_BIT),
  COGL_PIXEL_FORMAT_ABGR_8888_PRE = (COGL_PIXEL_FORMAT_32 | COGL_A_BIT | COGL_PREMULT_BIT | COGL_BGR_BIT | COGL_AFIRST_BIT),
  COGL_PIXEL_FORMAT_RGBA_4444_PRE = (COGL_PIXEL_FORMAT_RGBA_4444 | COGL_A_BIT | COGL_PREMULT_BIT),
  COGL_PIXEL_FORMAT_RGBA_5551_PRE = (COGL_PIXEL_FORMAT_RGBA_5551 | COGL_A_BIT | COGL_PREMULT_BIT)
} CoglPixelFormat;

/**
 * CoglFeatureFlags:
 * @COGL_FEATURE_TEXTURE_RECTANGLE: ARB_texture_rectangle support
 * @COGL_FEATURE_TEXTURE_NPOT: Non power of two textures are supported
 *    by the hardware. This is a equivalent to the
 *    %COGL_FEATURE_TEXTURE_NPOT_BASIC, %COGL_FEATURE_TEXTURE_NPOT_MIPMAP
 *    and %COGL_FEATURE_TEXTURE_NPOT_REPEAT features combined.
 * @COGL_FEATURE_TEXTURE_YUV: ycbcr conversion support
 * @COGL_FEATURE_TEXTURE_READ_PIXELS: glReadPixels() support
 * @COGL_FEATURE_SHADERS_GLSL: GLSL support
 * @COGL_FEATURE_SHADERS_ARBFP: ARBFP support
 * @COGL_FEATURE_OFFSCREEN: FBO support
 * @COGL_FEATURE_OFFSCREEN_MULTISAMPLE: Multisample support on FBOs
 * @COGL_FEATURE_OFFSCREEN_BLIT: Blit support on FBOs
 * @COGL_FEATURE_FOUR_CLIP_PLANES: At least 4 clip planes available
 * @COGL_FEATURE_STENCIL_BUFFER: Stencil buffer support
 * @COGL_FEATURE_VBOS: VBO support
 * @COGL_FEATURE_PBOS: PBO support
 * @COGL_FEATURE_UNSIGNED_INT_INDICES: Set if
 *     %COGL_INDICES_TYPE_UNSIGNED_INT is supported in
 *     cogl_vertex_buffer_indices_new().
 * @COGL_FEATURE_DEPTH_RANGE: cogl_material_set_depth_range() support
 * @COGL_FEATURE_TEXTURE_NPOT_BASIC: The hardware supports non power
 *     of two textures, but you also need to check the
 *     %COGL_FEATURE_TEXTURE_NPOT_MIPMAP and %COGL_FEATURE_TEXTURE_NPOT_REPEAT
 *     features to know if the hardware supports npot texture mipmaps
 *     or repeat modes other than
 *     %COGL_MATERIAL_WRAP_MODE_CLAMP_TO_EDGE respectively.
 * @COGL_FEATURE_TEXTURE_NPOT_MIPMAP: Mipmapping is supported in
 *     conjuntion with non power of two textures.
 * @COGL_FEATURE_TEXTURE_NPOT_REPEAT: Repeat modes other than
 *     %COGL_MATERIAL_WRAP_MODE_CLAMP_TO_EDGE are supported by the
 *     hardware.
 * @COGL_FEATURE_POINT_SPRITE: Whether
 *     cogl_material_set_layer_point_sprite_coords_enabled() is supported.
 * @COGL_FEATURE_TEXTURE_3D: 3D texture support
 *
 * Flags for the supported features.
 *
 * Since: 0.8
 */
typedef enum
{
  COGL_FEATURE_TEXTURE_RECTANGLE      = (1 << 1),
  COGL_FEATURE_TEXTURE_NPOT           = (1 << 2),
  COGL_FEATURE_TEXTURE_YUV            = (1 << 3),
  COGL_FEATURE_TEXTURE_READ_PIXELS    = (1 << 4),
  COGL_FEATURE_SHADERS_GLSL           = (1 << 5),
  COGL_FEATURE_OFFSCREEN              = (1 << 6),
  COGL_FEATURE_OFFSCREEN_MULTISAMPLE  = (1 << 7),
  COGL_FEATURE_OFFSCREEN_BLIT         = (1 << 8),
  COGL_FEATURE_FOUR_CLIP_PLANES       = (1 << 9),
  COGL_FEATURE_STENCIL_BUFFER         = (1 << 10),
  COGL_FEATURE_VBOS		      = (1 << 11),
  COGL_FEATURE_PBOS		      = (1 << 12),
  COGL_FEATURE_UNSIGNED_INT_INDICES   = (1 << 13),
  COGL_FEATURE_DEPTH_RANGE            = (1 << 14),
  COGL_FEATURE_TEXTURE_NPOT_BASIC     = (1 << 15),
  COGL_FEATURE_TEXTURE_NPOT_MIPMAP    = (1 << 16),
  COGL_FEATURE_TEXTURE_NPOT_REPEAT    = (1 << 17),
  COGL_FEATURE_POINT_SPRITE           = (1 << 18),
  COGL_FEATURE_TEXTURE_3D             = (1 << 19),
  COGL_FEATURE_SHADERS_ARBFP          = (1 << 20)
} CoglFeatureFlags;

/**
 * CoglBufferTarget:
 * @COGL_WINDOW_BUFFER: FIXME
 * @COGL_OFFSCREEN_BUFFER: FIXME
 *
 * Target flags for FBOs.
 *
 * Since: 0.8
 */
typedef enum
{
  COGL_WINDOW_BUFFER      = (1 << 1),
  COGL_OFFSCREEN_BUFFER   = (1 << 2)
} CoglBufferTarget;

/**
 * CoglColor:
 *
 * A structure for holding a color definition. The contents of
 * the CoglColor structure are private and should never by accessed
 * directly.
 *
 * Since: 1.0
 */
struct _CoglColor
{
  /*< private >*/
  guint8 COGL_PRIVATE (red);
  guint8 COGL_PRIVATE (green);
  guint8 COGL_PRIVATE (blue);

  guint8 COGL_PRIVATE (alpha);

  /* padding in case we want to change to floats at
   * some point */
  guint32 COGL_PRIVATE (padding0);
  guint32 COGL_PRIVATE (padding1);
  guint32 COGL_PRIVATE (padding2);
};

/**
 * CoglTextureVertex:
 * @x: Model x-coordinate
 * @y: Model y-coordinate
 * @z: Model z-coordinate
 * @tx: Texture x-coordinate
 * @ty: Texture y-coordinate
 * @color: The color to use at this vertex. This is ignored if
 *   use_color is %FALSE when calling cogl_polygon()
 *
 * Used to specify vertex information when calling cogl_polygon()
 */
struct _CoglTextureVertex
{
  float x, y, z;
  float tx, ty;

  CoglColor color;
};

/**
 * CoglTextureFlags:
 * @COGL_TEXTURE_NONE: No flags specified
 * @COGL_TEXTURE_NO_AUTO_MIPMAP: Disables the automatic generation of
 *   the mipmap pyramid from the base level image whenever it is
 *   updated. The mipmaps are only generated when the texture is
 *   rendered with a mipmap filter so it should be free to leave out
 *   this flag when using other filtering modes
 * @COGL_TEXTURE_NO_SLICING: Disables the slicing of the texture
 * @COGL_TEXTURE_NO_ATLAS: Disables the insertion of the texture inside
 *   the texture atlas used by Cogl
 *
 * Flags to pass to the cogl_texture_new_* family of functions.
 *
 * Since: 1.0
 */
typedef enum {
  COGL_TEXTURE_NONE           = 0,
  COGL_TEXTURE_NO_AUTO_MIPMAP = 1 << 0,
  COGL_TEXTURE_NO_SLICING     = 1 << 1,
  COGL_TEXTURE_NO_ATLAS       = 1 << 2
} CoglTextureFlags;

/**
 * CoglFogMode:
 * @COGL_FOG_MODE_LINEAR: Calculates the fog blend factor as:
 * |[
 *   f = end - eye_distance / end - start
 * ]|
 * @COGL_FOG_MODE_EXPONENTIAL: Calculates the fog blend factor as:
 * |[
 *   f = e ^ -(density * eye_distance)
 * ]|
 * @COGL_FOG_MODE_EXPONENTIAL_SQUARED: Calculates the fog blend factor as:
 * |[
 *   f = e ^ -(density * eye_distance)^2
 * ]|
 *
 * The fog mode determines the equation used to calculate the fogging blend
 * factor while fogging is enabled. The simplest %COGL_FOG_MODE_LINEAR mode
 * determines f as:
 *
 * |[
 *   f = end - eye_distance / end - start
 * ]|
 *
 * Where eye_distance is the distance of the current fragment in eye
 * coordinates from the origin.
 *
 * Since: 1.0
 */
typedef enum {
  COGL_FOG_MODE_LINEAR,
  COGL_FOG_MODE_EXPONENTIAL,
  COGL_FOG_MODE_EXPONENTIAL_SQUARED
} CoglFogMode;

/**
 * COGL_BLEND_STRING_ERROR:
 *
 * #GError domain for blend string parser errors
 *
 * Since: 1.0
 */
#define COGL_BLEND_STRING_ERROR (cogl_blend_string_error_quark ())

/**
 * CoglBlendStringError:
 * @COGL_BLEND_STRING_ERROR_PARSE_ERROR: Generic parse error
 * @COGL_BLEND_STRING_ERROR_ARGUMENT_PARSE_ERROR: Argument parse error
 * @COGL_BLEND_STRING_ERROR_INVALID_ERROR: Internal parser error
 * @COGL_BLEND_STRING_ERROR_GPU_UNSUPPORTED_ERROR: Blend string not
 *   supported by the GPU
 *
 * Error enumeration for the blend strings parser
 *
 * Since: 1.0
 */
typedef enum { /*< prefix=COGL_BLEND_STRING_ERROR >*/
  COGL_BLEND_STRING_ERROR_PARSE_ERROR,
  COGL_BLEND_STRING_ERROR_ARGUMENT_PARSE_ERROR,
  COGL_BLEND_STRING_ERROR_INVALID_ERROR,
  COGL_BLEND_STRING_ERROR_GPU_UNSUPPORTED_ERROR
} CoglBlendStringError;

GQuark
cogl_blend_string_error_quark (void);

#define COGL_ERROR (_cogl_error_quark ())

/**
 * CoglError:
 * @COGL_ERROR_UNSUPPORTED: You tried to use a feature or
 *    configuration not currently available.
 *
 * Error enumeration for Cogl
 *
 * The @COGL_ERROR_UNSUPPORTED error can be thrown for a variety of
 * reasons. For example:
 *
 * <itemizedlist>
 *  <listitem><para>You've tried to use a feature that is not
 *   advertised by cogl_get_features(). This could happen if you create
 *   a non-sliced texture with a non-power-of-two size when
 *   %COGL_FEATURE_TEXTURE_NPOT is not advertised.</para></listitem>
 *  <listitem><para>The GPU can not handle the configuration you have
 *   requested. An example might be if you try to use too many texture
 *   layers in a single #CoglMaterial</para></listitem>
 *  <listitem><para>The driver does not support some
 *   configuration.</para></listiem>
 * </itemizedlist>
 *
 * Currently this is only used by Cogl API marked as experimental so
 * this enum should also be considered experimental.
 *
 * Since: 1.4
 */
typedef enum { /*< prefix=COGL_ERROR >*/
  COGL_ERROR_UNSUPPORTED
} CoglError;

GQuark
_cogl_error_quark (void);

G_END_DECLS

#endif /* __COGL_TYPES_H__ */
