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
#include "atkdocument.h"

enum {
  LOAD_COMPLETE,
  RELOAD,
  LOAD_STOPPED,
  PAGE_CHANGED,
  LAST_SIGNAL
};

static void atk_document_base_init (AtkDocumentIface *class);

GType atk_document_get_type(void) {
  static GType type = 0;

  if (!type) {
    static const GTypeInfo tinfo =
    {
      sizeof (AtkDocumentIface),
      (GBaseInitFunc) atk_document_base_init,
      (GBaseFinalizeFunc) NULL,

    };

    type = g_type_register_static (G_TYPE_INTERFACE, "AtkDocument", &tinfo, 0);
  }

  return type;
}

static void atk_document_base_init(AtkDocumentIface *class) {
}

const gchar* atk_document_get_document_type(AtkDocument *document) {
    return NULL;
}

gpointer atk_document_get_document(AtkDocument *document) {
    return NULL;
}

const gchar * atk_document_get_locale(AtkDocument *document) {
    return NULL;
}


AtkAttributeSet * atk_document_get_attributes(AtkDocument *document) {
    return NULL;
}

const gchar * atk_document_get_attribute_value(AtkDocument *document, 
				  const gchar *attribute_name)
{
    return NULL;
}

gboolean atk_document_set_attribute_value (AtkDocument *document, 
				  const gchar *attribute_name,
				  const gchar *attribute_value) {
    return FALSE;
}

gint atk_document_get_current_page_number(AtkDocument *document) {
    return -1;
}

gint atk_document_get_page_count(AtkDocument *document) {
    return -1;
}
