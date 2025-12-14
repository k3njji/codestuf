#include<stdio.h>
#include<string.h>
#define x 3939

struct data{
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

void check(int flag){
	if(flag==0){
		puts("no");
	}
}

void loc1(struct data arr[], char substring[]){
	int flag = 0;
	for(int i = 0; i<x; i++){
		if(strstr(arr[i].loc1, substring)!=NULL){
			printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	check(flag);
}

int main()
{
	FILE *fp;
	fp = fopen("file.csv", "r");
	
	char header[1000];
	fscanf(fp, "%[^\n]\n", header);
	
	for(int i = 0; i<x; i++){
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", arr[i].loc1, arr[i].loc2, &arr[i].price, &arr[i].room, &arr[i].bath, &arr[i].carparks, arr[i].type, &arr[i].area, arr[i].furnish);
					printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);

	}
	
	char substring[50];
	char coloumn[50];
	
	scanf("%s in %s", substring, coloumn);
	getchar();
	
		printf("%s in %s", substring, coloumn);

	
	if(strcmp(coloumn, "Loc1")==0){
		loc1(arr, substring);
	}
	
	return 0;
}
