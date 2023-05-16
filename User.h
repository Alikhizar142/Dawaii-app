#pragma once
#include"Base.h"
#include "Data.h"
class User :public Base
{
	string username;
	string password;
public:
	Data d;
	User();
	void registers();
	void userLogin();
	void forget();
};