#include "question.h"
using namespace std;

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