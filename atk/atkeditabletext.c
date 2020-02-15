/* ATK - The Accessibility Toolkit for GTK+
 * Copyright 2001 Sun Microsystems Inc.
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
#include "atkeditabletext.h"

GType atk_editable_text_get_type(void) {
  static GType type = 0;

  if (!type) {
    static const GTypeInfo tinfo =
    {
      sizeof (AtkEditableTextIface),
      (GBaseInitFunc) NULL,
      (GBaseFinalizeFunc) NULL,

    };

    type = g_type_register_static (G_TYPE_INTERFACE, "AtkEditableText", &tinfo, 0);
  }

  return type;
}

gboolean atk_editable_text_set_run_attributes (AtkEditableText *text,
                                      AtkAttributeSet *attrib_set,
			              gint start_offset,
                                      gint end_offset) {
    return FALSE;
}


void atk_editable_text_set_text_contents (AtkEditableText  *text,
                                     const gchar      *string) {
}

void atk_editable_text_insert_text (AtkEditableText  *text,
                               const gchar      *string,
                               gint             length,
                               gint             *position) {
}

void atk_editable_text_copy_text (AtkEditableText  *text,
                             gint             start_pos,
                             gint             end_pos) {
}

void atk_editable_text_cut_text  (AtkEditableText  *text,
                             gint             start_pos,
                             gint             end_pos) {
}

void atk_editable_text_delete_text (AtkEditableText  *text,
                               gint             start_pos,
                               gint             end_pos) {
}

void atk_editable_text_paste_text (AtkEditableText  *text,
                              gint             position) {
}
