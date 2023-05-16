#include "Product.h"

void product::addProduct(string fname)
{
	system("cls");
	system("color F5");
	Product.clear();
	price.clear();
	quantity.clear();
	string choice = fname + ".txt";
	vector<string> temp;
	fstream file{choice};
	string read;
	string N;
	int p, amount;
	//  file.open(choice, ios::out | ios::in |ios::app);
	while (!file.eof())
	{
		getline(file, read);
		temp = Data::tokenise(read, ';');
		if (temp.size() != 3)
		{
			continue;
		}
		try
		{
			N = temp[0];
			p = stoi(temp[1]);
			amount = stoi(temp[2]);
		}
		catch (const exception &e)
		{
			cerr << e.what() << '\n';
			continue;
		}

		Product.push_back(N);
		price.push_back(p);
		quantity.push_back(amount);
	}
	file.close();

	cout << "--------------------------------------------  " << fname << "  --------------------------------------\n";
	cout << "serial number: \t-Medicine Names: \tPrice: \t-Quantity" << endl;
	for (int i = 0; i < Product.size(); i++)
	{
		cout << i + 1 << "\t\t" << Product[i] << "\t\t" << price[i] << "\t\t" << quantity[i] << endl;
	}
	cout << endl
		 << endl;
	cout << "----------------------------------------------------------------------------------------------------------\n";
	cout << "Enter the Product name you want to add : " << endl;
	string n;
	cin >> n;
	cout << "Enter Product price:" << endl;
	int pr;
	cin >> p;
	cout << "Enter Product Quantity" << endl;
	int qu;
	cin >> qu;
	Product.push_back(n);
	price.push_back(pr);
	quantity.push_back(qu);
	file.open(choice, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < Product.size(); i++)
		{
			file << Product[i] << ";" << price[i] << ";" << quantity[i] << endl;
		}
	}
	file.close();
}

void product::deleteProduct(string fname)
{
	system("cls");
	system("color F5");
	Product.clear();
	price.clear();
	quantity.clear();
	string choice = fname + ".txt";
	vector<string> temp;
	fstream file{choice};
	string read;
	string N;
	int p, amount;
	// file.open(choice, ios::out | ios::in| ios::app);
	while (!file.eof())
	{
		getline(file, read);
		temp = Data::tokenise(read, ';');
		if (temp.size() != 3)
		{
			continue;
		}
		try
		{
			N = temp[0];
			p = stoi(temp[1]);
			amount = stoi(temp[2]);
		}
		catch (const exception &e)
		{
			cerr << e.what() << '\n';
			continue;
		}
		Product.push_back(N);
		price.push_back(p);
		quantity.push_back(amount);
	}
	file.close();

	cout << "--------------------------------------------  " << fname << "  --------------------------------------\n";
	cout << "serial number: \t\t-Medicine Names: \t\tPrice: \t-Quantity" << endl;
	for (int i = 0; i < Product.size(); i++)
	{
		cout << i + 1 << "\t\t\t" << Product[i] << "\t\t" << price[i] << "\t\t" << quantity[i] << endl;
	}
	cout << endl
		 << endl;
	cout << "----------------------------------------------------------------------------------------------------------\n";
Top:
	cout << "Enter the serial Number you want to delete : " << endl;
	int sn;
	cin >> sn;
	if (sn > Product.size())
	{
		cout << "Invalid serial number" << endl;
		goto Top;
	}
	else
	{
		sn = sn - 1;
		Product.erase(Product.begin() + sn);
		price.erase(price.begin() + sn);
		quantity.erase(quantity.begin() + sn);
	}
	file.open(choice, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < Product.size(); i++)
		{
			file << Product[i] << ";" << price[i] << ";" << quantity[i] << endl;
		}
	}
	file.close();
}
void product::modifyProduct(string fname)
{
	system("cls");
	system("color B6");
	Product.clear();
	price.clear();
	quantity.clear();
	string choice = fname + ".txt";
	vector<string> temp;
	fstream file{choice};
	string read;
	string N;
	int p, amount;
	// file.open(choice, ios::out | ios::in |ios::app);
	while (!file.eof())
	{
		getline(file, read);
		temp = Data::tokenise(read, ';');
		if (temp.size() != 3)
		{
			continue;
		}
		try
		{
			N = temp[0];
			p = stoi(temp[1]);
			amount = stoi(temp[2]);
		}
		catch (const exception &e)
		{
			cerr << e.what() << '\n';
			continue;
		}
		Product.push_back(N);
		price.push_back(p);
		quantity.push_back(amount);
	}
	file.close();

	cout << "--------------------------------------------  " << fname << "  --------------------------------------\n";
	cout << "serial number: \t-Medicine Names: \tPrice: \t-Quantity" << endl;
	for (int i = 0; i < Product.size(); i++)
	{
		cout << i + 1 << "\t\t" << Product[i] << "\t\t" << price[i] << "\t\t" << quantity[i] << endl;
	}
	cout << endl
		 << endl;
	cout << "----------------------------------------------------------------------------------------------------------\n";
Top:
	cout << "Enter the serial Number you want to Edit: " << endl;
	int sn;
	cin >> sn;
	if (sn > Product.size())
	{
		cout << "Invalid serial number" << endl;
		goto Top;
	}
	else
	{
		sn = sn - 1;
		string n;
		int pr, q;
		cout << "Enter New Name" << endl;
		cin >> n;
		cout << "Enter New price " << endl;
		cin >> pr;
		cout << "Enter New Quantity " << endl;
		cin >> q;
		Product.at(sn) = n;
		price.at(sn) = (pr);
		quantity.at(sn) = (q);
	}
	file.open(choice, ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < Product.size(); i++)
		{
			file << Product[i] << ";" << price[i] << ";" << quantity[i] << endl;
		}
	}
	file.close();
}