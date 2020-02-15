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
#include <glib-object.h>
#include "atk.h"

static gpointer parent_class = NULL;

static void atk_relation_set_class_init (AtkRelationSetClass  *klass);
static void atk_relation_set_finalize   (GObject              *object);

GType atk_relation_set_get_type (void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkRelationSetClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) atk_relation_set_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,
        sizeof (AtkRelationSet),
        0,
        (GInstanceInitFunc) NULL,
      } ;
      type = g_type_register_static (G_TYPE_OBJECT, "AtkRelationSet", &typeInfo, 0) ;
    }
  return type;
}

static void atk_relation_set_class_init (AtkRelationSetClass *klass) {
}

AtkRelationSet* atk_relation_set_new(void) {
  AtkRelationSet *relation_set;

  relation_set = g_object_new (ATK_TYPE_RELATION_SET, NULL);
  return relation_set;
}

gboolean atk_relation_set_contains (AtkRelationSet   *set,
                           AtkRelationType  relationship) {
    return FALSE;
}

void atk_relation_set_remove (AtkRelationSet *set,
                         AtkRelation    *relation) {
}

void atk_relation_set_add (AtkRelationSet *set,
                      AtkRelation    *relation) {
}

gint atk_relation_set_get_n_relations(AtkRelationSet *set) {
    return 0;
}

AtkRelation* atk_relation_set_get_relation (AtkRelationSet *set,
                               gint           i) {
    return NULL;
}

AtkRelation* atk_relation_set_get_relation_by_type (AtkRelationSet  *set,
                                       AtkRelationType relationship)  {
  return NULL;
}

static void atk_relation_set_finalize(GObject *object) {
}

void atk_relation_set_add_relation_by_type (AtkRelationSet  *set,
                                       AtkRelationType relationship,
                                       AtkObject       *target) {
}

gboolean atk_relation_set_contains_target (AtkRelationSet  *set,
                                  AtkRelationType relationship,
                                  AtkObject       *target) {
    return FALSE;
}
