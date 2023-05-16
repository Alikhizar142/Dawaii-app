#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class Data
{
public:
	Data();
	void recipt(vector<string>name,vector<int> price);
	void welcome();
	void home();
	void Order(string Filename);
	vector < string> tokenise( string csvLine, char separator);
	vector <string>categories;
		int cart_count = 0;
	int product_in_cart[10000];
	int quantity_in_cart[10000];
	// string names[60] = { "Skin whitening", "Parodontax org", "Prodent Tpaste", "Minox solution", "Foltn hair men",
	// 	"Fltn hair women", "Hair life caps", "cas l day cream", "Mandl ac serum", "Antiseptic gel",
	// 	"Morinaga BF-1", "Morinafa BF-3", "Pediasure", "Baby balm", "Nestle NAN-1", "Similac total 2",
	// 	"baby lotion", "baby soap", "baby wipes", "pampers:", "canderel sweetener", "digas tablets khatti",
	// 	"digas syrup special", "hi clean hand foam", "first aid box piece", "hiclean water purific",
	// 	"herbion verona plus", "pediasure chocolate", "hashmi ispaghol sachet", "plasaline inf piece",
	// 	"activated charcoal", "johar joshanda sachet", "tooth rus pieces", "toothsiah syrup bottle",
	// 	"herbion ispaghol", "hiclean water purific", "herbion verona plus", "pediasure chocolate",
	// 	"hashmi ispaghol sachet", "plasaline inf piece", "Victorinox swis", "Victorinox Alox",
	// 	"Dettol Solution", "Dettol Cleaner ", "KN95 Mask Piece", "Mospel Repelent", "Beurer For Back",
	// 	"Saniplast Packs", "MG Body Massage", "Heating Pad MG9", "Nebulizer NB-607", "Normal saline 25",
	// 	"S Flamingo Ankle", "S Flamingo Elbow", "Dawai Wheelchair", "Nipro Syringe10c", "Accu-check Strip",
	// 	"Acu-check Active", "Ankle Binder (S)", "Arm Pouch  Small" };

	// vector<int> serial={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
	// 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
	// 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};

	// int amount[60] = { 12, 25, 42, 50, 100, 23, 54, 60, 125, 34, 120, 250, 420, 500, 1000, 123,
	// 	145, 340, 234, 560, 144, 117, 108, 675, 1350, 1791, 207, 292, 2500, 60, 120,
	// 	150, 100, 600, 130, 191, 227, 290, 2550, 600, 105, 10, 130, 643, 120, 151,
	// 	257, 200, 2500, 450, 50, 80, 430, 63, 20, 100, 27, 265, 250, 550 };
		
	// int quantity[60] = { 12, 21, 31, 44, 51, 43, 56, 23, 64, 45, 15, 41, 34, 44, 66, 43, 23, 56, 74, 34,
	// 	40, 46, 23, 64, 24, 78, 35, 65, 26, 45, 15, 41, 34, 44, 66, 12, 35, 56, 43, 50, 25,
	// 	48, 24, 47, 36, 15, 25, 50, 53, 45, 34, 56, 23, 57, 65, 58, 44, 76, 55, 33 };
	
};

