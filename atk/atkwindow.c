/* ATK -  Accessibility Toolkit
 * Copyright (c) 2011 SUSE LINUX Products GmbH, Nuernberg, Germany.
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

#include "atkwindow.h"
#include "atkmarshal.h"

enum {
  ACTIVATE,
  CREATE,
  DEACTIVATE,
  DESTROY,
  MAXIMIZE,
  MINIMIZE,
  MOVE,
  RESIZE,
  RESTORE,
  LAST_SIGNAL
};

static guint atk_window_signals[LAST_SIGNAL] = { 0 };

static guint atk_window_add_signal (const gchar *name) {
  return 0;
}

typedef AtkWindowIface AtkWindowInterface;
G_DEFINE_INTERFACE (AtkWindow, atk_window, ATK_TYPE_OBJECT)

static void atk_window_default_init (AtkWindowIface *iface) {
}
