/* ATK - The Accessibility Toolkit for GTK+
 * Copyright 2001, 2002, 2003 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include "atkhypertext.h"

enum {
  LINK_SELECTED,
  LAST_SIGNAL
};

static void atk_hypertext_base_init (AtkHypertextIface *class);

GType atk_hypertext_get_type(void) {
  static GType type = 0;

  if (!type) {
    static const GTypeInfo tinfo =
    {
      sizeof (AtkHypertextIface),
      (GBaseInitFunc) atk_hypertext_base_init,
      (GBaseFinalizeFunc) NULL,

    };

    type = g_type_register_static (G_TYPE_INTERFACE, "AtkHypertext", &tinfo, 0);
  }

  return type;
}

static void atk_hypertext_base_init(AtkHypertextIface *class) {
}

AtkHyperlink* atk_hypertext_get_link (AtkHypertext  *hypertext,
                        gint link_index) {
    return NULL;
}

gint atk_hypertext_get_n_links (AtkHypertext *hypertext) {
    return 0;
}

gint atk_hypertext_get_link_index (AtkHypertext  *hypertext,
                              gint          char_index) {
    return -1;
}
