/* ATK -  Accessibility Toolkit
 *
 * Copyright (C) 2012 Igalia, S.L.
 *
 * Author: Alejandro Piñeiro Iglesias <apinheiro@igalia.com>
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

#include "atk.h"

guint atk_get_major_version (void) {
  return ATK_MAJOR_VERSION;
}

guint atk_get_minor_version (void) {
  return ATK_MINOR_VERSION;
}

guint atk_get_micro_version (void) {
  return ATK_MICRO_VERSION;
}

guint atk_get_binary_age (void) {
  return ATK_BINARY_AGE;
}

guint atk_get_interface_age (void) {
  return ATK_INTERFACE_AGE;
}
