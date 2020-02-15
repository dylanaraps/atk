/* ATK -  Accessibility Toolkit
 * Copyright 2014 SUSE LLC.
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
#include "atktablecell.h"


typedef AtkTableCellIface AtkTableCellInterface;
G_DEFINE_INTERFACE (AtkTableCell, atk_table_cell, ATK_TYPE_OBJECT)

static gboolean atk_table_cell_real_get_row_column_span (AtkTableCell *cell,
                                                         gint         *row,
                                                         gint         *column,
                                                         gint         *row_span,
                                                         gint         *column_span);

static void
atk_table_cell_default_init (AtkTableCellInterface *iface)
{
  iface->get_row_column_span = atk_table_cell_real_get_row_column_span;
}

gint atk_table_cell_get_column_span (AtkTableCell *cell) {
    return 0;
}

GPtrArray * atk_table_cell_get_column_header_cells (AtkTableCell *cell) {
    return NULL;
}

gboolean atk_table_cell_get_position (AtkTableCell *cell,
                             gint         *row,
                             gint         *column) {
    return FALSE;
}

gint atk_table_cell_get_row_span (AtkTableCell *cell) {
    return 0;
}

GPtrArray * atk_table_cell_get_row_header_cells (AtkTableCell *cell) {
    return NULL;
}

gboolean atk_table_cell_get_row_column_span (AtkTableCell *cell,
                                    gint         *row,
                                    gint         *column,
                                    gint         *row_span,
                                    gint         *column_span) {
    return FALSE;
}

AtkObject * atk_table_cell_get_table (AtkTableCell *cell) {
    return NULL;
}

static gboolean atk_table_cell_real_get_row_column_span (AtkTableCell *cell,
                                         gint         *row,
                                         gint         *column,
                                         gint         *row_span,
                                         gint         *column_span) {
  return 0;
}
