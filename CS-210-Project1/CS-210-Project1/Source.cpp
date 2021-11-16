//PROJECT 1: CHADA TECH CLOCK
//FRED WAHAB
//CS-210

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<cstdlib>
#include <stdio.h>
#include <conio.h>
using namespace std;

//DISPLAY CLOCK FUNCTION
void displayClock(int modHour, int modMinute, int modSecond) {

    //clear screen
    system("CLS");

    int sec_prev = 0;

    //updates time every second.
    while (1) {

        //breaks loop if any key pressed.
        if (_kbhit()) break;

        int seconds, minutes, hours, stdHours;
        string str;

        //storing total seconds
        time_t total_seconds = time(0);

        //getting values of seconds, minutes and hours
        struct tm* ct = localtime(&total_seconds);

        //sets variables to local time + user input.
        seconds = ct->tm_sec + modSecond;
        minutes = ct->tm_min + modMinute;
        hours = ct->tm_hour + modHour;

        //converting it into 12 hour format
        stdHours = hours > 12 ? hours - 12 : hours;
        str = hours > 12 ? "PM" : "AM";

        //printing the result
        if (seconds == sec_prev + 1 || (sec_prev == 59 && seconds == 0)) {
            system("CLS");
            cout << endl;
            cout << endl;
            cout << "**************************     **************************" << endl;
            cout << "*      12-Hour Clock     *     *      24-Hour Clock     *" << endl;
            cout << "*       " << (stdHours < 10 ? "0" : "") << stdHours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << " " << str <<
                "      *     *        " <<
                (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds << "        *" << endl;
            cout << "**************************     **************************" << endl;
            cout << "                     Press any key.                      " << endl;

        }

        sec_prev = seconds;
    }
}

//DISPLAY MENU FUNCTION
void displayMenu() {
    cout << endl;
    cout << "**************************" << endl;
    cout << "* 1-Add One Hour         *" << endl;
    cout << "* 2-Add One Minute       *" << endl;
    cout << "* 3-Add One Second       *" << endl;
    cout << "* 4-Exit Program         *" << endl;
    cout << "**************************" << endl;
    cout << "     Make selection.      " << endl;
    cout << endl;
}

//USER INPUT FUNCTION
int userInput(int& input, int& modHour,int& modMinute,int& modSecond) {
    
    cin >> input;
    while (input < 1 || input > 4 || isdigit(input) != false) {
        cin.clear();
        cin.ignore();
        cout << "Enter only VALID operations: ";
        cin >> input;
    }

    //increases variable based on input.
    switch (input) {
    case 1:
        modHour++;
    case 2:
        modMinute++;
    case 3:
        modSecond++;
    }
    return 0;
}

//MAIN FUNCTION
int main() {
    // declare/initialize user variables.
    int input = 0;
    int modHour = 0, modMinute = 0, modSecond = 0;

    // continue until exit option is selected.
    while (input != 4) {

        // call functions.
        displayClock(modHour, modMinute, modSecond);

        displayMenu();

        userInput(input, modHour, modMinute, modSecond);

    }
    cout << "Goodbye!" << endl;
    return 0;
}

