#pragma once
#include"admin.h"
#include"User.h"

class Shop
{
	admin *ad;
	User *us;
public:
	Shop(User&);
	Shop(admin&);
	void adminPanel();
};

