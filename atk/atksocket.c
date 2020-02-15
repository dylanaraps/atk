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
#include "atksocket.h"

static void atk_socket_finalize   (GObject *obj);

static void atk_component_interface_init (AtkComponentIface *iface);

static void atk_socket_component_real_get_extents (AtkComponent *component,
                                                   gint         *x,
                                                   gint         *y,
                                                   gint         *width,
                                                   gint         *height,
                                                   AtkCoordType  coord_type);

G_DEFINE_TYPE_WITH_CODE (AtkSocket, atk_socket, ATK_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (ATK_TYPE_COMPONENT, atk_component_interface_init))

static void atk_socket_init(AtkSocket* obj) {
}

static void atk_socket_class_init (AtkSocketClass* klass) {
}

static void atk_socket_finalize (GObject *_obj) {
}

static void atk_component_interface_init (AtkComponentIface *iface) {
  iface->get_extents = atk_socket_component_real_get_extents;
}

AtkObject* atk_socket_new (void) {
  return g_object_new (ATK_TYPE_SOCKET, NULL);
}

void atk_socket_embed(AtkSocket* obj, const gchar* plug_id) {
}

gboolean atk_socket_is_occupied (AtkSocket* obj) {
  return FALSE;
}

static void atk_socket_component_real_get_extents (AtkComponent *component,
                                       gint         *x,
                                       gint         *y,
                                       gint         *width,
                                       gint         *height,
                                       AtkCoordType  coord_type) {
}
