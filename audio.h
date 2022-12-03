#include <gtk/gtk.h>
#include <iostream>
#include <utility>
#include <windows.h>
using namespace std;

#ifndef CPPPROJECT_AUDIO_H
#define CPPPROJECT_AUDIO_H

//Global variable for pitch
//will change how the notes sound
string mainpitch;

//Meant to change the pitch from main.cpp
void changepitch(string pitch){
    mainpitch = std::move(pitch);
}

//All of these are disgustingly coded, I like it
void pitchA(HANDLE consolecolor, string keypress);
void pitchB(HANDLE consolecolor, string keypress);
void pitchC(HANDLE consolecolor, string keypress);
void pitchD(HANDLE consolecolor, string keypress);
void pitchE(HANDLE consolecolor, string keypress);

//This files sole purpose is to play audio files
//The main part takes in a widget that is a button and gpointer data
//The gpointer data is a pointer to a char that is the key that is pressed
//The function then plays the audio file that corresponds to the key
//The audio files are stored in the same directory as the executable
//The button pressed is outputted to console alongside being colored (Windows only, supposedly)
void audio(GtkWidget *widget, gpointer data){
    //Changing color of the terminal
    HANDLE consolecolor = GetStdHandle(STD_OUTPUT_HANDLE);
    //Grabs the data and re-converts it to string
    string keypress = *(static_cast<string*>(data));

    //THIS WORKS, WHY? IT TOOK THREE HOURS TO FIGURE OUT
    if(mainpitch == "A"){
        pitchA(consolecolor, keypress);
    } else if (mainpitch == "B"){
        pitchB(consolecolor, keypress);
    } else if (mainpitch == "C"){
        pitchC(consolecolor, keypress);
    } else if (mainpitch == "D"){
        pitchD(consolecolor, keypress);
    } else if (mainpitch == "E"){
        pitchE(consolecolor, keypress);
    }
}

//Changes the pitch based on what each note action is from main.cpp
static void notes (GSimpleAction *simple_action, G_GNUC_UNUSED GVariant *parameter, G_GNUC_UNUSED gpointer *data) {
    //This will check the name of each, and assign the pitch based on that
    //This is to change the pitch of the note
    string pitch = (g_action_get_name (G_ACTION (simple_action)));

    //Setting console colors on pitch call
    HANDLE consolecolor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consolecolor, 15);
    if(pitch == "note0"){
        cout << "Pitch shifted back to normal" << endl;
        mainpitch = "A";
    }else if(pitch == "note1"){
        cout << "Pitch shifted up by 1" << endl;
        mainpitch = "B";
    } else if(pitch == "note2"){
        cout << "Pitch shifted up by 2" << endl;
        mainpitch = "C";
    } else if(pitch == "note3"){
        cout << "Pitch shifted up by 3" << endl;
        mainpitch = "D";
    }else if(pitch == "note4"){
        cout << "Pitch shifted up by 4" << endl;
        mainpitch = "E";
    }

}

//These next few functions are all similar with some minor changes, due to the way that GTK
//works, I had to make a function for each pitch, and then call the function based on the pitch
//I had attempted alternate ways to get this to work, and in each it would just randomly call a note

//Sets the pitch for inital / A, uses files with 0 in name
void pitchA(HANDLE consolecolor, string keypress){
    if(keypress[0] == 'C') {
        PlaySound(TEXT("pianokeys\\C0.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 10);
        cout << "Key C Pressed" << endl;
    }else if(keypress[0] == 'D') {
        PlaySound(TEXT("pianokeys\\D0.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 11);
        cout << "Key D Pressed" << endl;
    }else if(keypress[0] == 'E') {
        PlaySound(TEXT("pianokeys\\E0.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 12);
        cout << "Key E Pressed" << endl;
    }else if(keypress[0] == 'F') {
        PlaySound(TEXT("pianokeys\\F0.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 13);
        cout << "Key F Pressed" << endl;
    }else if(keypress[0] == 'G') {
        PlaySound(TEXT("pianokeys\\G0.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 14);
        cout << "Key G Pressed" << endl;
    }else if(keypress[0] == 'A') {
        PlaySound(TEXT("pianokeys\\A0.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,15);
        cout << "Key A Pressed" << endl;
    }else if(keypress[0] == 'B') {
        PlaySound(TEXT("pianokeys\\B0.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,16);
        cout << "Key B Pressed" << endl;
    }
}

//Sets the pitch for B, uses files with 1 in name
void pitchB(HANDLE consolecolor, string keypress){
    if(keypress[0] == 'C') {
        PlaySound(TEXT("pianokeys\\C1.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 10);
        cout << "Key C Pressed" << endl;
    }else if(keypress[0] == 'D') {
        PlaySound(TEXT("pianokeys\\D1.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 11);
        cout << "Key D Pressed" << endl;
    }else if(keypress[0] == 'E') {
        PlaySound(TEXT("pianokeys\\E1.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 12);
        cout << "Key E Pressed" << endl;
    }else if(keypress[0] == 'F') {
        PlaySound(TEXT("pianokeys\\F1.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 13);
        cout << "Key F Pressed" << endl;
    }else if(keypress[0] == 'G') {
        PlaySound(TEXT("pianokeys\\G1.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 14);
        cout << "Key G Pressed" << endl;
    }else if(keypress[0] == 'A') {
        PlaySound(TEXT("pianokeys\\A1.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,15);
        cout << "Key A Pressed" << endl;
    }else if(keypress[0] == 'B') {
        PlaySound(TEXT("pianokeys\\B1.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,16);
        cout << "Key B Pressed" << endl;
    }
}

//Sets the pitch for C, uses files with 2 in name
void pitchC(HANDLE consolecolor, string keypress){
    if(keypress[0] == 'C') {
        PlaySound(TEXT("pianokeys\\C2.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 10);
        cout << "Key C Pressed" << endl;
    }else if(keypress[0] == 'D') {
        PlaySound(TEXT("pianokeys\\D2.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 11);
        cout << "Key D Pressed" << endl;
    }else if(keypress[0] == 'E') {
        PlaySound(TEXT("pianokeys\\E2.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 12);
        cout << "Key E Pressed" << endl;
    }else if(keypress[0] == 'F') {
        PlaySound(TEXT("pianokeys\\F2.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 13);
        cout << "Key F Pressed" << endl;
    }else if(keypress[0] == 'G') {
        PlaySound(TEXT("pianokeys\\G2.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 14);
        cout << "Key G Pressed" << endl;
    }else if(keypress[0] == 'A') {
        PlaySound(TEXT("pianokeys\\A2.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,15);
        cout << "Key A Pressed" << endl;
    }else if(keypress[0] == 'B') {
        PlaySound(TEXT("pianokeys\\B2.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,16);
        cout << "Key B Pressed" << endl;
    }
}

//Sets the pitch for D, uses files with 3 in name
void pitchD(HANDLE consolecolor, string keypress){
    if(keypress[0] == 'C') {
        PlaySound(TEXT("pianokeys\\C3.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 10);
        cout << "Key C Pressed" << endl;
    }else if(keypress[0] == 'D') {
        PlaySound(TEXT("pianokeys\\D3.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 11);
        cout << "Key D Pressed" << endl;
    }else if(keypress[0] == 'E') {
        PlaySound(TEXT("pianokeys\\E3.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 12);
        cout << "Key E Pressed" << endl;
    }else if(keypress[0] == 'F') {
        PlaySound(TEXT("pianokeys\\F3.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 13);
        cout << "Key F Pressed" << endl;
    }else if(keypress[0] == 'G') {
        PlaySound(TEXT("pianokeys\\G3.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 14);
        cout << "Key G Pressed" << endl;
    }else if(keypress[0] == 'A') {
        PlaySound(TEXT("pianokeys\\A3.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,15);
        cout << "Key A Pressed" << endl;
    }else if(keypress[0] == 'B') {
        PlaySound(TEXT("pianokeys\\B3.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,16);
        cout << "Key B Pressed" << endl;
    }
}

//Sets the pitch for E, uses files with 4 in name
void pitchE(HANDLE consolecolor, string keypress){
    if(keypress[0] == 'C') {
        PlaySound(TEXT("pianokeys\\C4.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 10);
        cout << "Key C Pressed" << endl;
    }else if(keypress[0] == 'D') {
        PlaySound(TEXT("pianokeys\\D4.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 11);
        cout << "Key D Pressed" << endl;
    }else if(keypress[0] == 'E') {
        PlaySound(TEXT("pianokeys\\E4.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 12);
        cout << "Key E Pressed" << endl;
    }else if(keypress[0] == 'F') {
        PlaySound(TEXT("pianokeys\\F4.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 13);
        cout << "Key F Pressed" << endl;
    }else if(keypress[0] == 'G') {
        PlaySound(TEXT("pianokeys\\G4.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor, 14);
        cout << "Key G Pressed" << endl;
    }else if(keypress[0] == 'A') {
        PlaySound(TEXT("pianokeys\\A4.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,15);
        cout << "Key A Pressed" << endl;
    }else if(keypress[0] == 'B') {
        PlaySound(TEXT("pianokeys\\B4.wav"), nullptr, SND_FILENAME | SND_ASYNC);
        SetConsoleTextAttribute(consolecolor,16);
        cout << "Key B Pressed" << endl;
    }
}

#endif //CPPPROJECT_AUDIO_H
