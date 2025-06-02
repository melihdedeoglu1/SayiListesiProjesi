#include "Basamak.hpp"
#include "Sayi.hpp"

	Sayi::Sayi(){		
		basamakBaslangici=NULL;
	} 
	
	Sayi::~Sayi() {
        
        if (basamakBaslangici != nullptr) {
            delete basamakBaslangici;
            basamakBaslangici = nullptr;
        }
    }
	
    void Sayi::sayiyiBasamaklaraAyirma(int okunanSayi) {
		
        Basamak* sonBasamak = nullptr;
        while (okunanSayi != 0) {
            int basamakDegeri = okunanSayi % 10;
            Basamak* yeniBasamak = new Basamak(basamakDegeri);

            if (sonBasamak == nullptr) {
                basamakBaslangici = yeniBasamak;
            } 
			else{
                yeniBasamak->basamakNext = sonBasamak;
                basamakBaslangici = yeniBasamak;
            }

            sonBasamak = yeniBasamak;
            okunanSayi /= 10;
        }
    }

    void Sayi::sayiyiTersCevirme() {
        Basamak* onceki = nullptr;
        Basamak* simdiki = basamakBaslangici;
        Basamak* sonraki = nullptr;

        while (simdiki != nullptr) {
            sonraki = simdiki->basamakNext;
            simdiki->basamakNext = onceki;
            onceki = simdiki;
            simdiki = sonraki;
        }

        basamakBaslangici = onceki;
    }
	
	void Sayi::sayiyiGosterme() {
        Basamak* geciciBasamak = basamakBaslangici;
		string a;
        while (geciciBasamak != nullptr) {
			
            a+= to_string(geciciBasamak->basamakDeger);
			
            geciciBasamak = geciciBasamak->basamakNext;
        }
		int b = stoi(a);
		cout<<setw(10)<<b;
    }
	
	int Sayi::basamakSayisi() const {
        int basamak_Sayisi = 0;
        Basamak* geciciBasamak = basamakBaslangici;

        while (geciciBasamak != nullptr) {
            basamak_Sayisi++;
            geciciBasamak = geciciBasamak->basamakNext;
        }

        return basamak_Sayisi;
    }
	
	
	int Sayi::BasamaklarinDegeriniAl() {
		int deger = 0;
		
		Basamak* tempBasamak = basamakBaslangici;
		
		while (tempBasamak != NULL) {
			deger = deger * 10 + tempBasamak->basamakDeger;
			tempBasamak = tempBasamak->basamakNext;
		}

		return deger;
}
	
	
	
	