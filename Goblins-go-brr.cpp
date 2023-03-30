// Goblins-go-brr.cpp : Defines the entry point for the application

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "wtypes.h"
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int waitTime = 60000;
int waitTimeInSec = waitTime / 1000;

// Get the horizontal and vertical screen sizes in pixel
void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;
    // Get desktop window handler
    const HWND hDesktop = GetDesktopWindow();
    // Get screen size
    GetWindowRect(hDesktop, &desktop);
    // The top left cordinates are (0,0)
    // bottom right cordinates are (horizontal, vertical)
    horizontal = desktop.right;
    vertical = desktop.bottom;
}

int main() {
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStd, 12); //Bright red
    cout << "</> ";
    SetConsoleTextAttribute(hStd, 7); //Default White
    cout << "with love by ";
    SetConsoleTextAttribute(hStd, 11); //Bright cyan
    cout << "@alessiotorraco";
    SetConsoleTextAttribute(hStd, 7);
    cout << "\nVist ";
    SetConsoleTextAttribute(hStd, 9); //Bright blue
    cout << "https://github.com/alessiotorraco\n";
    SetConsoleTextAttribute(hStd, 7);
    cout << "\nScript Started!" << " " << "The cursor will automatically move every " << waitTime << "ms (" << waitTimeInSec << " seconds).";

    int horizontal = 1920;
    int vertical = 1080;
    GetDesktopResolution(horizontal, vertical);
    int start = 0;
    while (1 == 1) {
        cout << "\nPress ";
        SetConsoleTextAttribute(hStd, 15);
        cout << "Ctrl + C";
        SetConsoleTextAttribute(hStd, 7);
        cout << " to stop the script!\n";
        while (1 == 1) {
            int rangeh = 1 - vertical + 1;
            int h = rand() % rangeh + 10;

            int rangew = 1 - horizontal + 1;
            int w = rand() % rangew + 10;
            if (start == 0) {
                start = 1;
            }
            else {
                SetCursorPos(w, h);
            }
            this_thread::sleep_for(chrono::milliseconds(waitTime));
        }
    }
}