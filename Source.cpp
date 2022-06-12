#include <Windows.h>
#include <iostream>
using namespace std;

bool keyDownX = false;
bool keyDownY = false;
double timer = 1;

void menu(bool x, bool y) {
    system("cls");
    cout << "Welcome to ZG's Autoclicker!\nClick X to start and stop. Click Y to toggle between FAST and DEFAULT.\n";
    if (keyDownX == true) {
        cout << "Status: ON" << endl;
    }
    else {
        cout << "Status: OFF" << endl;
    }
    if (keyDownY == false) {
        cout << "Speed: Default" << endl;
    }
    else {
        cout << "Speed: FAST" << endl;
    }

}

int main()
{
    menu(keyDownX, keyDownY);
    while (true) {
        if (GetAsyncKeyState(0x58) & 1) {
            keyDownX = !keyDownX;
            menu(keyDownX, keyDownY);
        }
        if (keyDownX == true) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        if (GetAsyncKeyState(0x59) & 1) {
            keyDownY = !keyDownY;
            menu(keyDownX, keyDownY);
        }
        if (keyDownY == true) {
            timer = 0.1;
        }
        else {
            timer = 1;
        }
        Sleep(timer);
    }
    return 0;
}

