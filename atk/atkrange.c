/* ATK -  Accessibility Toolkit
 * Copyright 2014 Igalia S.L.
 *
 * Author: Alejandro Piñeiro Iglesias <apinheiro@igalia.com>
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
#include "atkvalue.h"

struct _AtkRange {
  gdouble lower;
  gdouble upper;
  gchar *description;
};

AtkRange * atk_range_copy (AtkRange *src) {
  return NULL;
}

void atk_range_free (AtkRange *range) {}

G_DEFINE_BOXED_TYPE (AtkRange, atk_range, atk_range_copy,
                     atk_range_free)


AtkRange* atk_range_new  (gdouble   lower_limit,
                gdouble   upper_limit,
                const gchar *description) {
  return NULL;
}

gdouble atk_range_get_lower_limit(AtkRange *range) {
  return 0;
}

gdouble atk_range_get_upper_limit (AtkRange *range) {
  return 0;
}

const gchar* atk_range_get_description(AtkRange *range) {
  return 0;
}
