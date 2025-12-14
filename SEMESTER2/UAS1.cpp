#include<stdio.h>
#include<string.h>

void menu(){
	puts("Menu Pilihan Operasi: ");
	puts("1. Ganti Huruf ");
	puts("2. Cek Karakter dalam nama: ");
	puts("3. Selesai ");
}

int cek(char name[], char alph){
	for(int i=0; i<strlen(name); i++){
		if(name[i] == alph){
			return 1;
		}
	}
	return 0;
}


int main()
{
	char name[500];
	printf("Masukkan nama pengguna: ");
	scanf("%[^\n]", name);
	while(true){
		menu();
		printf("Pilih Operasi yang ingin dilakukan (1/2/3): ");
		int pilihan;
		int alph;
		scanf("%d", &pilihan); getchar();
		
		if(pilihan == 1){
			printf("Masukkan huruf yang ingin diganti: ");
			scanf("%c", &alph); getchar();
			printf("Masukkan huruf baru: ");
			char ganti;
			scanf("%c", &ganti); getchar();
			for(int i=0; i<strlen(name); i++){
				if(name[i] == alph){
					name[i] = ganti;
				}
			}
			printf("Nama Baru setelah diganti huruf: %s", name);
			
		}else if(pilihan == 2){
			printf("Masukkan karakter yang ingin diperiksa: ");
			scanf("%c", &alph); getchar();
			int check = cek(name, alph);
			if(check == 1){
				printf("Karakter '%c' ditemukan dalam nama pengguna\n", alph);
			}else{
				printf("Tidak ditemukan\n");
			}
		}else if(pilihan == 3){
			puts("Keluar dari program, Terimakasih!");
			break;
		}
	}
	
	return 0;
}
