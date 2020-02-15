/* ATK - Accessibility Toolkit
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
#include "atkobjectfactory.h"
#include "atknoopobjectfactory.h"

static void atk_object_factory_class_init   (AtkObjectFactoryClass        *klass);

GType atk_object_factory_get_type(void) {
  static GType type = 0;

  if (!type) {
    GTypeInfo tinfo =
    {
      sizeof (AtkObjectFactoryClass),
      (GBaseInitFunc) NULL, /* base init */
      (GBaseFinalizeFunc) NULL, /* base finalize */
      (GClassInitFunc) atk_object_factory_class_init, /* class init */
      (GClassFinalizeFunc) NULL, /* class finalize */
      NULL, /* class data */
      sizeof (AtkObjectFactory), /* instance size */
      0, /* nb preallocs */
      (GInstanceInitFunc) NULL, /* instance init */
      NULL /* value table */
    };

    type = g_type_register_static (G_TYPE_OBJECT, "AtkObjectFactory", &tinfo, 0);
  }
  return type;
}

static void atk_object_factory_class_init(AtkObjectFactoryClass *klass) {
}

AtkObject* atk_object_factory_create_accessible (AtkObjectFactory *factory,
                                      GObject          *obj) {
  return NULL;
} 

void atk_object_factory_invalidate (AtkObjectFactory *factory) {
}

GType atk_object_factory_get_accessible_type(AtkObjectFactory *factory) {
    return G_TYPE_INVALID;
}
