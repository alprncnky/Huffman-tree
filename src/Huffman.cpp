/**
* @testprogram
* @BU PROGRAM TXT DOSYALARI HUFFMAN AGACI KULLANILARAK SIKISTIRILMA VE GERI OKUMA ISLEMI YAPIYOR
* @VERI YAPILARI 1A
* @4.ODEV
* @BASLANGIC TARIHI: 19/12/2017
* @ALPEREN CINKAYA alperen.cinkaya@ogr.sakarya.edu.tr
*/

#include "Huffman.hpp"

Huffman::Huffman(){
			harfler = 256;
			girdi="";
			tablostr = "";
			root=NULL;
		}

void Huffman::Al(string words)
{
	girdi = words;
}

void Huffman::DosyaOku(string dosyaYolu)throw(string){
	string satir;
	ifstream dosya(dosyaYolu.c_str());
	if (dosya.is_open())
	{
		while (getline(dosya,satir))
		{
			girdi+=satir;
			girdi+='>';
		}
		dosya.close();
	}
	else throw "Dosya acilamadi"; 
}
void Huffman::Kodla(){
	char karakterler[girdi.size()-1];
	
	strcpy(karakterler, girdi.c_str());
	
	//Frekanslarý say
	int frek[harfler]; 
	// frekanslarý sýfýrla
	for(int i=0;i<harfler;i++)frek[i] = 0;
	
	for (int i = 0; i < girdi.size()-1; i++)
		frek[karakterler[i]]++;
	
	// Huffman aðacýný oluþtur
	root = AgacOlustur(frek);
	
	// 01 kodlar oluþturuluyor
	KodOlustur(root, "");
}	
Dugum* Huffman::AgacOlustur(int frek[]){
	// dosyada var olan karakterler için düðüm oluþtur.
	Dugum* dugumler[harfler];
	for(int i=0;i<harfler;i++){
		if(frek[i]>0){
			dugumler[i] = new Dugum((char)i,frek[i]);
		}
		else{
			dugumler[i] = NULL;
		}
	}
	while(true){
		int ilkIndeks = MinDugumIndeks(dugumler);				
		Dugum *min1 = dugumler[ilkIndeks];
		dugumler[ilkIndeks] = NULL;
		int ikinciIndeks = MinDugumIndeks(dugumler);
		if(ikinciIndeks == -1){
			return min1;
		}
		Dugum *min2 = dugumler[ikinciIndeks];
		dugumler[ikinciIndeks] = NULL;
		dugumler[ilkIndeks] = new Dugum(0,min1->frekans+min2->frekans,min1,min2);
	}
	
}
int Huffman::MinDugumIndeks(Dugum* dugumler[]){
	Dugum* min;
	int minIndeks=-1;
	// ilk null olmayan düðümü min al
	for(int i=0;i<harfler;i++){
		if(dugumler[i] != NULL){
			min = dugumler[i];
			minIndeks = i;
			break;
		}
	}
	
	for(int i=0;i<harfler;i++)
	{
		if(dugumler[i] == NULL) continue;
		
		if(*min > *(dugumler[i])) {
			min = dugumler[i];
			minIndeks = i;
		}
	}
	return minIndeks;
}
void Huffman::KodOlustur(Dugum* alt_dugum,string kod){
	if(!alt_dugum->Yaprakmi()){
		KodOlustur(alt_dugum->sol,kod+'0');
		KodOlustur(alt_dugum->sag,kod+'1');
	}
	else{
		alt_dugum->kod = kod;
	}
}
ostream& operator<<(ostream& ekran,Huffman& sag){
	ekran<<"Huffman Agacindaki Karakterler ve Kodlari:"<<endl;
	sag.inorder(sag.root);
	return ekran;
}
void Huffman::inorder(Dugum* alt_dugum){
	if(alt_dugum != NULL){
		inorder(alt_dugum->sol);
		if(alt_dugum->Yaprakmi()) cout<<alt_dugum->karakter<<":"<<alt_dugum->kod<<endl;
		inorder(alt_dugum->sag);
	}
}

void Huffman::kokcagir(Huffman& sag)
{
	sag.tablotxt(sag.root);
}

void Huffman::tablotxt(Dugum* alt_dugum)
{
	if (alt_dugum != NULL) {
		tablotxt(alt_dugum->sol);
		if (alt_dugum->Yaprakmi()){
			tablostr += alt_dugum->karakter;
			tablostr += alt_dugum->kod;
			}
		tablotxt(alt_dugum->sag);
	}
}

void Huffman::yaz()
{
	cout << tablostr<<endl;
}

void Huffman::SilDugum(Dugum* alt_dugum){
	if(alt_dugum == NULL) return;
	SilDugum(alt_dugum->sol);
	SilDugum(alt_dugum->sag);
	delete alt_dugum;
	alt_dugum = NULL;
}
Huffman::~Huffman(){
	// Çöp oluþmamasý için aðaç temizleniyor.
	SilDugum(root);	
}