//IO and GTK files
#include <gtk/gtk.h>
#include <iostream>

//User defined files
#include "audio.h" //Audio input/output
//These can be removed if wanted
#include "shapes.h" //Draws a shape to console

//Linking Winmm for audio playback, for Windows only
//If you run it on linux or macOS, you will need to use a VM for audio playback
#pragma comment(lib, "Winmm.lib")
using namespace std;


//Destroys the window and exits the program
static void destroy()
{
    gtk_main_quit();
}

//Will need to be modularized later
static void keyboard(GtkWidget *Box, GtkWidget *button){
    //Attempting to add 6 buttons to the box
    //Adds C key to box with connector
    static string keyrefC = "C";
    button = gtk_button_new_with_label("C");
    g_signal_connect(button,"clicked", G_CALLBACK(audio), &keyrefC);
    gtk_box_pack_start(GTK_BOX(Box), button, TRUE, TRUE, 0);

    //Adds D key to box with connector
    static string keyrefD = "D";
    button = gtk_button_new_with_label("D");
    g_signal_connect(button,"clicked", G_CALLBACK(audio), &keyrefD);
    gtk_box_pack_start(GTK_BOX(Box), button, TRUE, TRUE, 0);

    //Adds E key to box with connector
    static string keyrefE = "E";
    button = gtk_button_new_with_label("E");
    g_signal_connect(button,"clicked", G_CALLBACK(audio), &keyrefE);
    gtk_box_pack_start(GTK_BOX(Box), button, TRUE, TRUE, 0);

    //Adds F key to box with connector
    static string keyrefF = "F";
    button = gtk_button_new_with_label("F");
    g_signal_connect(button,"clicked", G_CALLBACK(audio), &keyrefF);
    gtk_box_pack_start(GTK_BOX(Box), button, TRUE, TRUE, 0);

    //Adds G key to box with connector
    static string keyrefG = "G";
    button = gtk_button_new_with_label("G");
    g_signal_connect(button,"clicked", G_CALLBACK(audio), &keyrefG);
    gtk_box_pack_start(GTK_BOX(Box), button, TRUE, TRUE, 0);

    //Adds A key to box with connector
    static string keyrefA = "A";
    button = gtk_button_new_with_label("A");
    g_signal_connect(button,"clicked", G_CALLBACK(audio), &keyrefA);
    gtk_box_pack_start(GTK_BOX(Box), button, TRUE, TRUE, 0);

    //Adds B key to box with connector
    static string keyrefB = "B";
    button = gtk_button_new_with_label("B");
    g_signal_connect(button,"clicked", G_CALLBACK(audio), &keyrefB);
    gtk_box_pack_start(GTK_BOX(Box), button, TRUE, TRUE, 0);
}


//Must be called activate due to GTK documentation
//Cannot be removed from main.cpp as it needs to be with main method
static void activate(GApplication *app, gpointer *data){
    //Widgets & Signal Actiavtion (GSimpleAction)
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *Box;

    //Note Activators
    GSimpleAction *act_note0;
    GSimpleAction *act_note1;
    GSimpleAction *act_note2;
    GSimpleAction *act_note3;
    GSimpleAction *act_note4;
    //Shape activators (Remove if not wanted)
    GSimpleAction *diamonds;
    GSimpleAction *triangles;

    //Menubar items
    GMenu *menu_bar;
    GMenu *note_menu;
    //Shape and Image editing menus (Remove if not wanted)
    GMenu *shape_menu;
    GMenu *image_menu;

    //Creates menu items (pitches 0-4, 0 being default), diamond shape
    GMenuItem *menu_item_pitch0;
    GMenuItem *menu_item_pitch1;
    GMenuItem *menu_item_pitch2;
    GMenuItem *menu_item_pitch3;
    GMenuItem *menu_item_pitch4;
    //Shape and Image editing menu items (Remove if not wanted)
    GMenuItem *menu_item_diamond;
    GMenuItem *menu_item_triangle;

    //Menu bar baby
    menu_bar = g_menu_new();

    //Note menu
    note_menu = g_menu_new();
    g_menu_append_submenu(menu_bar, "Note", G_MENU_MODEL(note_menu));

    //Shape menu (Remove if not wanted)
    shape_menu = g_menu_new();
    g_menu_append_submenu(menu_bar, "Shapes", G_MENU_MODEL(shape_menu));

    //Makes the window, sets the title, height, width, and sets destory action on exit
    window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(window), "Toy Piano");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    //Makes actions, THIS IS FOR USE WITH METHOD NAMES!
    act_note0 = g_simple_action_new("note0", nullptr);
    act_note1 = g_simple_action_new("note1", nullptr);
    act_note2 = g_simple_action_new("note2", nullptr);
    act_note3 = g_simple_action_new("note3", nullptr);
    act_note4 = g_simple_action_new("note4", nullptr);
    //Shape activators (Remove if not wanted)
    diamonds = g_simple_action_new("diamond", nullptr);
    triangles = g_simple_action_new("triangle", nullptr);

    //Add each action to actionmap for later use (ie: next line)
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(act_note0));
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(act_note1));
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(act_note2));
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(act_note3));
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(act_note4));
    //Shape activators (Remove if not wanted)
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(diamonds));
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(triangles));

    //Connects the actions to the methods
    g_signal_connect(act_note0, "activate", G_CALLBACK(notes), NULL);
    g_signal_connect(act_note1, "activate", G_CALLBACK(notes), NULL);
    g_signal_connect(act_note2, "activate", G_CALLBACK(notes), NULL);
    g_signal_connect(act_note3, "activate", G_CALLBACK(notes), NULL);
    g_signal_connect(act_note4, "activate", G_CALLBACK(notes), NULL);
    //Shape activators (Remove if not wanted)
    g_signal_connect(diamonds, "activate", G_CALLBACK(diamondshape), NULL);
    g_signal_connect(triangles, "activate", G_CALLBACK(triangleshape), NULL);

    //Create the Note 0 - 4 menu items
    menu_item_pitch0 = g_menu_item_new("Normal Pitch", "app.note0");
    g_menu_append_item(note_menu, menu_item_pitch0);
    menu_item_pitch1 = g_menu_item_new("1st Pitch", "app.note1");
    g_menu_append_item(note_menu, menu_item_pitch1);
    menu_item_pitch2 = g_menu_item_new("2nd Pitch", "app.note2");
    g_menu_append_item(note_menu, menu_item_pitch2);
    menu_item_pitch3 = g_menu_item_new("3rd Pitch", "app.note3");
    g_menu_append_item(note_menu, menu_item_pitch3);
    menu_item_pitch4 = g_menu_item_new("4th Pitch", "app.note4");
    g_menu_append_item(note_menu, menu_item_pitch4);

    //Creates the diamond menu item for shapes (Remove if not wanted)
    menu_item_diamond = g_menu_item_new("Diamond", "app.diamond");
    g_menu_append_item(shape_menu, menu_item_diamond);
    menu_item_triangle = g_menu_item_new("Triangle", "app.triangle");
    g_menu_append_item(shape_menu, menu_item_triangle);

    //Sets the menu bar
    gtk_application_set_menubar(GTK_APPLICATION(app), G_MENU_MODEL(menu_bar));
    gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), TRUE);

    //Makes the box, sets the spacing, and adds it to the window
    Box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(window), Box);

    //Setting the inital pitch
    cout << "Initial pitch has been set to normal" << endl;
    string pitch = "A";
    changepitch(pitch);

    //Adds the buttons to the box via function
    keyboard(Box, button);

    //Shows the window
    gtk_widget_show_all(window);

    gtk_window_present(GTK_WINDOW(window));

}

int main(int argc, char *argv[]){
    //Initialize GTK+
    gtk_init(&argc, &argv);
    GtkApplication *app;
    int status;

    //Creates the application
    app = gtk_application_new("pianokeys.thompsoncpp", G_APPLICATION_DEFAULT_FLAGS);
    //Apprently it must be called by a method called active, damn GTK
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    //Runs the application
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    //Returns any errors
    //If an error returns with 'gtk_main_quit', then it's just the fact that 'X' is undefined in the application,
    //and it insinuates you want to exit the application
    return status;
}