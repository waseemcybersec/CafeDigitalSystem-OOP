#include <iostream>
#include"project.h"
#include <fstream>
#include <string>
#include<string.h>
#include <Windows.h>
#include <conio.h>
#include<iomanip>
using namespace std;

void waiting1()
{
    for (int i = 0; i < 10; i++)
    {
        Sleep(200);
        cout << "..";
    }
}

//class admin function start here

//constructor
admin::admin()
{
}

//destructor

void admin::login()
{
    string username;
    string pass;

    bool flag = false;
    do
    {
        cout << "\t\t\t\tEnter your user name :";
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        getline(cin, username);
        cout << "\t\t\t\tEnter your password : ";
        char ch;
        pass = "";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        if (username == "admin" && pass == "admin123")
        {
            flag = true;
            cout << "\n\n\t\t\t\tVerifying user data!\n\t\t\t\t";
            waiting1();
            cout << "\n\t\t\t\t ________________________________________\n";
            cout << "\t\t\t\t|                                        |";
            cout << "\n\t\t\t\t|           LOGIN SUCCESSFUL             |" << endl;
            cout << "\t\t\t\t|\tyou have login as : " << username << "        |" << endl;
            cout << "\t\t\t\t|________________________________________|" << endl << endl;
            Sleep(789);
        }
        else
        {
            cout << "\n\n\t\t\t\tIncorrect username or password\n";
            cout << "\t\t\t\tTry again\n\n";
        }
    } while (!flag);

}

//admin menu function
void admin::admin_menu()
{
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|             ADMIN MENU                 |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;

    cout << "\t\t\t\t-----------------------------------------------------\n";
    cout << "\t\t\t\t1.Manage stock " << endl;
    cout << "\t\t\t\t2.Manage credentials of employee and students/staff " << endl;
    cout << "\t\t\t\t3.Manage notification " << endl;
    cout << "\t\t\t\t4.see online or scheduled order" << endl;
    cout << "\t\t\t\t5.Manage complaints" << endl;
    cout << "\t\t\t\t6.See best seller Employee" << endl;
    cout << "\t\t\t\t7.Go to main menu\n";
    cout << "\t\t\t\t8.Exit\n\n";
    cout << "\t\t\t\t------------------------------------------------------\n\n";
}

//---------------------------------------------------------------------------------------------

//function for color
void stock:: set_color(int color_code)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
}
//for manage stock
void admin::manage_stock()
{
    st.load_menu();
    st.manage_stock();
}
//stock class definition start here
//constructor
stock::stock()
{
    ifstream fin("stock.txt");
    if (!fin) 
    {
        cout << "\t\t\t\tFile not found!";
    }
    else 
    {
        string nam, quant, pri, t_price;
        while (fin >> nam >> quant >> pri)
        {
            count++;
        }
    }
    fin.close();

    name = new string[count];
    quantity = new int[count];
    price = new float[count];
    total_price = new float[count];
}

//destructor
stock::~stock()
{
    delete[] name;
    delete[] quantity;
    delete[] price;
    delete[] total_price;
}
void stock::manage_stock()
{ 
    cout << "\t\t\t\t1. Display Stock Menu\n";
    cout << "\t\t\t\t2. Add Item to menu\n";
    cout << "\t\t\t\t3. search Stock Item\n";
    cout << "\t\t\t\t4. update stock Item\n";
    cout << "\t\t\t\t5. Remove stock Item\n";
    cout << "\t\t\t\t6. go to admin menu\n";
    cout << "\t\t\t\t7. Exit\n";

    int choice;
    //stock st;
    cout << "\n\t\t\t\tEnter your choice:";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        stock_menu();
        Sleep(789);
        manage_stock();
        break;
    }
    case 2:
    {
        add_stock();
        Sleep(789);
        manage_stock();
        break;
    }
    case 3:
    {
        search_stock();
        Sleep(789);
        manage_stock();
        break;
    }
    case 4:
    {
        update_stock();
        Sleep(789);
        manage_stock();
        break;
    }
    case 5:
    {
        remove_stock();
        Sleep(789);
        manage_stock();
        break;
    }
    case 6:
    {
        admin a;
        Sleep(789);
        a.admin_menu();
        break;
    }
    default:
    {
        cout << "\t\t\t\tInvalid choice!\n";
    }
    }
}

//initializing static count variable 
 int stock::count = 0;

//ftns definiton for stock class
//for load stock menu
void stock::load_menu()
{
    ifstream fin("stock.txt");
    if (!fin)
    {
        cout << "\t\t\t\tFile not found!";
        return;
    }
    count = 0;

    string nam, quant, pri, t_price;
    while (fin >> nam >> quant >> pri)
    {
        name[count] = nam;
        quantity[count] = stoi(quant);
        price[count] = stof(pri); 
        total_price[count] = quantity[count] * price[count];
        count++;
    }

    fin.close();
}


//for stock menu
void stock::stock_menu()
{
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|             STOCK MENU                 |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;
    cout << "\t\t\t-------------------------------------------------------------------------\n";
    cout <<"\t\t\t"<< setw(15) << "Item Name" << setw(15) << "Quantity" << setw(15) << "Price" << setw(18) << "Total Price\n";
    cout << "\t\t\t--------------------------------------------------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        if (quantity[i] <= 15 && quantity[i] > 0)
        {
            set_color(12);
        }
        else if (quantity[i] == 0) 
        {
           set_color(14);
        }

        cout <<"\t\t\t"<< setw(14) << name[i] << setw(14) << quantity[i] << setw(15) << price[i] << setw(14) << total_price[i] << endl;
        set_color(7);
    }
    cout << "\t\t\t---------------------------------------------------------------------------\n";

    for (int i = 0; i < count; i++) 
    {
        char ch;
        if (quantity[i] <= 10 && quantity[i] >= 0) 
        {
            cout << "\n\t\t\t\tDo you want to add stock to " << name[i] << " (Y/N) ";
            cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                cout << "\t\t\t\tEnter the new quantity for " << name[i] << " :";
 
                int new_quantity;
                cin >> new_quantity;
                quantity[i] = new_quantity;

                // Update quantity in the file
                ifstream fin2("stock.txt");
                ofstream fout2("temp.txt");
                string temp_name;
                int temp_quantity;
                float temp_price;
                while (fin2 >> temp_name >> temp_quantity >> temp_price)
                {
                    if (temp_name == name[i])
                    {
                        fout2 << name[i] << " " << new_quantity << " " << price[i] << endl;
                    }
                    else
                    {
                        fout2 << temp_name << " " << temp_quantity << " " << temp_price << endl;
                    }
                }
                fin2.close();
                fout2.close();
                remove("stock.txt");
                rename("temp.txt", "stock.txt");

                cout << "\n\t\t\t\t------------------------------------------\n";
                cout << "\t\t\t\t\t" << name[i] << " updated successfully\n";
                cout << "\t\t\t\t------------------------------------------\n";
            }

            else if (ch == 'N' || ch == 'n') {
                cout << "\n\t\t\t\tok good!\n\n";
            }
            else {
                cout << "\t\t\t\tInvalid choice!\n\n\n";
            }
        }
    }   
}

//for add stock
void stock::add_stock()
{
    if (count < 100)
    {
        string NAME;
        int QUANTITY;
        float PRICE, TOTAL_PRICE;

        cout << "\t\t\t\tEnter the name of Item you want to add : ";
        cin >> NAME;
        cout << "\t\t\t\tEnter the quantity of the Item : ";
        cin >> QUANTITY;
        cout << "\t\t\t\tEnter the price of the item : ";
        cin >> PRICE;
        TOTAL_PRICE = QUANTITY * PRICE;

        // reeallocate memory to
        string* temp_name = new string[count + 1];
        int* temp_quantity = new int[count + 1];
        float* temp_price = new float[count + 1];
        float* temp_total_price = new float[count + 1];

        for (int i = 0; i < count; i++)
        {
            temp_name[i] = name[i];
            temp_quantity[i] = quantity[i];
            temp_price[i] = price[i];
            temp_total_price[i] = total_price[i];
        }

        temp_name[count] = NAME;
        temp_quantity[count] = QUANTITY;
        temp_price[count] = PRICE;
        temp_total_price[count] = TOTAL_PRICE;

        //delete out old array 
        delete[] name;
        delete[] quantity;
        delete[] price;
        delete[] total_price;

        //assign the new arrayyy 
        name = temp_name;
        quantity = temp_quantity;
        price = temp_price;
        total_price = temp_total_price;

        count++;

        //adding the new item to stock.txt
        ofstream fout("stock.txt", ios::app);
        if (!fout)
        {
            cout << "\n\t\t\t\tFile not open!\n";
        }
        else
        {
            fout << NAME << " " << QUANTITY << " " << PRICE << endl;
        }

        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t\tItem added successfully \n\n";
        cout << "\t\t\t\t------------------------------------------\n";
    }
    else
    {
        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t\t\tMenu is full! sorry you cannot add more items \n\n";
        cout << "\t\t\t\t------------------------------------------\n";
    }
}

//for search stock
void stock::search_stock()
{
    string item_name;
    cout << "\n\n\t\t\t\tEnter the name of the item you want to search :";
    cin >> item_name;

    string name;
    int quantity;
    float price;
    bool found = false;
    ifstream fin("stock.txt", ios::in);
    if (!fin)
    {
        cout << "\n\t\t\t\tFile not found!";
    }
    else
    {
        while (fin >> name >> quantity >> price)
        {
            if (name == item_name)
            {
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        cout << "\n\t\t\t\tItem not found in the menu!" << endl << endl;
    }
    else
    {
        cout << "\n\t\t\t\t-------------------\n";
        cout << "\t\t\t\t    ITEM FOUND\n";
        cout << "\t\t\t\t    NAME : " << item_name << endl;
        cout << "\t\t\t\t    QUANTITY : " << quantity << endl;
        cout << "\t\t\t\t    PRICE : " << price << endl;
        cout << "\t\t\t\t-------------------\n\n";
    }
}
void stock::update_stock()
{
    string update_item;
    cout << "\n\t\t\t\tEnter the name of the item you want to update:";
    cin >> update_item;
    
    string temp_name;
    int temp_quantity;
    float temp_price;
    bool found = false;
    //opening stock.txt
    ifstream fin("stock.txt", ios::in);
    ofstream fout("temp.txt", ios::app);
    if (!fin)
    {
        cout << "\n\t\t\t\tFile not found!";
    }
    else
    {
        while (fin >> temp_name >> temp_quantity >> temp_price)
        {
            if (temp_name == update_item)
            {
                found = true;
                cout << "\n\t\t\t\tEnter the new quantity for " << update_item << " : ";
                cin >> temp_quantity;
                cout << "\n\t\t\t\tEnter the new price for " << update_item << " : ";
                cin >> temp_price; 
                fout << temp_name << " " << temp_quantity << " " << temp_price << endl;
            }
            else
            {
                fout << temp_name << " " << temp_quantity << " " << temp_price << endl;
            }
        }
    }
    fin.close();
    fout.close();
    if (!found)
    {
        cout << "\n\t\t\t\tItem " << update_item << " not found in the menu" << endl;
        remove("temp.txt");
    }
    else
    {
        remove("stock.txt");
        rename("temp.txt", "stock.txt");
        load_menu(); 
        cout << "\t\t\t\t------------------------------------------\n";
        cout << "\t\t\t\t\tItem "<<update_item<<" update successfully \n\n";
        cout << "\t\t\t\t------------------------------------------\n";
    }
}
//for remove stock
void stock::remove_stock()
{
    string remove_item;
    cout << "\n\t\t\t\tEnter the name of item you want to remove :";
    cin >> remove_item;

    string temp_name;
    int temp_quantity;
    float temp_price;
    bool found = false;
    //opening files
    ifstream fin("stock.txt", ios::in);
    ofstream fout("temp.txt", ios::app);
    if (!fin)
    {
        cout << "\n\t\t\t\tFile not found!";
    }
    else
    {
        while (fin >> temp_name >> temp_quantity >> temp_price)
        {
            if (temp_name == remove_item)
            {
                cout << "\t\t\t\t------------------------------------------\n";
                cout << "\t\t\t\t\tItem "<<remove_item<<" removed successfully \n\n";
                cout << "\t\t\t\t------------------------------------------\n";
                cout << endl << endl;
                found = true;
            }
            else
            {
                fout << temp_name << " " << temp_quantity << " " << temp_price << endl;
            }
        }
    }
    fin.close();
    fout.close();
    if (!found)
    {
        cout << "\n\t\t\t\tItem "<<remove_item<<" not found in menu!"<<endl;
        remove("temp.txt");
    }
    else
    {
        remove("stock.txt");
        rename("temp.txt", "stock.txt");
        load_menu();
    }
}
//--------------------------------------------------------------------------------------------
//for manage credentials
void admin::manage_credentials()
{
    ma.manage_credentials();
}

//class credential ftn def.

credential::credential()
{
    name = "";
    pass = "";
}
void credential::manage_credentials()
{
    cout << "\n\t\t\t\t1. view credentials\n";
    cout << "\t\t\t\t2. Add credentials\n";
    cout << "\t\t\t\t3. remove credentials\n";
    cout << "\t\t\t\t4. go to admin_menu\n";

    int choice;
    cout << "\n\t\t\t\tEnter your choice:";
    cin >> choice;
   
    switch(choice)
    {
        case 1:
        {
            view_credentials();
            Sleep(789);
            manage_credentials();
            break;
        }
        case 2:
        {
            add_credentials();
            Sleep(789);
            manage_credentials();
            break;
        }
        case 3:
        {
            remove_credentials();
            Sleep(789);
            manage_credentials();
            break;
        }
        case 4:
        {
            admin a;
            Sleep(789);
            a.admin_menu();
            break;
        }
        default:
        {
            cout << "\t\t\t\tInvalid choice!\n";
        }
    }
}
//for view credentials
void credential::view_credentials()
{
    ifstream fin("credential.txt", ios::in);
    if (!fin)
    {
        cout << "\n\t\t\t\tFile not found!";
    }
    else
    {
     
        int i = 1;
        cout << "\t\t\t\t--------------------------------------------------\n";
        while (getline(fin, name,' ') && getline(fin,pass,'\n'))
        {
            cout <<"\n\t\t\t\t"<<i<<") user name : "<< name<<" & password : "<<pass << endl;
            i++;
        }
        cout << "\t\t\t\t--------------------------------------------------\n";
    }
    fin.close();
}

//for add credential
void credential::add_credentials()
{
    
    cout << "\t\t\t\tEnter the user name : ";

    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin, name);
    cout << "\t\t\t\tEnter the password : ";
    char ch;
    pass = "";
    ch = _getch();
    while (ch != 13) 
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    ofstream fout("credential.txt", ios::app);
    if (!fout)
    {
        cout << "\t\t\t\tFile not found\n";
        exit(0);
    }
    else
    {
        fout << name << " " << pass << "\n";
        fout.close();
        cout << "\n\t\t\t\t ________________________________________\n";
        cout << "\t\t\t\t|                                        |";
        cout << "\n\t\t\t\t|           CREDENTIALS ADDED            |" << endl;
        cout << "\t\t\t\t|________________________________________|" << endl << endl;
    }
}

//for remove credential
void credential::remove_credentials()
{
    string name;
    cout << "\t\t\t\tEnter the name to remove: ";
    if (cin.peek() == '\n')
    {
        cin.ignore();
    }
    getline(cin,name);

    ifstream inFile("credential.txt");
    ofstream tempFile("temp.txt");

    string currName, currPassword;

    while (inFile >> currName >> currPassword) 
    {
        if (currName != name) 
        {
            tempFile << currName << " " << currPassword << "\n";

        }
    }
    inFile.close();
    tempFile.close();

    remove("credential.txt");
    rename("temp.txt", "credential.txt");

    cout << "\n\t\t\t\t ________________________________________\n";

    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|           CREDENTIALS REMOVED          |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;
}
//----------------------------------------------------------------------------------------------
//for manage notification
void admin::manage_notification()
{
    nt.manage_notification();
}

//notification class ftn definition start here

notification::notification()
{
    line = "";
}
void notification::manage_notification()
{
    cout << "\n\t\t\t\t1. view Notifications\n";
    cout << "\t\t\t\t2. Add Notification\n";
    cout << "\t\t\t\t3. remove Notification\n";
    cout << "\t\t\t\t4. go to admin menu\n";

    int choice;
    cout << "\n\t\t\t\tEnter your choice:";
    cin >> choice;
  
    switch (choice)
    {
    case 1:
    {
        view_notification();
        Sleep(789);
        manage_notification();
        break;
    }
    case 2:
    {
        add_notification();
        Sleep(789);
        manage_notification();
        break;
    }
    case 3:
    {
        remove_notification();
        Sleep(789);
        manage_notification();
        break;
    }
    case 4:
    {
        admin a;
        Sleep(789);
        a.admin_menu();
        break;
    }
    default:
    {
        cout << "\t\t\t\tInvalid choice!\n";
    }
    }
}

//for view notificatin
void notification::view_notification()
{
    ifstream fin("notification.txt");
    if (!fin) 
    {
        cout << "\t\t\t\tFile not found!";
    }
    else 
    {
       
        int i = 1;
        cout << "\t\t\t\t--------------------------------------------------\n";
        while (getline(fin, line)) 
        {
            cout << "\n\t\t\t\t" << i << ") " << line << endl;
            i++;
        }
        cout << "\t\t\t\t--------------------------------------------------\n";
    }
    fin.close();
}
//for Add notification
void notification::add_notification() {
    //string notification;
    cout << "\t\t\t\tEnter the notification: ";
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, line);

    ofstream fout("notification.txt", ios::app);
    if (!fout) {
        cout << "\t\t\t\tFile not found\n";
        exit(0);
    }
    else {
        fout << line << "\n";
        fout.close();
        cout << "\n\t\t\t\t ________________________________________\n";
        cout << "\t\t\t\t|                                        |";
        cout << "\n\t\t\t\t|           NOTIFICATION ADDED           |" << endl;
        cout << "\t\t\t\t|________________________________________|" << endl << endl;
    }
}
//for Remove notification
void notification::remove_notification()
{
    string line;
    cout << "\t\t\t\tEnter the notification to remove: ";
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, line);

    ifstream inFile("notification.txt");
    ofstream tempFile("temp.txt");

    string currNotification;

    while (getline(inFile, currNotification)) 
    {
        if (currNotification != line)
        {
            tempFile << currNotification << "\n";
        }
    }
    inFile.close();
    tempFile.close();

    remove("notification.txt");
    rename("temp.txt", "notification.txt");

    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|        NOTIFICATION REMOVED            |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;
}

//----------------------------------------------------------------------------------------------
//for mangage complain
void admin::manage_complain()
{
    cmp.manage_complain();
}

//complain class definition.

complain::complain()
{
    details = "";
}
void complain::manage_complain()
{
    cout << "\n\t\t\t\t1. view Complain\n";
    cout << "\t\t\t\t2. Remove complain\n";
    cout << "\t\t\t\t3. go to admin_menu\n";

    int choice;
    cout << "\n\t\t\t\tEnter your choice:";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
    {
        view_complain();
        Sleep(789);
        manage_complain();
        break;
    }
    case 2:
    {
        remove_complain();
        Sleep(789);
        manage_complain();
        break;
    }
    case 3:
    {
        admin a;
        Sleep(789);
        a.admin_menu();
        break;
    }
    default:
    {
        cout << "\t\t\t\tInvalid choice!\n";
    }
    }
}

//for view complain
void complain::view_complain()
{
    ifstream fin("complain.txt");
    if (!fin) 
    {
        cout << "\t\t\t\tFile not found!";
    }
    else
    {
        
        int i = 1;
        cout << "\t\t\t\t--------------------------------------------------\n";
        while (getline(fin, details))
        {
            cout << "\n\t\t\t\t" << i << ") " << details << endl;
            i++;
        }
        cout << "\t\t\t\t--------------------------------------------------\n";
    }
    fin.close();
}

//for remove complain
void complain::remove_complain()
{
    string details;
    cout << "\t\t\t\tEnter the complain you want to remove: ";
    if (cin.peek() == '\n') 
    {
        cin.ignore();
    }
    getline(cin, details);

    ifstream inFile("complain.txt");
    ofstream tempFile("temp.txt");

    string currComplain;

    while (getline(inFile, currComplain))
    {
        if (currComplain != details) 
        {
            tempFile << currComplain << "\n";
        }
    }
    inFile.close();
    tempFile.close();

    remove("complain.txt");
    rename("temp.txt", "complain.txt");

    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|        COMPLAIN REMOVED                |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;
}
//----------------------------------------------------------------------------------------------

//for view schedule order
void admin::see_order()
{
    sch.see_order();
}

//-----------------------------------------------------------------------------------------------------

//for best seller employee
void admin::best_employee() {
    ifstream file("best_employee.txt"); 
    if (!file) 
    {
        cout << "\n\t\t\t\tError opening file." << endl;
    }

    string name;
    int highest_score = 0;
    string best_employee_name;

    while (file >> name) 
    {
        int score;
        file >> score; 

        if (score > highest_score) 
        {
            highest_score = score;
            best_employee_name = name;
        }
    }

    file.close(); // Close the file

    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\n\t\t\t\t\tThe best employee is: " << best_employee_name << endl;
    cout << "\n\t\t\t\t ________________________________________\n";
}
