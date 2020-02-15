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

#include "atkutil.h"
#include "atkmarshal.h"

static void atk_util_class_init (AtkUtilClass *klass);

static AtkObject *previous_focus_object = NULL;

typedef struct _AtkUtilListenerInfo AtkUtilListenerInfo;
struct _AtkUtilListenerInfo
{
  gint key;
  guint signal_id;
  gulong hook_id;
};
static GHashTable *listener_list = NULL;

GType atk_util_get_type (void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkUtilClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) atk_util_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,
        sizeof (AtkUtil),
        0,
        (GInstanceInitFunc) NULL,
      } ;
      type = g_type_register_static (G_TYPE_OBJECT, "AtkUtil", &typeInfo, 0) ;
    }
  return type;
}

/*
 * This file supports the addition and removal of multiple focus handlers
 * as long as they are all called in the same thread.
 */
static AtkEventListenerInit  focus_tracker_init = (AtkEventListenerInit) NULL;

static gboolean init_done = FALSE;

/*
 * Array of FocusTracker structs
 */
static GArray *trackers = NULL;
static guint  global_index = 0;

typedef struct _FocusTracker FocusTracker;

struct _FocusTracker {
  guint index;
  AtkEventListener func;
};

void atk_focus_tracker_init (AtkEventListenerInit    init)
{
}

guint atk_add_focus_tracker (AtkEventListener   focus_tracker) {
    return 0;
}

void atk_remove_focus_tracker (guint            tracker_id) {
}

void atk_focus_tracker_notify (AtkObject       *object) {
}

static guint add_listener (GSignalEmissionHook listener,
              const gchar         *object_type,
              const gchar         *signal_name,
              const gchar         *detail_string,
              const gchar         *hook_data) {
  return 0;
}

static guint atk_util_real_add_global_event_listener (GSignalEmissionHook listener,
                                         const gchar *event_type) {
  return 0;
}

guint atk_add_global_event_listener (GSignalEmissionHook listener,
			       const gchar        *event_type) {
  return 0;
}

void atk_remove_global_event_listener (guint listener_id) {
}

guint atk_add_key_event_listener (AtkKeySnoopFunc listener, gpointer data) {
  return 0;
}

void atk_remove_key_event_listener (guint listener_id) {
}

AtkObject* atk_get_root (void) {
  return NULL;
}

AtkObject* atk_get_focus_object (void) {
  return previous_focus_object;
}

const gchar* atk_get_toolkit_name (void) {
  return NULL;
}

const gchar* atk_get_toolkit_version (void) {
  return NULL;
}

const gchar * atk_get_version (void) {
  return VERSION;
}

static void atk_util_class_init (AtkUtilClass *klass) { }
