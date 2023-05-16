#include <iostream>
#include <string>
#include <windows.h>
// #include<graphics.h>
#include <conio.h>
#include <math.h>
#include "Base.h"
#include "Data.h"
using namespace std;

void loadingScreen(int duration)
{

    system("color F4");
    cout << "Loading...\n";
    for (int i = 0; i <= 100; i += 10)
    {
        cout << "[" << i << "%]";
        Sleep(duration);
        cout << "\r"; // move the cursor back to the beginning of the line
    }
    cout << "Done!\n";
}

int main()
{
    loadingScreen(500); // duration in milliseconds

    Base s;
    system("Color B0");

    s.menu();
    // system("pause");
}
