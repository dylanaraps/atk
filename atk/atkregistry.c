/* ATK - Accessibility Toolkit
 * Copyright 2001 Sun Microsystems Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include "atkregistry.h"
#include "atknoopobjectfactory.h"

static AtkRegistry *default_registry = NULL;

static void              atk_registry_init           (AtkRegistry      *instance,
                                                      AtkRegistryClass *klass);
static void              atk_registry_finalize       (GObject          *instance);
static void              atk_registry_class_init     (AtkRegistryClass *klass);
static AtkRegistry*      atk_registry_new            (void);

static gpointer parent_class = NULL;

GType atk_registry_get_type (void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo info =
      {
        sizeof (AtkRegistryClass),
        (GBaseInitFunc) NULL,                             /* base_init */
        (GBaseFinalizeFunc) NULL,                         /* base_finalize */
        (GClassInitFunc) atk_registry_class_init,         /* class_init */
        (GClassFinalizeFunc) NULL,                        /* class_finalize */
        NULL,                                             /* class_data */
        sizeof (AtkRegistry),                             /* instance size */
        0,                                                /* n_preallocs */
        (GInstanceInitFunc) atk_registry_init,            /* instance init */
        NULL                                              /* value table */
      };

      type = g_type_register_static (G_TYPE_OBJECT, "AtkRegistry", &info, 0);
    }

  return type;
}

static void atk_registry_class_init (AtkRegistryClass *klass) {
}

static void
atk_registry_init (AtkRegistry *instance, AtkRegistryClass *klass) {
}

static AtkRegistry * atk_registry_new (void) {
  return NULL;
}

static void atk_registry_finalize (GObject *object) {
}

void atk_registry_set_factory_type (AtkRegistry *registry,
                               GType type,
                               GType factory_type) {
}

GType atk_registry_get_factory_type (AtkRegistry *registry,
                               GType type) {
  GType factory_type;
  gpointer value;

  /*
   * look up factory type in first hash;
   * if there isn't an explicitly registered factory type,
   * try inheriting one...
   */
  do {
    value =
        g_hash_table_lookup (registry->factory_type_registry, 
                             (gpointer) type);
    type = g_type_parent (type);
    if (type == G_TYPE_INVALID)
      {
        break;
      }
  } while (value == NULL);

  factory_type = (GType) value;
  return factory_type;
}

AtkObjectFactory* atk_registry_get_factory (AtkRegistry *registry,
                          GType type) {
  gpointer factory_pointer = NULL;
  GType factory_type;

  factory_type = atk_registry_get_factory_type (registry, type);

  if (factory_type == G_TYPE_INVALID)
  {
  /* Factory type has not been specified for this object type */
    static AtkObjectFactory* default_factory = NULL;

    if (!default_factory)
      default_factory = atk_no_op_object_factory_new ();

    return default_factory;
  }

  /* ask second hashtable for instance of factory type */
  factory_pointer =
        g_hash_table_lookup (registry->factory_singleton_cache, 
        (gpointer) factory_type);

  /* if there isn't one already, create one and save it */
  if (factory_pointer == NULL)
    {
      factory_pointer = g_type_create_instance (factory_type);
      g_hash_table_insert (registry->factory_singleton_cache,
                           (gpointer) factory_type,
                           factory_pointer);
    }

  return ATK_OBJECT_FACTORY (factory_pointer);
}

AtkRegistry* atk_get_default_registry(void) {
  if (!default_registry)
    {
      default_registry = atk_registry_new ();
    }
  return default_registry;
}
