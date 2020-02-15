/* ATK -  Accessibility Toolkit
 * Copyright 2007 Sun Microsystems Inc.
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
#include "atkmisc.h"

static void atk_misc_class_init (AtkMiscClass *klass);

GType atk_misc_get_type(void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkMiscClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) atk_misc_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,
        sizeof (AtkMisc),
        0,
        (GInstanceInitFunc) NULL,
      } ;
      type = g_type_register_static (G_TYPE_OBJECT, "AtkMisc", &typeInfo, 0) ;
    }
  return type;
}

static void atk_misc_class_init (AtkMiscClass *klass) {}

void atk_misc_threads_enter(AtkMisc *misc) {}

void atk_misc_threads_leave (AtkMisc *misc) {}

AtkMisc *atk_misc_instance = NULL;

const AtkMisc * atk_misc_get_instance(void) {
  return atk_misc_instance;
}
