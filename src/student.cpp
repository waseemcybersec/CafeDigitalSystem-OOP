#include <iostream>
#include"project.h"
#include <fstream>
#include <string>
#include<string.h>
#include <Windows.h>
#include <conio.h>
#include<iomanip>

void Student::student_menu()
{
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|             STUDENT MENU               |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;
    cout << "\t\t\t\t1. search items\n\t\t\t\t2. Give scheduled order\n\t\t\t\t3. Give complaints\n\t\t\t\t4. See notifications\n\t\t\t\t5. Going to main menu\n\t\t\t\t6. Exit\n";
    cout << "\t\t\t\tSelect your choice (1-4): ";
}

//for view notification
void Student::view_notification()
{
    nt.view_notification();
    Sleep(789);
}

//for add complain from student
void Student::add_complain()
{
    string details;
    cout << "\t\t\t\tEnter the complain : ";
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, details);

    ofstream fout("complain.txt", ios::app);
    if (!fout) 
    {
        cout << "\t\t\t\tFile not found\n";
        exit(0);
    }
    else
    {
        fout << details << "\n";
        fout.close();
        cout << "\n\t\t\t\t ________________________________________\n";
        cout << "\t\t\t\t|                                        |";
        cout << "\n\t\t\t\t|           COMPLAIN ADDED               |" << endl;
        cout << "\t\t\t\t|________________________________________|" << endl << endl;
    }
    Sleep(789);
}

//for search stock items
void Student::search_stock()
{
    st.search_stock();
}

//for giving schedule order
void Student::give_order()
{
    sch.give_order();
}

//schedule order function give order definition
schedule_order::schedule_order()
{
    name = "";
    item_name = "";
    time = "";
    quantity = 0;
    total = 0.0;
}
void schedule_order::give_order()
{
    // Display stock menu
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|             STOCK MENU                 |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;
    cout << "\t\t\t-------------------------------------------------------------------------\n";
    cout << "\t\t\t" << setw(15) << "Item Name" << setw(15) << "Quantity" << setw(15) << "Price\n";
    cout << "\t\t\t--------------------------------------------------------------------------\n";

    string temp_name;
    int temp_quantity;
    float temp_price;

    ifstream fin("stock.txt");
    while (fin >> temp_name >> temp_quantity >> temp_price) {
        cout << "\t\t\t" << setw(14) << temp_name << setw(14) << temp_quantity << setw(14) << temp_price << endl;
    }
    fin.close();
    cout << "\t\t\t---------------------------------------------------------------------------\n";
    cout << "\n\t\t\t\tEnter your Name :";
    cin >> name;
    cout << "\n\t\t\t\tEnter the name of item you want to buy : ";
    cin >> item_name;

    // Variables for reading from file
    string n;
    int q;
    float p;
    bool found = false;
    //flag for checking that order placed successfully 
    bool flag = false;

    // Opening file for searching item
    ifstream fin2("stock.txt");
    if (!fin2)
    {
        cout << "\n\t\t\t\tFile not found!";
    }
    else
    {
        ofstream fout("temp.txt");
        while (fin2 >> n >> q >> p)
        {
            if (item_name == n)
            {
                found = true;
                cout << "\n\t\t\t\tEnter the quantity : ";
                cin >> quantity;
                if (quantity <= q)
                {
                    flag = true;
                    total = quantity * p;
                    cout << "\n\t\t\t\tEnter the time on which you will recieve your order : ";
                    cin >> time;
                    cout << "\n\t\t\t\t--------------------------\n";
                    cout << "\t\t\t\t    ORDER SUCCESSFULL\n";
                    cout << "\t\t\t\t    CUSTOMER NAME : " << name << endl;
                    cout << "\t\t\t\t    ITEM NAME : " << item_name << endl;
                    cout << "\t\t\t\t    QUANTITY : " << quantity << endl;
                    cout << "\t\t\t\t    TOTAL COST : " << total << endl;
                    cout << "\t\t\t\t    TIME : " << time << endl;
                    cout << "\n\t\t\t\t    PLEASE BE ON TIME";
                    cout << "\n\t\t\t\t-----------------------------\n\n";

                    // Update stock in temp.txt
                    fout << n << " " << (q - quantity) << " " << p << endl;
                }
                else
                {
                    cout << "\n\t\t\t\tSorry Insufficient quantity in the stock!";
                    fout << n << " " << q << " " << p << endl; //for quantity change
                }
            }
            else
            {
                fout << n << " " << q << " " << p << endl; //others items unchanged
            }
        }
        fin2.close();
        fout.close();

        // Replace stock.txt with temp.txt
        remove("stock.txt");
        rename("temp.txt", "stock.txt");
    }

    //now writing to schedule_order.txt
    if (flag)
    {
        ofstream file("schedule_order.txt", ios::app);
        if (!file)
        {
            cout << "\n\t\t\t\tFile not found";
        }
        else
        {
            file << name << " " << item_name << " " << quantity << " " << total << " " << time << endl;
        }
        file.close();
    }
    //if item not found in the menu
    if (!found)
    {
        cout << "\n\t\t\t\tItem not found in the menu!";
    }
}