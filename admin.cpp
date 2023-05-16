#include "data.h"
#include "Shop.h"
#include "Product.h"
#include <iomanip>
admin::admin()
{
	username = "admin";
	password = "admin";
}

void admin::login()
{
	system("color B2");
	admin object;
	bool check = 0;
	do
	{
		string user_name, password1;
		cout << "\t\t\t\t\tEnter your user name: ";
		getline(cin, user_name);
		cout << "\t\t\t\t\tEnter your password: ";
		getline(cin, password1);
		if (user_name == username && password1 == password)
		{
			check = 1;
		}
		else
		{
			cout << "\t\t\t\t\tWrong Credentials!\n";
			cout << "\t\t\t\t\tDO you want to go back press y ";
			char d;
			cin >> d;
			if (d == 'y' || d == 'Y')
			{
				system("cls");
				menu();
			}
			system("cls");
		}
	} while (check != 1);
	if (check == 1)
	{
		Shop sh(object);
		sh.adminPanel();
	}
}
int admin::deleteUser()
{
top:
	system("color C2");
	system("cls");
	vector<string> cat;
	string name = "user.txt";
	fstream file;
	string line;
	file.open(name, ios::app | ios::out | ios::in);
	if (file.is_open())
	{

		cout << "************************************************************************************************************************" << endl;

		// int count=1;
		while (getline(file, line))
		{
			cat.push_back(line);
		}
		file.close();
	}
	for (int i = 0; i < cat.size(); i++)
	{
		cout << i + 1 << "                  " << cat[i] << endl;
	}

	cout << "************************************************************************************************************************" << endl;
	cout << "Enter Index you want to delete" << endl;
	int i;
	cin >> i;
	i = i - 1;
	cat.erase(cat.begin() + i);

	file.open(name, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < cat.size(); i++)
		{
			file << cat[i] << endl;
		}
	}

	return 1;
}

int admin::addCategory()
{
top:

	system("cls");
	system("color B9");
	vector<string> cat;
	string name = "categories.txt";
	fstream file;
	string line;
	file.open(name, ios::app | ios::out | ios::in);
	if (file.is_open())
	{

		cout << "************************************************************************************************************************" << endl;

		// int count=1;
		while (getline(file, line))
		{
			cat.push_back(line);
		}
		file.close();
	}
	for (int i = 0; i < cat.size(); i++)
	{
		cout << i + 1 << "                  " << cat[i] << endl;
	}

	cout << "************************************************************************************************************************" << endl;
	cout << "Enter name of new Category" << endl;
	cin >> line;
	cat.push_back(line);
	file.open(name, ios::out | ios::in);
	{
		if (file.is_open())
		{
			for (int i = 0; i < cat.size(); i++)
			{
				file << cat[i] << endl;
			}
		}
	}

	return 1;
}

int admin::deleteCategory()
{
top:
	system("cls");
	vector<string> cat;
	string name = "categories.txt";
	fstream file;
	string line;
	file.open(name, ios::app | ios::out | ios::in);
	if (file.is_open())
	{

		cout << "************************************************************************************************************************" << endl;

		// int count=1;
		while (getline(file, line))
		{
			cat.push_back(line);
		}
		file.close();
	}
	for (int i = 0; i < cat.size(); i++)
	{
		cout << i + 1 << "                  " << cat[i] << endl;
	}

	cout << "************************************************************************************************************************" << endl;
	cout << "Enter Index you want to delete" << endl;
	int i;
	cin >> i;
	i = i - 1;
	cat.erase(cat.begin() + i);

	file.open(name, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < cat.size(); i++)
		{
			file << cat[i] << endl;
		}
	}
	return 1;
}

int admin::addProduct()
{
top:
	system("cls");
	system("cls");
	system("color B9");
	vector<string> cat;
	string name = "categories.txt";
	fstream file;
	string line;
	file.open(name, ios::app | ios::out | ios::in);
	if (file.is_open())
	{

		while (getline(file, line))
		{
			cat.push_back(line);
		}
		file.close();
	}

	cout << "************************************************************************************************************************" << endl;

	for (int i = 0; i < cat.size(); i++)
	{
		cout << setw(30) << "                         -Press " << i + 1 << " for " << cat[i] << "                             " << endl;
	}
	cout << "                         -Press 0 for back to the panel                             " << endl;
	cout << "************************************************************************************************************************" << endl;
	int choice;
	cout << "\t\t\t\t\t\t ";
	cin >> choice;
	if (choice == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i <= cat.size(); i++)
		{
			if (choice == i)
			{
				product::addProduct(cat[i - 1]);
			}
		}
	}
	return 1;
}

int admin::deleteProduct()
{
top:
	system("cls");
	system("cls");
	system("color B9");
	vector<string> cat;
	string name = "categories.txt";
	fstream file;
	string line;
	file.open(name, ios::app | ios::out | ios::in);
	if (file.is_open())
	{

		while (getline(file, line))
		{
			cat.push_back(line);
		}
		file.close();
	}

	cout << "************************************************************************************************************************" << endl;

	for (int i = 0; i < cat.size(); i++)
	{
		cout << setw(30) << "                            -Press" << i + 1 << "   for " << cat[i] << setw(30) << "                           " << endl;
	}
	cout << "                            -Press 0 for back to the panel                             " << endl;
	cout << "************************************************************************************************************************" << endl;
	int choice;
	cout << "\t\t\t\t\t\t ";
	cin >> choice;
	if (choice == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i <= cat.size(); i++)
		{
			if (choice == i)
			{
				product::deleteProduct(cat[i - 1]);
			}
		}
	}
	return 1;
}

int admin::modifyProduct()
{
top:

	system("cls");
	system("color B9");
	vector<string> cat;
	string name = "categories.txt";
	fstream file;
	string line;
	file.open(name, ios::app | ios::out | ios::in);
	if (file.is_open())
	{

		while (getline(file, line))
		{
			cat.push_back(line);
		}
		file.close();
	}

	cout << "************************************************************************************************************************" << endl;

	for (int i = 0; i < cat.size(); i++)
	{
		cout << setw(30) << "                           -Press" << i + 1 << "   for " << cat[i] << endl;
	}
	cout << "                         -Press 0 for back to the panel                            " << endl;
	cout << "************************************************************************************************************************" << endl;
	int choice;
	cout << "\t\t\t\t\t\t ";
	cin >> choice;
	if (choice == 0)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i <= cat.size(); i++)
		{
			if (choice == i)
			{
				product::modifyProduct(cat[i - 1]);
			}
		}
	}
}
