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
#include "atkimage.h"

GType atk_image_get_type(void) {
  static GType type = 0;

  if (!type) {
    static const GTypeInfo tinfo =
    {
      sizeof (AtkImageIface),
      (GBaseInitFunc) NULL,
      (GBaseFinalizeFunc) NULL
    };

    type = g_type_register_static (G_TYPE_INTERFACE, "AtkImage", &tinfo, 0);
  }

  return type;
}

const gchar* atk_image_get_image_description (AtkImage *image) {
    return NULL;
}

void atk_image_get_image_size (AtkImage *image, 
                          int      *width,
                          int      *height) {
}

gboolean atk_image_set_image_description(AtkImage *image,
                                 const gchar     *description) {
    return FALSE;
}

void atk_image_get_image_position (AtkImage *image,
                        gint *x,
                        gint *y,
                        AtkCoordType coord_type) {
}

const gchar* atk_image_get_image_locale(AtkImage *image) {
    return NULL;
}
