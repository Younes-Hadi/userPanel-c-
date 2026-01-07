#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include <cstdlib>

using namespace std;

void mainPanel(string);
void loginPanel();
void moveCursor(int, int);
void actionDoner(string, string, bool);
int main()
{
    system("cls");
    moveCursor(0, 0);
    loginPanel();
    return 0;
}

void actionDoner(string act, string username, bool full)
{
    system("cls");
    moveCursor(0, 0);
    bool fullAccess = full;
    username == "admin" ? fullAccess = true : username == "student" ? fullAccess = false
                                                                    : fullAccess;

    string navbar[] = {"Home", "Items list", "classes list", "Add new item", "Borrow item", "contact us"};
    for (int i = 0; i < 6; i++)
    {
        (fullAccess && i == 3) ? (cout << "   |   " << navbar[i]) : (!fullAccess && i == 4) ? (cout << "   |   " << navbar[i])
                                                                : (i < 3 || i == 5)         ? cout << "   |   " << navbar[i]
                                                                                            : cout << "";
        if (i == (sizeof(navbar) / sizeof(navbar[0])) - 1)
        {
            cout << "   |" << endl;
        }
    }
    if (fullAccess && act == "borrow item")
    {
        moveCursor(33, 7);
        cout << "This is for student accessibility my friend! ;)";
        Sleep(5000);
        mainPanel(username);
    }
    else if (!fullAccess && act == "add new item")
    {
        moveCursor(40, 7);
        cout << "Please enter an available action..." << endl;
        Sleep(5000);
        mainPanel(username);
    }
    else if (act == "1" || act == "home")
        mainPanel(username);
    else if (act == "2" || act == "Items list")
        cout << "we will add Items list in next update! :)";
    else if (act == "3" || act == "classes list")
        cout << "we will add classes list in next update! :)";
    else if (act == "4")
        cout << "we will add " << ((fullAccess) ? "Add new item" : "Borrow item") << "in next update! :)";
    else if (act == "5")
        cout << "we will add contact us in the next update! ;)";
    else if (act == "logout")
        main();
}

void mainPanel(string username)
{
    system("cls");
    moveCursor(0, 0);
    bool fullAccess;
    username == "admin" ? fullAccess = true : username == "student" ? fullAccess = false
                                                                    : fullAccess;

    string navbar[] = {"Home", "Items list", "classes list", "Add new item", "Borrow item", "contact us"};
    for (int i = 0; i < 6; i++)
    {
        (fullAccess && i == 3) ? (cout << "   |   " << navbar[i]) : (!fullAccess && i == 4) ? (cout << "   |   " << navbar[i])
                                                                : (i < 3 || i == 5)         ? cout << "   |   " << navbar[i]
                                                                                            : cout << "";
        if (i == (sizeof(navbar) / sizeof(navbar[0])) - 1)
        {
            cout << "   |" << endl;
        }
    }
    moveCursor(50, 7);
    cout << "WELCOME " << username << '!' << endl;
    moveCursor(0, 15);
    cout << "Please enter the action that you want...(You can call the number of navbar item!)" << endl;
    string action;
    getline(cin, action);
    if (action == "exit")
    {
        system("cls");
        exit(0);
    }
    for (int i = 0; i < action.length(); i++)
    {
        if (action[i] != ' ')
            action[i] = tolower(action[i]);
    }
    actionDoner(action, username, fullAccess);
}

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
            else if (i == 5)
                cout << "                   |      Please enter your username       |                    " << endl;
            else if (i == 9)
                cout << "                   |      Please enter your password       |                    " << endl;
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
        getline(cin, user);
        if (user == "exit" || pass == "exit")
        {
            system("cls");
            exit(0);
        }
        moveCursor(30, 13);
        getline(cin, pass);
        if (pass == "exit")
        {
            system("cls");
            exit(0);
        }

        moveCursor(0, 26);
        for (int i = 0; i < user.length(); i++)
        {
            user[i] = tolower(user[i]);
        }
        for (int i = 0; i < pass.length(); i++)
        {
            pass[i] = tolower(pass[i]);
        }

        if ((user == "admin" || user == "student") && pass == "pass")
        {
            valid = true;
            mainPanel(user);
        }
        else
        {
            system("cls");
            moveCursor(35, 11);
            cout << "Please enter a valid username or password...";
            Sleep(4000);
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