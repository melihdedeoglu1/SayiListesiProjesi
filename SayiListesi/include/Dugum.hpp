#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

class Dugum {
	
	public:
		Sayi* sayiBaslangic;
		Dugum* dugumNext;

		Dugum(Sayi*);
		~Dugum();
};

#endif