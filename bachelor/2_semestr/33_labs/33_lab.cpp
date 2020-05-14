//g++ `pkg-config --cflags gtk+-3.0` -o 33_lab 33_lab.cpp `pkg-config --libs gtk+-3.0`

#include <iostream>
#include <gtk/gtk.h>
#include <string>
#include <cstdlib>

using namespace std;

class Time
{
    private:
    string time;
    int hours;
    int min;
    int sec;
    public:
    void set_hours(string in_time)
    {
        hours = atoi(in_time.c_str());
        cout << hours << endl;
    }
    void set_min(string in_time)
    {
        min = atoi(in_time.c_str());
        cout << min << endl;
    }
    void set_sec(string in_time)
    {
        sec = atoi(in_time.c_str());
        cout << sec << endl;
    }
};

string in_time;
Time time1;
Time time2;
GtkWidget *entry_time1;
GtkWidget *entry_time2;

static void chek_hours1(GtkWidget *widget, gpointer data)
{
    in_time = gtk_entry_get_text(GTK_ENTRY(entry_time1));
    time1.set_hours(in_time);
}

static void chek_min1(GtkWidget *widget, gpointer data)
{
    in_time = gtk_entry_get_text(GTK_ENTRY(entry_time1));
    time1.set_min(in_time);
}

static void chek_sec1(GtkWidget *widget, gpointer data)
{
    in_time = gtk_entry_get_text(GTK_ENTRY(entry_time1));
    time1.set_sec(in_time);
}

static void chek_hours2(GtkWidget *widget, gpointer data)
{
    in_time = gtk_entry_get_text(GTK_ENTRY(entry_time2));
    time2.set_hours(in_time);
}

static void chek_min2(GtkWidget *widget, gpointer data)
{
    in_time = gtk_entry_get_text(GTK_ENTRY(entry_time2));
    time2.set_min(in_time);
}

static void chek_sec2(GtkWidget *widget, gpointer data)
{
    in_time = gtk_entry_get_text(GTK_ENTRY(entry_time2));
    time2.set_sec(in_time);
}

static void activate (GtkApplication* app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    
    GtkWidget *label;
    
    string in_time1;
    
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "33_lab");
    gtk_window_set_default_size (GTK_WINDOW (window), 159, 350);
    
    grid = gtk_grid_new();
    
    gtk_container_add(GTK_CONTAINER(window), grid);
    
    entry_time1 = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry_time1), "Time 1");
    //get_text(GTK_ENTRY(entry), in_time1);
    
    gtk_grid_attach(GTK_GRID(grid), entry_time1, 0, 0, 1, 1);
    
    button = gtk_button_new_with_label("Ч");
    
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_hours1), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);
    
    button = gtk_button_new_with_label("Мин");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_min1), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);
    
    button = gtk_button_new_with_label("Сек");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_sec1), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);
    
    entry_time2 = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(entry_time2), "Time 2");
    gtk_grid_attach(GTK_GRID(grid), entry_time2, 0, 4, 1, 1);
    
    button = gtk_button_new_with_label("Ч");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_hours2), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 1, 1);
    
    button = gtk_button_new_with_label("Мин");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_min2), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 1, 1);
    
    button = gtk_button_new_with_label("Сек");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_sec2), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 7, 1, 1);
    
    button = gtk_button_new_with_label("-");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 8, 1, 1);
    
    button = gtk_button_new_with_label("+");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 8, 1, 1);
    
    button = gtk_button_new_with_label("Интер");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 9, 1, 1);
    
    button = gtk_button_new_with_label("Пред");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 9, 1, 1);
    
    gchar *str = "Ответ:";
    
    label = gtk_label_new(str);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 10, 1, 1);
    
    button = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    
    gtk_grid_attach(GTK_GRID(grid), button, 0, 11, 1, 1);
    
    gtk_widget_show_all(window);
}

int main (int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

  return status;
}
