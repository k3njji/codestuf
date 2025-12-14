#include<stdio.h>
#include<string.h>
const int x = 3939;

struct aol{
	char loc1[50];
	char loc2[50];
	char price[50];
	char room[50];
	char bath[50];
	char carparks[50];
	char type[50];
	char area[50];
	char furnish[50];
}arr[3939];

void Home(){
	puts("Searching House Data:");
	printf("Input Keyword: (DataX in coulumnName)\n");
	printf("Example: Kepong in loc1\n");
	puts("Column Name: ");
	printf("1. loc1\n2. loc2\n3. rooms\n4. bathrooms\n5. carparks\n6. type\n7. furnish\n");
	puts("Press 0 to EXIT");
	puts("(CASE SENSITIVE)");
}

void check(int flag){
	if(flag==0){
		puts("Data doesn't Exist");
	}
	puts("");
}

void loc1(struct aol arr[], char input[3][50]){
	int flag=0;
	printf("===========================================================================================================================================================\n");
	printf("||Location 1               ||Location 2    ||Price         ||Room          ||Bathrooms     ||Carparks      ||Type          ||Area          ||Furnish      |\n");
	printf("===========================================================================================================================================================\n");
		for(int i=0; i<x; i++){
		if(strstr(arr[i].loc1, input[0])!=NULL){
				printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	printf("===========================================================================================================================================================\n");
	check(flag);
	Home();
}

void loc2(struct aol arr[], char input[3][50]){
	int flag=0;
	printf("===========================================================================================================================================================\n");
	printf("||Location 1               ||Location 2    ||Price         ||Room          ||Bathrooms     ||Carparks      ||Type          ||Area          ||Furnish      |\n");
	printf("===========================================================================================================================================================\n");
	for(int i=0; i<x; i++){
		if(strstr(arr[i].loc2, input[0])!=NULL){
				printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	printf("===========================================================================================================================================================\n");
	check(flag);
	Home();
}

void room(struct aol arr[], char input[3][50]){
	int flag=0;
printf("===========================================================================================================================================================\n");
	printf("||Location 1               ||Location 2    ||Price         ||Room          ||Bathrooms     ||Carparks      ||Type          ||Area          ||Furnish      |\n");
	printf("===========================================================================================================================================================\n");
	for(int i=0; i<x; i++){
		if(strstr(arr[i].room, input[0])!=NULL){
				printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	printf("===========================================================================================================================================================\n");
	check(flag);
	Home();
}

void bath(struct aol arr[], char input[3][50]){
	int flag=0;
	printf("===========================================================================================================================================================\n");
	printf("||Location 1               ||Location 2    ||Price         ||Room          ||Bathrooms     ||Carparks      ||Type          ||Area          ||Furnish      |\n");
	printf("===========================================================================================================================================================\n");
	for(int i=0; i<x; i++){
		if(strstr(arr[i].bath, input[0])!=NULL){
				printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	printf("===========================================================================================================================================================\n");
	check(flag);
	Home();

}

void carparks(struct aol arr[], char input[3][50]){
	int flag=0;
	printf("===========================================================================================================================================================\n");
	printf("||Location 1               ||Location 2    ||Price         ||Room          ||Bathrooms     ||Carparks      ||Type          ||Area          ||Furnish      |\n");
	printf("===========================================================================================================================================================\n");
	for(int i=0; i<x; i++){
		if(strstr(arr[i].carparks, input[0])!=NULL){
				printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	printf("===========================================================================================================================================================\n");
	check(flag);
	Home();
}

void type(struct aol arr[], char input[3][50]){
	int flag=0;
printf("===========================================================================================================================================================\n");
	printf("||Location 1               ||Location 2    ||Price         ||Room          ||Bathrooms     ||Carparks      ||Type          ||Area          ||Furnish      |\n");
	printf("===========================================================================================================================================================\n");
	for(int i=0; i<x; i++){
		if(strstr(arr[i].type, input[0])!=NULL){
				printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	printf("===========================================================================================================================================================\n");
	check(flag);
	Home();
}
	
void furnish(struct aol arr[], char input[3][50]){
	int flag=0;
	printf("===========================================================================================================================================================\n");
	printf("||Location 1               ||Location 2    ||Price         ||Room          ||Bathrooms     ||Carparks      ||Type          ||Area          ||Furnish      |\n");
	printf("===========================================================================================================================================================\n");
	for(int i=0; i<x; i++){
		if(strstr(arr[i].furnish, input[0])!=NULL){
				printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	printf("===========================================================================================================================================================\n");
	check(flag);
	Home();
}

int main()
{
	FILE *fp;
	
	fp = fopen("file.csv", "r");
	char a[5000];
	fscanf(fp, "%[^\n]\n", &a);
	for(int i=0; i<x; i++){
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", arr[i].loc1, arr[i].loc2, &arr[i].price, &arr[i].room, &arr[i].bath, &arr[i].carparks, arr[i].type, &arr[i].area, arr[i].furnish);
	}
	fclose(fp);
	Home();
	int cek=1;
	while(cek!=0){
		char b[100];
		scanf("%[^\n]", &b); getchar();
		int len=strlen(b);
		char input[3][50]={0};
		int j=0, k=0;
		int check=0;
		for(int i=0; i<len; i++){
			if(b[i]==' '){
			}else{
				input[j][k]=b[i];
				if(b[i+1]==' '|| b[i+1]==len){
					check++;
					j++;
					k=0;
					continue;
				}else{
					k++;
				}
			}
		}
		if(check==2){
		if(strcmp(input[1], "in")==0){
			if(strcmp(input[2], "loc1")==0){
				loc1(arr, input);
			}else if(strcmp(input[2], "loc2")==0){
				loc2(arr, input);
			}else if(strcmp(input[2], "type")==0){
				type(arr, input);
			}else if(strcmp(input[2], "rooms")==0){
				room(arr, input);
			}else if(strcmp(input[2], "bathrooms")==0){
				bath(arr, input);
			}else if(strcmp(input[2], "carparks")==0){
				carparks(arr, input);
			}else if(strcmp(input[2], "furnish")==0){
				furnish(arr, input);
			}else{
				puts("Wrong Input");
			}
		}else{
			puts("Wrong Input");
		}
	}else if(strcmp(b, "0")==0){
		cek=0;
	}else{
		puts("Wrong Input");
	}
	}
	return 0;
}
