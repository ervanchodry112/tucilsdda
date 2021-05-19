#include "question.h"
using namespace std;

void menu();
bool banding(char *ans, int value);
char *input(int index);
void nilai();

int main(){
	
	int pilih, benar, salah;
	benar = 0;

	while(true){
		system("cls");
		menu();
		cout << "Masukkan pilihan anda : ";
		cin >> pilih;

		switch(pilih){
			case 1:
				for(int i = 0; i < 5; i++){
					system("cls");
					srand(time(NULL));
					int num = rand()%25;

					char *answer = input(num);
					if(banding(answer, num)){
						cout << "Jawaban anda benar" << endl;
						benar++;
					}else{
						cout << "Maaf jawaban anda salah" << endl;
					}
					system("pause");
				}
				break;
			// case 2:

			case 3 :
				exit(1);

			default : 
				cout << "Masukkan anda tidak valid" << endl;
				system("pause");

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
	if(ans == jawab[value]){
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

	// char *kecil = tolower(*jawaban);
	
	return jawaban;
}


void nilai(){

}