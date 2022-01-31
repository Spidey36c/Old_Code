#include <windows.h>
#include <iostream>
using std::cout;
using std::endl;

void main()
{
    HANDLE hStdout = nullptr;
    COORD cursor;

    cursor.X = 15;
    cursor.Y = 5;

    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdout, cursor);
    SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

    cout << "This is a test" << endl;
    
    cursor.X = 30;
    cursor.Y = 20;

    SetConsoleCursorPosition(hStdout, cursor);
    SetConsoleTextAttribute(hStdout, BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    
    char topLeftCorner = static_cast<char>(201);
    char bottomLeft = static_cast<char>(200);
    char topRight = static_cast<char>(187);
    char bottomRight = static_cast<char>(188);
    char horizontal = static_cast<char>(205);
    char vertical = static_cast<char>(186);
    
    cout << topLeftCorner;
    for (int i = 0; i < 12; i++)
        cout << horizontal;
    cout << topRight;
    cursor.X = 30;
    cursor.Y = 21;
    SetConsoleCursorPosition(hStdout, cursor);
    cout << vertical << "  H E L L O " << vertical;
    cursor.X = 30;
    cursor.Y = 22;
    SetConsoleCursorPosition(hStdout, cursor);
    cout << bottomLeft;
    for (int i = 0; i < 12; i++)
        cout << horizontal;
    cout << bottomRight << endl;

    cursor.X = 20;
    cursor.Y = 0;
    SetConsoleCursorPosition(hStdout, cursor);
    SetConsoleTextAttribute(hStdout, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY );
    cout << "Back to Top     " << static_cast<char>(3) 
        << static_cast<char>(4) << static_cast<char>(5) 
        << static_cast<char>(6) << endl;
}