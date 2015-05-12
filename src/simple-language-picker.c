/* simple-language-picker.c generated by valac 0.28.0, the Vala compiler
 * generated from simple-language-picker.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <glib/gi18n-lib.h>
#include <gdk/gdk.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_SIMPLE_LANGUAGE_PICKER (simple_language_picker_get_type ())
#define SIMPLE_LANGUAGE_PICKER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SIMPLE_LANGUAGE_PICKER, SimpleLanguagePicker))
#define SIMPLE_LANGUAGE_PICKER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SIMPLE_LANGUAGE_PICKER, SimpleLanguagePickerClass))
#define IS_SIMPLE_LANGUAGE_PICKER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SIMPLE_LANGUAGE_PICKER))
#define IS_SIMPLE_LANGUAGE_PICKER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SIMPLE_LANGUAGE_PICKER))
#define SIMPLE_LANGUAGE_PICKER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SIMPLE_LANGUAGE_PICKER, SimpleLanguagePickerClass))

typedef struct _SimpleLanguagePicker SimpleLanguagePicker;
typedef struct _SimpleLanguagePickerClass SimpleLanguagePickerClass;
typedef struct _SimpleLanguagePickerPrivate SimpleLanguagePickerPrivate;

#define TYPE_PROGRAMMING_LANGUAGES (programming_languages_get_type ())
#define PROGRAMMING_LANGUAGES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PROGRAMMING_LANGUAGES, ProgrammingLanguages))
#define PROGRAMMING_LANGUAGES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PROGRAMMING_LANGUAGES, ProgrammingLanguagesClass))
#define IS_PROGRAMMING_LANGUAGES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PROGRAMMING_LANGUAGES))
#define IS_PROGRAMMING_LANGUAGES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PROGRAMMING_LANGUAGES))
#define PROGRAMMING_LANGUAGES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PROGRAMMING_LANGUAGES, ProgrammingLanguagesClass))

typedef struct _ProgrammingLanguages ProgrammingLanguages;
typedef struct _ProgrammingLanguagesClass ProgrammingLanguagesClass;
#define _programming_languages_unref0(var) ((var == NULL) ? NULL : (var = (programming_languages_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _SimpleLanguagePicker {
	GtkPopover parent_instance;
	SimpleLanguagePickerPrivate * priv;
};

struct _SimpleLanguagePickerClass {
	GtkPopoverClass parent_class;
};

struct _SimpleLanguagePickerPrivate {
	ProgrammingLanguages* plangs;
	GtkScrolledWindow* scroll;
	GtkBox* lang_box;
	GtkFrame* frame;
	GtkSearchEntry* search_entry;
	GtkListBox* list_view;
};


static gpointer simple_language_picker_parent_class = NULL;

GType simple_language_picker_get_type (void) G_GNUC_CONST;
gpointer programming_languages_ref (gpointer instance);
void programming_languages_unref (gpointer instance);
GParamSpec* param_spec_programming_languages (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_programming_languages (GValue* value, gpointer v_object);
void value_take_programming_languages (GValue* value, gpointer v_object);
gpointer value_get_programming_languages (const GValue* value);
GType programming_languages_get_type (void) G_GNUC_CONST;
#define SIMPLE_LANGUAGE_PICKER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_SIMPLE_LANGUAGE_PICKER, SimpleLanguagePickerPrivate))
enum  {
	SIMPLE_LANGUAGE_PICKER_DUMMY_PROPERTY
};
SimpleLanguagePicker* simple_language_picker_new (GtkWidget* parent);
SimpleLanguagePicker* simple_language_picker_construct (GType object_type, GtkWidget* parent);
static void simple_language_picker_create_widgets (SimpleLanguagePicker* self);
ProgrammingLanguages* programming_languages_new (void);
ProgrammingLanguages* programming_languages_construct (GType object_type);
static void simple_language_picker_on_language_selected (SimpleLanguagePicker* self, GtkListBoxRow* row);
static void _simple_language_picker_on_language_selected_gtk_list_box_row_activated (GtkListBox* _sender, GtkListBoxRow* row, gpointer self);
static gboolean simple_language_picker_row_filter (SimpleLanguagePicker* self, GtkListBoxRow* row);
static gboolean _simple_language_picker_row_filter_gtk_list_box_filter_func (GtkListBoxRow* row, gpointer self);
static gboolean __lambda20_ (SimpleLanguagePicker* self, GdkEventKey* event);
static gboolean ___lambda20__gtk_widget_key_release_event (GtkWidget* _sender, GdkEventKey* event, gpointer self);
GList* programming_languages_get_languages (ProgrammingLanguages* self);
static void __lambda21_ (SimpleLanguagePicker* self, const gchar* entry);
static void ___lambda21__gfunc (gconstpointer data, gpointer self);
static void simple_language_picker_finalize (GObject* obj);


SimpleLanguagePicker* simple_language_picker_construct (GType object_type, GtkWidget* parent) {
	SimpleLanguagePicker * self = NULL;
	GtkWidget* _tmp0_ = NULL;
	g_return_val_if_fail (parent != NULL, NULL);
	_tmp0_ = parent;
	self = (SimpleLanguagePicker*) g_object_new (object_type, "relative-to", _tmp0_, NULL);
	gtk_container_set_border_width ((GtkContainer*) self, (guint) 5);
	simple_language_picker_create_widgets (self);
	return self;
}


SimpleLanguagePicker* simple_language_picker_new (GtkWidget* parent) {
	return simple_language_picker_construct (TYPE_SIMPLE_LANGUAGE_PICKER, parent);
}


static void _simple_language_picker_on_language_selected_gtk_list_box_row_activated (GtkListBox* _sender, GtkListBoxRow* row, gpointer self) {
	simple_language_picker_on_language_selected ((SimpleLanguagePicker*) self, row);
}


static gboolean _simple_language_picker_row_filter_gtk_list_box_filter_func (GtkListBoxRow* row, gpointer self) {
	gboolean result;
	result = simple_language_picker_row_filter ((SimpleLanguagePicker*) self, row);
	return result;
}


static gboolean __lambda20_ (SimpleLanguagePicker* self, GdkEventKey* event) {
	gboolean result = FALSE;
	GtkListBox* _tmp0_ = NULL;
	g_return_val_if_fail (event != NULL, FALSE);
	_tmp0_ = self->priv->list_view;
	gtk_list_box_invalidate_filter (_tmp0_);
	result = TRUE;
	return result;
}


static gboolean ___lambda20__gtk_widget_key_release_event (GtkWidget* _sender, GdkEventKey* event, gpointer self) {
	gboolean result;
	result = __lambda20_ ((SimpleLanguagePicker*) self, event);
	return result;
}


static void __lambda21_ (SimpleLanguagePicker* self, const gchar* entry) {
	GtkLabel* label = NULL;
	const gchar* _tmp0_ = NULL;
	GtkLabel* _tmp1_ = NULL;
	GtkListBox* _tmp2_ = NULL;
	g_return_if_fail (entry != NULL);
	_tmp0_ = entry;
	_tmp1_ = (GtkLabel*) gtk_label_new ((const gchar*) _tmp0_);
	g_object_ref_sink (_tmp1_);
	label = _tmp1_;
	_tmp2_ = self->priv->list_view;
	gtk_container_add ((GtkContainer*) _tmp2_, (GtkWidget*) label);
	_g_object_unref0 (label);
}


static void ___lambda21__gfunc (gconstpointer data, gpointer self) {
	__lambda21_ ((SimpleLanguagePicker*) self, (const gchar*) data);
}


static void simple_language_picker_create_widgets (SimpleLanguagePicker* self) {
	ProgrammingLanguages* _tmp0_ = NULL;
	GtkListBox* _tmp1_ = NULL;
	GtkListBox* _tmp2_ = NULL;
	GtkListBox* _tmp3_ = NULL;
	GtkListBox* _tmp4_ = NULL;
	GtkListBox* _tmp5_ = NULL;
	GtkSearchEntry* _tmp6_ = NULL;
	GtkSearchEntry* _tmp7_ = NULL;
	const gchar* _tmp8_ = NULL;
	GtkSearchEntry* _tmp9_ = NULL;
	GtkSearchEntry* _tmp10_ = NULL;
	ProgrammingLanguages* _tmp11_ = NULL;
	GList* _tmp12_ = NULL;
	GList* _tmp13_ = NULL;
	GtkScrolledWindow* _tmp14_ = NULL;
	GtkScrolledWindow* _tmp15_ = NULL;
	GtkScrolledWindow* _tmp16_ = NULL;
	GtkScrolledWindow* _tmp17_ = NULL;
	GtkListBox* _tmp18_ = NULL;
	GtkBox* _tmp19_ = NULL;
	GtkBox* _tmp20_ = NULL;
	GtkSearchEntry* _tmp21_ = NULL;
	GtkBox* _tmp22_ = NULL;
	GtkScrolledWindow* _tmp23_ = NULL;
	GtkFrame* _tmp24_ = NULL;
	GtkFrame* _tmp25_ = NULL;
	GtkBox* _tmp26_ = NULL;
	GtkFrame* _tmp27_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = programming_languages_new ();
	_programming_languages_unref0 (self->priv->plangs);
	self->priv->plangs = _tmp0_;
	_tmp1_ = (GtkListBox*) gtk_list_box_new ();
	g_object_ref_sink (_tmp1_);
	_g_object_unref0 (self->priv->list_view);
	self->priv->list_view = _tmp1_;
	_tmp2_ = self->priv->list_view;
	gtk_list_box_set_selection_mode (_tmp2_, GTK_SELECTION_SINGLE);
	_tmp3_ = self->priv->list_view;
	gtk_list_box_set_activate_on_single_click (_tmp3_, TRUE);
	_tmp4_ = self->priv->list_view;
	g_signal_connect_object (_tmp4_, "row-activated", (GCallback) _simple_language_picker_on_language_selected_gtk_list_box_row_activated, self, 0);
	_tmp5_ = self->priv->list_view;
	gtk_list_box_set_filter_func (_tmp5_, _simple_language_picker_row_filter_gtk_list_box_filter_func, g_object_ref (self), g_object_unref);
	_tmp6_ = (GtkSearchEntry*) gtk_search_entry_new ();
	g_object_ref_sink (_tmp6_);
	_g_object_unref0 (self->priv->search_entry);
	self->priv->search_entry = _tmp6_;
	_tmp7_ = self->priv->search_entry;
	_tmp8_ = _ ("Search highlight mode...");
	gtk_entry_set_placeholder_text ((GtkEntry*) _tmp7_, _tmp8_);
	_tmp9_ = self->priv->search_entry;
	gtk_entry_set_width_chars ((GtkEntry*) _tmp9_, 30);
	_tmp10_ = self->priv->search_entry;
	g_signal_connect_object ((GtkWidget*) _tmp10_, "key-release-event", (GCallback) ___lambda20__gtk_widget_key_release_event, self, 0);
	_tmp11_ = self->priv->plangs;
	_tmp12_ = programming_languages_get_languages (_tmp11_);
	_tmp13_ = _tmp12_;
	g_list_foreach (_tmp13_, ___lambda21__gfunc, self);
	_tmp14_ = (GtkScrolledWindow*) gtk_scrolled_window_new (NULL, NULL);
	g_object_ref_sink (_tmp14_);
	_g_object_unref0 (self->priv->scroll);
	self->priv->scroll = _tmp14_;
	_tmp15_ = self->priv->scroll;
	gtk_scrolled_window_set_policy (_tmp15_, GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
	_tmp16_ = self->priv->scroll;
	g_object_set ((GtkWidget*) _tmp16_, "height-request", 300, NULL);
	_tmp17_ = self->priv->scroll;
	_tmp18_ = self->priv->list_view;
	gtk_container_add ((GtkContainer*) _tmp17_, (GtkWidget*) _tmp18_);
	_tmp19_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	g_object_ref_sink (_tmp19_);
	_g_object_unref0 (self->priv->lang_box);
	self->priv->lang_box = _tmp19_;
	_tmp20_ = self->priv->lang_box;
	_tmp21_ = self->priv->search_entry;
	gtk_box_pack_start (_tmp20_, (GtkWidget*) _tmp21_, TRUE, TRUE, (guint) 0);
	_tmp22_ = self->priv->lang_box;
	_tmp23_ = self->priv->scroll;
	gtk_box_pack_start (_tmp22_, (GtkWidget*) _tmp23_, TRUE, TRUE, (guint) 0);
	_tmp24_ = (GtkFrame*) gtk_frame_new (NULL);
	g_object_ref_sink (_tmp24_);
	_g_object_unref0 (self->priv->frame);
	self->priv->frame = _tmp24_;
	_tmp25_ = self->priv->frame;
	_tmp26_ = self->priv->lang_box;
	gtk_container_add ((GtkContainer*) _tmp25_, (GtkWidget*) _tmp26_);
	_tmp27_ = self->priv->frame;
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp27_);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void simple_language_picker_on_language_selected (SimpleLanguagePicker* self, GtkListBoxRow* row) {
	GtkLabel* lang = NULL;
	GtkListBoxRow* _tmp0_ = NULL;
	GtkWidget* _tmp1_ = NULL;
	GtkLabel* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	GtkSearchEntry* _tmp5_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (row != NULL);
	_tmp0_ = row;
	_tmp1_ = gtk_bin_get_child ((GtkBin*) _tmp0_);
	_tmp2_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp1_, gtk_label_get_type ()) ? ((GtkLabel*) _tmp1_) : NULL);
	lang = _tmp2_;
	_tmp3_ = gtk_label_get_label (lang);
	_tmp4_ = _tmp3_;
	g_signal_emit_by_name (self, "language-selected", _tmp4_);
	_tmp5_ = self->priv->search_entry;
	gtk_entry_set_text ((GtkEntry*) _tmp5_, "");
	gtk_widget_hide ((GtkWidget*) self);
	_g_object_unref0 (lang);
}


static gboolean string_contains (const gchar* self, const gchar* needle) {
	gboolean result = FALSE;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (needle != NULL, FALSE);
	_tmp0_ = needle;
	_tmp1_ = strstr ((gchar*) self, (gchar*) _tmp0_);
	result = _tmp1_ != NULL;
	return result;
}


static gboolean simple_language_picker_row_filter (SimpleLanguagePicker* self, GtkListBoxRow* row) {
	gboolean result = FALSE;
	GtkLabel* label = NULL;
	GtkListBoxRow* _tmp0_ = NULL;
	GtkWidget* _tmp1_ = NULL;
	GtkLabel* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	GtkSearchEntry* _tmp7_ = NULL;
	const gchar* _tmp8_ = NULL;
	const gchar* _tmp9_ = NULL;
	gchar* _tmp10_ = NULL;
	gchar* _tmp11_ = NULL;
	gboolean _tmp12_ = FALSE;
	gboolean _tmp13_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (row != NULL, FALSE);
	_tmp0_ = row;
	_tmp1_ = gtk_bin_get_child ((GtkBin*) _tmp0_);
	_tmp2_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp1_, gtk_label_get_type ()) ? ((GtkLabel*) _tmp1_) : NULL);
	label = _tmp2_;
	_tmp3_ = gtk_label_get_label (label);
	_tmp4_ = _tmp3_;
	_tmp5_ = g_utf8_strdown (_tmp4_, (gssize) (-1));
	_tmp6_ = _tmp5_;
	_tmp7_ = self->priv->search_entry;
	_tmp8_ = gtk_entry_get_text ((GtkEntry*) _tmp7_);
	_tmp9_ = _tmp8_;
	_tmp10_ = g_utf8_strdown (_tmp9_, (gssize) (-1));
	_tmp11_ = _tmp10_;
	_tmp12_ = string_contains (_tmp6_, _tmp11_);
	_tmp13_ = _tmp12_;
	_g_free0 (_tmp11_);
	_g_free0 (_tmp6_);
	result = _tmp13_;
	_g_object_unref0 (label);
	return result;
}


static void simple_language_picker_class_init (SimpleLanguagePickerClass * klass) {
	simple_language_picker_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (SimpleLanguagePickerPrivate));
	G_OBJECT_CLASS (klass)->finalize = simple_language_picker_finalize;
	g_signal_new ("language_selected", TYPE_SIMPLE_LANGUAGE_PICKER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
}


static void simple_language_picker_instance_init (SimpleLanguagePicker * self) {
	self->priv = SIMPLE_LANGUAGE_PICKER_GET_PRIVATE (self);
}


static void simple_language_picker_finalize (GObject* obj) {
	SimpleLanguagePicker * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_SIMPLE_LANGUAGE_PICKER, SimpleLanguagePicker);
	_programming_languages_unref0 (self->priv->plangs);
	_g_object_unref0 (self->priv->scroll);
	_g_object_unref0 (self->priv->lang_box);
	_g_object_unref0 (self->priv->frame);
	_g_object_unref0 (self->priv->search_entry);
	_g_object_unref0 (self->priv->list_view);
	G_OBJECT_CLASS (simple_language_picker_parent_class)->finalize (obj);
}


GType simple_language_picker_get_type (void) {
	static volatile gsize simple_language_picker_type_id__volatile = 0;
	if (g_once_init_enter (&simple_language_picker_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (SimpleLanguagePickerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) simple_language_picker_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (SimpleLanguagePicker), 0, (GInstanceInitFunc) simple_language_picker_instance_init, NULL };
		GType simple_language_picker_type_id;
		simple_language_picker_type_id = g_type_register_static (gtk_popover_get_type (), "SimpleLanguagePicker", &g_define_type_info, 0);
		g_once_init_leave (&simple_language_picker_type_id__volatile, simple_language_picker_type_id);
	}
	return simple_language_picker_type_id__volatile;
}



