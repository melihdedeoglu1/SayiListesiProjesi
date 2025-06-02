#include "Basamak.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"
#include "SayilarListesi.hpp"

	SayilarListesi::SayilarListesi(){
		dugumBaslangic=NULL;
	} 
	
	SayilarListesi::~SayilarListesi() {
        
        if (dugumBaslangic != NULL) {
            delete dugumBaslangic;
            dugumBaslangic = NULL;
        }
    }
	
	void SayilarListesi::yazdirBasSon(int sayi){
		cout<<"############"<<"   ";
		for(int i=0; i<sayi;i++){
		cout<<"*******"<<"   ";
		}
		cout<<endl;
	}
	
    void SayilarListesi::yazdirOrta(int sayi){
		cout<<"#----------#"<<"   ";
		for(int i=0; i<sayi;i++){
		cout<<"*******"<<"   ";
		}
		cout<<endl;
	}

    void SayilarListesi::sayiDugumuEkleme(Sayi* deger) {
		
        Dugum* eklenecekDugum = new Dugum(deger);

        if (dugumBaslangic == nullptr) {
            dugumBaslangic = eklenecekDugum;
        } 
		else{
            Dugum* geciciDugum = dugumBaslangic;
            while (geciciDugum->dugumNext != nullptr) {
                geciciDugum = geciciDugum->dugumNext;
            }
            geciciDugum->dugumNext = eklenecekDugum;
        }
		
    }
 
	void SayilarListesi::listeyiGosterme(){
		
        Dugum* geciciDugum = dugumBaslangic;
		int basamakadeti;
		
        while (geciciDugum != nullptr) {
			
			basamakadeti=geciciDugum->sayiBaslangic->basamakSayisi();
			
			yazdirBasSon(basamakadeti);
            
            cout << "#" <<setw(10)<< geciciDugum->sayiBaslangic << "#" ;
			
			Basamak* geciciBasamak = geciciDugum->sayiBaslangic->basamakBaslangici;
			
            while (geciciBasamak != nullptr) {
				
				uintptr_t address = reinterpret_cast<uintptr_t>(geciciBasamak);
				int lastThreeDigits = address % 1000;
			
                cout << setw(4)<<"*" <<hex <<setw(4) << lastThreeDigits <<dec<<" *" ;
				               
                geciciBasamak = geciciBasamak->basamakNext;
            }
			
			cout<<endl;		
			yazdirOrta(basamakadeti);
			
            cout << "#";		
			geciciDugum->sayiBaslangic->sayiyiGosterme();		
			cout << "#";
			
			geciciBasamak = geciciDugum->sayiBaslangic->basamakBaslangici;
			
			while (geciciBasamak != nullptr) {
               
                cout <<setw(4)<< "*" <<setw(3)<< geciciBasamak->basamakDeger << "  *" ;
                
                geciciBasamak = geciciBasamak->basamakNext;
            }
			
			cout << endl;			
			yazdirBasSon(basamakadeti);           			
            cout << endl;
			
            geciciDugum = geciciDugum->dugumNext;
        }
		
    }
	
    void SayilarListesi::cevrilmisListeyiGosterme(bool tersi){    //listeyi terse çevirip gösterme işlemini yaptım 
		
        Dugum* geciciDugum = dugumBaslangic;
		int basamakadeti;
		
        while (geciciDugum != nullptr) {
			
            basamakadeti=geciciDugum->sayiBaslangic->basamakSayisi();
			
			yazdirBasSon(basamakadeti);
			
            cout << "#" <<setw(10)<< geciciDugum->sayiBaslangic << "#" ;
			
			if (tersi) {
                geciciDugum->sayiBaslangic->sayiyiTersCevirme();
            }
			
			Basamak* geciciBasamak = geciciDugum->sayiBaslangic->basamakBaslangici;
			
			 while (geciciBasamak != nullptr) {
			
				uintptr_t address = reinterpret_cast<uintptr_t>(geciciBasamak);
				int lastThreeDigits = address % 1000;
			
                cout << setw(4)<<"*" <<hex<<setw(4) << lastThreeDigits <<dec<<" *" ;
				               
                geciciBasamak = geciciBasamak->basamakNext;
            }
			
			cout<<endl;			
			yazdirOrta(basamakadeti);
			
            cout << "#";			
			geciciDugum->sayiBaslangic->sayiyiGosterme();		
			cout << "#";
			
			geciciBasamak = geciciDugum->sayiBaslangic->basamakBaslangici;
			
			while (geciciBasamak != nullptr) {
                
                cout <<setw(4)<< "*" <<setw(3)<< geciciBasamak->basamakDeger << "  *" ;
                
                geciciBasamak = geciciBasamak->basamakNext;
            }
			
			cout << endl;
			yazdirBasSon(basamakadeti);       	
            cout << endl;
			
            geciciDugum = geciciDugum->dugumNext;
        }		
    }
	
	void SayilarListesi::tekBasamaklilariBasaAlma() { 
		Dugum* geciciDugum = dugumBaslangic;
		
		while (geciciDugum != NULL) {
			Basamak* geciciBasamak = geciciDugum->sayiBaslangic->basamakBaslangici;
			Basamak* tekBasamaklar = NULL;
			Basamak* ciftBasamaklar = NULL;
			Basamak* sonTekBasamak = NULL;    
			Basamak* sonCiftBasamak = NULL;	  

			while (geciciBasamak != NULL) {
				Basamak* gecici = geciciBasamak;
				geciciBasamak = geciciBasamak->basamakNext;
				gecici->basamakNext = NULL;

				if (gecici->basamakDeger % 2 == 1) {
					if (tekBasamaklar == NULL) {
						tekBasamaklar = gecici;
						sonTekBasamak = gecici;
					} 
					else {
                    sonTekBasamak->basamakNext = gecici;
                    sonTekBasamak = gecici;
					}
				}
				else {
					if (ciftBasamaklar == NULL) {
						ciftBasamaklar = gecici;
						sonCiftBasamak = gecici;
					}
					else {
						sonCiftBasamak->basamakNext = gecici;
						sonCiftBasamak = gecici;
					}
				}
			}

			if (tekBasamaklar != NULL) {
				sonTekBasamak->basamakNext = ciftBasamaklar;
				geciciDugum->sayiBaslangic->basamakBaslangici = tekBasamaklar;
			}
			else{
				geciciDugum->sayiBaslangic->basamakBaslangici = ciftBasamaklar;
			}

			geciciDugum = geciciDugum->dugumNext;
		}
	}
	
	void SayilarListesi::enBuyukSayiyiCikarma() {
		
		if (dugumBaslangic == NULL) {
			cout << "Listede eleman yok." << endl;
			return;
		}

		Dugum* enBuyukDugum = dugumBaslangic;
		Dugum* simdikiDugum = dugumBaslangic->dugumNext;
		
		int enBuyukDeger = enBuyukDugum->sayiBaslangic->BasamaklarinDegeriniAl();

		while (simdikiDugum != NULL) {
			int sayiDegeri = simdikiDugum->sayiBaslangic->BasamaklarinDegeriniAl();

			if (sayiDegeri > enBuyukDeger) {
				enBuyukDeger = sayiDegeri;
				enBuyukDugum = simdikiDugum;
			}

			simdikiDugum = simdikiDugum->dugumNext;
		}

		if (enBuyukDugum == dugumBaslangic) {
			dugumBaslangic = enBuyukDugum->dugumNext;
		} else {
			Dugum* oncekiDugum = dugumBaslangic;
			while (oncekiDugum->dugumNext != enBuyukDugum) {
				oncekiDugum = oncekiDugum->dugumNext;
			}
			oncekiDugum->dugumNext = enBuyukDugum->dugumNext;
		}

	}
	
	
	
	
	
	
	
	