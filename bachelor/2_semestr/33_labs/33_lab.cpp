//g++ `pkg-config --cflags gtk+-3.0` -o 33_lab 33_lab.cpp `pkg-config --libs gtk+-3.0`

#include <iostream>
#include <gtk/gtk.h>
#include <string>
#include <cstdlib>

using namespace std;

int all_sec, conver_sec;
int all_hours = 0;
int all_min = 0;
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
        cout << hours << " hours" << endl;
    }
    void set_min(string in_time)
    {
        min = atoi(in_time.c_str());
        cout << min << " min" << endl;
    }
    void set_sec(string in_time)
    {
        sec = atoi(in_time.c_str());
        cout << sec << " sec" << endl;
    }
    void minus(Time &in_time_two)
    {
        int all_sec_one = 0; 
        int all_sec_two = 0;
        all_sec = 0;
        all_min = 0;
        all_hours = 0;
        all_sec_one = hours * 3600 + min * 60 + sec;
        all_sec_two = in_time_two.hours * 3600 + in_time_two.min * 60 + in_time_two.sec;
        all_sec = all_sec_one - all_sec_two;
        
        while(all_sec >= 60)
        {
            all_min++;
            all_sec = all_sec - 60;
        }
        while(all_min >= 60)
        {
            all_hours++;
            all_min = all_min - 60;
        }
        cout << all_hours << " hours " << all_min << " min " << all_sec << " sec " << endl;
    }
    void plus(Time &in_time_two)
    {
        int all_sec_one = 0; 
        int all_sec_two = 0;
        all_sec = 0;
        all_min = 0;
        all_hours = 0;
        all_sec_one = hours * 3600 + min * 60 + sec;
        all_sec_two = in_time_two.hours * 3600 + in_time_two.min * 60 + in_time_two.sec;
        all_sec = all_sec_one + all_sec_two;
        
        while(all_sec >= 60)
        {
            all_min++;
            all_sec = all_sec - 60;
        }
        while(all_min >= 60)
        {
            all_hours++;
            all_min = all_min - 60;
        }
        cout << all_hours << " hours " << all_min << " min " << all_sec << " sec " << endl;
    }
    void time_inter(Time &in_time_two)
    {
        int all_sec_one = 0; 
        int all_sec_two = 0;
        all_sec = 0;
        all_min = 0;
        all_hours = 0;
        all_sec_one = hours * 3600 + min * 60 + sec;
        all_sec_two = in_time_two.hours * 3600 + in_time_two.min * 60 + in_time_two.sec;
        all_sec = all_sec_two - all_sec_one;
        conver_sec = all_sec;
        while(all_sec >= 60)
        {
            all_min++;
            all_sec = all_sec - 60;
        }
        while(all_min >= 60)
        {
            all_hours++;
            all_min = all_min - 60;
        }
        cout << all_hours << " hours " << all_min << " min " << all_sec << " sec " << endl;
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

static void chek_minus(GtkWidget *widget, gpointer data)
{
    time1.minus(time2);
}

static void chek_plus(GtkWidget *widget, gpointer data)
{
    time1.plus(time2);
}

static void chek_inter(GtkWidget *widget, gpointer data)
{
    time1.time_inter(time2);
}

static void chek_conver(GtkWidget *widget, gpointer data)
{
    cout << conver_sec << " sec ";
    int conver_min   = 0;
    int conver_hours = 0;
    while(conver_sec >= 60)
    {
        conver_min++;
        conver_sec = conver_sec - 60;
    }
    cout << conver_min << " min ";
    while(conver_min >= 60)
    {
        conver_hours++;
        conver_min = conver_min - 60;
    }
    cout << conver_hours << " hours " << endl;
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
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_minus), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 8, 1, 1);
    
    button = gtk_button_new_with_label("+");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_plus), window);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 8, 1, 1);
    
    button = gtk_button_new_with_label("Интер");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_inter), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 9, 1, 1);
    
    button = gtk_button_new_with_label("Преобр");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(chek_conver), window);
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
