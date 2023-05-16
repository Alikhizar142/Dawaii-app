#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"data.h"
#include<string>
using namespace std;
class product:public Data{
    vector<string> Product;
    vector<int> price;
    vector<int> quantity;
public:
	void addProduct(string);
	void deleteProduct(string);
	void modifyProduct(string);
};