#include "Basamak.hpp"


	Basamak::Basamak(int basamakDeger){
		
		this->basamakDeger=basamakDeger;
		basamakNext=NULL;
		
	}
	
	Basamak::~Basamak() {
        
        if (basamakNext != nullptr) {
            delete basamakNext;
            basamakNext = nullptr;
        }
    }
	