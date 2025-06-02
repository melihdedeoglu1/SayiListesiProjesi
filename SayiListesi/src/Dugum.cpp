#include "Sayi.hpp"
#include "Dugum.hpp"

		Dugum::Dugum(Sayi* deger) : sayiBaslangic(deger), dugumNext(NULL) {}
		
		Dugum::~Dugum(){
        
			if (sayiBaslangic != NULL) {
				delete sayiBaslangic;
				sayiBaslangic = NULL;
			}

			if (dugumNext != NULL) {
				delete dugumNext;
				dugumNext = NULL;
			}
		}