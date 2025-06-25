#include <iostream>
#include"project.h"
#include <fstream>
#include <string>
#include<string.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

//global function for waiting when login meet
void waiting()
{
    for (int i = 0; i < 10; i++)
    {
        Sleep(200);
        cout << "..";
    }
}

//class user function start here

//constructor
user::user()
{
    name = "";
    password = "";
}
//function for registeration
void user:: registration() 
{
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|               Create Account           |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;
    cout << "\t\t\t\tEnter the user name : ";

    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, name);
    cout << "\t\t\t\tEnter the password : ";
    char ch;
    password = "";
    ch = _getch();
    while (ch != 13) {
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    // encrypting the password
    password = EncryptDecrypt(password);

    ofstream fout("credential.txt", ios::app);
    if (!fout) {
        cout << "\t\t\t\tFile not found\n";
        exit(0);
    }
    else {
        fout << name << " " << password << "\n";
        fout.close();
        cout << "\n\t\t\t\t ________________________________________\n";
        cout << "\t\t\t\t|                                        |";
        cout << "\n\t\t\t\t|           REGISTRATION SUCCESSFUL      |" << endl;
        cout << "\t\t\t\t|________________________________________|" << endl << endl;
    }
}

void user:: login() 
{
label1:
    string username;
    string pass;
    bool login = false;

    cout << "\t\t\t\tEnter your user name :";
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, username);
    cout << "\t\t\t\tEnter your password : ";
    char ch;
    pass = "";
    ch = _getch();
    while (ch != 13) {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    ifstream fin("credential.txt");
    if (!fin) {
        cout << "\n\t\t\t\tFile not found!!\n";
        exit(0);
    }
    else {
        while (fin >> name >> password) {
            // decrypting the password
            string decryptedPassword = EncryptDecrypt(password);
            if (username == name && pass == decryptedPassword) {
                login = true;
                break;
            }
        }
        fin.close();
    }

    if (login) {
        cout << "\n\n\t\t\t\tVerifying user data!\n\t\t\t\t";
        waiting();
        cout << "\n\t\t\t\t ________________________________________\n";
        cout << "\t\t\t\t|                                        |";
        cout << "\n\t\t\t\t|           LOGIN SUCCESSFUL             |" << endl;
        cout << "\t\t\t\t|\tyou have login as : " << name << "       |" << endl;
        cout << "\t\t\t\t|________________________________________|" << endl << endl;
        Sleep(789);
    }
    else {
        cout << "\n\t\t\t\tIncorrect username or password\n";
        cout << "\t\t\t\tPlease try again\n";
        goto label1;
    }
}
string user:: get_name() const
{
    return name;
}