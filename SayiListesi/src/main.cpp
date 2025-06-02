#include "Basamak.hpp"
#include "Sayi.hpp"
#include "Dugum.hpp"
#include "SayilarListesi.hpp"

using namespace std;

int main() {
	
    SayilarListesi liste;

    ifstream dosyaOkuma("Sayilar.txt");
    if (dosyaOkuma.is_open()) {
		
        string satir;
        while (getline(dosyaOkuma, satir)) {
			
            istringstream satirAtama(satir);
            int okunanSayi;
            while (satirAtama >> okunanSayi) {
				
                Sayi* sayi = new Sayi();
				liste.sayiDugumuEkleme(sayi);				
                sayi->sayiyiBasamaklaraAyirma(okunanSayi);
				
            }
        }
        dosyaOkuma.close();
    }
	
	liste.listeyiGosterme();
	
	string secenek;
	
	do {
		cout<<endl;
		cout<<"1.Tek basamaklari Basa Al"<<endl;
		cout<<"2.Basamaklari Tersle"<<endl;
		cout<<"3.En Buyuk Cikar"<<endl;
		cout<<"4.cikis"<<endl;
		
		do{				
			cin>>secenek;	
			
			if(!(secenek=="1" || secenek=="2" || secenek=="3" || secenek=="4")){
				
				cout<<endl<<"Lutfen 1,2,3 veya 4 tuslayiniz.!!"<<endl<<endl;					
				cout<<"1.Tek basamaklari Basa Al"<<endl;
				cout<<"2.Basamaklari Tersle"<<endl;
				cout<<"3.En Buyuk Cikar"<<endl;
				cout<<"4.cikis"<<endl;
			}
					
		}while(!(secenek=="1" || secenek=="2" || secenek=="3" || secenek=="4"));
			
		int secenekInt=stoi(secenek);
		
		switch (secenekInt){
			
			case 1:{
				
				liste.tekBasamaklilariBasaAlma();
				liste.listeyiGosterme();
				break;
			}
			case 2:{
				
				liste.cevrilmisListeyiGosterme(1);
				break;
			}
			case 3:{
				
				liste.enBuyukSayiyiCikarma();
				liste.listeyiGosterme();
				break;
			}
			case 4:{
								
				return 0;
			}
					
		};
		
		if(secenek=="1" || secenek=="2" || secenek=="3" || secenek=="4"){
			continue;
		}
			
	}while(secenek=="1" || secenek=="2" || secenek=="3" || secenek=="4");
	
	
	
					
    return 0;
}