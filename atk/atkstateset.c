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
#include "atkobject.h"
#include "atkstateset.h"

#define ATK_STATE(state_enum)             ((AtkState)((guint64)1 << ((state_enum)%64)))

struct _AtkRealStateSet
{
  GObject parent;

  AtkState state;
};

typedef struct _AtkRealStateSet      AtkRealStateSet;

static void            atk_state_set_class_init       (AtkStateSetClass  *klass);

GType atk_state_set_get_type(void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkStateSetClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) atk_state_set_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,
        sizeof (AtkRealStateSet),
        0,
        (GInstanceInitFunc) NULL,
      } ;
      type = g_type_register_static (G_TYPE_OBJECT, "AtkStateSet", &typeInfo, 0) ;
    }
  return type;
}

static void
atk_state_set_class_init (AtkStateSetClass *klass)
{
}

AtkStateSet* atk_state_set_new(void) {
  return (AtkStateSet*) g_object_new (ATK_TYPE_STATE_SET, NULL);
}

gboolean atk_state_set_is_empty (AtkStateSet   *set) {
    return TRUE;
}

gboolean atk_state_set_add_state (AtkStateSet   *set,
                         AtkStateType  type) {
    return TRUE;
}
void atk_state_set_add_states (AtkStateSet   *set,
                          AtkStateType  *types,
                          gint          n_types) {
}

void atk_state_set_clear_states(AtkStateSet   *set) {
}

gboolean atk_state_set_contains_state (AtkStateSet   *set,
                              AtkStateType  type) {
    return FALSE;
}

gboolean atk_state_set_contains_states (AtkStateSet   *set,
                               AtkStateType  *types,
                               gint          n_types) {
  return FALSE;
}

gboolean atk_state_set_remove_state (AtkStateSet  *set,
                            AtkStateType type) {
    return FALSE;
}

AtkStateSet*
atk_state_set_and_sets (AtkStateSet  *set,
                        AtkStateSet  *compare_set) {
  return NULL;
}

AtkStateSet* atk_state_set_or_sets (AtkStateSet  *set,
                       AtkStateSet  *compare_set) {
  return NULL;
}

AtkStateSet* atk_state_set_xor_sets (AtkStateSet  *set,
                        AtkStateSet  *compare_set) {
  return NULL;
}
