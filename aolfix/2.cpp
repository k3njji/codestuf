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

void loc1(char substring[]){
	int flag = 0;
	for(int i = 0; i<x; i++){
		if(strstr(arr[i].loc1, substring)!=NULL){
			printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	check(flag);
}

void loc2(char substring[]){
	int flag = 0;
	for(int i = 0; i<x; i++){
		if(strstr(arr[i].loc2, substring)!=NULL){
			printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	check(flag);
}

void room(char substring[]){
	int flag = 0;
	for(int i = 0; i<x; i++){
		if(strstr(arr[i].room, substring)!=NULL){
			printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	check(flag);
}

void bathroom(char substring[]){
	int flag = 0;
	for(int i = 0; i<x; i++){
		if(strstr(arr[i].bath, substring)!=NULL){
			printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	check(flag);
}

void car(char substring[]){
	int flag = 0;
	for(int i = 0; i<x; i++){
		if(strstr(arr[i].carparks, substring)!=NULL){
			printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	check(flag);
}

void type(char substring[]){
	int flag = 0;
	for(int i = 0; i<x; i++){
		if(strstr(arr[i].type, substring)!=NULL){
			printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
			flag=1;
		}
	}
	check(flag);
}

void furnish(char substring[]){
	int flag = 0;
	for(int i = 0; i<x; i++){
		if(strstr(arr[i].furnish, substring)!=NULL){
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
//					printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);

	}
	
	char substring[50];
	char coloumn[50];
	
//	scanf("%s in %s", substring, coloumn);
//	getchar();
	
	puts("Searching House Data:");
	printf("Input Keyword: (DataX in coulumnName)\n");
	printf("Example: Kepong in loc1\n");
	puts("Column Name: ");
	printf("1. loc1\n2. loc2\n3. rooms\n4. bathrooms\n5. carparks\n6. type\n7. furnish\n");
	puts("Press 0 to EXIT");
	puts("(CASE SENSITIVE)");

	int flag = 1;
	while(flag==1){
		scanf("%s in %s", substring, coloumn);
	getchar();
	if(strcmp(coloumn, "loc1")==0){
		loc1(substring);
	}else if(strcmp(coloumn, "loc2")==0){
		loc2(substring);
	}else if(strcmp(coloumn, "room")==0){
		room(substring);
	}else if(strcmp(coloumn, "bathroom")==0){
		bathroom(substring);
	}else if(strcmp(coloumn, "carparks")==0){
		car(substring);
	}else if(strcmp(coloumn, "type")==0){
		type(substring);
	}else if(strcmp(coloumn, "furnish")==0){
		furnish(substring);
	}else{
		flag=0;
	}
}
	
	return 0;
}
