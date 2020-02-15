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

static GPtrArray *extra_names = NULL;

static gpointer parent_class = NULL;
  
static void atk_relation_class_init   (AtkRelationClass *klass);
static void atk_relation_finalize     (GObject          *object);
static void atk_relation_set_property (GObject          *object,
                                       guint            prop_id,
                                       const GValue     *value,
                                       GParamSpec       *pspec);
static void atk_relation_get_property (GObject          *object,
                                       guint            prop_id,
                                       GValue           *value,
                                       GParamSpec       *pspec);

static GPtrArray* atk_relation_get_ptr_array_from_value_array (GValueArray *array);
static GValueArray* atk_relation_get_value_array_from_ptr_array (GPtrArray *array);

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

static void delete_object_while_in_relation (gpointer callback_data,
                                 GObject *where_the_object_was) {
}

void atk_relation_add_target (AtkRelation *relation,
                         AtkObject   *target) {
}

gboolean atk_relation_remove_target (AtkRelation *relation,
                            AtkObject *target) {
  return FALSE;
}

static void atk_relation_finalize(GObject *object) {
}

static void atk_relation_set_property(GObject       *object,
                           guint         prop_id,
                           const GValue  *value,
                           GParamSpec    *pspec) {
}

static void atk_relation_get_property (GObject    *object,
                           guint      prop_id,
                           GValue     *value,
                           GParamSpec *pspec) {
}

static GPtrArray* atk_relation_get_ptr_array_from_value_array (GValueArray *array) {
  gint i;
  GPtrArray *return_array;
  GValue *value;
  GObject *obj;

  return_array = g_ptr_array_sized_new (array->n_values);
  for (i = 0; i < array->n_values; i++)
    {
      value = g_value_array_get_nth (array, i);
      obj = g_value_get_object (value);
      g_ptr_array_add (return_array, obj);
      g_object_weak_ref (obj, (GWeakNotify) delete_object_while_in_relation, return_array);
    }
      
  return return_array;
}

static GValueArray* atk_relation_get_value_array_from_ptr_array (GPtrArray *array) {
  int         i;
  GValueArray *return_array;
  GValue      *value;

  return_array = g_value_array_new (array->len);
  for (i = 0; i < array->len; i++)
    {
      value = g_new0 (GValue, 1);
      g_value_init (value, ATK_TYPE_OBJECT);
      g_value_set_object (value, g_ptr_array_index (array, i));
      return_array = g_value_array_append (return_array, value);
    }
  return return_array;
}
