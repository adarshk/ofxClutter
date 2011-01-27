/*
 * Cogl
 *
 * An object oriented GL/GLES Abstraction/Utility Layer
 *
 * Copyright (C) 2007,2008,2009 Intel Corporation.
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

#ifndef __COGL_OFFSCREEN_H__
#define __COGL_OFFSCREEN_H__

#include <cogl/cogl-types.h>

G_BEGIN_DECLS

/**
 * SECTION:cogl-offscreen
 * @short_description: Fuctions for creating and manipulating offscreen
 *                     framebuffers.
 *
 * Cogl allows creating and operating on offscreen framebuffers.
 */

/* Offscreen api */

/**
 * cogl_offscreen_new_to_texture:
 * @handle: A CoglHandle for a Cogl texture
 *
 * This creates an offscreen buffer object using the given texture as the
 * primary color buffer. It doesn't just initialize the contents of the
 * offscreen buffer with the texture; they are tightly bound so that
 * drawing to the offscreen buffer effectivly updates the contents of the
 * given texture. You don't need to destroy the offscreen buffer before
 * you can use the texture again.
 *
 * Note: This does not work with sliced Cogl textures.
 *
 * Return value: (transfer full): a #CoglHandle for the new offscreen
 *   buffer or %COGL_INVALID_HANDLE if it wasn't possible to create the
 *   buffer.
 */
CoglHandle      cogl_offscreen_new_to_texture (CoglHandle         handle);

/**
 * cogl_is_offscreen:
 * @handle: A CoglHandle for an offscreen buffer
 *
 * Determines whether the given #CoglHandle references an offscreen buffer
 * object.
 *
 * Returns: %TRUE if the handle references an offscreen buffer,
 *   %FALSE otherwise
 */
gboolean        cogl_is_offscreen             (CoglHandle          handle);

#ifndef COGL_DISABLE_DEPRECATED

/**
 * cogl_offscreen_ref:
 * @handle: A CoglHandle for an offscreen buffer
 *
 * Increments the reference count on the offscreen buffer.
 *
 * Return value: (transfer none): For convenience it returns the given CoglHandle
 *
 * Deprecated: 1.2: cogl_handle_ref() should be used in new code.
 */
CoglHandle      cogl_offscreen_ref            (CoglHandle          handle) G_GNUC_DEPRECATED;

/**
 * cogl_offscreen_unref:
 * @handle: A CoglHandle for an offscreen buffer
 *
 * Decreases the reference count for the offscreen buffer and frees it when
 * the count reaches 0.
 *
 * Deprecated: 1.2: cogl_handle_unref() should be used in new code.
 */
void            cogl_offscreen_unref          (CoglHandle          handle) G_GNUC_DEPRECATED;

#endif /* COGL_DISABLE_DEPRECATED */

G_END_DECLS

#endif /* __COGL_OFFSCREEN_H__ */
