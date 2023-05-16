#include "Base.h"
#include "admin.h"
#include "User.h"

Base::Base()
{
}

void Base::menu()
{
	system("cls");

	User us;
	string usn;
	int choice;
	welcome();
	cout << "************************************************************************************************************************" << endl;
	cout << "*****************                            -Press 1 to Admin login:                                   ****************" << endl;
	cout << "*****************                            -Press 2 to User login:                                    ****************" << endl;
	cout << "*****************                            -Press 3 to REGISTER:                                      ****************" << endl;
	cout << "*****************                            -Press 4 to Forget Password:                               ****************" << endl;
	cout << "*****************                            -Enter your choice:                                        ****************" << endl;
	cout << "************************************************************************************************************************" << endl;
	cin >> choice;
	system("cls");
	Beep(2000, 350);
	cin.get();
	if (choice == 1)
	{
		cout << "--------------------------------------------Welcome to our system!------------------------------------------------------\n";
		admin ad;
		ad.login();
	}
	else if (choice == 2)
	{
		us.userLogin();
	}
	else if (choice == 3)
	{
		us.registers();
	}
	else if (choice == 4)
	{
		us.forget();
	}
}

void Base::welcome()
{

	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t*          ++++++++++++++++++++++++++++++++++++           *" << endl;
	cout << "\t\t\t*          ++++++++++++++++++++++++++++++++++++           *" << endl;
	cout << "\t\t\t*          ++++++++++++++++++++++++++++++++++++           *" << endl;
	cout << "\t\t\t*          ++++++++++++++++++++++++++++++++++++           *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t*                         +++++                           *" << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

	cout << "\t\t\t* *\t\t\t\t\t\t        * *" << endl;
	cout << "\t\t\t-------<(  W E L O C M E  T O  D A W A I I  A P P  )>--------" << endl;
	cout << "\t\t\t* *\t\t\t\t\t\t        * *" << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
	cout << endl;
	Beep(2000, 350);
}
