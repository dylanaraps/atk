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
#include "atktable.h"
#include "atkmarshal.h"

enum {
  ROW_INSERTED,
  ROW_DELETED,
  COLUMN_INSERTED,
  COLUMN_DELETED,
  ROW_REORDERED,
  COLUMN_REORDERED,
  MODEL_CHANGED,
  LAST_SIGNAL
};

static void  atk_table_base_init (gpointer *g_class);

GType atk_table_get_type(void) {
  static GType type = 0;
  
  if (!type) {
    GTypeInfo tinfo =
    {
      sizeof (AtkTableIface),
      (GBaseInitFunc) atk_table_base_init,
      (GBaseFinalizeFunc) NULL,
      
    };
    
    type = g_type_register_static (G_TYPE_INTERFACE, "AtkTable", &tinfo, 0);
  }
  
  return type;
}


static void atk_table_base_init (gpointer *g_class) {
}

AtkObject* atk_table_ref_at (AtkTable *table,
                  gint     row,
                  gint     column)
{
    return NULL;
}

gint atk_table_get_index_at (AtkTable *table,
                        gint     row,
                        gint     column) {
    return -1;
}

gint atk_table_get_row_at_index(AtkTable *table,
                            gint     index) {
    return -1;
}

gint atk_table_get_column_at_index(AtkTable *table,
                               gint     index) {
    return -1;
}

AtkObject* atk_table_get_caption(AtkTable *table) {
    return NULL;
}

gint atk_table_get_n_columns (AtkTable *table) {
    return 0;
}

const gchar* atk_table_get_column_description (AtkTable *table,
                                  gint     column) {
    return NULL;
}

gint atk_table_get_column_extent_at (AtkTable *table,
                                gint     row,
                                gint     column) {
    return 0;
}

AtkObject* atk_table_get_column_header (AtkTable *table, gint column) {
    return NULL;
}

gint atk_table_get_n_rows (AtkTable *table) {
    return 0;
}

const gchar* atk_table_get_row_description (AtkTable *table,
                               gint      row) {
    return NULL;
}

gint atk_table_get_row_extent_at (AtkTable *table,
                             gint     row,
                             gint     column) {
    return 0;
}

AtkObject* atk_table_get_row_header (AtkTable *table, gint row) {
    return NULL;
}

AtkObject* atk_table_get_summary (AtkTable *table) {
    return NULL;
}

gint atk_table_get_selected_rows (AtkTable *table, gint **selected) {
    return 0;
}

gint  atk_table_get_selected_columns (AtkTable *table, gint **selected) {
    return 0;
}

gboolean atk_table_is_column_selected (AtkTable *table,
                              gint     column) {
    return FALSE;
}

gboolean atk_table_is_row_selected (AtkTable *table,
                           gint     row) {
    return FALSE;
}

gboolean atk_table_is_selected (AtkTable *table,
                       gint     row,
                       gint     column) {
    return FALSE;
}

gboolean atk_table_add_row_selection (AtkTable *table,
                       		 gint     row) {
    return FALSE;
}

gboolean atk_table_remove_row_selection (AtkTable *table,
                       		    gint     row) {
    return FALSE;
}

gboolean atk_table_add_column_selection (AtkTable *table,
                       		    gint     column) {
    return FALSE;
}

gboolean atk_table_remove_column_selection (AtkTable *table,
                       			   gint     column) {
    return FALSE;
}

void atk_table_set_caption (AtkTable       *table,
                       AtkObject      *caption) {
}

void atk_table_set_column_description (AtkTable       *table,
                                  gint           column,
                                  const gchar    *description) {
}

void atk_table_set_column_header (AtkTable  *table,
                             gint      column,
                             AtkObject *header) {
}

void atk_table_set_row_description (AtkTable       *table,
                               gint           row,
                               const gchar    *description) {
}

void atk_table_set_row_header (AtkTable  *table,
                          gint      row,
                          AtkObject *header) {
}

void atk_table_set_summary (AtkTable       *table,
                       AtkObject      *accessible) {
}
