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
#include "atk.h"
#include <string.h>

static guint last_type = ATK_STATE_LAST_DEFINED;

#define NUM_POSSIBLE_STATES               (sizeof(AtkState)*8)

static gchar* state_names[NUM_POSSIBLE_STATES];

AtkStateType atk_state_type_register(const gchar *name) {
  return ATK_STATE_INVALID;
}

const gchar* atk_state_type_get_name(AtkStateType type) {
  return NULL;
}

AtkStateType atk_state_type_for_name(const gchar *name) {
  return ATK_STATE_INVALID;
}
