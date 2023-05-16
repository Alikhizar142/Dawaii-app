#include "data.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
using namespace std;

Data::Data()
{
}
void Data::recipt(vector<string> name, vector<int> price)
{
	cout << "Recipt under development\n";
	int total = 0;
	cout << left << setw(10) << "Sr.No" << setw(25) << "Medicine Name" << setw(10) << "Qty." << setw(10) << "Rate" << setw(10) << "Price" << endl;
	for (int i = 0; i < cart_count; i++)
	{
		cout << left << setw(10) << product_in_cart[i] << setw(25) << name[product_in_cart[i]] << setw(10) << quantity_in_cart[i] << setw(10) << price[product_in_cart[i]] << quantity_in_cart[i] * price[product_in_cart[i]] << endl;
		total += quantity_in_cart[i] * price[product_in_cart[i]];
	}
	cout << "\tYour total bill is: " << total << endl;
}

void Data::welcome()
{
	cout << "\t\t\t\tEnter any Key to continue" << endl
		 << endl;
	Beep(2000, 350);
	cin.get();
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
	cin.get();
}

void Data::home()
{
	cout << "Login Success!!!!\nFurther program under development............\n"
		 << endl;
	cout << "\tSerial No!: " << endl;
	categories.clear();
	string Filename{"categories.txt"};

	ifstream csvfile{Filename};
	string line;
	if (csvfile.is_open())
	{
		while (getline(csvfile, line))
		{
			categories.push_back(line);
		}
	}

	for (int i = 0; i < categories.size(); i++)
	{
		cout << "\t" << i + 1 << "\t\t" << categories[i] << endl;
	}
	cout << endl;
	cout << "\t\t---Enter the serial No to appropriate result: ";
	Beep(2000, 350);
	int choice;
	cin >> choice;
	choice = choice - 1;
	string f = categories[choice];

	system("cls");
	Order(f);
}
vector<string> Data::tokenise(string Line, char separator)
{
	vector<string> tokens;
	signed int start, end;
	string token;
	start = Line.find_first_not_of(separator, 0);
	do
	{
		end = Line.find_first_of(separator, start);
		if (start == Line.length() || start == end)
			break;
		if (end >= 0)
			token = Line.substr(start, end - start);
		else
			token = Line.substr(start, Line.length() - start);
		tokens.push_back(token);
		start = end + 1;
	} while (end != string::npos);
	return tokens;
}

void Data::Order(string Filename)
{
	string d = Filename;
	vector<string> product;
	vector<int> price;
	vector<int> quantity;
	vector<string> tokens;
	string Name{Filename += ".txt"};
	fstream file{Name};
	string line;
	if (file.is_open())
	{
		int prices, amount;
		string name;
		// cout<<"File open"<<endl;
		while (getline(file, line))
		{
			tokens = tokenise(line, ';');
			if (tokens.size() != 3)
			{
				continue;
			}
			try
			{
				name = tokens[0];
				prices = stoi(tokens[1]);
				amount = stoi(tokens[2]);
			}
			catch (const exception &e)
			{
				//  cerr << e.what() << '\n';
				continue;
			}
			price.push_back(prices);
			quantity.push_back(amount);
			product.push_back(name);
		}
	}

	system("cls");

	int choice = 0;
	cout << endl
		 << "\t\t\t\t\t\t" << d << "   Products" << endl
		 << endl;
	cout << "serial number: \t\t-Medicine Names: \t\tPrice: \t\t-Quantity:" << endl;
	cout << endl;
	for (int i = 0; i < product.size(); i++)
	{
		cout << i + 1 << "\t\t\t" << product[i] << "\t\t\t" << price[i] << "\t\t\t" << quantity[i] << endl;
	}
	cout << endl
		 << endl;
	int c = 1;
	int serial_no;
AGAIN:
	cout << "Enter the serial number to select the item: ";
	cin >> serial_no;
	serial_no = serial_no - 1;
	product_in_cart[cart_count] = serial_no;
	cout << product[serial_no] << "\t" << price[serial_no] << endl;
	int quant;
START:
	cout << "Enter the quantity of the items: " << endl;
	cin >> quant;
	if (quant <= quantity[serial_no])
	{
		if (quant > 0)
		{
			quantity_in_cart[cart_count] = quant;
			cart_count++;
			int x = quantity[serial_no] - quant;
			quantity.at(serial_no) = x;
			file.open(Name, ios::out);
			if (file.is_open())
			{
				for (int i = 0; i < product.size(); i++)
				{
					file << product[i] << ";" << price[i] << ";" << quantity[i] << endl;
				}
				file.close();
			}
			else
			{
				cout << "Error in opening the file" << endl;
			}
			cout << "**************************    Item added to cart.    **********************************************" << endl;

			int back; // This variable is for to go back to home
			cout << "Press -1 to go back home menu\nOr Enter another number to continue\nOr Enter -2 to go to cart: ";
			cin >> back;

			if (back == -1)
			{
				system("cls");
				home();
			}
			else if (back == -2)
			{
				system("cls");
				recipt(product, price);
			}
			else
			{
				goto AGAIN;
			}
		}
		else
		{
			cout << "You have entered 0 quantity. Please enter a valid quantity." << endl;
			goto START;
		}
	}
	else
	{
		cout << "We don't have this much in stock right now! " << endl;
		goto START;
	}
}
