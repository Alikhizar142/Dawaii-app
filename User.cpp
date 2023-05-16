#include "User.h"
#include "Shop.h"

User::User()
{
	username = "\0";
	password = "\0";
}

void User::registers()
{
	system("color E0");
	int count = 0;
	cout << "----------------------------------------------Welcome to our system!----------------------------------------------------\n";
	cout << "******************                             -ENTER USER NAME:                                  **********************" << endl;
	cout << " \t\t\t\t\t\t ";
	getline(cin, username);
again:
	fstream file;
	string name;
	file.open("user.txt", ios::out | ios::app | ios::in);
	if (!file.is_open())
	{
		cout << "******************                                       file didn't open                                      *************************" << endl;
	}
	else
	{
		while (file >> name)
		{
			if (count == 4)
			{
				cout << endl
					 << endl;
				cout << "\t\t\t\t\t  Your limit has been exceed " << endl;
				break;
			}
			if (name == username)
			{
				count++;
				cout << "******************                          User name already present                                *******************" << endl;
				Sleep(1000);
				system("cls");
				cout << "******************                            -ENTER NEW USER NAME:                                   ***************" << endl;
				cout << "\t\t\t\t\t\t ";
				getline(cin, username);
				file.close();
				goto again;
			}
		}
		if (count == 4)
		{
			cout << endl
				 << endl;
			cout << "\t\t\t\t\tare you want to go back press any key ";
			char d;
			cin >> d;
			if (d == 'y' || d == 'Y')
			{
				system("cls");
				menu();
			}
			else
			{
				system("cls");
				menu();
			}
		}
		file.close();
		ofstream file1;
		file1.open("user.txt", ios::app);
		string password;
		cout << "******************                            -ENTER PASSWORD :                                   *******************" << endl;
		cout << "\t\t\t\t\t\t";
		getline(cin, password);
		file1 << username << " " << password << endl;
		file1.close();
	}
	system("cls");
	cout << "----------------------------------------------Thanks for the registration!----------------------------------------------\n";
	cout << endl
		 << endl;
	cout << "----------------------------------------------Go back to menu and then login your account------------------------------ " << endl;
	cout << endl
		 << endl;
	cout << "\t\t\t\t\t\tPress y to go back ";
	char d;
	cin >> d;
	if (d == 'y' || d == 'Y')
	{
		system("cls");
		menu();
	}
}

void User::userLogin()
{
	system("color F9");
	cout << "----------------------------------------------Welcome to our system!----------------------------------------------------\n";
	cout << "******************                             -ENTER USER NAME:                                   *********************" << endl;
	cout << "\t\t\t\t\t\t ";
	getline(cin, username);
	cout << "******************                             -ENTER PASSWORD :                                   *********************" << endl;
	cout << "\t\t\t\t\t\t ";
	getline(cin, password);
	bool check = 0;
	static int count = 1;
	fstream file;
	file.open("user.txt", ios::in);
	if (!file.is_open())
	{
		cout << "******************                                    file didn't open                                      *************************" << endl;
	}
	else
	{
		string name, fpassword;
		while (file >> name >> fpassword)
		{
			if (name == username && fpassword == password)
			{
				check = 1;
			}
		}
	}
	if (check == 1)
	{
		d.home();
		// d.recipt();
		cout << "\n----------------------------------------------Thank you for visiting:)--------------------------------------------------\n";
		Sleep(500);
		cout << "\t\t\t\t\tare you want to go back press y other wise n ";
		char d;
		cin >> d;
		if (d == 'y' || d == 'Y')
		{
			system("cls");
			menu();
		}
		User object;
		Shop p(object);
	}
	else
	{
		cout << endl
			 << endl;
		cout << "\t\t\t\t\t    Invalid credentials !" << endl;
		Sleep(500);
		count++;
		if (count == 4)
		{
			cout << "\t\t\t\t\t  Your limit has been exceed " << endl;
			Sleep(500);
			system("cls");
			count = 0;
			menu();
		}
		else
		{
			system("cls");
			userLogin();
		}
	}
}

void User::forget()
{
	system("cls");
	system("Color F9");
	cout << "--------------------------------------------- Forget your password !----------------------------------------------------\n";
	string read, passread;
	bool check = 0;
	int again = 0;
	int d;
	cout << "******************                             -ENTER USER NAME:                                   *********************" << endl;
	cout << "\t\t\t\t\t\t ";
	getline(cin, username);
	fstream file;
	file.open("user.txt", ios::in);
	while (file >> read)
	{
		if (read == username)
		{
			check = 1;
			cout << "******************                             -ENTER PASSWORD :                                   *********************" << endl;
			cout << "\t\t\t\t\t\t ";
			getline(cin, password);
		}
	}
	file.close();
	if (check == 1)
	{
		ifstream file("user.txt");
		fstream file1;
		file1.open("newuser.txt", ios::out | ios::app);
		while (file >> read >> passread)
		{
			if (read == username)
			{
				cout << endl
					 << endl;
				system("cls");
				cout << "\t\t\t\t\tYour Password has been successfully changed " << endl;
				file1 << username << " " << password << endl;
			}
			else
			{
				file1 << read << " " << passread << endl;
			}
		}
		file.close();
		file1.close();
		remove("user.txt");
		rename("newuser.txt", "user.txt");
		char da;
		cout << "\t\t\t\t\t  are you want to go back press y ";
		cin >> da;
		if (da == 'y' || da == 'Y')
		{
			system("cls");
			menu();
		}
	}
	else
	{
		cout << endl
			 << endl;
		cout << "\t\t\t\t\t    Invalid credentials !" << endl;
		cout << endl
			 << endl;
		cout << "\t\t\t\t\tPress 1 to again enter the username " << endl;
		cout << "\t\t\t\t\tPress 2 or any key to go back to home " << endl;
		cout << "\t\t\t\t\t\t";
		cin >> d;
		if (d == 1)
		{
			cin.ignore();
			forget();
		}
		else
		{
			again = 1;
			system("cls");
			menu();
		}
	}
}
