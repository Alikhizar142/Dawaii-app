#pragma once
#include"Base.h"
#include"data.h"
#include"Product.h"
class admin :public product,public Base{
	string username;
	string password;
public:
	admin();
	void login();
	int addCategory();
	int deleteCategory();
	int addProduct();
	int deleteProduct();
	int modifyProduct();
	int deleteUser();
};
