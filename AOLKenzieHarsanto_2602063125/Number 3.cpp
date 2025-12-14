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
	char type[75];
	char area[50];
	char furnish[50];
}arr[3939];

void bubble(struct aol arr[]){
	for(int i=0; i<x; i++){
		for(int j=0; j<x-i; j++){
			if(strcmp(arr[j].loc1, arr[j+1].loc1)>0){
				struct aol temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
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
	
	bubble(arr);
	
	printf("===========================================================================================================================================================\n");
	printf("||Location 1               ||Location 2    ||Price         ||Room          ||Bathrooms     ||Carparks      ||Type          ||Area          ||Furnish      |\n");
	printf("===========================================================================================================================================================\n");
	
	for(int i=1; i<=x; i++){
		printf("|%-25s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s ||%-13s|\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
	}		
	printf("===========================================================================================================================================================\n");
	
	return 0;
}
