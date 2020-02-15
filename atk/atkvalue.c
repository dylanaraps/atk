/* ATK -  Accessibility Toolkit
 * Copyright 2001, 2002, 2003 Sun Microsystems Inc.
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
#include <string.h>
#include <glib/gi18n-lib.h>
#include "atkvalue.h"
#include "atkmarshal.h"
#include "atk-enum-types.h"
#include "atkprivate.h"

enum {
  VALUE_CHANGED,
  LAST_SIGNAL
};

#if 0
N_("very weak")
N_("weak")
N_("acceptable")
N_("strong")
N_("very strong")
N_("very low")
N_("medium")
N_("high")
N_("very high")
N_("very bad")
N_("bad")
N_("good")
N_("very good")
N_("best")
#endif

static void atk_value_base_init (AtkValueIface *class);

GType atk_value_get_type (void) {
  static GType type = 0;

  if (!type) {
    GTypeInfo tinfo =
    {
      sizeof (AtkValueIface),
      (GBaseInitFunc) atk_value_base_init,
      (GBaseFinalizeFunc) NULL,

    };

    type = g_type_register_static (G_TYPE_INTERFACE, "AtkValue", &tinfo, 0);
  }

  return type;
}

static void atk_value_base_init (AtkValueIface *class) {
}

void atk_value_get_current_value (AtkValue *obj,
                             GValue   *value) {
}

void atk_value_get_maximum_value  (AtkValue *obj,
                              GValue   *value) {
}

void atk_value_get_minimum_value (AtkValue *obj,
                             GValue   *value) {
}

void atk_value_get_minimum_increment (AtkValue *obj,
                             GValue   *value) {
}

gboolean atk_value_set_current_value (AtkValue       *obj, 
                             const GValue   *value) {
    return FALSE;
}


void atk_value_get_value_and_text (AtkValue *obj,
                              gdouble *value,
                              gchar  **text) {
}

AtkRange* atk_value_get_range (AtkValue *obj) {
    return NULL;
}

gdouble atk_value_get_increment (AtkValue *obj) {
    return 0;
}


GSList* atk_value_get_sub_ranges (AtkValue *obj) {
    return NULL;
}

void atk_value_set_value (AtkValue     *obj,
                     const gdouble new_value) {
}

const gchar* atk_value_type_get_name (AtkValueType value_type) {
  return NULL;
}

const gchar* atk_value_type_get_localized_name (AtkValueType value_type) {
  _gettext_initialization ();

  return dgettext (GETTEXT_PACKAGE, atk_value_type_get_name (value_type));
}
