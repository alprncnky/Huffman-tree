/**
* @testprogram
* @BU PROGRAM TXT DOSYALARI HUFFMAN AGACI KULLANILARAK SIKISTIRILMA VE GERI OKUMA ISLEMI YAPIYOR
* @VERI YAPILARI 1A
* @4.ODEV
* @BASLANGIC TARIHI: 19/12/2017
* @ALPEREN CINKAYA alperen.cinkaya@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

		Dugum::Dugum(char kr,int frek, Dugum* sl,Dugum *sg){
			karakter=kr;
			frekans=frek;
			sol=sl;
			sag=sg;
			kod="";
		}
		bool Dugum::Yaprakmi() const{
			if(sol == NULL && sag == NULL) return true;
			return false;
		}
		bool Dugum::operator==(Dugum& sag){
			if(this->karakter == sag.karakter) return true;
			else return false;
		}
		bool Dugum::operator!=(Dugum& sag){
			if(this->karakter != sag.karakter) return true;
			else return false;
		}
		bool Dugum::operator>(Dugum& sag){
			if(this->frekans > sag.frekans) return true;
			else return false;
		}