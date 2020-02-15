/* ATK - The Accessibility Toolkit for GTK+
 * Copyright 2001 Sun Microsystems Inc.
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
#include "atkmarshal.h"
#include <string.h>

enum {
  TEXT_CHANGED,
  TEXT_CARET_MOVED,
  TEXT_SELECTION_CHANGED,
  TEXT_ATTRIBUTES_CHANGED,
  TEXT_INSERT,
  TEXT_REMOVE,
  LAST_SIGNAL
};

static void atk_text_base_init (AtkTextIface *class);

GType atk_text_get_type (void) {
  static GType type = 0;

  if (!type) 
    {
      static const GTypeInfo tinfo =
      {
        sizeof (AtkTextIface),
        (GBaseInitFunc) atk_text_base_init,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) NULL /* atk_text_interface_init */ ,
        (GClassFinalizeFunc) NULL,

      };

      type = g_type_register_static (G_TYPE_INTERFACE, "AtkText", &tinfo, 0);
    }

  return type;
}

static void atk_text_base_init (AtkTextIface *class) {
}

gchar* atk_text_get_text (AtkText      *text,
                   gint         start_offset,
                   gint         end_offset) {
    return NULL;
}

gunichar atk_text_get_character_at_offset (AtkText      *text,
                                  gint         offset) {
    return (gunichar) 0;
}

gchar* atk_text_get_text_after_offset (AtkText          *text,
                                gint             offset,
                                AtkTextBoundary  boundary_type,
 				gint             *start_offset,
				gint		 *end_offset) {
    return NULL;
}

gchar* atk_text_get_text_at_offset (AtkText          *text,
                             gint             offset,
                             AtkTextBoundary  boundary_type,
			     gint             *start_offset,
			     gint             *end_offset) {
    return NULL;
}

gchar* atk_text_get_text_before_offset (AtkText          *text,
                                 gint             offset,
                                 AtkTextBoundary  boundary_type,
				 gint             *start_offset,
				 gint		  *end_offset) {
    return NULL;
}

gchar* atk_text_get_string_at_offset (AtkText *text,
                                      gint offset,
                                      AtkTextGranularity granularity,
                                      gint *start_offset,
                                      gint *end_offset) {
    return NULL;
}

gint atk_text_get_caret_offset (AtkText *text) {
    return -1;
}

void atk_text_get_character_extents (AtkText *text,
                                gint offset,
                                gint *x,
                                gint *y,
                                gint *width,
                                gint *height,
                                AtkCoordType coords) {
}

AtkAttributeSet* atk_text_get_run_attributes (AtkText          *text,
                             gint             offset,
                             gint             *start_offset,
                             gint             *end_offset) {
    return NULL;
}

AtkAttributeSet* atk_text_get_default_attributes (AtkText *text) {
    return NULL;
}

gint atk_text_get_character_count (AtkText *text) {
    return -1;
}

gint atk_text_get_offset_at_point (AtkText *text,
                              gint x,
                              gint y,
			      AtkCoordType coords) {
    return -1;
}

gint atk_text_get_n_selections (AtkText *text) {
    return -1;
}

gchar* atk_text_get_selection (AtkText *text, 
                        gint    selection_num,
                        gint    *start_offset,
                        gint    *end_offset) {
    return NULL;
}

gboolean atk_text_add_selection (AtkText *text, 
                        gint    start_offset,
                        gint    end_offset) {
    return FALSE;
}

gboolean atk_text_remove_selection (AtkText *text, 
                           gint    selection_num) {
    return FALSE;
}

gboolean atk_text_set_selection (AtkText *text, 
                        gint    selection_num,
                        gint    start_offset, 
                        gint    end_offset) {
    return FALSE;
}

gboolean atk_text_set_caret_offset (AtkText *text,
                           gint    offset) {
    return FALSE;
}

void atk_text_get_range_extents (AtkText          *text,
                            gint             start_offset,
                            gint             end_offset,
                            AtkCoordType     coord_type,
                            AtkTextRectangle *rect) {
}

AtkTextRange** atk_text_get_bounded_ranges (AtkText          *text,
                             AtkTextRectangle *rect,
                             AtkCoordType      coord_type,
                             AtkTextClipType   x_clip_type,
                             AtkTextClipType   y_clip_type) {
    return NULL;
}

void atk_attribute_set_free (AtkAttributeSet *attrib_set) {
}

AtkTextAttribute atk_text_attribute_register (const gchar *name) {
  return ATK_TEXT_ATTR_INVALID;
}

const gchar* atk_text_attribute_get_name (AtkTextAttribute attr) {
  return NULL;
}

AtkTextAttribute atk_text_attribute_for_name (const gchar *name) {
  return ATK_TEXT_ATTR_INVALID;
}

const gchar* atk_text_attribute_get_value (AtkTextAttribute attr,
                              gint             index) {
    return NULL;
}

gboolean atk_text_scroll_substring_to (AtkText       *text,
                              gint          start_offset,
                              gint          end_offset,
                              AtkScrollType type) {
    return FALSE;
}

gboolean atk_text_scroll_substring_to_point (AtkText      *text,
                                    gint         start_offset,
                                    gint         end_offset,
                                    AtkCoordType coords,
                                    gint         x,
                                    gint         y) {
    return FALSE;
}

void atk_text_free_ranges (AtkTextRange **ranges) {
}

static AtkTextRange * atk_text_range_copy (AtkTextRange *src) {
  AtkTextRange *dst = g_new0 (AtkTextRange, 1);
  return dst;
}

static void
atk_text_range_free (AtkTextRange *range) {
}

G_DEFINE_BOXED_TYPE (AtkTextRange, atk_text_range, atk_text_range_copy,
                     atk_text_range_free)
