/* ATK - Accessibility Toolkit
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
#include <atk/atkgobjectaccessible.h>
#include <atk/atkregistry.h>
#include <atk/atkutil.h>

static void       atk_gobject_accessible_class_init       (AtkGObjectAccessibleClass   *klass);

GType atk_gobject_accessible_get_type(void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo tinfo =
      {
        sizeof (AtkGObjectAccessibleClass),
        (GBaseInitFunc) NULL, /* base init */
        (GBaseFinalizeFunc) NULL, /* base finalize */
        (GClassInitFunc) atk_gobject_accessible_class_init,
        (GClassFinalizeFunc) NULL, /* class finalize */
        NULL, /* class data */
        sizeof (AtkGObjectAccessible),
        0, /* nb preallocs */
        (GInstanceInitFunc) NULL, /* instance init */
        NULL /* value table */
      };

      type = g_type_register_static (ATK_TYPE_OBJECT,
                                     "AtkGObjectAccessible", &tinfo, 0);
    }

  return type;
}

AtkObject* atk_gobject_accessible_for_object (GObject *obj) {
    return NULL;
}

GObject * atk_gobject_accessible_get_object (AtkGObjectAccessible *obj){
  return NULL;
}
 
static void atk_gobject_accessible_class_init (AtkGObjectAccessibleClass *klass)
{ 
}
