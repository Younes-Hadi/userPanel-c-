// Libraries...
#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <fstream>

// Using...
using namespace std;

// Global variables...
int itemsLength = 4;
string itemsName[100] = {"laptop", "computercase", "projector", "broom"};
int itemsCount[100] = {3, 5, 8, 4};
bool fullAccess;
string username;
string borrowedItem = ""; // name of the borrowed item
int itemNum = 0;          // number of borrowed items
int importantNumber;      // number of borrowed item's index

// Functions...
void mainPanel();
void loginPanel();
void moveCursor(int, int);
void toLowerCase(string &);
void navbarPack();
void loginInput();
void actionDoner(string);
void ItemController(string);
void changeItems(string, int);
void viewItem(string &);
void addItem(string &);
void borrowItem(string &);
void repayItem(string &);
void itemsDetail(string, int);
void repayAlarm();
void editItem(int);
void deleteItem(int);
void unknownError(string);
void invalid();
void navigationText(string);
int main()
{
    loginPanel();
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void actionDoner(string act)
{
    string actionMode;
    navbarPack();
    if (fullAccess && act == "borrow item")
    {
        moveCursor(33, 7);
        cout << "This is for student accessibility my friend! ;)";
        Sleep(5000);
        mainPanel();
    }
    else if (!fullAccess && act == "add new item")
    {
        moveCursor(40, 7);
        cout << "Please enter an available action..." << endl;
        Sleep(5000);
        mainPanel();
    }
    else if (act == "1" || act == "home")
        mainPanel();
    else if (act == "2" || act == "items list")
    {
        actionMode = "list";
        ItemController(actionMode);
    }
    else if (act == "3" || act == "classes list")
    {
        cout << "we will add classes list in next update! :)";
        Sleep(3000);
        mainPanel();
    }
    else if (act == "4" || act == "borrow item" || act == "add new item")
    {
        if (fullAccess)
        {
            actionMode = "new";
            ItemController(actionMode);
        }
        else if (!fullAccess)
        {
            actionMode = "borrow";
            ItemController(actionMode);
        }
    }
    else if (act == "5" || act == "contact us")
    {
        system("cls");
        moveCursor(35, 11);
        cout << "Please contact us with youneshadi07@gmail.com, in email!" << endl;
        Sleep(5000);
        mainPanel();
    }
    else
        invalid();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainPanel()
{
    navbarPack();
    moveCursor(40, 7);
    cout << "WELCOME " << username << '!' << endl;
    moveCursor(0, 15);
    cout << "Please enter the action that you want...(You can call the number of navbar items!)" << endl;
    string action;
    getline(cin, action);
    toLowerCase(action);
    navigationText(action);
    actionDoner(action);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loginPanel()
{
    string pass;
    bool valid = false;
    string situation = "login";
    while (!valid)
    {
        loginInput();
        moveCursor(30, 9);
        getline(cin, username);
        toLowerCase(username);
        moveCursor(30, 13);
        getline(cin, pass);
        moveCursor(0, 26);
        if ((username == "admin" || username == "student") && pass == "pass")
        {
            if (username == "admin")
                fullAccess = true;
            else if (username == "student")
                fullAccess = false;
            else
                unknownError(situation);
            valid = true;
            mainPanel();
        }
        else
        {
            system("cls");
            moveCursor(35, 11);
            cout << "Please enter a valid username or password...";
            Sleep(4000);
            loginPanel();
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ItemController(string mode)
{
    string situation = "ItemController";
    repayAlarm();
    moveCursor(7, 7);

    // items list:
    if (mode == "list")
    {
        viewItem(mode);
    } // adding item
    else if (mode == "new" && fullAccess)
    {
        addItem(mode);
    } // borrowing item
    else if (mode == "borrow" && !fullAccess)
    {
        borrowItem(mode);
    }
    else
        unknownError(situation);
    string action;
    getline(cin, action);
    toLowerCase(action);
    navigationText(action);
    for (int i = 0; i < itemsLength; i++)
    {
        if (action == "repay" && !fullAccess)
        { // repay item
            if (itemNum > 0)
            {
                repayItem(mode);
            }
            else
                invalid();
        }
        else if (action == itemsName[i])
        {
            itemsDetail(action, i);
            return;
        }
        else
            continue;
    }
    actionDoner(action);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void changeItems(string action, int index)
{
    if (fullAccess && action == "edit")
    {
        editItem(index);
    }
    else if (fullAccess && action == "delete")
        deleteItem(index);
    else
        invalid();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void viewItem(string &mode)
{
    int j = 0;

    cout << "The items that we have right now are:" << endl
         << endl;
    for (int i = 0; i < itemsLength; i++)
    {
        cout << "     *" << itemsName[i] << " in count of " << itemsCount[i] << '.' << endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void addItem(string &mode)
{
    int a = itemsLength;
    string unCheckedVlaue;
    cout << "Please enter name of the item that you want to add, then enter count of it..." << endl;
    getline(cin, unCheckedVlaue);
    toLowerCase(unCheckedVlaue);
    navigationText(unCheckedVlaue);
    itemsName[a] = unCheckedVlaue;
    unCheckedVlaue = "";
    cin >> itemsCount[a];
    cin.ignore();
    cout << itemsName[a] << " in count of " << itemsCount[a] << ", added to the items list successfully!" << endl;
    itemsLength += 1;
    Sleep(4000);
    mainPanel();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borrowItem(string &mode)
{
    bool loop = true;
    string lastName = borrowedItem;
    string situation = "borrowItem";
    while (loop)
    {
        if (borrowedItem == "")
        {
            cout << "       Please enter the name of the item that you want to borrow, then enter count of it..." << endl;
            getline(cin, borrowedItem);
            toLowerCase(borrowedItem);
            navigationText(borrowedItem);
            if (borrowedItem == "repay")
            {
                borrowedItem = lastName;
                repayItem(mode);
            }
            else
            {
                for (int i = 0; i < itemsLength; i++)
                {
                    if (itemsName[i] == borrowedItem)
                    {
                        importantNumber = i;
                        break;
                    }
                    else if (i == itemsLength - 1 && itemsName[itemsLength - 1] != borrowedItem)
                    {
                        system("cls");
                        moveCursor(35, 11);
                        cout << "Please enter an item from the item's list..." << endl;
                        borrowedItem = lastName;
                        Sleep(4000);
                        system("cls");
                        ItemController(mode);
                    }
                }
                int itemNumFake;
                cin >> itemNumFake;
                cin.ignore();
                if (itemNumFake > 3 || itemNum + itemNumFake > 3)
                {
                    system("cls");
                    moveCursor(35, 11);
                    cout << "The maximum number of borrowing is 3!" << endl;
                    borrowedItem = lastName;
                    itemNumFake = 0;
                    Sleep(4000);
                    continue;
                }
                else if (itemNumFake < 1)
                {
                    system("cls");
                    moveCursor(35, 11);
                    cout << "The minimum number of borrowing is 1!" << endl;
                    borrowedItem = lastName;
                    itemNumFake = 0;
                    Sleep(4000);
                    continue;
                }
                else if (itemNumFake > itemsCount[importantNumber])
                {

                    system("cls");
                    moveCursor(35, 11);
                    cout << "You asked for " << itemNumFake << " " << borrowedItem << ((itemNum > 1) ? 's' : ' ') << ", that is more than what we have currently..." << endl;
                    itemNumFake = 0;
                    borrowedItem = lastName;
                    Sleep(4000);
                    continue;
                }
                else
                {
                    itemsCount[importantNumber] -= itemNumFake;
                    itemNum += itemNumFake;
                    cout << itemNumFake << ' ' << itemsName[importantNumber] << ((itemNumFake > 1) ? 's' : ' ') << " borrowed successfully!" << endl;
                    Sleep(4000);
                    loop = false;
                    mainPanel();
                }
            }
        }
        else if (itemNum != 0)
        {
            cout << endl
                 << "       " << "Please repay the last item" << ((itemNum > 1) ? "s " : " ") << "to be able to borrow another item." << endl;
            Sleep(4000);
            loop = false;
        }
        else
            unknownError(situation);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void repayItem(string &mode)
{
    system("cls");
    moveCursor(30, 10);
    cout << "The borrowed item" << (itemNum > 1 ? "s are " : " is ") << borrowedItem << " in count of " << itemNum << ".";
    moveCursor(20, 11);
    cout << "Please type the name and number of the items that you want to repay..." << endl
         << endl;
    string repayOption;
    int repayNum;
    getline(cin, repayOption);
    toLowerCase(repayOption);
    navigationText(repayOption);
    if (repayOption != borrowedItem)
    {
        cout << "Please enter an option from the item" << (itemNum > 1 ? "s" : "") << " that you have borrowed..." << endl;
        Sleep(3000);
        mainPanel();
    }
    else if (repayOption == borrowedItem)
    {
        cin >> repayNum;
        cin.ignore();
        if (repayNum > 0 && repayNum <= itemNum)
        {
            itemNum -= repayNum;
            itemsCount[importantNumber] += repayNum;
            cout << repayNum << " " << repayOption << (repayNum > 1 ? "s" : "") << " repayed successfully!" << endl;
            if (itemNum == 0)
            {
                borrowedItem = "";
            }
            Sleep(4000);
            mainPanel();
        }
        else
        {
            repayNum = 0;
            repayOption = "";
            invalid();
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void itemsDetail(string name, int index)
{
    string action;
    system("cls");
    moveCursor(10, 5);
    cout << setw(3) << "< " << name << endl;
    for (int i = 1; i <= 40; i++)
    {

        if (i == 40)
            cout << endl
                 << endl;
        else if (i == 1)
            cout << setw(7) << "\t_";
        else
            cout << "_";
    }
    cout << setw(7) << "\t" << "> in count of " << itemsCount[index] << endl;
    if (itemNum > 0 && name == borrowedItem)
    {
        moveCursor(0, 10);
        for (int i = 0; i < 4; i++)
        {
            cout << "\t\t\b";
            if (i == 0)
                cout << " _________________________________ " << endl;
            else if (i == 1)
                cout << "| " << " \t\t\t\t " << "|" << endl;
            else if (i == 2)
                cout << "|_________________________________|" << endl;
            if (i == 3)
            {
                moveCursor(17, 11);
                cout << itemNum << " of " << borrowedItem << "s are borrowed." << endl
                     << endl
                     << endl;
            }
        }
    }
    if (fullAccess)
    {
        moveCursor(17, 19);
        cout << "_____________________________";
        moveCursor(20, 20);
        cout << "EDIT" << "      |      " << "DELETE" << endl;
    }
    getline(cin, action);
    toLowerCase(action);
    navigationText(action);
    if (action == "edit" || action == "delete")
    {
        changeItems(action, index);
    }
    else if (action != "edit" || action != "delete")
        actionDoner(action);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteItem(int index)
{
    system("cls");
    moveCursor(35, 11);
    cout << "We will try to add this option in the next updates..." << endl;
    Sleep(4000);
    mainPanel();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void editItem(int index)
{
    int newNumber;
    cout << "Tell use what change you want to make..." << endl;
    cout << "Change number of " << itemsName[index] << ((itemNum + itemsCount[index] > 1) ? 's' : ' ') << " from " << itemNum + itemsCount[index] << " to..." << endl;
    cin >> newNumber;
    cin.ignore();
    string situation = "edit";
    if (borrowedItem == itemsName[index] && newNumber < itemNum)
    {
        cout << "Currently, you are not able to change the " << itemsName[index] << "'s count to " << newNumber << endl;
        Sleep(3000);
        mainPanel();
    }
    else if (newNumber >= itemNum && newNumber > 0)
    {
        itemsCount[index] = newNumber - itemNum;
        cout << "\t" << itemsName[index] << " count changed to " << itemsCount[index] + itemNum << " successfully!" << endl;
        newNumber = 0;
        Sleep(4000);
        mainPanel();
        return;
    }
    else
        unknownError(situation);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void unknownError(string situation)
{
    system("cls");
    moveCursor(35, 11);
    cout << "An unknown error caused in " << situation << "  checking, please try again later..." << endl;
    Sleep(4000);
    mainPanel();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void invalid()
{
    system("cls");
    moveCursor(35, 11);
    cout << "Please enter a valid action..." << endl;
    Sleep(3000);
    mainPanel();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void repayAlarm()
{
    if (itemNum > 0 && !fullAccess)
    {
        for (int i = 1, l = 3; i < 4; i++, l++)
        {
            moveCursor(10, l);
            cout << ((i == 1) ? " _________________________ " : (i == 2) ? "|                         |"
                                                            : (i == 3)   ? "|_________________________|"
                                                                         : "An error caused!!!")
                 << endl;
        }
        for (int i = 1, l = 3; i < 4; i++, l++)
        {
            moveCursor(50, l);
            cout << ((i == 1) ? " _______ " : (i == 2) ? "|       |"
                                          : (i == 3)   ? "|_______|"
                                                       : "An error caused!!!")
                 << endl;
        }
        moveCursor(11, 4);
        cout << "You have borrowed " << itemNum << " items";
        moveCursor(51, 4);
        cout << "!Repay!";
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void navbarPack()
{
    string navbar[6] = {"Home", "Items list", "classes list", "Add new item", "Borrow item", "contact us"};
    system("cls");
    moveCursor(0, 0);
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
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void toLowerCase(string &text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
            text[i] = tolower(text[i]);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void navigationText(string text)
{
    if (text == "exit")
    {
        system("cls");
        exit(0);
    }
    else if (text == "logout")
        loginPanel();
    else if (text == "back")
    {
        text = "";
        mainPanel();
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void moveCursor(int x, int y)
{
    COORD position;

    position.X = x;
    position.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loginInput()
{
    system("cls");
    moveCursor(0, 2);
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
}