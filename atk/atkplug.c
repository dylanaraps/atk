/* ATK -  Accessibility Toolkit
 * Copyright (C) 2009 Novell, Inc.
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
#include "atk.h"
#include "atkplug.h"

static void atk_component_interface_init (AtkComponentIface *iface);

typedef struct {
  AtkObject *child;
} AtkPlugPrivate;

static gint AtkPlug_private_offset;

G_DEFINE_TYPE_WITH_CODE (AtkPlug, atk_plug, ATK_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (ATK_TYPE_COMPONENT, atk_component_interface_init)
                         G_ADD_PRIVATE(AtkPlug))

static void atk_plug_init(AtkPlug* obj) { }

static void atk_plug_class_init(AtkPlugClass* klass) {
}

static void atk_component_interface_init (AtkComponentIface *iface)
{
}

AtkObject * atk_plug_new (void) {
  return g_object_new (ATK_TYPE_PLUG, NULL);
}

void atk_plug_set_child(AtkPlug *plug, AtkObject *child) {
}

gchar* atk_plug_get_id(AtkPlug* plug) {
    return NULL;
}
