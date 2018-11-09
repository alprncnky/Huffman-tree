/**
* @testprogram
* @BU PROGRAM TXT DOSYALARI HUFFMAN AGACI KULLANILARAK SIKISTIRILMA VE GERI OKUMA ISLEMI YAPIYOR
* @VERI YAPILARI 1A
* @4.ODEV
* @BASLANGIC TARIHI: 19/12/2017
* @ALPEREN CINKAYA alperen.cinkaya@ogr.sakarya.edu.tr
*/

#include "Islem.hpp"


void Islem::txtduzenle()								// txt deki bosluklari "@" ve satir sonlarini ">" yaptik.
{
	cin >> dosyaPath;
	ifstream dosya(dosyaPath.c_str());
	if (dosya.is_open())
	{
		while (getline(dosya, line))
		{
			input += line;
			input += '>';
		}
		dosya.close();
	}
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
		{
			input[i] = '@';
		}
	}
}

void Islem::hfm_okut()
{
	nesn->Al(input);			// girdi=input yapiyor Huffman fonksiyonalri icin
	nesn->Kodla();				//Huffman Agac olusuyor
}

void Islem::yazdir()
{
	nesn->kokcagir(*nesn);				//tablo icin string olusturuyor.     ---- TODO: string i yolla
}

void Islem::tablo_txt()
{
	ofstream outputTablo("Tablo.txt");
	outputTablo << nesn->tablostr;
}


void Islem::bit_dat_write_str()												// burayi kontrol et
{
	bitdata = "";

	for (int i = 0; i<input.size(); i++)
	{
		for (int s = 0; s < nesn->tablostr.size(); s++)
		{
			if (input[i] == nesn->tablostr[s])
			{
				s = s + 1;
				while (nesn->tablostr[s] == '1' || nesn->tablostr[s] == '0')
				{
					bitdata += nesn->tablostr[s];
					s = s + 1;
				}
			}
		}
	}
}

void Islem::create_bit_dat_file()
{
	ofstream bd("Bit.dat");

	bitset<8> bitset1;
	unsigned long a;
	unsigned char b;
	int sayac = 0;
	int count = 0;
	for (int i = 0; i < bitdata.size(); i++)
	{
		if (sayac == 8)
		{
			count = count + 1;
			sayac = 0;
			a = bitset1.to_ulong();
			b = static_cast<unsigned char>(a);
			bd << b;
		}
		if (bitdata[i] == '1')
		{
			bitset1[sayac] = 1;
		}
		else if (bitdata[i] == '0')
		{
			bitset1[sayac] = 0;
		}
		sayac = sayac + 1;
	}
}

void Islem::read_bit_dat_file()									// bit.data dan okuduk 1010101.. string olustu aratma yap
{																//--- Hata --- eksik aliyor
	int length;
	char * buffer;

	in_bitdata = "";
	oneszeros = "";
	ifstream bitdosya("Bit.dat");
	if (bitdosya.is_open())
	{
		bitdosya.seekg(0, ios::end);
		length = bitdosya.tellg();

		bitdosya.seekg(0, ios::beg);
		buffer = new char[length];
		bitdosya.read(buffer, length);
		bitdosya.close();
	}

	for (int b = 0; b < length - 1; b++)
	{
		Bitsetler *bitnesne = new Bitsetler();
		oneszeros += bitnesne->bital(buffer[b]);
		delete bitnesne;
	}
}

void Islem::convert_with_table()			//oneszeros tan cagir sirayla tarayip bak tabloda eslesme varmi
{
	output = "";
	get_tablo_str = "";
	ifstream tablodosya("Tablo.txt");
	if (tablodosya.is_open())
	{
		while (getline(tablodosya, line))
		{
			get_tablo_str += line;
		}
	}

	string temp = "";
	string temp2 = "";

	for (int i = 0; i < oneszeros.size(); i++)
	{
		temp += oneszeros[i];

		for (int s = 0; s < get_tablo_str.size(); s++)
		{
			if (get_tablo_str[s] == '1' || get_tablo_str[s] == '0')
			{
				temp2 += get_tablo_str[s];
			}
			else
			{
				if (temp == temp2)
				{
					int geri = temp2.size() + 1;
					output += get_tablo_str[s - geri];
					temp = "";
				}
				temp2 = "";
			}

		}
	}
	for (int i = 0; i < output.size(); i++)
	{
		if (output[i] == '@')
		{
			output[i] = ' ';
		}
		else if (output[i] == '>')
		{
			output[i] = '\n';
		}
	}

}


void Islem::compress()
	{
		txtduzenle();
		hfm_okut();
		yazdir();
		tablo_txt();
		bit_dat_write_str();
		create_bit_dat_file();
	}

void Islem::open()
	{
		read_bit_dat_file();
		convert_with_table();
	}

string Islem::get_output()
	{
		return output;
	}

Islem::~Islem()
	{
		delete nesn;
	}