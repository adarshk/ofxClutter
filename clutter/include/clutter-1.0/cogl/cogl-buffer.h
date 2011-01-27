/*
 * Cogl
 *
 * An object oriented GL/GLES Abstraction/Utility Layer
 *
 * Copyright (C)2010 Intel Corporation.
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
 *
 * Authors:
 *   Damien Lespiau <damien.lespiau@intel.com>
 *   Robert Bragg <robert@linux.intel.com>
 */

#if !defined(__COGL_H_INSIDE__) && !defined(CLUTTER_COMPILATION)
#error "Only <cogl/cogl.h> can be included directly."
#endif

#ifndef __COGL_BUFFER_H__
#define __COGL_BUFFER_H__

#include <glib.h>
#include <cogl/cogl-types.h>

G_BEGIN_DECLS

/**
 * SECTION:cogl-buffer
 * @short_description: Buffer creation and manipulation
 * @stability: Unstable
 *
 * COGL allows the creation and the manipulation of buffers. If the underlying
 * OpenGL implementation allows it, COGL will use Pixel Buffer Objects.
 */

/* All of the cogl-buffer API is currently experimental so we suffix
 * the actual symbols with _EXP so if somone is monitoring for ABI
 * changes it will hopefully be clearer to them what's going on if any
 * of the symbols dissapear at a later date.
 */
#define cogl_is_buffer  cogl_is_buffer_EXP
#define cogl_buffer_get_size cogl_buffer_get_size_EXP
#define cogl_buffer_set_usage_hint cogl_buffer_set_usage_hint_EXP
#define cogl_buffer_get_usage_hint cogl_buffer_get_usage_hint_EXP
#define cogl_buffer_set_update_hint cogl_buffer_set_update_hint_EXP
#define cogl_buffer_get_update_hint cogl_buffer_get_update_hint_EXP
#define cogl_buffer_map cogl_buffer_map_EXP
#define cogl_buffer_unmap cogl_buffer_unmap_EXP
#define cogl_buffer_set_data cogl_buffer_set_data_EXP

typedef struct _CoglBuffer CoglBuffer;

/**
 * cogl_is_buffer:
 * @buffer: a buffer object
 *
 * Checks whether @buffer is a buffer object.
 *
 * Return value: %TRUE if the handle is a CoglBuffer, and %FALSE otherwise
 *
 * Since: 1.2
 * Stability: Unstable
 */
gboolean
cogl_is_buffer (const void *object);

/**
 * cogl_buffer_get_size:
 * @buffer: a buffer object
 *
 * Retrieves the size of buffer
 *
 * Return value: the size of the buffer in bytes
 *
 * Since: 1.2
 * Stability: Unstable
 */
unsigned int
cogl_buffer_get_size (CoglBuffer *buffer);

/**
 * CoglBufferUpdateHint:
 * @COGL_BUFFER_UPDATE_HINT_STATIC: the buffer will not change over time
 * @COGL_BUFFER_UPDATE_HINT_DYNAMIC: the buffer will change from time to time
 * @COGL_BUFFER_UPDATE_HINT_STREAM: the buffer will be used once or a couple of
 *   times
 *
 * The update hint on a buffer allows the user to give some detail on how often
 * the buffer data is going to be updated.
 *
 * Since: 1.2
 * Stability: Unstable
 */
typedef enum { /*< prefix=COGL_BUFFER_UPDATE_HINT >*/
  COGL_BUFFER_UPDATE_HINT_STATIC,
  COGL_BUFFER_UPDATE_HINT_DYNAMIC,
  COGL_BUFFER_UPDATE_HINT_STREAM
} CoglBufferUpdateHint;

/**
 * cogl_buffer_set_update_hint:
 * @buffer: a buffer object
 * @hint: the new hint
 *
 * Sets the update hint on a buffer. See #CoglBufferUpdateHint for a description
 * of the available hints.
 *
 * Since: 1.2
 * Stability: Unstable
 */
void
cogl_buffer_set_update_hint (CoglBuffer          *buffer,
                             CoglBufferUpdateHint hint);

/**
 * cogl_buffer_get_update_hint:
 * @buffer: a buffer object
 *
 * Retrieves the update hints set using cogl_buffer_set_update_hint()
 *
 * Return value: the #CoglBufferUpdateHint currently used by the buffer
 *
 * Since: 1.2
 * Stability: Unstable
 */
CoglBufferUpdateHint
cogl_buffer_get_update_hint (CoglBuffer *buffer);

/**
 * CoglBufferAccess:
 * @COGL_BUFFER_ACCESS_READ: the buffer will be read
 * @COGL_BUFFER_ACCESS_WRITE: the buffer will written to
 * @COGL_BUFFER_ACCESS_READ_WRITE: the buffer will be used for both reading and
 *   writing
 *
 * The access hints for cogl_buffer_set_update_hint()
 *
 * Since: 1.2
 * Stability: Unstable
 */
typedef enum { /*< prefix=COGL_BUFFER_ACCESS >*/
 COGL_BUFFER_ACCESS_READ       = 1 << 0,
 COGL_BUFFER_ACCESS_WRITE      = 1 << 1,
 COGL_BUFFER_ACCESS_READ_WRITE = COGL_BUFFER_ACCESS_READ | COGL_BUFFER_ACCESS_WRITE
} CoglBufferAccess;


/**
 * CoglBufferMapHint:
 * COGL_BUFFER_MAP_HINT_DISCARD: Tells Cogl that you plan to replace
 *                               all the buffer's contents.
 *
 * Hints to Cogl about how you are planning to modify the data once it
 * is mapped.
 *
 * Since: 1.4
 * Stability: Unstable
 */
typedef enum { /*< prefix=COGL_BUFFER_MAP_HINT >*/
    COGL_BUFFER_MAP_HINT_DISCARD = 1 << 0
} CoglBufferMapHint;

/**
 * cogl_buffer_map:
 * @buffer: a buffer object
 * @access: how the mapped buffer will be used by the application
 * @hints: A mask of #CoglBufferMapHint<!-- -->s that tell Cogl how
 *        the data will be modified once mapped.
 *
 * Maps the buffer into the application address space for direct access.
 *
 * It is strongly recommended that you pass
 * %COGL_BUFFER_MAP_HINT_DISCARD as a hint if you are going to replace
 * all the buffer's data. This way if the buffer is currently being
 * used by the GPU then the driver won't have to stall the CPU and
 * wait for the hardware to finish because it can instead allocate a
 * new buffer to map.
 *
 * The behaviour is undefined if you access the buffer in a way
 * conflicting with the @access mask you pass. It is also an error to
 * release your last reference while the buffer is mapped.
 *
 * Return value: A pointer to the mapped memory or %NULL is the call fails
 *
 * Since: 1.2
 * Stability: Unstable
 */
guint8 *
cogl_buffer_map (CoglBuffer        *buffer,
                 CoglBufferAccess   access,
                 CoglBufferMapHint  hints);

/**
 * cogl_buffer_unmap:
 * @buffer: a buffer object
 *
 * Unmaps a buffer previously mapped by cogl_buffer_map().
 *
 * Since: 1.2
 * Stability: Unstable
 */
void
cogl_buffer_unmap (CoglBuffer *buffer);

/**
 * cogl_buffer_set_data:
 * @buffer: a buffer object
 * @offset: destination offset (in bytes) in the buffer
 * @data: a pointer to the data to be copied into the buffer
 * @size: number of bytes to copy
 *
 * Updates part of the buffer with new data from @data. Where to put this new
 * data is controlled by @offset and @offset + @data should be less than the
 * buffer size.
 *
 * Return value: %TRUE is the operation succeeded, %FALSE otherwise
 *
 * Since: 1.2
 * Stability: Unstable
 */
gboolean
cogl_buffer_set_data (CoglBuffer  *buffer,
                      gsize        offset,
                      const guint8 *data,
                      gsize        size);

G_END_DECLS

#endif /* __COGL_BUFFER_H__ */
