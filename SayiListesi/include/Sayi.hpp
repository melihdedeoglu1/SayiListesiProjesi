#ifndef SAYI_HPP
#define SAYI_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

#include "Basamak.hpp"

using namespace std;

class Sayi {
	
	public:		
		Basamak* basamakBaslangici;
	
		Sayi();  
		~Sayi();
		
		void sayiyiBasamaklaraAyirma(int);

		void sayiyiTersCevirme();
	
		void sayiyiGosterme();
		
		int basamakSayisi() const;
		
		int BasamaklarinDegeriniAl();
		
};

#endif