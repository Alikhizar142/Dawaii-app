#include "Shop.h"
Shop::Shop(admin &ads)
{
}

Shop::Shop(User &us)
{
}

void Shop::adminPanel()
{
	system("cls");
	system("Color B4");
	int choice;
	cout << "************************************************************************************************************************" << endl;
	cout << "*****************                            -Press 1 to Add Category:                                  ****************" << endl;
	cout << "*****************                            -Press 2 to delete Category:                               ****************" << endl;
	cout << "*****************                            -Press 3 to Add Product:                                   ****************" << endl;
	cout << "*****************                            -Press 4 to Delete Product:                                ****************" << endl;
	cout << "*****************                            -Press 5 to Modify Product:                                ****************" << endl;
	cout << "*****************                            -Press 6 to Delete User:                                   ****************" << endl;
	cout << "*****************                            -Press 0 to go back :                                      ****************" << endl;
	cout << "*****************                            -Enter your choice:                                        ****************" << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << "\t\t\t\t\t\t ";
	cin >> choice;
	switch (choice)
	{
	case 0:
		ad->menu();
		break;
	case 1:
		if (ad->addCategory())
		{
			adminPanel();
		}
		break;
	case 2:
		if (ad->deleteCategory())
		{
			adminPanel();
		}
	case 3:
		if (ad->addProduct())
		{
			adminPanel();
		}
		break;
	case 4:
		if (ad->deleteProduct())
		{
			adminPanel();
		}
		break;
	case 5:
		if (ad->modifyProduct())
		{
			adminPanel();
		}
	case 6:
		if (ad->deleteUser())
		{
			adminPanel();
		};
		break;
	}
}
