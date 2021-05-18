#include <iostream>
#include "question.h"

void menu(){
	cout << "Pilih menu:" << endl;
	cout << "\t 1. Mulai kuis" << endl;
	cout << "\t 2. Lihat nilai" << endl;
	cout << "\t 3. Keluar" << endl;
}

char *jawab(){
	char jawaban [51];
	
	cout << "Tulis jawaban singkat satu kata menggunakan huruf kecil: ";
	cin.getline (jawaban, 51);
	
	return jawaban;
}

bool banding();
void nilai();

int main(){
	
}
