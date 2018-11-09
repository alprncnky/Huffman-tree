#ifndef ISLEM_HPP
#define ISLEM_HPP

#include <bitset>
#include "Bitsetler.hpp"
#include "Huffman.hpp"

class Islem
{
private:
	string dosyaPath;			// abc.txt  gir
	string input;
	string line;
	string line2;
	string bitdata;				// 101010111011010... lari tutan bitdata stringi
	string in_bitdata;			// bit.data dosyasindan bu stringe gelsin  &%%&£%%/6^##%... halinde oluscak
	string oneszeros;			// in_bitdata stringini 1010101011 haline getir   ( zip li 101010 lar bunlar )
	string output;				//ekrana yazilacak string ( Lorem, inpus... )
	string get_tablo_str;		// dosyadan Tablo.txt oku buna gecir

	Huffman *nesn = new Huffman();

	void txtduzenle();		// txt deki bosluklari "@" ve satir sonlarini ">" yaptik.

	void hfm_okut();			// girdi=input yapiyor Huffman fonksiyonalri icin		Huffman Agac olusuyor

	void yazdir();			//tablo icin string olusturuyor.     ---- TODO: string i yolla

	void tablo_txt();

	void bit_dat_write_str();			// burayi kontrol et

	void create_bit_dat_file();

	void read_bit_dat_file();			// bit.data dan okuduk 1010101.. string olustu aratma yap	--- Hata --- eksik aliyor

	void convert_with_table();			//oneszeros tan cagir sirayla tarayip bak tabloda eslesme varmi

public:

	void compress();

	void open();

	string get_output();

	~Islem();

};


#endif