#include "about_window.h"

void create_about_window() {
    GtkWidget* about_window;
    GtkWidget* about_window_box;
    GtkWidget* about_window_logo;
    GtkWidget* about_window_text;

    about_window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(about_window), "About");
    gtk_window_set_default_size(GTK_WINDOW(about_window), 400, 200);

    about_window_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 30);
    about_window_text = gtk_label_new("Koyori");
    gtk_box_append(GTK_BOX(about_window_box), about_window_text);

    about_window_logo = gtk_image_new_from_file("resources/logo.jpg");
    gtk_box_append(GTK_BOX(about_window_box), about_window_logo);

    gtk_window_set_child(GTK_WINDOW(about_window), about_window_box);
    
    gtk_widget_show(about_window);
}