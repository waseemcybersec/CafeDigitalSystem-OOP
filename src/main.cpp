#include<iostream>
#include"project.h"
#include<Windows.h>
using namespace std;

//function for color
void set_color1(int color_code)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
}

int main()
{
	set_color1(14);
	cout << "\t\t          _____                    _____                    _____                  \n";
	cout << "\t\t         /\\    \\                  /\\    \\                  /\\    \\                 \n";
	cout << "\t\t        /::\\    \\                /::\\    \\                /::\\    \\                \n";
	cout << "\t\t       /::::\\    \\              /::::\\    \\              /::::\\    \\               \n";
	cout << "\t\t      /::::::\\    \\            /::::::\\    \\            /::::::\\    \\              \n";
	cout << "\t\t     /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\             \n";
	cout << "\t\t    /:::/  \\:::\\    \\        /:::/  \\:::\\    \\        /:::/__\\:::\\    \\            \n";
	cout << "\t\t   /:::/    \\:::\\    \\      /:::/    \\:::\\    \\       \\:::\\   \\:::\\    \\           \n";
	cout << "\t\t  /:::/    / \\:::\\    \\    /:::/    / \\:::\\    \\    ___\\:::\\   \\:::\\    \\          \n";
	cout << "\t\t /:::/    /   \\:::\\    \\  /:::/    /   \\:::\\ ___\\  /\\   \\:::\\   \\:::\\    \\         \n";
	cout << "\t\t/:::/____/     \\:::\\____\\/:::/____/     \\:::|    |/::\\   \\:::\\   \\:::\\____\\        \n";
	cout << "\t\t\\:::\\    \\      \\::/    /\\:::\\    \\     /:::|____|\\:::\\   \\:::\\   \\::/    /        \n";
	cout << "\t\t \\:::\\    \\      \\/____/  \\:::\\    \\   /:::/    /  \\:::\\   \\:::\\   \\/____/         \n";
	cout << "\t\t  \\:::\\    \\               \\:::\\    \\ /:::/    /    \\:::\\   \\:::\\    \\             \n";
	cout << "\t\t   \\:::\\    \\               \\:::\\    /:::/    /      \\:::\\   \\:::\\____\\            \n";
	cout << "\t\t    \\:::\\    \\               \\:::\\  /:::/    /        \\:::\\  /:::/    /            \n";
	cout << "\t\t     \\:::\\    \\               \\:::\\/:::/    /          \\:::\\/:::/    /             \n";
	cout << "\t\t      \\:::\\    \\               \\::::::/    /            \\::::::/    /              \n";
	cout << "\t\t       \\:::\\____\\               \\::::/    /              \\::::/    /               \n";
	cout << "\t\t        \\::/    /                \\::/____/                \\::/    /                \n";
	cout << "\t\t         \\/____/                  ~~                       \\/____/                 \n";

	
label6:
	cout << "\t\t\t-----------------------------------------------------------\n\n";
	set_color1(12);
	cout << "\t\t\t\t    _    ____  __  __ ___ _   _ \n";
	cout << "\t\t\t\t   / \\  |  _ \\|  \\/  |_ _| \\ | |\n";
	cout << "\t\t\t1.\t  / _ \\ | | | | |\\/| || ||  \\| |\n";
	cout << "\t\t\t\t / ___ \\| |_| | |  | || || |\\  |\n";
	cout << "\t\t\t\t/_/   \\_\\____/|_|  |_|___|_| \\_|\n";
	cout << "\t\t\t\t                                 \n";

	set_color1(15);
	cout << "\t\t\t\t  _____ __  __ ____  _     _____   _______ _____ \n";
	cout << "\t\t\t\t | ____|  \\/  |  _ \\| |   / _ \\ \\ / / ____| ____|\n";
	cout << "\t\t\t2.\t |  _| | |\\/| | |_) | |  | | | \\ V /|  _| |  _|  \n";
	cout << "\t\t\t\t | |___| |  | |  __/| |__| |_| || | | |___| |___ \n";
	cout << "\t\t\t\t |_____|_|  |_|_|   |_____\\___/ |_| |_____|_____|\n";
	cout << "\t\t\t\t                                                \n";

	set_color1(9);
	cout << "\t\t\t\t  ____ _____ _   _ ____  _____ _   _ _____ \n";
	cout << "\t\t\t\t / ___|_   _| | | |  _ \\| ____| \\ | |_   _|\n";
	cout << "\t\t\t2.\t \\___ \\ | | | | | | | | |  _| |  \\| | | |  \n";
	cout << "\t\t\t\t  ___) || | | |_| | |_| | |___| |\\  | | |  \n";
	cout << "\t\t\t\t |____/ |_|  \\___/|____/|_____|_| \\_| |_|  \n";
	cout << "\t\t\t\t                                          \n";

	set_color1(7);
	cout << "\t\t\t\tselect your role: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
	{
		admin adm;
		adm.admin::login();
label7:
		adm.admin_menu();
label3:
		cout << "\n\t\t\t\tEnter your choice :";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			adm.manage_stock();
			goto label3;
			break;
		}
		case 2:
		{
			adm.manage_credentials();
			goto label3;
			break;
		}
		case 3:
		{
			adm.manage_notification();
			goto label3;
			break;
		}
		case 4:
		{
			adm.see_order();
			Sleep(789);
			goto label7;
			break;
		}
		case 5:
		{
			adm.manage_complain();
			goto label3;
			break;
		}
		case 6:
		{
			adm.best_employee();
			Sleep(789);
			goto label7;
			break;
		}
		case 7:
		{
			cout << "\n\t\t\t\tGOING TO MAIN MENU\n";
			goto label6;
		}
		case 8:
		{
			cout << "\n\t\t\t\tCDS exiting!!\n";
			cout << "\t\t\t\t THANK YOU!!\n";
			exit(0);
		}
		default:
		{
			cout << "\n\t\t\t\tInvalid choice!\n";
		}
	    }
		break;
	}
	case 2:
	{
		employee emp;
		label1:
		cout << "\n\n\t\t\t\t1) REGISTRATION\n";
		cout << "\t\t\t\t2) LOGIN\n";
		cout << "\n\t\t\t\tEnter your choice:";
		char ch;
		cin >> ch;
		if (ch == '1')
		{
		emp.user::registration();
		goto label1;
		}
		else if (ch == '2')
		{
			emp.user::login();
label4:
			emp.emp_menu();
			cout << "\t\t\t\tEnter your choice:";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				emp.take_order(emp);
				goto label4;
				break;
			}
			case 2:
			{
				emp.search_stock();
				goto label4;
				break;
			}
			case 3:
			{
				emp.see_order();
				Sleep(789);
				goto label4;
				break;
			}
			case 4:
			{
				emp.view_notification();
				goto  label4;
				break;
			}
			case 5:
			{
				cout << "\n\t\t\t\tGOING TO MAIN MENU\n";
				goto label6;
				break;
			}
			case 6:
			{
				cout << "\n\t\t\t\tCDS exiting!!\n";
				cout << "\t\t\t\t THANK YOU!!\n";
				exit(0);
			}
			default:
			{
				cout << "\n\t\t\t\tInvalid choice!\n";
			}
			}
		}
		else
		{
			cout << "\n\t\t\t\tInvalid choice!\n";
		}
		break;
	}
	case 3:
	{
		Student st;
label2:
		cout << "\n\n\t\t\t\t1) REGISTRATION\n";
		cout << "\t\t\t\t2) LOGIN\n";
		cout << "\n\t\t\t\tEnter your choice:";
		char ch;
		cin >> ch;
		if (ch == '1')
		{
			st.user::registration();
			goto label2;
		}
		else if (ch == '2')
		{
			st.user::login();
label5:
			st.student_menu();
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				st.search_stock();
				goto label5;
				break;
			}
			case 2:
			{
				st.give_order();
				goto label5;
				break;
			}
			case 3:
			{
				st.add_complain();
				goto label5;
				break;
			}
			case 4:
			{
				st.view_notification();
				goto label5;
				break;
			}
			case 5:
			{
				cout << "\n\t\t\t\tGOING TO MAIN MENU\n";
				goto label6;
				break;
			}
			case 6:
			{
				cout << "\n\t\t\t\tCDS exiting!!\n";
				cout << "\t\t\t\t THANK YOU!!\n";
				exit(0);
			}
			default:
			{
				cout << "\n\t\t\t\tInvalid choice!";
			}
			}
		}
		else
		{
			cout << "\n\t\t\t\tInvalid choice!\n";
		}
		break;
	}
	default:
	{
		cout << "\n\t\t\t\tInvalid choice!\n";
	}
	}
}
