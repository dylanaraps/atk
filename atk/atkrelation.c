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
#include <string.h>
#include <glib-object.h>
#include "atk.h"

enum {
  PROP_0,

  PROP_RELATION_TYPE,
  PROP_TARGET,
  PROP_LAST
};

static void atk_relation_class_init   (AtkRelationClass *klass);

GType atk_relation_get_type(void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkRelationClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) atk_relation_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,
        sizeof (AtkRelation),
        0,
        (GInstanceInitFunc) NULL,
      } ;
      type = g_type_register_static (G_TYPE_OBJECT, "AtkRelation", &typeInfo, 0) ;
    }
  return type;
}

static void atk_relation_class_init(AtkRelationClass *klass) {}

AtkRelationType atk_relation_type_register (const gchar *name) {
  return ATK_RELATION_NULL;
}

const gchar* atk_relation_type_get_name (AtkRelationType type) {
  return NULL;
}

AtkRelationType atk_relation_type_for_name(const gchar *name) {
  return ATK_RELATION_NULL;
}

AtkRelation* atk_relation_new (AtkObject       **targets,
                  gint            n_targets,
                  AtkRelationType relationship) {
  return NULL;
}

AtkRelationType atk_relation_get_relation_type(AtkRelation *relation) {
  return 0;
}

GPtrArray* atk_relation_get_target (AtkRelation *relation) {
  return NULL;
}

void atk_relation_add_target (AtkRelation *relation,
                         AtkObject   *target) {
}

gboolean atk_relation_remove_target (AtkRelation *relation,
                            AtkObject *target) {
  return FALSE;
}
