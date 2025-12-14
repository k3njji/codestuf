#include<stdio.h>
#include<string.h>
const int x=3939;
	
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

void choice(){
	puts("========================");
	puts("||Malaysian House Data||");
	puts("========================");
	puts("1. Loc1");
	puts("2. Loc2");
	puts("3. Room");
	puts("4. Bathrooms");
	puts("5. Carparks");
	puts("6. Type");
	puts("7. Furnish");
	puts("8. Area");
	puts("9. Price");
	puts("Type the Number or the Words to Show the Data");
	puts("Press 0 to EXIT");
	puts("(CASE SENSITIVE)");
}

void location1(struct aol arr[]){
	int count[x]={0};
	
	int unik = 0;
	char ans[x][30];
	for(int i=0; i<x; i++){
		int flag=0;
		for(int j=0; j<unik; j++){
			if(strcmp(arr[i].loc1, ans[j])==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			strcpy(ans[unik], arr[i].loc1);
			unik++;
		}
	}
	
	for(int i=0; i<unik; i++){
		for(int j=0; j<x; j++){
			if(strcmp(ans[i], arr[j].loc1)==0){
				count[i]++;
			}
		}
	}
	puts("=================");
	puts("Location 1 Data: ");
	puts("=================");
	for(int i=0; i<unik; i++){
		printf("%-25s : %-10d\n", ans[i], count[i]);
	}
	int k=0, o=0;
	for(int i=0; i<unik-1; i++){
		if(count[k]<count[i+1]){
			k=i+1;
		}
	}
	for(int i=0; i<unik-1; i++){
		if(count[o]>=count[i+1]){
			o=i+1;
		}
	}
	printf("Maximum Value : %s with frequency : %d\n", ans[k], count[k]);
	printf("Minimum Value : %s with frequency : %d\n", ans[o], count[o]);
	choice();
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
	puts("=================");
	puts("Location 2 Data :");
	puts("=================");
	for(int i=0; i<unique; i++){
		printf("%-25s : %-10d\n", ans[i], count[i]);
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
	printf("Maximum Value : %s with frequency : %d\n", ans[k], count[k]);
	printf("Minimum Value : %s with frequency : %d\n", ans[o], count[o]);
	choice();
}

void room(struct aol arr[]){
	int count[x]={0};
	int freq=0;
	for(int i=0; i<x; i++){
		count[arr[i].room]++;
	}
	int start=0;
	int check = 0;
	puts("===========");
	puts("Room Data : ");
	puts("===========");
	for(int i=0; i<x; i++){
		if(count[i]>0){
			printf("%-5d House with %d Room\n", count[i], i);
			if(check==0){
				start=i;
				check=1;
			}
		}
	}

int k=start, l=start;
	for(int i=start; i<x; i++){
		if(count[k]<count[i] && count[i]!=0){
			k=i;
		}
		if(count[l]>count[i] && count[i]!=0){
			l=i;
		}
	}
	printf("Maximum Value : %d with frequency : %d\n", k, count[k]);
	printf("Minimum Value : %d with frequency : %d\n", l, count[l]);
	choice();
}

void bathrooms(struct aol arr[]){
	int count[x]={0};
	for(int i=0; i<x; i++){
		count[arr[i].bath]++;
	}
	
	int start=0;
	int check=0;

	puts("===============");
	puts("Bathrooms Data:");
	puts("===============");
	for(int i=0; i<x; i++){
			if(count[i]>0){
			printf("%-5d House with %d Bathooms\n", count[i], i);
			if(check==0){
				start=i;
				check=1;
			}
		}
	}

int k=start, l=start;
	for(int i=start; i<x; i++){
		if(count[k]<count[i] && count[i]!=0){
			k=i;
		}
		if(count[l]>count[i] && count[i]!=0){
			l=i;
		}
	}
	printf("Maximum Value : %d with frequency : %d\n", k, count[k]);
	printf("Minimum Value : %d with frequency : %d\n", l, count[l]);
	choice();
}

void car(struct aol arr[]){
	int count[x]={0};
	for(int i=0; i<x; i++){
		count[arr[i].carparks]++;
	}
		int start=0;
		int check = 0;
	puts("==============");
	puts("Carparks Data: ");
	puts("==============");
	
	for(int i=0; i<x; i++){
			if(count[i]>0){
			printf("%-5d House with %d Carparks\n", count[i], i);
			if(check==0){
				start=i;
				check = 1;
			}
		}
	}

int k=start, l=start;
	for(int i=start; i<x; i++){
		if(count[k]<count[i] && count[i]!=0){
			k=i;
		}
		if(count[l]>count[i] && count[i]!=0){
			l=i;
		}
	}
	printf("Maximum Value : %d with frequency : %d\n", k, count[k]);
	printf("Minimum Value : %d with frequency : %d\n", l, count[l]);
	choice();
}

void type(struct aol arr[]){
	int count[x]={0};
	
	int unik = 0;
	char ans[x][30];
	for(int i=0; i<x; i++){
		int flag=0;
		for(int j=0; j<unik; j++){
			if(strcmp(arr[i].type, ans[j])==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			strcpy(ans[unik], arr[i].type);
			unik++;
		}
	}
	
	for(int i=0; i<unik; i++){
		for(int j=0; j<x; j++){
			if(strcmp(ans[i], arr[j].type)==0){
				count[i]++;
			}
		}
	}
	puts("==================");
	puts("Housing Type Data: ");
	puts("==================");
	for(int i=0; i<unik; i++){
		printf("%-25s : %-10d\n", ans[i], count[i]);
	}
	int k=0, o=0;
	for(int i=0; i<unik-1; i++){
		if(count[k]<count[i+1]){
			k=i+1;
		}
	}
	for(int i=0; i<unik-1; i++){
		if(count[o]>=count[i+1]){
			o=i+1;
		}
	}
	printf("Maximum Value : %s with frequency : %d\n", ans[k], count[k]);
	printf("Minimum Value : %s with frequency : %d\n", ans[o], count[o]);
	choice();
}

void furnish(struct aol arr[]){
	int count[x]={0};
	
	int unik = 0;
	char ans[x][30];
	for(int i=0; i<x; i++){
		int flag=0;
		for(int j=0; j<unik; j++){
			if(strcmp(arr[i].furnish, ans[j])==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			strcpy(ans[unik], arr[i].furnish);
			unik++;
		}
	}
	
	for(int i=0; i<unik; i++){
		for(int j=0; j<x; j++){
			if(strcmp(ans[i], arr[j].furnish)==0){
				count[i]++;
			}
		}
	}
	puts("=====================");
	puts("Housing Furnish Data: ");
	puts("=====================");
	for(int i=0; i<unik; i++){
		printf("%-25s : %-10d\n", ans[i], count[i]);
	}
	int k=0, o=0;
	for(int i=0; i<unik-1; i++){
		if(count[k]<count[i+1]){
			k=i+1;
		}
	}
	for(int i=0; i<unik-1; i++){
		if(count[o]>=count[i+1]){
			o=i+1;
		}
	}
	printf("Maximum Value : %s with frequency : %d\n", ans[k], count[k]);
	printf("Minimum Value : %s with frequency : %d\n", ans[o], count[o]);
	choice();
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
	puts("===================");
	puts("Housing Area Data :");
	puts("===================");
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
	puts("====================");
	puts("House Pricing Data :");
	puts("====================");
	printf("The Average House Price in Malaysia is RM. %0.lf\n", total/x);
	printf("The Lowest House Price in Malaysia is in the Province of %s in the city of %s with RM. %d\n", max.loc2, min.loc1, min.price);
	printf("The Highest House Price in Malaysia is in the Province of %s in the city of %s with RM. %d\n", max.loc2, min.loc1, max.price);
}

int main()
{
	
	FILE *fp;
	
	fp = fopen("file.csv", "r");
	char a[1000];
	fscanf(fp, "%[^\n]\n", &a);
	for(int i=0; i<x; i++){
		fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n", arr[i].loc1, arr[i].loc2, &arr[i].price, &arr[i].room, &arr[i].bath, &arr[i].carparks, arr[i].type, &arr[i].area, arr[i].furnish);
	}
	fclose(fp);

	choice();
	
	int flag = 0;
	while(flag!=1){
		char b[10];
		scanf("%s", &b);
		if(strcmp(b, "Loc1")==0 || strcmp(b, "1")==0){
			location1(arr);
		}else if(strcmp(b, "Loc2")==0 || strcmp(b, "2")==0){
			location2(arr);
		}else if(strcmp(b, "Room")==0 || strcmp(b, "3")==0){
			room(arr);
		}else if(strcmp(b, "Bathrooms")==0 || strcmp(b, "4")==0){
			bathrooms(arr);
		}else if(strcmp(b, "Carparks")==0 || strcmp(b, "5")==0){
			car(arr);
		}else if(strcmp(b, "Type")==0 || strcmp(b, "6")==0){
			type(arr);
		}else if(strcmp(b, "Furnish")==0 || strcmp(b, "7")==0){
			furnish(arr);
		}else if(strcmp(b, "0")==0 || strcmp(b, "EXIT")==0){
			flag=1;
			puts("The Program is Terminated");
			puts("Thank You :D");
		}else if(strcmp(b, "Area")==0 || strcmp(b, "8")==0){
			area(arr);
		}else if(strcmp(b, "Price")==0 || strcmp(b, "9")==0){
			price(arr);
		}else{
			puts("Data not Found!");
			choice();
		}
	}
		return 0;
}
