/**
* @testprogram
* @BU PROGRAM TXT DOSYALARI HUFFMAN AGACI KULLANILARAK SIKISTIRILMA VE GERI OKUMA ISLEMI YAPIYOR
* @VERI YAPILARI 1A
* @4.ODEV
* @BASLANGIC TARIHI: 19/12/2017
* @ALPEREN CINKAYA alperen.cinkaya@ogr.sakarya.edu.tr
*/

#include "Islem.hpp"

int main(){

	system("cls");
	cout << "<-------- SIKISTIRMA PROGRAMI -------->" << endl;
	cout << "1- DOSYAYI SIKISTIR" << endl;
	cout << "2-SIKISTIRILMIS DOSYAYI EKRANA YAZ" << endl;
	cout << "SECIMINIZ :";
	int sayi;
	cin >> sayi;
	while (sayi != 1 && sayi != 2)
	{
		cout << "YANLIS GIRIS YAPTINIZ.TEKRAR DENEYINIZ..." << endl;
		cout << "SECIMINIZ :";
		cin >> sayi;
	}
	if (sayi == 1)
	{
		cout << "DOSYA ADI : ";
		Islem *nesne = new Islem();
		nesne->compress();				//	<---- SIKISTIRMA 
		delete nesne;
		cout << "ISLEMINIZ BASARIYLA GERCEKLESTI" << endl;
	}
	else if (sayi == 2)
	{
		Islem *nesne = new Islem();
		nesne->open();				//	<---- ACIP OKU
		cout << nesne->get_output();
	}

	return 0;
}