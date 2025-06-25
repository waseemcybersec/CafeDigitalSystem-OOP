#include <iostream>
#include"project.h"
#include <fstream>
#include <string>
#include<string.h>
#include <Windows.h>
#include <conio.h>
#include<iomanip>
using namespace std;

void employee::emp_menu()
{
    cout << "\n\t\t\t\t ________________________________________\n";
    cout << "\t\t\t\t|                                        |";
    cout << "\n\t\t\t\t|             EMPLOYEE MENU              |" << endl;
    cout << "\t\t\t\t|________________________________________|" << endl << endl;
    cout << "\t\t\t\t1. Take order from student/staff\n\t\t\t\t2. search items\n\t\t\t\t3. see online/scheduled order\n\t\t\t\t4. view Notification\n\t\t\t\t5. going to main menu\n\t\t\t\t6. exit\n";

}

//for view notification
void employee::view_notification()
{
    nt.view_notification();
    Sleep(789);
}
//for search stock items
void employee::search_stock()
{
    st.search_stock();
}

//for take order
void employee::take_order(employee& a)
{
    //for best seller employee
    if (obj.take_order())
    {
        ifstream fin("best_employee.txt"); 
        ofstream fout("temp.txt"); 

        if (!fin) {
            cout << "\n\t\t\t\tFile not found";
        }
        else {
            string emp_name;
            int sell_marks;
            bool found = false;

            
            while (fin >> emp_name >> sell_marks) 
            {
                if (a.get_name() == emp_name)
                {
                    found = true;
                    sell_marks++; 
                    fout << emp_name << " " << sell_marks << endl;
                }
                else 
                {
                    fout << emp_name << " " << sell_marks << endl;
                }
            }

            fin.close();
            fout.close();

            if (!found) 
            {
                // If employeee data not found
                ofstream fout2("best_employee.txt", ios::app);
                fout2 << a.get_name() << " " << 1 << endl;
                fout2.close();
            }
            else 
            {
                
                remove("best_employee.txt");
                rename("temp.txt", "best_employee.txt");
            }
        }
    }
}
//class order definition start here
order::order()
{
    customer_name = "";
    item_name = "";
    quantity = 0;
    total_price = 0.0;
}
bool order::take_order() 
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
    while (fin >> temp_name >> temp_quantity >> temp_price) 
    {
        cout << "\t\t\t" << setw(14) << temp_name << setw(14) << temp_quantity << setw(14) << temp_price << endl;
    }
    fin.close();
    cout << "\t\t\t---------------------------------------------------------------------------\n";
    cout << "\n\t\t\t\tEnter the Name of customer :";
    cin >> customer_name;
    cout << "\n\t\t\t\tEnter the name of item you want to buy : ";
    cin >> item_name;

    // Variables for reading from file
    string n;
    int q;
    float p;
    bool found = false;
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
                    cout << "\n\t\t\t\t--------------------------\n";
                    cout << "\t\t\t\t    ORDER SUCCESSFULL\n";
                    cout << "\t\t\t\t    CUSTOMER NAME : " << customer_name << endl;
                    cout << "\t\t\t\t    ITEM NAME : " << item_name << endl;
                    cout << "\t\t\t\t    QUANTITY : " << quantity << endl;
                    cout << "\t\t\t\t    TOTAL COST : " << p * quantity << endl;
                    cout << "\t\t\t\t-----------------------------\n\n";

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

    if (!found) 
    {
        cout << "\n\t\t\t\tItem not found in the menu!";
        return false;
    }
    else
    {
        return true;
    }
}
//for view schedule order
void employee::see_order()
{
    sch.see_order();
}

//view schedule order definition
void schedule_order::see_order()
{
    ifstream fin("schedule_order.txt", ios::in);
    if (!fin)
    {
        cout << "\n\t\t\t\tFile not found!";
    }
    else
    {
        int i = 1;
        while (fin >> name >> item_name >> quantity >> total >> time)
        {
            cout << "\n\t\t\t\t--------------------------\n";
            cout <<"\t\t\t\t"<< i << endl;
            cout << "\t\t\t\t    CUSTOMER NAME : " << name << endl;
            cout << "\t\t\t\t    ITEM NAME : " << item_name << endl;
            cout << "\t\t\t\t    QUANTITY : " << quantity << endl;
            cout << "\t\t\t\t    TOTAL COST : " << total  << endl;
            cout << "\t\t\t\t    TIME : " << time << endl;
            i++;
            cout << "\n\t\t\t\t--------------------------\n";
        }
    }
    fin.close();
}
