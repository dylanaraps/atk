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
#include <string.h>
#include <locale.h>

#include <glib-object.h>
#include <glib/gi18n-lib.h>

#include "atk.h"
#include "atkmarshal.h"
#include "atkprivate.h"

static GPtrArray *role_names = NULL;

enum
{
  PROP_0,  /* gobject convention */

  PROP_NAME,
  PROP_DESCRIPTION,
  PROP_PARENT,      /* ancestry has changed */
  PROP_VALUE,
  PROP_ROLE,
  PROP_LAYER,
  PROP_MDI_ZORDER,
  PROP_TABLE_CAPTION,
  PROP_TABLE_COLUMN_DESCRIPTION,
  PROP_TABLE_COLUMN_HEADER,
  PROP_TABLE_ROW_DESCRIPTION,
  PROP_TABLE_ROW_HEADER,
  PROP_TABLE_SUMMARY,
  PROP_TABLE_CAPTION_OBJECT,
  PROP_HYPERTEXT_NUM_LINKS,
  PROP_ACCESSIBLE_ID,
  PROP_LAST         /* gobject convention */
};

enum {
  CHILDREN_CHANGED,
  FOCUS_EVENT,
  PROPERTY_CHANGE,
  STATE_CHANGE,
  VISIBLE_DATA_CHANGED,
  ACTIVE_DESCENDANT_CHANGED,
  
  LAST_SIGNAL
};

/* These are listed here for extraction by intltool */
#if 0
  N_("invalid")
  N_("accelerator label")
  N_("alert")
  N_("animation")
  N_("arrow")
  N_("calendar")
  N_("canvas")
  N_("check box")
  N_("check menu item")
  N_("color chooser")
  N_("column header")
  N_("combo box")
  N_("dateeditor")
  N_("desktop icon")
  N_("desktop frame")
  N_("dial")
  N_("dialog")
  N_("directory pane")
  N_("drawing area")
  N_("file chooser")
  N_("filler")
  /* I know it looks wrong but that is what Java returns */
  N_("fontchooser")
  N_("frame")
  N_("glass pane")
  N_("html container")
  N_("icon")
  N_("image")
  N_("internal frame")
  N_("label")
  N_("layered pane")
  N_("list")
  N_("list item")
  N_("menu")
  N_("menu bar")
  N_("menu item")
  N_("option pane")
  N_("page tab")
  N_("page tab list")
  N_("panel")
  N_("password text")
  N_("popup menu")
  N_("progress bar")
  N_("push button")
  N_("radio button")
  N_("radio menu item")
  N_("root pane")
  N_("row header")
  N_("scroll bar")
  N_("scroll pane")
  N_("separator")
  N_("slider")
  N_("split pane")
  N_("spin button")
  N_("statusbar")
  N_("table")
  N_("table cell")
  N_("table column header")
  N_("table row header")
  N_("tear off menu item")
  N_("terminal")
  N_("text")
  N_("toggle button")
  N_("tool bar")
  N_("tool tip")
  N_("tree")
  N_("tree table")
  N_("unknown")
  N_("viewport")
  N_("window")
  N_("header")
  N_("footer")
  N_("paragraph")
  N_("ruler")
  N_("application")
  N_("autocomplete")
  N_("edit bar")
  N_("embedded component")
  N_("entry")
  N_("chart")
  N_("caption")
  N_("document frame")
  N_("heading")
  N_("page")
  N_("section")
  N_("redundant object")
  N_("form")
  N_("link")
  N_("input method window")
  N_("table row")
  N_("tree item")
  N_("document spreadsheet")
  N_("document presentation")
  N_("document text")
  N_("document web")
  N_("document email")
  N_("comment")
  N_("list box")
  N_("grouping")
  N_("image map")
  N_("notification")
  N_("info bar")
  N_("level bar")
  N_("title bar")
  N_("block quote")
  N_("audio")
  N_("video")
  N_("definition")
  N_("article")
  N_("landmark")
  N_("log")
  N_("marquee")
  N_("math")
  N_("rating")
  N_("timer")
  N_("description list")
  N_("description term")
  N_("description value")
#endif /* 0 */

typedef struct {
  gchar *accessible_id;
} AtkObjectPrivate;

static gint AtkObject_private_offset;

static void            atk_object_class_init        (AtkObjectClass  *klass);
static void            atk_object_init              (AtkObject       *accessible,
                                                     AtkObjectClass  *klass);
static AtkRelationSet* atk_object_real_ref_relation_set 
                                                    (AtkObject       *accessible);
static void            atk_object_real_initialize   (AtkObject       *accessible,
                                                     gpointer        data);
static void            atk_object_real_set_property (GObject         *object,
                                                     guint            prop_id,
                                                     const GValue    *value,
                                                     GParamSpec      *pspec);
static void            atk_object_real_get_property (GObject         *object,
                                                     guint            prop_id,
                                                     GValue          *value,
                                                     GParamSpec      *pspec);
static void            atk_object_finalize          (GObject         *object);
static const gchar*    atk_object_real_get_name     (AtkObject       *object);
static const gchar*    atk_object_real_get_description
                                                   (AtkObject       *object);
static AtkObject*      atk_object_real_get_parent  (AtkObject       *object);
static AtkRole         atk_object_real_get_role    (AtkObject       *object);
static AtkLayer        atk_object_real_get_layer   (AtkObject       *object);
static AtkStateSet*    atk_object_real_ref_state_set
                                                   (AtkObject       *object);
static void            atk_object_real_set_name    (AtkObject       *object,
                                                    const gchar     *name);
static void            atk_object_real_set_description
                                                   (AtkObject       *object,
                                                    const gchar     *description);
static void            atk_object_real_set_parent  (AtkObject       *object,
                                                    AtkObject       *parent);
static void            atk_object_real_set_role    (AtkObject       *object,
                                                    AtkRole         role);
static void            atk_object_notify           (GObject         *obj,
                                                    GParamSpec      *pspec);
static const gchar*    atk_object_real_get_object_locale
                                                   (AtkObject       *object);

static guint atk_object_signals[LAST_SIGNAL] = { 0, };

static gpointer parent_class = NULL;

static const gchar* const atk_object_name_property_name = "accessible-name";
static const gchar* const atk_object_name_property_description = "accessible-description";
static const gchar* const atk_object_name_property_parent = "accessible-parent";
static const gchar* const atk_object_name_property_value = "accessible-value";
static const gchar* const atk_object_name_property_role = "accessible-role";
static const gchar* const atk_object_name_property_component_layer = "accessible-component-layer";
static const gchar* const atk_object_name_property_component_mdi_zorder = "accessible-component-mdi-zorder";
static const gchar* const atk_object_name_property_table_caption = "accessible-table-caption";
static const gchar* const atk_object_name_property_table_column_description = "accessible-table-column-description";
static const gchar* const atk_object_name_property_table_column_header = "accessible-table-column-header";
static const gchar* const atk_object_name_property_table_row_description = "accessible-table-row-description";
static const gchar* const atk_object_name_property_table_row_header = "accessible-table-row-header";
static const gchar* const atk_object_name_property_table_summary = "accessible-table-summary";
static const gchar* const atk_object_name_property_table_caption_object = "accessible-table-caption-object";
static const gchar* const atk_object_name_property_hypertext_num_links = "accessible-hypertext-nlinks";

static void initialize_role_names() {}

GType atk_object_get_type(void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkObjectClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) atk_object_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,
        sizeof (AtkObject),
        0,
        (GInstanceInitFunc) atk_object_init,
      } ;
      type = g_type_register_static (G_TYPE_OBJECT, "AtkObject", &typeInfo, 0) ;

      AtkObject_private_offset =
        g_type_add_instance_private (type, sizeof (AtkObjectPrivate));
    }
  return type;
}

static inline gpointer atk_object_get_instance_private (AtkObject *self) {
  return (G_STRUCT_MEMBER_P (self, AtkObject_private_offset));
}

static void atk_object_class_init (AtkObjectClass *klass) {}

static void atk_object_init(AtkObject *accessible, AtkObjectClass *klass) {}

GType atk_implementor_get_type(void) {
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo typeInfo =
      {
        sizeof (AtkImplementorIface),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
      } ;

      type = g_type_register_static (G_TYPE_INTERFACE, "AtkImplementorIface", &typeInfo, 0) ;
    }

  return type;
}

const gchar* atk_object_get_name (AtkObject *accessible) {
    return NULL;
}

const gchar* atk_object_get_description(AtkObject *accessible) {
    return NULL;
}

AtkObject* atk_object_get_parent(AtkObject *accessible) {
    return NULL;
}

AtkObject* atk_object_peek_parent (AtkObject *accessible) {
  return accessible->accessible_parent;
}

gint atk_object_get_n_accessible_children (AtkObject *accessible) {
    return 0;
}

AtkObject* atk_object_ref_accessible_child(AtkObject *accessible, gint i) {
    return NULL;
}

AtkRelationSet* atk_object_ref_relation_set(AtkObject *accessible) {
    return NULL;
}

AtkRole atk_role_register(const gchar *name) {
    return ATK_ROLE_INVALID;
}

AtkRole atk_object_get_role(AtkObject *accessible) {
    return ATK_ROLE_UNKNOWN;
}

AtkLayer atk_object_get_layer(AtkObject *accessible) {
    return ATK_LAYER_INVALID;
}

gint atk_object_get_mdi_zorder(AtkObject *accessible) {
    return G_MININT;
}

AtkStateSet* atk_object_ref_state_set (AtkObject *accessible) {
    return NULL;
}

gint atk_object_get_index_in_parent(AtkObject *accessible) {
    return -1;
}

void atk_object_set_name (AtkObject *accessible, const gchar *name) {
}

void atk_object_set_description (AtkObject   *accessible,
                            const gchar *description) {}

void atk_object_set_parent (AtkObject *accessible,
                       AtkObject *parent) {}

void atk_object_set_role (AtkObject *accessible, 
                     AtkRole   role) {
}

guint atk_object_connect_property_change_handler (AtkObject *accessible,
                                            AtkPropertyChangeHandler *handler){
    return 0;
}

void atk_object_remove_property_change_handler  (AtkObject *accessible,
                                            guint      handler_id) {}

void atk_object_notify_state_change (AtkObject *accessible,
                                AtkState  state,
                                gboolean  value) {}

AtkObject * atk_implementor_ref_accessible (AtkImplementor *implementor) {
  return NULL;
}

AtkAttributeSet * atk_object_get_attributes (AtkObject *accessible) {
    return NULL;
}

static AtkRelationSet* atk_object_real_ref_relation_set(AtkObject *accessible) {
  return NULL;
}

static void atk_object_real_set_property (GObject      *object,
                              guint         prop_id,
                              const GValue *value,
                              GParamSpec   *pspec) {}

static void atk_object_real_get_property (GObject      *object,
                              guint         prop_id,
                              GValue       *value,
                              GParamSpec   *pspec) {}

static void atk_object_finalize(GObject *object) { }

static const gchar* atk_object_real_get_name(AtkObject *object) {
  return object->name;
}

static const gchar* atk_object_real_get_description (AtkObject *object) {
  return object->description;
}

static AtkObject* atk_object_real_get_parent(AtkObject *object) {
  return atk_object_peek_parent (object);
}

static AtkRole atk_object_real_get_role (AtkObject *object) {
  return object->role;
}

static AtkLayer atk_object_real_get_layer(AtkObject *object) {
  return object->layer;
}

static AtkStateSet* atk_object_real_ref_state_set(AtkObject *accessible) {
  AtkStateSet *state_set;

  state_set = atk_state_set_new ();

  return state_set; 
}

static void atk_object_real_set_name (AtkObject       *object,
                          const gchar     *name) {
}

static void atk_object_real_set_description (AtkObject       *object,
                                 const gchar     *description) {}

static void atk_object_real_set_parent (AtkObject       *object,
                            AtkObject       *parent) {}

static void
atk_object_real_set_role (AtkObject *object,
                          AtkRole   role)
{
  object->role = role;
}

void atk_object_initialize (AtkObject  *accessible,
                       gpointer   data) { }

static void atk_object_notify (GObject     *obj,
                   GParamSpec  *pspec) {
}

const gchar* atk_role_get_name (AtkRole role) {
  return NULL;
}

const gchar* atk_role_get_localized_name(AtkRole role) {
  return NULL;
}

static const gchar* atk_object_real_get_object_locale (AtkObject *object) {
  return setlocale (LC_MESSAGES, NULL);
}

const gchar* atk_object_get_object_locale(AtkObject *accessible) {
    return NULL;
}


AtkRole atk_role_for_name(const gchar *name) {
  return ATK_ROLE_INVALID;
}

gboolean atk_object_add_relationship (AtkObject       *object,
                             AtkRelationType relationship,
                             AtkObject       *target) {
    return FALSE;
}

gboolean atk_object_remove_relationship (AtkObject       *object,
                                AtkRelationType relationship,
                                AtkObject       *target) {
  return FALSE;
}

const gchar* atk_object_get_accessible_id(AtkObject *accessible) {
  AtkObjectPrivate *private = atk_object_get_instance_private (accessible);
  return private->accessible_id;
}

void atk_object_set_accessible_id(AtkObject *accessible, const gchar *id) {
}

static void
atk_object_real_initialize (AtkObject *accessible,
                            gpointer  data) {
}
