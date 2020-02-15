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
#include "atkselection.h"

enum {
  SELECTION_CHANGED,
  LAST_SIGNAL
};

static void atk_selection_base_init (gpointer *g_class);
static guint atk_selection_signals[LAST_SIGNAL] = { 0 };

GType atk_selection_get_type(void) {
  static GType type = 0;

  if (!type) {
    GTypeInfo tinfo =
    {
      sizeof (AtkSelectionIface),
      (GBaseInitFunc)atk_selection_base_init,
      (GBaseFinalizeFunc) NULL,

    };

    type = g_type_register_static (G_TYPE_INTERFACE, "AtkSelection", &tinfo, 0);
  }

  return type;
}

static void atk_selection_base_init (gpointer *g_class) {
}

gboolean atk_selection_add_selection (AtkSelection *obj,
                             gint         i) {
    return FALSE;
}

gboolean atk_selection_clear_selection(AtkSelection *obj) {
    return FALSE;
}

AtkObject* atk_selection_ref_selection (AtkSelection *obj,
                             gint         i) {
    return NULL;
}

gint atk_selection_get_selection_count (AtkSelection *obj) {
    return 0;
}

gboolean atk_selection_is_child_selected (AtkSelection *obj,
                                 gint         i) {
    return FALSE;
}

gboolean atk_selection_remove_selection (AtkSelection *obj,
                                gint         i) {
    return FALSE;
}

gboolean atk_selection_select_all_selection (AtkSelection *obj) {
    return FALSE;
}
