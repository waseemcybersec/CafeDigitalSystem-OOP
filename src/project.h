#pragma once
#include<string>
using namespace std;

//class user start here
class user
{
private:
    string name;
    string password;
    //function for encrypt decryption
    string EncryptDecrypt(string data) {
        char key = 'K';
        string result = data;
        for (int i = 0; i < data.length(); ++i) {
            result[i] = data[i] ^ key;
        }
        return result;
    }
public:
    user();
    void registration();
    void login();
    string get_name() const;
};

//class credential
class credential
{
    string name, pass;
public:
    credential();
    void manage_credentials();
    void view_credentials();
    void add_credentials();
    void remove_credentials();
};
//class notification
class notification
{
    string line;
public:
    notification();
    void manage_notification();
    void view_notification();
    void add_notification();
    void remove_notification();
};
//class complain
class complain
{
    string details;
public:
    complain();
    void manage_complain();
    void view_complain();
    void remove_complain();
};

//for stock
class stock
{
    string* name;
    int* quantity;
    float* price;
    float* total_price;
    static int count;
public:
    stock();
    ~stock();
    void set_color(int); //for color
    void manage_stock();
    void load_menu();
    void stock_menu();
    void add_stock();
    void search_stock();
    void update_stock();
    void remove_stock();
};

//for take order
class order
{
    string customer_name;
    string item_name;
    int quantity;
    float total_price;
public:
    order();
    bool take_order();
};

//class schedule order
class schedule_order
{
    string name;
    string item_name;
    string time;
    int quantity;
    float total;
public:
    schedule_order();
    void give_order();
    void see_order();
};
//admin class
class admin :public user
{
    credential ma;
    notification nt;
    complain cmp;
    stock st;
    schedule_order sch;
public:
    admin();
    void login();
    void admin_menu();
    //for manage stock
    void manage_stock();
    //for manage credentials 
    void manage_credentials();
    //for manage notification
    void manage_notification();
    //for manage complain
    void manage_complain();
    //for view schedule order
    void see_order();
    //for best seller emplooyee
    void best_employee();
};



//class employee start here
class employee :public user
{
    notification nt;
    stock st;
    order obj;
    schedule_order sch;
public:
    void emp_menu();
    //for view notification
    void view_notification();
    //for search stock item
    void search_stock();
    //for take order
    void take_order(employee&);
    //for view schedule order
    void see_order();
  
};

//student class start here
class Student : public user
{
    notification nt;
    stock st;
    schedule_order sch;
public:
    //for student menu
    void student_menu();
    //for view notification
    void view_notification();
    //for add complain
    void add_complain();
    //for search stock item
    void search_stock();
    //for schedule order
    void give_order();

};
