#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

class SayilarListesi {

public:
	
	Dugum* dugumBaslangic;
	
	SayilarListesi();
		
	~SayilarListesi();
	
	void yazdirBasSon(int);
	
    void yazdirOrta(int);
	
    void sayiDugumuEkleme(Sayi*);
	
	void listeyiGosterme();
	
    void cevrilmisListeyiGosterme(bool);
	
	void tekBasamaklilariBasaAlma();
	
	void enBuyukSayiyiCikarma();
	
};

#endif