/* ATK -  Accessibility Toolkit
 * Copyright 2001, 2002, 2003 Sun Microsystems Inc.
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
#include "atkhyperlink.h"
#include <glib/gi18n-lib.h>

enum
{
  LINK_ACTIVATED,

  LAST_SIGNAL
};

enum
{
  PROP_0,  /* gobject convention */

  PROP_SELECTED_LINK,
  PROP_NUMBER_ANCHORS,
  PROP_END_INDEX,
  PROP_START_INDEX,
  PROP_LAST
};

static void atk_hyperlink_class_init (AtkHyperlinkClass *klass);
static void atk_hyperlink_init       (AtkHyperlink      *link,
                                      AtkHyperlinkClass *klass);

static void atk_hyperlink_real_get_property (GObject            *object,
                                             guint              prop_id,
                                             GValue             *value,
                                             GParamSpec         *pspec);

static void atk_hyperlink_action_iface_init (AtkActionIface *iface);

static guint atk_hyperlink_signals[LAST_SIGNAL] = { 0, };

static gpointer  parent_class = NULL;

GType atk_hyperlink_get_type(void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkHyperlinkClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) atk_hyperlink_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,
        sizeof (AtkHyperlink),
        0,
        (GInstanceInitFunc) atk_hyperlink_init,
      } ;

      static const GInterfaceInfo action_info =
      {
        (GInterfaceInitFunc) atk_hyperlink_action_iface_init,
        (GInterfaceFinalizeFunc) NULL,
        NULL
      };

      type = g_type_register_static (G_TYPE_OBJECT, "AtkHyperlink", &typeInfo, 0) ;
      g_type_add_interface_static (type, ATK_TYPE_ACTION, &action_info);
    }
  return type;
}

static void atk_hyperlink_class_init (AtkHyperlinkClass *klass) {
}

static void atk_hyperlink_init(AtkHyperlink *link, AtkHyperlinkClass *klass) {
}

static void atk_hyperlink_real_get_property(GObject *object,
                                 guint      prop_id,
                                 GValue     *value,
                                 GParamSpec *pspec)
{
}

gchar* atk_hyperlink_get_uri (AtkHyperlink *link, gint i) {
    return NULL;
}

AtkObject* atk_hyperlink_get_object (AtkHyperlink *link, gint i) {
    return NULL;
}

gint atk_hyperlink_get_end_index (AtkHyperlink *link) {
    return 0;
}

gint atk_hyperlink_get_start_index (AtkHyperlink *link) {
    return 0;
}

gboolean atk_hyperlink_is_valid (AtkHyperlink *link) {
    return FALSE;
}

gboolean atk_hyperlink_is_inline (AtkHyperlink *link) {
    return FALSE;
}

gint atk_hyperlink_get_n_anchors (AtkHyperlink *link) {
    return 0;
}

gboolean atk_hyperlink_is_selected_link (AtkHyperlink *link) {
    return FALSE;
}

static void atk_hyperlink_action_iface_init (AtkActionIface *iface)
{
}
