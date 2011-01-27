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

#ifndef __COGL_H__
#define __COGL_H__

#include <glib.h>

#define __COGL_H_INSIDE__

#include <cogl/cogl-defines.h>

#include <cogl/cogl-object.h>
#include <cogl/cogl-bitmap.h>
#include <cogl/cogl-color.h>
#include <cogl/cogl-fixed.h>
#include <cogl/cogl-material.h>
#include <cogl/cogl-matrix.h>
#include <cogl/cogl-offscreen.h>
#include <cogl/cogl-primitives.h>
#include <cogl/cogl-path.h>
#include <cogl/cogl-shader.h>
#include <cogl/cogl-texture.h>
#include <cogl/cogl-types.h>
#include <cogl/cogl-vertex-buffer.h>

#include <cogl/cogl-enum-types.h>

#include <cogl/cogl-deprecated.h>

#if defined (COGL_ENABLE_EXPERIMENTAL_API)
#include <cogl/cogl-buffer.h>
#include <cogl/cogl-pixel-array.h>
#include <cogl/cogl-vector.h>
#include <cogl/cogl-texture-3d.h>
#endif

G_BEGIN_DECLS

/**
 * SECTION:cogl
 * @short_description: General purpose API
 *
 * General utility functions for COGL.
 */

typedef struct _CoglFramebuffer CoglFramebuffer;

/**
 * cogl_get_option_group:
 *
 * Retrieves the #GOptionGroup used by COGL to parse the command
 * line options. Clutter uses this to handle the COGL command line
 * options during its initialization process.
 *
 * Return value: a #GOptionGroup
 *
 * Since: 1.0
 */
GOptionGroup *
cogl_get_option_group (void);

/* Misc */
/**
 * cogl_get_features:
 *
 * Returns all of the features supported by COGL.
 *
 * Return value: A logical OR of all the supported COGL features.
 *
 * Since: 0.8
 */
CoglFeatureFlags
cogl_get_features (void);

/**
 * cogl_features_available:
 * @features: A bitmask of features to check for
 *
 * Checks whether the given COGL features are available. Multiple
 * features can be checked for by or-ing them together with the '|'
 * operator. %TRUE is only returned if all of the requested features
 * are available.
 *
 * Return value: %TRUE if the features are available, %FALSE otherwise.
 */
gboolean
cogl_features_available (CoglFeatureFlags features);

/**
 * cogl_get_proc_address:
 * @name: the name of the function.
 *
 * Gets a pointer to a given GL or GL ES extension function. This acts
 * as a wrapper around glXGetProcAddress() or whatever is the
 * appropriate function for the current backend.
 *
 * Return value: a pointer to the requested function or %NULL if the
 *   function is not available.
 */
CoglFuncPtr
cogl_get_proc_address (const char *name);

#ifndef COGL_DISABLE_DEPRECATED

/**
 * cogl_check_extension:
 * @name: extension to check for
 * @ext: list of extensions
 *
 * Check whether @name occurs in list of extensions in @ext.
 *
 * Return value: %TRUE if the extension occurs in the list, %FALSE otherwise.
 *
 * Deprecated: 1.2: OpenGL is an implementation detail for Cogl and so it's
 *   not appropriate to expose OpenGL extensions through the Cogl API. This
 *   function can be replaced by the following equivalent code:
 * |[
 *   gboolean retval = (strstr (ext, name) != NULL) ? TRUE : FALSE;
 * ]|
 */
gboolean
cogl_check_extension (const char *name,
                      const char *ext) G_GNUC_DEPRECATED;

#endif /* COGL_DISABLE_DEPRECATED */

/**
 * cogl_get_bitmasks:
 * @red: (out): Return location for the number of red bits or %NULL
 * @green: (out): Return location for the number of green bits or %NULL
 * @blue: (out): Return location for the number of blue bits or %NULL
 * @alpha: (out): Return location for the number of alpha bits or %NULL
 *
 * Gets the number of bitplanes used for each of the color components
 * in the color buffer. Pass %NULL for any of the arguments if the
 * value is not required.
 */
void
cogl_get_bitmasks (int *red,
                   int *green,
                   int *blue,
                   int *alpha);

/*
 * _cogl_framebuffer_get_red_bits:
 * @framebuffer: a handle for a framebuffer
 *
 * Retrieves the number of red bits of @framebuffer
 *
 * Return value: the number of bits
 *
 * Since: 1.4
 */
int
_cogl_framebuffer_get_red_bits (CoglFramebuffer *framebuffer);

/*
 * _cogl_framebuffer_get_green_bits:
 * @framebuffer: a handle for a framebuffer
 *
 * Retrieves the number of green bits of @framebuffer
 *
 * Return value: the number of bits
 *
 * Since: 1.4
 */
int
_cogl_framebuffer_get_green_bits (CoglFramebuffer *framebuffer);

/*
 * _cogl_framebuffer_get_blue_bits:
 * @framebuffer: a handle for a framebuffer
 *
 * Retrieves the number of blue bits of @framebuffer
 *
 * Return value: the number of bits
 *
 * Since: 1.4
 */
int
_cogl_framebuffer_get_blue_bits (CoglFramebuffer *framebuffer);

/*
 * _cogl_framebuffer_get_alpha_bits:
 * @framebuffer: a handle for a framebuffer
 *
 * Retrieves the number of alpha bits of @framebuffer
 *
 * Return value: the number of bits
 *
 * Since: 1.4
 */
int
_cogl_framebuffer_get_alpha_bits (CoglFramebuffer *framebuffer);

/**
 * cogl_perspective:
 * @fovy: Vertical of view angle in degrees.
 * @aspect: Aspect ratio of diesplay
 * @z_near: Nearest visible point
 * @z_far: Furthest visible point along the z-axis
 *
 * Replaces the current projection matrix with a perspective matrix
 * based on the provided values.
 */
void
cogl_perspective (float fovy,
                  float aspect,
                  float z_near,
                  float z_far);

/**
 * cogl_frustum:
 * @left: Left clipping plane
 * @right: Right clipping plane
 * @bottom: Bottom clipping plane
 * @top: Top clipping plane
 * @z_near: Nearest visible point
 * @z_far: Furthest visible point along the z-axis
 *
 * Replaces the current projection matrix with a perspective matrix
 * for the given viewing frustum.
 *
 * Since: 0.8.2
 */
void
cogl_frustum (float left,
              float right,
              float bottom,
              float top,
              float z_near,
              float z_far);

/**
 * cogl_ortho:
 * @left: The coordinate for the left clipping plane
 * @right: The coordinate for the right clipping plane
 * @bottom: The coordinate for the bottom clipping plane
 * @top: The coordinate for the top clipping plane
 * @near: The <emphasis>distance</emphasis> to the near clipping
 *   plane (negative if the plane is behind the viewer)
 * @far: The <emphasis>distance</emphasis> for the far clipping
 *   plane (negative if the plane is behind the viewer)
 *
 * Replaces the current projection matrix with an orthographic projection
 * matrix. See <xref linkend="cogl-ortho-matrix"/> to see how the matrix is
 * calculated.
 *
 * <figure id="cogl-ortho-matrix">
 *   <title></title>
 *   <graphic fileref="cogl_ortho.png" format="PNG"/>
 * </figure>
 *
 * <note>This function copies the arguments from OpenGL's glOrtho() even
 * though they are unnecessarily confusing due to the z near and z far
 * arguments actually being a "distance" from the origin, where
 * negative values are behind the viewer, instead of coordinates for
 * the z clipping planes which would have been consistent with the
 * left, right bottom and top arguments.</note>
 *
 * Since: 1.0
 */
void
cogl_ortho (float left,
            float right,
            float bottom,
            float top,
            float near,
            float far);

/*
 * _cogl_setup_viewport:
 * @width: Width of the viewport
 * @height: Height of the viewport
 * @fovy: Field of view angle in degrees
 * @aspect: Aspect ratio to determine the field of view along the x-axis
 * @z_near: Nearest visible point along the z-axis
 * @z_far: Furthest visible point along the z-axis
 *
 * Replaces the current viewport and projection matrix with the given
 * values. The viewport is placed at the top left corner of the window
 * with the given width and height. The projection matrix is replaced
 * with one that has a viewing angle of @fovy along the y-axis and a
 * view scaled according to @aspect along the x-axis. The view is
 * clipped according to @z_near and @z_far on the z-axis.
 *
 * This function is used only by Clutter.
 */
void
_cogl_setup_viewport (unsigned int width,
                      unsigned int height,
                      float fovy,
                      float aspect,
                      float z_near,
                      float z_far);

#ifndef COGL_DISABLE_DEPRECATED

/**
 * cogl_viewport:
 * @width: Width of the viewport
 * @height: Height of the viewport
 *
 * Replace the current viewport with the given values.
 *
 * Since: 0.8.2
 *
 * Deprecated: 1.2: Use cogl_set_viewport() instead
 */
void
cogl_viewport (unsigned int width,
	       unsigned int height) G_GNUC_DEPRECATED;

#endif /* COGL_DISABLE_DEPRECATED */

/**
 * cogl_set_viewport:
 * @x: X offset of the viewport
 * @y: Y offset of the viewport
 * @width: Width of the viewport
 * @height: Height of the viewport
 *
 * Replaces the current viewport with the given values.
 *
 * Since: 1.2
 */
void
cogl_set_viewport (int x,
                   int y,
                   int width,
                   int height);

/**
 * cogl_push_matrix:
 *
 * Stores the current model-view matrix on the matrix stack. The matrix
 * can later be restored with cogl_pop_matrix().
 */
void
cogl_push_matrix (void);

/**
 * cogl_pop_matrix:
 *
 * Restores the current model-view matrix from the matrix stack.
 */
void
cogl_pop_matrix (void);

/**
 * cogl_scale:
 * @x: Amount to scale along the x-axis
 * @y: Amount to scale along the y-axis
 * @z: Amount to scale along the z-axis
 *
 * Multiplies the current model-view matrix by one that scales the x,
 * y and z axes by the given values.
 */
void
cogl_scale (float x,
            float y,
            float z);

/**
 * cogl_translate:
 * @x: Distance to translate along the x-axis
 * @y: Distance to translate along the y-axis
 * @z: Distance to translate along the z-axis
 *
 * Multiplies the current model-view matrix by one that translates the
 * model along all three axes according to the given values.
 */
void
cogl_translate (float x,
                float y,
                float z);

/**
 * cogl_rotate:
 * @angle: Angle in degrees to rotate.
 * @x: X-component of vertex to rotate around.
 * @y: Y-component of vertex to rotate around.
 * @z: Z-component of vertex to rotate around.
 *
 * Multiplies the current model-view matrix by one that rotates the
 * model around the vertex specified by @x, @y and @z. The rotation
 * follows the right-hand thumb rule so for example rotating by 10
 * degrees about the vertex (0, 0, 1) causes a small counter-clockwise
 * rotation.
 */
void
cogl_rotate (float angle,
             float x,
             float y,
             float z);

/**
 * cogl_transform:
 * @matrix: the matrix to multiply with the current model-view
 *
 * Multiplies the current model-view matrix by the given matrix.
 *
 * Since: 1.4
 */
void
cogl_transform (const CoglMatrix *matrix);

/**
 * cogl_get_modelview_matrix:
 * @matrix: (out): return location for the model-view matrix
 *
 * Stores the current model-view matrix in @matrix.
 */
void
cogl_get_modelview_matrix (CoglMatrix *matrix);

/**
 * cogl_set_modelview_matrix:
 * @matrix: the new model-view matrix
 *
 * Loads @matrix as the new model-view matrix.
 */
void
cogl_set_modelview_matrix (CoglMatrix *matrix);

/**
 * cogl_get_projection_matrix:
 * @matrix: (out): return location for the projection matrix
 *
 * Stores the current projection matrix in @matrix.
 */
void
cogl_get_projection_matrix (CoglMatrix *matrix);

/**
 * cogl_set_projection_matrix:
 * @matrix: the new projection matrix
 *
 * Loads matrix as the new projection matrix.
 */
void
cogl_set_projection_matrix (CoglMatrix *matrix);

/**
 * cogl_get_viewport:
 * @v: (out) (array fixed-size=4): pointer to a 4 element array
 *   of #float<!-- -->s to receive the viewport dimensions.
 *
 * Stores the current viewport in @v. @v[0] and @v[1] get the x and y
 * position of the viewport and @v[2] and @v[3] get the width and
 * height.
 */
void
cogl_get_viewport (float v[4]);

/**
 * cogl_set_depth_test_enabled:
 * @setting: %TRUE to enable depth testing or %FALSE to disable.
 *
 * Sets whether depth testing is enabled. If it is disabled then the
 * order that actors are layered on the screen depends solely on the
 * order specified using clutter_actor_raise() and
 * clutter_actor_lower(), otherwise it will also take into account the
 * actor's depth. Depth testing is disabled by default.
 *
 * Deprecated: 1.4: Use cogl_material_set_depth_test_enabled()
 * instead.
 */
void
cogl_set_depth_test_enabled (gboolean setting);

/**
 * cogl_get_depth_test_enabled:
 *
 * Queries if depth testing has been enabled via cogl_set_depth_test_enable()
 *
 * Return value: %TRUE if depth testing is enabled, and %FALSE otherwise
 *
 * Deprecated: 1.4: Use cogl_material_get_depth_test_enabled()
 * instead.
 */
gboolean
cogl_get_depth_test_enabled (void);

/**
 * cogl_set_backface_culling_enabled:
 * @setting: %TRUE to enable backface culling or %FALSE to disable.
 *
 * Sets whether textures positioned so that their backface is showing
 * should be hidden. This can be used to efficiently draw two-sided
 * textures or fully closed cubes without enabling depth testing. This
 * only affects calls to the cogl_rectangle* family of functions and
 * cogl_vertex_buffer_draw*. Backface culling is disabled by default.
 */
void
cogl_set_backface_culling_enabled (gboolean setting);

/**
 * cogl_get_backface_culling_enabled:
 *
 * Queries if backface culling has been enabled via
 * cogl_set_backface_culling_enabled()
 *
 * Return value: %TRUE if backface culling is enabled, and %FALSE otherwise
 */
gboolean
cogl_get_backface_culling_enabled (void);

/**
 * cogl_set_fog:
 * @fog_color: The color of the fog
 * @mode: A #CoglFogMode that determines the equation used to calculate the
 *   fogging blend factor.
 * @density: Used by %COGL_FOG_MODE_EXPONENTIAL and by
 *   %COGL_FOG_MODE_EXPONENTIAL_SQUARED equations.
 * @z_near: Position along Z axis where no fogging should be applied
 * @z_far: Position along Z axis where full fogging should be applied
 *
 * Enables fogging. Fogging causes vertices that are further away from the eye
 * to be rendered with a different color. The color is determined according to
 * the chosen fog mode; at it's simplest the color is linearly interpolated so
 * that vertices at @z_near are drawn fully with their original color and
 * vertices at @z_far are drawn fully with @fog_color. Fogging will remain
 * enabled until you call cogl_disable_fog().
 *
 * <note>The fogging functions only work correctly when primitives use
 * unmultiplied alpha colors. By default Cogl will premultiply textures
 * and cogl_set_source_color() will premultiply colors, so unless you
 * explicitly load your textures requesting an unmultiplied internal format
 * and use cogl_material_set_color() you can only use fogging with fully
 * opaque primitives. This might improve in the future when we can depend
 * on fragment shaders.</note>
 */
void
cogl_set_fog (const CoglColor *fog_color,
              CoglFogMode mode,
              float density,
              float z_near,
              float z_far);

/**
 * cogl_disable_fog:
 *
 * This function disables fogging, so primitives drawn afterwards will not be
 * blended with any previously set fog color.
 */
void
cogl_disable_fog (void);

/**
 * CoglBufferBit:
 * @COGL_BUFFER_BIT_COLOR: Selects the primary color buffer
 * @COGL_BUFFER_BIT_DEPTH: Selects the depth buffer
 * @COGL_BUFFER_BIT_STENCIL: Selects the stencil buffer
 *
 * Types of auxiliary buffers
 *
 * Since: 1.0
 */
typedef enum {
  COGL_BUFFER_BIT_COLOR   = 1L<<0,
  COGL_BUFFER_BIT_DEPTH   = 1L<<1,
  COGL_BUFFER_BIT_STENCIL = 1L<<2
} CoglBufferBit;

/**
 * cogl_clear:
 * @color: Background color to clear to
 * @buffers: A mask of #CoglBufferBit<!-- -->'s identifying which auxiliary
 *   buffers to clear
 *
 * Clears all the auxiliary buffers identified in the @buffers mask, and if
 * that includes the color buffer then the specified @color is used.
 */
void
cogl_clear (const CoglColor *color,
            unsigned long buffers);

/**
 * cogl_set_source:
 * @material: A #CoglHandle for a material
 *
 * This function sets the source material that will be used to fill subsequent
 * geometry emitted via the cogl API.
 *
 * <note>In the future we may add the ability to set a front facing material,
 * and a back facing material, in which case this function will set both to the
 * same.</note>
 *
 * Since: 1.0
 */
void
cogl_set_source (CoglHandle material);

/**
 * cogl_set_source_color:
 * @color: a #CoglColor
 *
 * This is a convenience function for creating a solid fill source material
 * from the given color. This color will be used for any subsequent drawing
 * operation.
 *
 * The color will be premultiplied by Cogl, so the color should be
 * non-premultiplied. For example: use (1.0, 0.0, 0.0, 0.5) for
 * semi-transparent red.
 *
 * See also cogl_set_source_color4ub() and cogl_set_source_color4f()
 * if you already have the color components.
 *
 * Since: 1.0
 */
void
cogl_set_source_color (const CoglColor *color);

/**
 * cogl_set_source_color4ub:
 * @red: value of the red channel, between 0 and 255
 * @green: value of the green channel, between 0 and 255
 * @blue: value of the blue channel, between 0 and 255
 * @alpha: value of the alpha channel, between 0 and 255
 *
 * This is a convenience function for creating a solid fill source material
 * from the given color using unsigned bytes for each component. This
 * color will be used for any subsequent drawing operation.
 *
 * The value for each component is an unsigned byte in the range
 * between 0 and 255.
 *
 * Since: 1.0
 */
void
cogl_set_source_color4ub (guint8 red,
                          guint8 green,
                          guint8 blue,
                          guint8 alpha);

/**
 * cogl_set_source_color4f:
 * @red: value of the red channel, between 0 and %1.0
 * @green: value of the green channel, between 0 and %1.0
 * @blue: value of the blue channel, between 0 and %1.0
 * @alpha: value of the alpha channel, between 0 and %1.0
 *
 * This is a convenience function for creating a solid fill source material
 * from the given color using normalized values for each component. This color
 * will be used for any subsequent drawing operation.
 *
 * The value for each component is a fixed point number in the range
 * between 0 and %1.0. If the values passed in are outside that
 * range, they will be clamped.
 *
 * Since: 1.0
 */
void
cogl_set_source_color4f (float red,
                         float green,
                         float blue,
                         float alpha);

/**
 * cogl_set_source_texture:
 * @texture_handle: The Cogl texture you want as your source
 *
 * This is a convenience function for creating a material with the first
 * layer set to #texture_handle and setting that material as the source with
 * cogl_set_source.
 *
 * Note: There is no interaction between calls to cogl_set_source_color
 * and cogl_set_source_texture. If you need to blend a texture with a color then
 * you can create a simple material like this:
 * <programlisting>
 * material = cogl_material_new ();
 * cogl_material_set_color4ub (material, 0xff, 0x00, 0x00, 0x80);
 * cogl_material_set_layer (material, 0, tex_handle);
 * cogl_set_source (material);
 * </programlisting>
 *
 * Since: 1.0
 */
void
cogl_set_source_texture (CoglHandle texture_handle);

/**
 * SECTION:cogl-clipping
 * @short_description: Fuctions for manipulating a stack of clipping regions
 *
 * To support clipping your geometry to rectangles or paths Cogl exposes a
 * stack based API whereby each clip region you push onto the stack is
 * intersected with the previous region.
 */

#ifndef COGL_DISABLE_DEPRECATED

/**
 * cogl_clip_push_window_rect:
 * @x_offset: left edge of the clip rectangle in window coordinates
 * @y_offset: top edge of the clip rectangle in window coordinates
 * @width: width of the clip rectangle
 * @height: height of the clip rectangle
 *
 * Specifies a rectangular clipping area for all subsequent drawing
 * operations. Any drawing commands that extend outside the rectangle
 * will be clipped so that only the portion inside the rectangle will
 * be displayed. The rectangle dimensions are not transformed by the
 * current model-view matrix.
 *
 * The rectangle is intersected with the current clip region. To undo
 * the effect of this function, call cogl_clip_pop().
 *
 * Deprecated: 1.2: Use cogl_clip_push_window_rectangle() instead
 */
void
cogl_clip_push_window_rect (float x_offset,
                            float y_offset,
                            float width,
                            float height) G_GNUC_DEPRECATED;

#endif /* COGL_DISABLE_DEPRECATED */

/**
 * cogl_clip_push_window_rectangle:
 * @x_offset: left edge of the clip rectangle in window coordinates
 * @y_offset: top edge of the clip rectangle in window coordinates
 * @width: width of the clip rectangle
 * @height: height of the clip rectangle
 *
 * Specifies a rectangular clipping area for all subsequent drawing
 * operations. Any drawing commands that extend outside the rectangle
 * will be clipped so that only the portion inside the rectangle will
 * be displayed. The rectangle dimensions are not transformed by the
 * current model-view matrix.
 *
 * The rectangle is intersected with the current clip region. To undo
 * the effect of this function, call cogl_clip_pop().
 *
 * Since: 1.2
 */
void
cogl_clip_push_window_rectangle (int x_offset,
                                 int y_offset,
                                 int width,
                                 int height);

#ifndef COGL_DISABLE_DEPRECATED

/**
 * cogl_clip_push:
 * @x_offset: left edge of the clip rectangle
 * @y_offset: top edge of the clip rectangle
 * @width: width of the clip rectangle
 * @height: height of the clip rectangle
 *
 * Specifies a rectangular clipping area for all subsequent drawing
 * operations. Any drawing commands that extend outside the rectangle
 * will be clipped so that only the portion inside the rectangle will
 * be displayed. The rectangle dimensions are transformed by the
 * current model-view matrix.
 *
 * The rectangle is intersected with the current clip region. To undo
 * the effect of this function, call cogl_clip_pop().
 *
 * Deprecated: 1.2: The x, y, width, height arguments are inconsistent
 *   with other API that specify rectangles in model space, and when used
 *   with a coordinate space that puts the origin at the center and y+
 *   extending up, it's awkward to use. Please use cogl_clip_push_rectangle()
 *   instead
 */
void
cogl_clip_push (float x_offset,
                float y_offset,
                float width,
                float height) G_GNUC_DEPRECATED;

#endif /* COGL_DISABLE_DEPRECATED */

/**
 * cogl_clip_push_rectangle:
 * @x0: x coordinate for top left corner of the clip rectangle
 * @y0: y coordinate for top left corner of the clip rectangle
 * @x1: x coordinate for bottom right corner of the clip rectangle
 * @y1: y coordinate for bottom right corner of the clip rectangle
 *
 * Specifies a rectangular clipping area for all subsequent drawing
 * operations. Any drawing commands that extend outside the rectangle
 * will be clipped so that only the portion inside the rectangle will
 * be displayed. The rectangle dimensions are transformed by the
 * current model-view matrix.
 *
 * The rectangle is intersected with the current clip region. To undo
 * the effect of this function, call cogl_clip_pop().
 *
 * Since: 1.2
 */
void
cogl_clip_push_rectangle (float x0,
                          float y0,
                          float x1,
                          float y1);

/**
 * cogl_clip_push_from_path:
 *
 * Sets a new clipping area using the current path. The current path
 * is then cleared. The clipping area is intersected with the previous
 * clipping area. To restore the previous clipping area, call
 * cogl_clip_pop().
 *
 * Since: 1.0
 */
void
cogl_clip_push_from_path (void);

/**
 * cogl_clip_push_from_path_preserve:
 *
 * Sets a new clipping area using the current path. The current path
 * is then cleared. The clipping area is intersected with the previous
 * clipping area. To restore the previous clipping area, call
 * cogl_clip_pop().
 *
 * Since: 1.0
 */
void
cogl_clip_push_from_path_preserve (void);

/**
 * cogl_clip_pop:
 *
 * Reverts the clipping region to the state before the last call to
 * cogl_clip_push().
 */
void
cogl_clip_pop (void);

#ifndef COGL_DISABLE_DEPRECATED

/**
 * cogl_clip_ensure:
 *
 * Ensures that the current clipping region has been set in GL. This
 * will automatically be called before any Cogl primitives but it
 * maybe be neccessary to call if you are using raw GL calls with
 * clipping.
 *
 * Deprecated: 1.2: Calling this function has no effect
 *
 * Since: 1.0
 */
void
cogl_clip_ensure (void) G_GNUC_DEPRECATED;

/**
 * cogl_clip_stack_save:
 *
 * Save the entire state of the clipping stack and then clear all
 * clipping. The previous state can be returned to with
 * cogl_clip_stack_restore(). Each call to cogl_clip_push() after this
 * must be matched by a call to cogl_clip_pop() before calling
 * cogl_clip_stack_restore().
 *
 * Deprecated: 1.2: This was originally added to allow us to save the
 *   clip stack when switching to an offscreen framebuffer, but it's
 *   not necessary anymore given that framebuffers now own separate
 *   clip stacks which will be automatically switched between when a
 *   new buffer is set. Calling this function has no effect
 *
 * Since: 0.8.2
 */
void
cogl_clip_stack_save (void) G_GNUC_DEPRECATED;

/**
 * cogl_clip_stack_restore:
 *
 * Restore the state of the clipping stack that was previously saved
 * by cogl_clip_stack_save().
 *
 * Deprecated: 1.2: This was originally added to allow us to restore
 *   the clip stack when switching back from an offscreen framebuffer,
 *   but it's not necessary anymore given that framebuffers now own
 *   separate clip stacks which will be automatically switched between
 *   when a new buffer is set. Calling this function has no effect
 *
 * Since: 0.8.2
 */
void
cogl_clip_stack_restore (void) G_GNUC_DEPRECATED;

#endif /* COGL_DISABLE_DEPRECATED */

/**
 * cogl_set_framebuffer:
 * @buffer: A #CoglFramebuffer object, either onscreen or offscreen.
 *
 * This redirects all subsequent drawing to the specified framebuffer. This can
 * either be an offscreen buffer created with cogl_offscreen_new_to_texture ()
 * or in the future it may be an onscreen framebuffers too.
 *
 * Since: 1.2
 */
void
cogl_set_framebuffer (CoglFramebuffer *buffer);

/**
 * cogl_push_framebuffer:
 * @buffer: A #CoglFramebuffer object, either onscreen or offscreen.
 *
 * Redirects all subsequent drawing to the specified framebuffer. This can
 * either be an offscreen buffer created with cogl_offscreen_new_to_texture ()
 * or in the future it may be an onscreen framebuffer too.
 *
 * You should understand that a framebuffer owns the following state:
 * <itemizedlist>
 *  <listitem><simpara>The projection matrix</simpara></listitem>
 *  <listitem><simpara>The modelview matrix stack</simpara></listitem>
 *  <listitem><simpara>The viewport</simpara></listitem>
 *  <listitem><simpara>The clip stack</simpara></listitem>
 * </itemizedlist>
 * So these items will automatically be saved and restored when you
 * push and pop between different framebuffers.
 *
 * Also remember a newly allocated framebuffer will have an identity matrix for
 * the projection and modelview matrices which gives you a coordinate space
 * like OpenGL with (-1, -1) corresponding to the top left of the viewport,
 * (1, 1) corresponding to the bottom right and +z coming out towards the
 * viewer.
 *
 * If you want to set up a coordinate space like Clutter does with (0, 0)
 * corresponding to the top left and (framebuffer_width, framebuffer_height)
 * corresponding to the bottom right you can do so like this:
 *
 * |[
 * static void
 * setup_viewport (unsigned int width,
 *                 unsigned int height,
 *                 float fovy,
 *                 float aspect,
 *                 float z_near,
 *                 float z_far)
 * {
 *   float z_camera;
 *   CoglMatrix projection_matrix;
 *   CoglMatrix mv_matrix;
 *
 *   cogl_set_viewport (0, 0, width, height);
 *   cogl_perspective (fovy, aspect, z_near, z_far);
 *
 *   cogl_get_projection_matrix (&amp;projection_matrix);
 *   z_camera = 0.5 * projection_matrix.xx;
 *
 *   cogl_matrix_init_identity (&amp;mv_matrix);
 *   cogl_matrix_translate (&amp;mv_matrix, -0.5f, -0.5f, -z_camera);
 *   cogl_matrix_scale (&amp;mv_matrix, 1.0f / width, -1.0f / height, 1.0f / width);
 *   cogl_matrix_translate (&amp;mv_matrix, 0.0f, -1.0 * height, 0.0f);
 *   cogl_set_modelview_matrix (&amp;mv_matrix);
 * }
 *
 * static void
 * my_init_framebuffer (ClutterStage *stage,
 *                      CoglFramebuffer *framebuffer,
 *                      unsigned int framebuffer_width,
 *                      unsigned int framebuffer_height)
 * {
 *   ClutterPerspective perspective;
 *
 *   clutter_stage_get_perspective (stage, &perspective);
 *
 *   cogl_push_framebuffer (framebuffer);
 *   setup_viewport (framebuffer_width,
 *                   framebuffer_height,
 *                   perspective.fovy,
 *                   perspective.aspect,
 *                   perspective.z_near,
 *                   perspective.z_far);
 * }
 * ]|
 *
 * The previous framebuffer can be restored by calling cogl_pop_framebuffer()
 *
 * Since: 1.2
 */
void
cogl_push_framebuffer (CoglFramebuffer *buffer);

/**
 * cogl_pop_framebuffer:
 *
 * Restores the framebuffer that was previously at the top of the stack.
 * All subsequent drawing will be redirected to this framebuffer.
 *
 * Since: 1.2
 */
void
cogl_pop_framebuffer (void);

#ifndef COGL_DISABLE_DEPRECATED

/**
 * cogl_set_draw_buffer:
 * @target: A #CoglBufferTarget that specifies what kind of framebuffer you
 *          are setting as the render target.
 * @offscreen: If you are setting a framebuffer of type COGL_OFFSCREEN_BUFFER
 *             then this is a CoglHandle for the offscreen buffer.
 *
 * Redirects all subsequent drawing to the specified framebuffer. This
 * can either be an offscreen buffer created with
 * cogl_offscreen_new_to_texture () or you can revert to your original
 * on screen window buffer.
 *
 * Deprecated: 1.2: The target argument was redundant since we could look at
 *    the type of CoglHandle given instead.
 */
void
cogl_set_draw_buffer (CoglBufferTarget target,
                      CoglHandle offscreen) G_GNUC_DEPRECATED;

/**
 * cogl_push_draw_buffer:
 *
 * Save cogl_set_draw_buffer() state.
 *
 * Deprecated: 1.2: The draw buffer API was replaced with a framebuffer API
 */
void
cogl_push_draw_buffer (void) G_GNUC_DEPRECATED;

/**
 * cogl_pop_draw_buffer:
 *
 * Restore cogl_set_draw_buffer() state.
 *
 * Deprecated: 1.2: The draw buffer API was replaced with a framebuffer API
 */
void
cogl_pop_draw_buffer (void) G_GNUC_DEPRECATED;

#endif /* COGL_DISABLE_DEPRECATED */

/**
 * CoglReadPixelsFlags:
 * @COGL_READ_PIXELS_COLOR_BUFFER: Read from the color buffer
 *
 * Flags for cogl_read_pixels()
 *
 * Since: 1.0
 */
typedef enum { /*< prefix=COGL_READ_PIXELS >*/
  COGL_READ_PIXELS_COLOR_BUFFER = 1L << 0
} CoglReadPixelsFlags;

/**
 * cogl_read_pixels:
 * @x: The window x position to start reading from
 * @y: The window y position to start reading from
 * @width: The width of the rectangle you want to read
 * @height: The height of the rectangle you want to read
 * @source: Identifies which auxillary buffer you want to read
 *          (only COGL_READ_PIXELS_COLOR_BUFFER supported currently)
 * @format: The pixel format you want the result in
 *          (only COGL_PIXEL_FORMAT_RGBA_8888 supported currently)
 * @pixels: The location to write the pixel data.
 *
 * This reads a rectangle of pixels from the current framebuffer where
 * position (0, 0) is the top left. The pixel at (x, y) is the first
 * read, and the data is returned with a rowstride of (width * 4).
 *
 * Currently Cogl assumes that the framebuffer is in a premultiplied
 * format so if @format is non-premultiplied it will convert it. To
 * read the pixel values without any conversion you should either
 * specify a format that doesn't use an alpha channel or use one of
 * the formats ending in PRE.
 */
void
cogl_read_pixels (int x,
                  int y,
                  int width,
                  int height,
                  CoglReadPixelsFlags source,
                  CoglPixelFormat format,
                  guint8 *pixels);

/**
 * cogl_flush:
 *
 * This function should only need to be called in exceptional circumstances.
 *
 * As an optimization Cogl drawing functions may batch up primitives
 * internally, so if you are trying to use raw GL outside of Cogl you stand a
 * better chance of being successful if you ask Cogl to flush any batched
 * geometry before making your state changes.
 *
 * It only ensure that the underlying driver is issued all the commands
 * necessary to draw the batched primitives. It provides no guarantees about
 * when the driver will complete the rendering.
 *
 * This provides no guarantees about the GL state upon returning and to avoid
 * confusing Cogl you should aim to restore any changes you make before
 * resuming use of Cogl.
 *
 * If you are making state changes with the intention of affecting Cogl drawing
 * primitives you are 100% on your own since you stand a good chance of
 * conflicting with Cogl internals. For example clutter-gst which currently
 * uses direct GL calls to bind ARBfp programs will very likely break when Cogl
 * starts to use ARBfb programs itself for the material API.
 *
 * Since: 1.0
 */
void
cogl_flush (void);

/**
 * cogl_begin_gl:
 *
 * We do not advise nor reliably support the interleaving of raw GL drawing and
 * Cogl drawing functions, but if you insist, cogl_begin_gl() and cogl_end_gl()
 * provide a simple mechanism that may at least give you a fighting chance of
 * succeeding.
 *
 * Note: this doesn't help you modify the behaviour of Cogl drawing functions
 * through the modification of GL state; that will never be reliably supported,
 * but if you are trying to do something like:
 *
 * |[
 * {
 *    - setup some OpenGL state.
 *    - draw using OpenGL (e.g. glDrawArrays() )
 *    - reset modified OpenGL state.
 *    - continue using Cogl to draw
 * }
 * ]|
 *
 * You should surround blocks of drawing using raw GL with cogl_begin_gl()
 * and cogl_end_gl():
 *
 * |[
 * {
 *    cogl_begin_gl ();
 *    - setup some OpenGL state.
 *    - draw using OpenGL (e.g. glDrawArrays() )
 *    - reset modified OpenGL state.
 *    cogl_end_gl ();
 *    - continue using Cogl to draw
 * }
 * ]|
 *
 * Don't ever try and do:
 *
 * |[
 * {
 *    - setup some OpenGL state.
 *    - use Cogl to draw
 *    - reset modified OpenGL state.
 * }
 * ]|
 *
 * When the internals of Cogl evolves, this is very liable to break.
 *
 * This function will flush all batched primitives, and subsequently flush
 * all internal Cogl state to OpenGL as if it were going to draw something
 * itself.
 *
 * The result is that the OpenGL modelview matrix will be setup; the state
 * corresponding to the current source material will be set up and other world
 * state such as backface culling, depth and fogging enabledness will be sent
 * to OpenGL.
 *
 * <note>No special material state is flushed, so if you want Cogl to setup a
 * simplified material state it is your responsibility to set a simple source
 * material before calling cogl_begin_gl(). E.g. by calling
 * cogl_set_source_color4ub().</note>
 *
 * <note>It is your responsibility to restore any OpenGL state that you modify
 * to how it was after calling cogl_begin_gl() if you don't do this then the
 * result of further Cogl calls is undefined.</note>
 *
 * <note>You can not nest begin/end blocks.</note>
 *
 * Again we would like to stress, we do not advise the use of this API and if
 * possible we would prefer to improve Cogl than have developers require raw
 * OpenGL.
 *
 * Since: 1.0
 */
void
cogl_begin_gl (void);

/**
 * cogl_end_gl:
 *
 * This is the counterpart to cogl_begin_gl() used to delimit blocks of drawing
 * code using raw OpenGL. Please refer to cogl_begin_gl() for full details.
 *
 * Since: 1.0
 */
void
cogl_end_gl (void);

/*
 * Internal API available only to Clutter.
 *
 * These are typically only to deal with the poor seperation of
 * responsabilities that currently exists between Clutter and Cogl.
 * Eventually a lot of the backend code currently in Clutter will
 * move down into Cogl and these functions will be removed.
 */

void
_cogl_destroy_context (void);

/*< private >*/
#define COGL_DRIVER_ERROR (_cogl_driver_error_quark ())

typedef enum { /*< prefix=COGL_DRIVER_ERROR >*/
  COGL_DRIVER_ERROR_UNKNOWN_VERSION,
  COGL_DRIVER_ERROR_INVALID_VERSION
} CoglDriverError;

gboolean
_cogl_check_extension (const char *name, const char *ext);

void
_cogl_set_indirect_context  (gboolean indirect);

void
_cogl_set_viewport (int x, int y, int width, int height);

gboolean
_cogl_check_driver_valid (GError **error);

GQuark
_cogl_driver_error_quark (void);

void
_cogl_onscreen_clutter_backend_set_size (int width, int height);

G_END_DECLS

#undef __COGL_H_INSIDE__

#endif /* __COGL_H__ */
