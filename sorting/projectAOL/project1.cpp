#include<stdio.h>
#include<string.h>
const int x=3939;
	FILE *fp;
	
struct aol{
	char loc1[75];
	char loc2[75];
	int price;
	int room;
	int bath;
	int carparks;
	char type[75];
	int area;
	char furnish[75];
}arr[3939];

void location1(struct aol arr[]){
	int count[x]={0};
	int unique = 0;
	char ans[x][30];
	
	for(int i=0; i<x; i++){
		int flag=0;
		for(int j=0; j<unique; j++){
			if(strcmp(arr[i].loc1, ans[j])==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			strcpy(ans[unique], arr[i].loc1);
			unique++;
		}
	}
	
	for(int i=0; i<unique; i++){
		for(int j=0; j<x; j++){
			if(strcmp(ans[i], arr[j].loc1)==0){
				count[i]++;
			}
		}
	}
	puts("Location 1 Data: ");
	for(int i=0; i<66; i++){
		printf("%s\t:\t%d\n", ans[i], count[i]);
	}
	int k=0, o=0;
	for(int i=0; i<unique-1; i++){
		if(count[k]<count[i+1]){
			k=i+1;
		}
	}
	for(int i=0; i<unique-1; i++){
		if(count[o]>=count[i+1]){
			o=i+1;
		}
	}
	printf("Maximum Value: %s with frequency: %d\n", ans[k], count[k]);
	printf("Maximum Value: %s with frequency: %d\n", ans[o], count[o]);
}

void location2(struct aol arr[]){
	int count[x]={0};
	int unique = 0;
	char ans[x][30];
	
	for(int i=0; i<x; i++){
		int flag=0;
		for(int j=0; j<unique; j++){
			if(strcmp(arr[i].loc2, ans[j])==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			strcpy(ans[unique], arr[i].loc2);
			unique++;
		}
	}
	for(int i=0; i<unique; i++){
		for(int j=0; j<x; j++){
			if(strcmp(ans[i], arr[j].loc2)==0){
				count[i]++;
			}
		}
	}
	puts("Location 2 Data :");
	for(int i=0; i<unique; i++){
		printf("%s is the only Location so the maximum, minimum, and the average value is %d\n", ans[i], count[i]);
	}
}

void area(struct aol arr[]){
	struct aol min;
	struct aol max;
	min = arr[0];
	max = arr[0];
	
	int total = 0;
	for(int i=0; i<x; i++){
		total+=arr[i].area;
	}
	
	for(int i=1; i<x; i++){
		if(min.area>arr[i].area){
			min=arr[i];
		}
		if(max.area<arr[i].area){
			max=arr[i];	
		}
	}
	printf("The Average Housing Area in Malaysia is %d m^2\n", total/x);
	printf("The Lowest Housing Area in Malaysia is in the Province of %s in the city of %s with %d m^2\n", min.loc2, min.loc1, min.area);
	printf("The Highest Housing Area in Malaysia is in the Province of %s in the city of %s with %d m^2\n", max.loc2, max.loc1, max.area);
}

void price(struct aol arr[]){
	struct aol min;
	struct aol max;
	min = arr[0];
	max = arr[0];
	
	double total = 0;
	for(int i=0; i<x; i++){
		total+=arr[i].price;
	}
	
	for(int i=1; i<x; i++){
		if(min.price>arr[i].price){
			min=arr[i];
		}
		if(max.price<arr[i].price){
			max=arr[i];	
		}
	}
	printf("The Average Housing Price in Malaysia is RM. %0.lf\n", total/x);
	printf("The Lowest Housing Price in Malaysia is in the Province of %s in the city of %s with RM. %d\n", max.loc2, min.loc1, min.price);
	printf("The Highes Housing Price in Malaysia is in the Province of %s in the city of %s with RM. %d\n", max.loc2, min.loc1, max.price);
}

int main()
{
	fp = fopen("file.csv", "r");
	char a[5000];
	fscanf(fp, "%[^\n]\n", &a);
	for(int i=0; i<x; i++){
		fscanf(fp, "%[^;];%[^;];%d;%d;%d;%d;%[^;];%d;%[^\n]\n", arr[i].loc1, arr[i].loc2, &arr[i].price, &arr[i].room, &arr[i].bath, &arr[i].carparks, arr[i].type, &arr[i].area, arr[i].furnish);
//		printf("%d\n", i);
	}
	fclose(fp);
	
	
	puts("Choose bla bla bla: ");
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
	location1(arr);
//	location2(arr);
//	price(arr);
//	area(arr);

for(int i=0; i<x; i++){
	printf("%s %s %d %d %d %d %s %d %s\n", arr[i].loc1, arr[i].loc2, arr[i].price, arr[i].room, arr[i].bath, arr[i].carparks, arr[i].type, arr[i].area, arr[i].furnish);
//printf(" %d\n", i);
}
	return 0;
}
