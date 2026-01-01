#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

// int welcomePanel();
void loginPanel();
void buttonControl(string);
void moveCursor(int, int);
int main()
{
    system("cls");
    moveCursor(0, 0);
    loginPanel();
    return 0;
}

// int welcomePanel(){

// }

void loginPanel()
{

    string user, pass;
    bool valid = false;

    while (!valid)
    {
        system("cls");
        moveCursor(0, 0);
        cout << endl
             << endl;
        for (int i = 0; i <= 21; i++)
        {
            if (i == 0 || i == 21)
            {
                cout << "                    ---------------------------------------                    " << endl;
            }
            else if (i == 3)
            {
                cout << "                   |                WELCOME                |                    " << endl;
            }
            else if (i == 6 || i == 10 || i == 14)
            {
                cout << "                   |       _________________________       |                    " << endl;
            }
            else if (i == 7 || i == 11)
            {
                cout << "                   |      |                         |      |                    " << endl;
            }
            else if (i == 8 || i == 12)
            {
                cout << "                   |      |_________________________|      |                    " << endl;
            }
            else if (i == 15)
            {
                cout << "                   |      (_________SUBMIT__________)      |                    " << endl;
            }
            else
            {
                cout << "                   |                                       |                    " << endl;
            }
        }

        moveCursor(30, 9);
        cin >> user;

        moveCursor(30, 13);
        cin >> pass;

        moveCursor(0, 26);

        if (user == "name" && pass == "word")
        {
            valid = true;
            cout << "right";
        }
    }
}

void moveCursor(int x, int y)
{
    COORD position;

    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}