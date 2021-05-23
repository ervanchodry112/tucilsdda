#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>
using namespace std;

char tanya[26][201] = {"Tombol di keyboard yang berfungsi menghapus karakter sebelah kanan kursor yaitu",
                       "Sistem operasi yang hanya dapat dijalankan pada komputer jenis apple", 
                       "Microsoft Windows merupakan sistem operasi komputer yang berbasis",
                       "Variasi dari sistem operasi linux biasa disebut dengan", 
                       "Bilangan biner merupakan sistem bilangan yang mempunyai radik paling kecil",
                       "Dalam Kode BCD menggunakan kode biner sebanyak berapa bit",
                       "Komponen fisik yang membentuk sistem komputer adalah",
                       "Komponen non fisik untuk menjalankan, mengendalikan dan mengatur proses oleh perangkat keras komputer adalah",
                       "Manusia dengan tenaga dan ilmu pengetahuan yang digunakan untuk mengoperasikan serta mengatur system komputer adalah",
                       "Hardware yang berfungsi sebagai alat penunjuk untuk mengatur posisi kursor di layar adalah",
                       "Microsoft word adalah contoh program aplikasi pengolah",
                       "Jenis memori yang digunakan pada sistem yang menggunakan Pentium, disebut",
                       "Yang berfungsi untuk membentuk fungsi pengolahan data komputer adalah",
                       "Untuk melakukan cold booting dilakukan dengan menekan tombol",
                       "Unit pemrosesan pada komputer",
                       "Program aplikasi yang digunakan secara bebas dan boleh disebarluaskan tanpa harus membayar lisensinya disebut",
                       "Suatu Jenis Jaringan Komputer dengan mencakup wilayah lokal",
                       "Jenis Jaringan Komputer yang menggunakan media transmisi data tanpa menggunakan kabel",
                       "Data yang dibangkitkan dari sister sumber tidak ditransmisikan secara langsung dalam bentuk aslinya",
                       "Area memori yang menyimpan data ketika mereka sedang dipindahkan antara dua device atau antara device dan aplikasi",
                       "Pengembangan dari sistem operasi unix yang dikembangkan oleh Linus Benedict Torvals merupakan contoh jenis sistem operasi",
                       "Sistem Operasi untuk jaringan komputer dan banyak digunakan pada komputer besar seperti supercomputer merupakan contoh jenis sistem operasi",
                       "Orang yang mengoperasikan komputer disebut juga dengan istilah",
                       "Perangkat input yang digunakan seseorang untuk berkomunikasi dengan sistem komputer disebut",
                       "Tombol di keyboard yang berfungsi menghapus karakter sebelah kiri kursor yaitu"};

char jawab[26][51] = {"delete", "macintosh","gui","distro","2",
                      "4","hardware","software","brainware","mouse",
                      "Kata","edoram","alu","power","cpu",
                      "freeware","lan","wireless","transmitter","buffering",
                      "linux","unix","brainware","mouse","backspace"}; 

void menu();
bool banding(char *ans, int value);
char *input(int index);
void result(int *betul, int n);
char nama[11][51];


int main(){
	int pilih, benar[11], id;
	float nilai;
	id = 0;

	while(true){
		system("cls");
		menu();
		cout << "Masukkan pilihan anda : ";
		cin >> pilih;

		switch(pilih){
			case 1:
				id++;
				cout << "Masukkan nama anda : ";
				cin >> nama[id];
				static int yes = 0;

				for(int i = 0; i < 5; i++){
					system("cls");
					srand(time(NULL));
					int num = rand()%25;

					char *answer = input(num);
					if(banding(answer, num)){
						cout << "Jawaban anda benar" << endl;
						yes++;
					}else{
						cout << "Maaf jawaban anda salah" << endl;
					}
					system("pause");
				}
				benar[id] = yes;
				break;

			case 2:
				result(benar, id);
				system("pause");
				break;

			case 3 :
				exit(1);

			default : 
				cout << "Masukkan anda tidak valid" << endl;
				system("pause");
				break;

		}
	}

	return 0;
}

void menu(){
	cout << "Pilih menu:" << endl;
	cout << "\t 1. Mulai kuis" << endl;
	cout << "\t 2. Lihat nilai" << endl;
	cout << "\t 3. Keluar" << endl;
}

bool banding(char *ans, int value){
	char *cek = strstr(jawab[value], ans);
	if(cek){
		return true;
	}else{
		return false;
	}
}

char *input(int index){
	char *jawaban = new char[51];

	cout << tanya[index] << endl;
	cout << "Tulis jawaban singkat satu kata menggunakan huruf kecil: ";
	cin >> jawaban;

	static char kecil[51];
	for(int i = 0; i < strlen(jawaban); i++){
		kecil[i] = tolower(jawaban[i]);
	}
	
	return kecil;
}


void result(int *betul, int n){
	int salah[n];
	int nilaiAkhir[n];

	cout << "========================================================================================\n";
	cout << "Nomor\t||\tNama\t||\tBenar\t||\tSalah\t||\tNilai Akhir\t||\n";
	cout << "========================================================================================\n";

	for(int i = 1; i <= n; i++){
		salah[i] = 5 - betul[i];
		nilaiAkhir[i] = betul[i]*20;
		cout << i << "\t|| " << nama[i] << "\t||\t" << betul[i] << "\t\t||\t";
		cout << salah[i] << "\t||\t" << nilaiAkhir[i] << "\t||" << endl;

	}
}
