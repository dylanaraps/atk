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
#include "atkcomponent.h"

enum {
  BOUNDS_CHANGED,
  LAST_SIGNAL
};

static void       atk_component_base_init (AtkComponentIface *class);

GType atk_component_get_type(void) {
  static GType type = 0;

  if (!type) {
    static const GTypeInfo tinfo = {
      sizeof (AtkComponentIface),
      (GBaseInitFunc) atk_component_base_init,
      (GBaseFinalizeFunc) NULL,
    };

    type = g_type_register_static (G_TYPE_INTERFACE, "AtkComponent", &tinfo, 0);
  }

  return type;
}

static void atk_component_base_init(AtkComponentIface *class) {}


guint atk_component_add_focus_handler(AtkComponent *component, AtkFocusHandler handler) {
    return 0;
}

void atk_component_remove_focus_handler(AtkComponent *component, guint handler_id) {
}

gboolean atk_component_contains(AtkComponent *component, gint x, gint y,
    AtkCoordType coord_type) {
    return FALSE;
}

AtkObject* atk_component_ref_accessible_at_point(AtkComponent *component,
                                       gint x,
                                       gint y,
                                       AtkCoordType coord_type) {
    return NULL;
}

void atk_component_get_extents(AtkComponent *component,
                              gint *x,
                              gint *y,
                              gint *width,
                              gint *height,
                              AtkCoordType coord_type) {
}

void atk_component_get_position(AtkComponent *component, gint *x, gint *y,
      AtkCoordType coord_type) {
}

void atk_component_get_size(AtkComponent *component, gint *width, gint *height) {
}

AtkLayer atk_component_get_layer(AtkComponent *component) {
    return ATK_LAYER_WIDGET;
}

gint atk_component_get_mdi_zorder(AtkComponent *component) {
    return G_MININT;
}

gdouble atk_component_get_alpha(AtkComponent *component) {
    return (gdouble) 1.0;
}

gboolean atk_component_grab_focus (AtkComponent *component) {
    return FALSE;
}

gboolean atk_component_set_extents(AtkComponent *component,
                             gint x,
                             gint y,
                             gint width,
                             gint height,
                             AtkCoordType coord_type) {
    return FALSE;
}

gboolean atk_component_set_position(AtkComponent *component,
                              gint x,
                              gint y,
                              AtkCoordType coord_type) {
    return FALSE;
}

gboolean atk_component_set_size(AtkComponent *component, gint x, gint y) {
    return FALSE;
}

gboolean atk_component_scroll_to (AtkComponent *component, AtkScrollType type) {
  return FALSE;
}

gboolean atk_component_scroll_to_point (AtkComponent *component, AtkCoordType coords, gint x, gint y) {
  return FALSE;
}

GType atk_rectangle_get_type (void) {
  static GType our_type = 0;
  return our_type;
}

