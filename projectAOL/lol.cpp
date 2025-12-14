#include<stdio.h>
#include<string.h>

	FILE *fp;


struct aol{
	char loc1[30];
	char loc2[30];
	char price[30];
	char room[30];
	char bath[30];
	char carparks[30];
	char type[30];
	char area[30];
	char furnish[30];
};

//void location2(struct aol arr[]){
//	int count[3939]={0};
//	int unique = 0;
//	char ans[3939][30];
//	
//	for(int i=0; i<3939; i++){
//		int flag=0;
//		for(int j=0; j<unique; j++){
//			if(strcmp(arr[i].loc2, ans[j])==0){
//				flag=1;
//				break;
//			}
//		}
//		if(flag==0){
//			strcpy(ans[unique], arr[i].loc2);
//			unique++;
//		}
//	}
//	for(int i=0; i<unique; i++){
//		for(int j=0; j<3939; j++){
//			if(strcmp(ans[i], arr[j].loc2)==0){
//				count[i]++;
//			}
//		}
//	}
//	puts("Location 2 Data :");
//	for(int i=0; i<unique; i++){
//		printf("%s is the only Location so the maximum, minimum, and the average value is %d\n", ans[i], count[i]);
//	}
//}


//void location1(struct aol arr[]){
//	int count[3939]={0};
//	int unique = 0;
//	char ans[3939][30];
//	
//	for(int i=0; i<3939; i++){
//		int flag=0;
//		for(int j=0; j<unique; j++){
//			if(strcmp(arr[i].loc1, ans[j])==0){
//				flag=1;
//				break;
//			}
//		}
//		if(flag==0){
//			strcpy(ans[unique], arr[i].loc1);
//			unique++;
//		}
//	}
//	
//	for(int i=0; i<unique; i++){
//		for(int j=0; j<3939; j++){
//			if(strcmp(ans[i], arr[j].loc1)==0){
//				count[i]++;
//			}
//		}
//	}
//	puts("Location 1 Data: ");
//	for(int i=0; i<unique; i++){
//		printf("%s %d\n", ans[i], count[i]);
//	}
//}
//
//void area(struct aol arr[]){
//	struct aol min;
//	struct aol max;
//	min = arr[0];
//	max = arr[0];
//	
//	int total = 0;
//	for(int i=0; i<3939; i++){
//		total+=arr[i].area;
//	}
//	
//	for(int i=1; i<3939; i++){
//		if(min.area>arr[i].area){
//			min=arr[i];
//		}
//		if(max.area<arr[i].area){
//			max=arr[i];	
//		}
//	}
//	printf("The Average Housing Area in Malaysia is %d m^2\n", total/3939);
//	printf("The Lowest Housing Area in Malaysia is in the Province of %s in the city of %s with %d m^2\n", min.loc2, min.loc1, min.area);
//	printf("The Highest Housing Area in Malaysia is in the Province of %s in the city of %s with %d m^2\n", max.loc2, max.loc1, max.area);
//}
//
//void price(struct aol arr[]){
//	struct aol min;
//	struct aol max;
//	min = arr[0];
//	max = arr[0];
//	
//	double total = 0;
//	for(int i=0; i<3939; i++){
//		total+=arr[i].price;
//	}
//	
//	for(int i=1; i<3939; i++){
//		if(min.price>arr[i].price){
//			min=arr[i];
//		}
//		if(max.price<arr[i].price){
//			max=arr[i];	
//		}
//	}
//	printf("The Average Housing Price in Malaysia is RM. %0.lf\n", total/3939);
//	printf("The Lowest Housing Price in Malaysia is in the Province of %s in the city of %s with RM. %d\n", max.loc2, min.loc1, min.price);
//	printf("The Highes Housing Price in Malaysia is in the Province of %s in the city of %s with RM. %d\n", max.loc2, min.loc1, max.price);
//}

int main()
{
	struct aol arr[3939];
	fp = fopen("file1.csv", "r");
	char a[5000];
	fscanf(fp, "%[^\n]\n", a);
	for(int i=0; i<3939; i++){
		fscanf(fp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", &arr[i].loc1, &arr[i].loc2, &arr[i].price, &arr[i].room, &arr[i].bath, &arr[i].carparks, &arr[i].type, &arr[i].area, &arr[i].furnish);
	printf("%d\n", i);
	}
	
	printf("Choose bla bla bla: \n");
	puts("1. Location 1");
	puts("2. Location 2");
	puts("3. Price");
	puts("4. Room");
	puts("5. Bathrooms");
	puts("6. Carparks");
	puts("7. Type");
	puts("8. Area");
	puts("9. Furnish");
	puts("Press 0 to exit!");
//	location1(arr);
//	location2(arr);
//	price(arr);
//	area(arr);
//	printf("%s", arr[0].loc1);

//for(int i=0; i<3939; i++){
////	printf("%s %s %d %d %d %d %s %d %s\n", arr[2].loc1, arr[2].loc2, arr[2].price, arr[3938].room, arr[3938].bath, arr[3938].carparks, arr[3938].type, arr[3938].area, arr[3938].furnish);
//printf("%d\n", i);
//}
	return 0;
}
