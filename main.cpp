#include <iostream>
#include <cstdlib>
#include <stdio.h>
#define max 5
using namespace std;

char answer;
int x=0,score_target,jumlah_pemain;
string nama_target;
bool ketemu = false;
string pertanyaan[10] = 
{
	"Siapa Dosen Pengampu Mata Kuliah Struktur Data?",
	"Apa saja metode sorting yang telah dipelajari?",
	"Manakah dari operator berikut yang dapat digunakan untuk mengakses fungsi/method anggota struct?",
	"Perhatikan coding di bawah ini\nint i = 5, j = 10, k;\nk = j % i\nBerapa nilai k?",
	"Apa saja jenis pencarian pada c++?",
	"Apakah benar struct dapat dikombinasikan dengan Array?",
	"Berikut 2 operator pada pointer",
	"Metode pencarian yang syarat datanya harus sudah terurut?",
	"Perhatikan code di bawah ini :\nint matrix[x][y];\nManakah variable yang disebut kolom?",
	"First In First Out (FIFO) merupakan konsep dari?"
};
string jawaban1[10] = 
{
	"Ike Verawati",
	"BubleSort, InsertionSort, dan SelectionSort",
	":",
	"2",
	"Squential dan Binary", 
	"Benar",
	"% dan *",
	"Squential",
	"x",
	"Queue"
};
string jawaban2[10] = 
{
	"Uyock Saputro",
	"BubleSort, LinearSort, dan BinarySort",
	".",
	"0",
	"Buble dan Binary",
	"Salah",
	"& dan *",
	"Binary",
	"y",
	"Stack"
};
char kunci[10]={'A','A','B','B','A','A','B','B','A','A'};//kunci jawaban

struct Pemain
{
	string nama;
	int score;
}P[max],temp,cari;

struct QUEUE
{
	string data[max];
	int head;
	int tail;
}antrian;

void init() 
{
	antrian.head=0;
	antrian.tail=0;
	x = 0;
	jumlah_pemain = 0;
}

bool kosong()
{
	if(antrian.tail==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool penuh()
{
	if(antrian.tail==max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void tampilData()
{
	if(!kosong())
	{
		cout << "Daftar antrian pemain : " << endl;
		for(int i=antrian.head;i<=antrian.tail-1;i++)
		{
			cout << antrian.data[i] << " | ";
		}
	}
	cout << "\n";
}

void InputDataPemain()
{
	P[x].score = 0;
	for(int i=0;i<10;i++)
	{
		cout << i+1 << ". " << pertanyaan[i] << endl;
		cout << "A. " << jawaban1[i] <<	"\nB. " << jawaban2[i] << endl;
		cout << "Jawab[A/B] : "; cin >> answer;
		if(answer == kunci[i])
		{
			P[x].score += 100;
		}
		else
		{
			P[x].score -= 25;
		}
		cout << endl;
	}
}

void enqueue()//Fungsi menambah antrian
{
	tampilData();
	if(!penuh())
	{
		string baru;
		cout << "Nama Pemain yang akan dimasukan : ";
		cin >> baru;
		antrian.data[antrian.tail]=baru;
		
		antrian.tail++;
		jumlah_pemain = antrian.tail;
	}
	else
	{
		cout << "Pemain sudah penuh!!";
	}
	getchar();
}

void dequeue()//Fungsi mengurangi antrian
{
	tampilData();
	if(!kosong())
	{
		cout << "Jawablah Quiz di bawah ini " << antrian.data[antrian.head] << " : " << endl;
		P[x].nama = antrian.data[antrian.head];
		for(int i=antrian.head;i<antrian.tail;i++)
		{
			antrian.data[i]=antrian.data[i+1];
		}
		InputDataPemain();
		antrian.tail--;
		x++;
	}
	else
	{
		cout << "Antrian Pemain Kosong";
	}
	getchar();
}

void buble_sort(int x)//Fungsi mengurutkan dengan metode Bublesort
{
	for(int i=0;i<(x-1);i++)
	{
		for(int j=0;j<(x-1);j++)
		{
			if(P[j].score < P[j+1].score)
			{
				//Proses penukaran
				temp = P[j];
				P[j] = P[j+1];
				P[j+1] = temp;
			}
		}
	}
}

void Searching(string target,int x)//Mencari nama pemain menggunakan Linear Search
{
	cari.nama = target;
	
	for(int i=0;i<x;i++)
	{
		if(cari.nama == P[i].nama)
		{
			ketemu = true;
			cari = P[i];
			
		}
	}
	if(ketemu)
	{
		cout << "Data Pemain Ditemukan : \nNama\t: "  << cari.nama << "\tScore\t: " << cari.score << endl;
	}
	else
	{
		cout << "Pemain tidak ditemukan" << endl;
	}
}

void tampil_score(int x)//Menampilkan Score Akhir Para Pemain
{
	cout << "================" << endl;
	cout << "| NAMA | SCORE |" << endl;
	cout << "================" << endl;
	for(int i=0;i<x;i++)
	{
	cout << "| "<< P[i].nama << " |  " << P[i].score << "  |" << endl;
	}
	cout << "================" << endl;
}

int main()
{
	int pil1,pil2;
	
	do
	{
		tampilData();
		cout << "QUIZ SEDERHANA" << endl;
		cout << "Menu Utama\n";
		cout << "==========\n";
		cout << "  [1] Buat Antrian Pemain Baru\n";
		cout << "  [2] Tambah Antrian Pemain\n";
		cout << "  [3] Pemain Menjawab Quiz\n";
		cout << "  [4] Data Score Pemain\n";
		cout << "  [0] Keluar\n";
		cout << "==========\n";
		cout << "Masukan Pilihan : "; cin >> pil1;
		system("cls");
	
		switch(pil1)
		{
			case 1 :
				init();
				system("cls");
			break;
			case 2 :
				enqueue();
				system("cls");
			break;
			case 3 :
				dequeue();
				system("cls");
			break;
			case 4 :
				system("cls");
				buble_sort(jumlah_pemain);
				tampil_score(jumlah_pemain);
				cout << "Cari Pemain : "; cin >> nama_target;
				Searching(nama_target,jumlah_pemain);
			break;
		}
		
	}while(pil1!= 0);
	
	
}