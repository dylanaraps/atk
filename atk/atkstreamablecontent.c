/* ATK -  Accessibility Toolkit
 * Copyright 2001 Sun Microsystems Inc.
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
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include "atkstreamablecontent.h"

GType atk_streamable_content_get_type(void) {
  static GType type = 0;

  if (!type) {
    GTypeInfo tinfo =
    {
      sizeof (AtkStreamableContentIface),
      (GBaseInitFunc) NULL,
      (GBaseFinalizeFunc) NULL,

    };

    type = g_type_register_static (G_TYPE_INTERFACE, "AtkStreamableContent", &tinfo, 0);
  }

  return type;
}

gint atk_streamable_content_get_n_mime_types (AtkStreamableContent *streamable) {
    return 0;
}

const gchar* atk_streamable_content_get_mime_type (AtkStreamableContent *streamable,
                                      gint                 i) {
    return NULL;
}

GIOChannel* atk_streamable_content_get_stream (AtkStreamableContent *streamable,
                                   const gchar          *mime_type) {
    return NULL;
}

const gchar* atk_streamable_content_get_uri (AtkStreamableContent *streamable,
				const gchar          *mime_type) {
    return NULL;
}
