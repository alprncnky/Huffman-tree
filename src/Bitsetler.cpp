/**
* @testprogram
* @BU PROGRAM TXT DOSYALARI HUFFMAN AGACI KULLANILARAK SIKISTIRILMA VE GERI OKUMA ISLEMI YAPIYOR
* @VERI YAPILARI 1A
* @4.ODEV
* @BASLANGIC TARIHI: 19/12/2017
* @ALPEREN CINKAYA alperen.cinkaya@ogr.sakarya.edu.tr
*/

#include "Bitsetler.hpp"

string Bitsetler::bital(char a)
{
	rakam = "";
	bitset<8> bitset2(a);
	for (int i = 0; i < 8; i++)
	{
		if (bitset2[i] == 1)
		{
			rakam += "1";
		}
		else
		{
			rakam += "0";
		}
	}
	return rakam;
}