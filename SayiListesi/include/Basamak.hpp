#ifndef BASAMAK_HPP
#define BASAMAK_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

class Basamak {
	
	public:
		int basamakDeger;
		Basamak* basamakNext;

		Basamak(int);
		~Basamak();
};

#endif