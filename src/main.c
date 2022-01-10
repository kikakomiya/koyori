#include <stdlib.h>
#include <gio/gio.h>
#include <gtk/gtk.h>

#include "about_window.h"

void exit_app() {
    exit(0);
}

void action_callback(GSimpleAction* simple_action, G_GNUC_UNUSED GVariant* parameter, G_GNUC_UNUSED gpointer* data) {
    g_print("Action %s clicked.\n", g_action_get_name(G_ACTION(simple_action)));
}

void activate(GApplication* app, G_GNUC_UNUSED gpointer* data) {
    GtkWidget* window;
    GSimpleAction* exit_action;
    GSimpleAction* about_action;

    GMenu* menu_bar;
    GMenu* file_menu;
    GMenu* help_menu;

    GMenuItem* menu_item_exit;
    GMenuItem* menu_item_about;

    menu_bar = g_menu_new();

    file_menu = g_menu_new();
    g_menu_append_submenu(menu_bar, "File", G_MENU_MODEL(file_menu));

    help_menu = g_menu_new();
    g_menu_append_submenu(menu_bar, "Help", G_MENU_MODEL(help_menu));

    window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(window), "Koyori");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    exit_action = g_simple_action_new("Exit", NULL);
    about_action = g_simple_action_new("About", NULL);

    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(exit_action));
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(about_action));

    g_signal_connect(exit_action, "activate", G_CALLBACK(exit_app), NULL);
    g_signal_connect(about_action, "activate", G_CALLBACK(create_about_window), NULL);

    menu_item_exit = g_menu_item_new("Exit", "app.Exit");
    g_menu_append_item(file_menu, menu_item_exit);

    menu_item_about = g_menu_item_new("About", "app.About");
    g_menu_append_item(help_menu, menu_item_about);

    gtk_application_set_menubar(GTK_APPLICATION(app), G_MENU_MODEL(menu_bar));
    gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), TRUE);

    gtk_window_present(GTK_WINDOW(window));

    g_object_unref(exit_action);
    g_object_unref(about_action);
    g_object_unref(menu_item_exit);
    g_object_unref(menu_item_about);
    g_object_unref(file_menu);
    g_object_unref(help_menu);
    g_object_unref(menu_bar);
}

int main(int argc, char** argv) {
    GtkApplication* app;
    int status;

    app = gtk_application_new("dev.vkcrose.koyori", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}