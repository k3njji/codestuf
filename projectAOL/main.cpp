#include <stdio.h>
#include <string.h>

struct Data{
	char loc1[255];
	char loc2[255];
	char type[255];
	char furnish[255];
	int price, rooms, bathrooms, car, area;
};


int N = 0, M = 0;
struct Data d[5000];

void inputData(){
	FILE *fp = fopen("file1.csv", "r");
	
	char temp[255];
	fscanf(fp, "%[^\n]\n", temp);
	
	while(fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n",
		d[N].loc1, d[N].loc2, &d[N].price, &d[N].rooms, &d[N].bathrooms, &d[N].car,
		d[N].type, &d[N].area, d[N].furnish) != EOF){
		N++;
	}
	
}

void describe(){
	char istr[255];
	printf("Input column name: ");
	scanf("%s", istr); getchar();
	
	if(strcmp(istr, "loc1") == 0 || strcmp(istr, "loc2") == 0 ||
		strcmp(istr, "type") == 0 || strcmp(istr, "furnish") == 0){
		
		struct Unique{
			char str[255];
			int ctr;
		}u[5000];
		
		M = 0;
		
		for(int i = 0; i < N; i++){
			int flag = 0;
			for(int j = 0; j < M; j++){
				if(strcmp(istr, "loc1") == 0){
					if(strcmp(u[j].str, d[i].loc1) == 0){
						u[j].ctr++;
						flag = 1;
						break;
					}
				}
				else if(strcmp(istr, "loc2") == 0){
					if(strcmp(u[j].str, d[i].loc2) == 0){
						u[j].ctr++;
						flag = 1;
						break;
					}
				}
				else if(strcmp(istr, "type") == 0){
					if(strcmp(u[j].str, d[i].type) == 0){
						u[j].ctr++;
						flag = 1;
						break;
					}
				}
				else if(strcmp(istr, "furnish") == 0){
					if(strcmp(u[j].str, d[i].furnish) == 0){
						u[j].ctr++;
						flag = 1;
						break;
					}
				}
			}
			if(flag == 0){
				if(strcmp(istr, "loc1") == 0) strcpy(u[M].str, d[i].loc1);
				if(strcmp(istr, "loc2") == 0) strcpy(u[M].str, d[i].loc2);
				if(strcmp(istr, "type") == 0) strcpy(u[M].str, d[i].type);
				if(strcmp(istr, "furnish") == 0) strcpy(u[M].str, d[i].furnish);
				u[M].ctr = 1;
				M++;
			}
		}
		
		int max = -1, min = 9999;
		int maxidx = -1, minidx = -1;
		for(int i = 0; i < M; i++){
			printf("%s : %d\n", u[i].str, u[i].ctr);
			if(u[i].ctr >= max){
				max = u[i].ctr;
				maxidx = i;
			}
			if(u[i].ctr <= min){
				min = u[i].ctr;
				minidx = i;
			}
		}
		printf("Maximum value: %s with frequency: %d\n", u[maxidx].str, u[maxidx].ctr);
		printf("Minimum value: %s with frequency: %d\n", u[minidx].str, u[minidx].ctr);			
	}
	else if(strcmp(istr, "rooms")== 0 || strcmp(istr, "bathrooms") == 0 || strcmp(istr, "carparks") ==0){
    	struct Unique{
    		int num;
    		int ctr;
		}u[5000];
		
		M = 0;
		
		for(int i = 0; i < N; i++){
			int flag = 0;
			for(int j = 0; j < M; j++){
				if(strcmp(istr, "rooms") == 0){
					if(d[i].rooms == u[j].num){
						u[j].ctr++;
						flag = 1;
						break;
					}
				}
				else if(strcmp(istr, "bathrooms") == 0){
					if(u[j].num == d[i].bathrooms){
						u[j].ctr++;
						flag = 1;
						break;
					}
				}
				else if(strcmp(istr, "carparks") == 0){
					if(u[j].num == d[i].car){
						u[j].ctr++;
						flag = 1;
						break;
					}
				}
			}
			if(flag == 0){
				if(strcmp(istr, "rooms") == 0) u[M].num = d[i].rooms;
				if(strcmp(istr, "bathrooms") == 0) u[M].num = d[i].bathrooms;
				if(strcmp(istr, "carparks") == 0) u[M].num = d[i].car;
				u[M].ctr = 1;
				M++;
			}
		}
		
		int max = -1, min = 9999;
		int maxidx = -1, minidx = -1;
		for(int i = 0; i < M; i++){
			printf("%d : %d\n", u[i].num, u[i].ctr);
			if(u[i].ctr >= max){
				max = u[i].ctr;
				maxidx = i;
			}
			if(u[i].ctr <= min){
				min = u[i].ctr;
				minidx = i;
			}
		}
		printf("Maximum value: %d with frequency: %d\n", u[maxidx].num, u[maxidx].ctr);
		printf("Minimum value: %d with frequency: %d\n", u[minidx].num, u[minidx].ctr);	
		
		
		
	}
	else if(strcmp(istr, "area") == 0 || strcmp(istr, "price") == 0){
		int max = -1, min = 99999999;
		long long int sum = 0;
		if(strcmp(istr, "price") == 0){
			for(int i =0 ; i < N; i++){
				if(d[i].price < min){
					min = d[i].price;
				}
				if(d[i].price > max){
					max = d[i].price;
				}
				sum += d[i].price;
			}
		}
		else if(strcmp(istr, "area") == 0){
			for(int i =0 ; i < N; i++){
				if(d[i].area < min){
					min = d[i].area;
					}
				if(d[i].area > max){
					max = d[i].area;
				}
				sum += d[i].area;
			}
		}
		
		printf("Maximum value : %d\n", max);
		printf("Minimum value : %d\n", min);
		printf("Average value : %.2lf\n", (double)sum/(double)N);
	}
	else{
		printf("Invalid column name\n");
	}
	printf("Press Enter to Continue...\n");
	getchar();

}

int isSubstr(char *s1, char *s2){
    int len1 = strlen(s1), len2= strlen(s2);
 
    for (int i = 0; i <= len2-len1; i++) {
        int j;
        for(j = 0; j < len1; j++){
            if(s2[i + j] != s1[j]){
            	break;
			}
		}
        if(j == len1){
            return 1;
        }
    }
    return 0;
}

void printData(Data i){
	printf("%-20s| %-20s| %-8d| %-3d| %-3d| %-3d| %-10s| %-5d| %-10s\n", i.loc1, i.loc2, i.price, i.rooms, i.bathrooms, i.car, i.type, i.area, i.furnish);
}

void search(){
	char input[255];
	
	char ch[255][255];
	int c =0;
	printf("Input search term [DataX in Col]: ");
	scanf("%[^\n]", input); getchar();
	
	char *tok = strtok(input, " ");
	while(tok != NULL){
		strcpy(ch[c], tok);
		tok = strtok(NULL, " ");
		c++;
	}
	
	char str[255];
	char col[255];
	
	strcpy(str, ch[0]);
	strcpy(col, ch[2]);
	
	//printf("%s-%s\n", str, col);
	for(int i = 0; i < N; i++){
		if(strcmp(col, "loc1") == 0){
			if(isSubstr(str, d[i].loc1)){
				printData(d[i]);
			}
		}
		else if(strcmp(col,"loc2") == 0){
			if(isSubstr(str, d[i].loc2)){
				printData(d[i]);
			}
	    }
	    else if(strcmp(col, "rooms") == 0){
	        if(str[0] - '0' == d[i].rooms){
				printData(d[i]);
			}
	    }
	    else if(strcmp(col, "bathrooms") == 0){
	        if(str[0] - '0' ==  d[i].bathrooms){
				printData(d[i]);
			}
	    }
	    else if(strcmp(col, "carparks") == 0){
	        if(str[0] - '0' ==  d[i].car){
				printData(d[i]);
			}
	    }
	    else if(strcmp(col, "type") == 0){
	        if(isSubstr(str, d[i].type)){
				printData(d[i]);
			}
	    }
	    else if(strcmp(col, "furnish") == 0){
	        if(isSubstr(str, d[i].furnish)){
				printData(d[i]);
			}
	    }
	}
	printf("Press Enter to Continue...\n");
	getchar();
}

void sort(){
	for(int i =0 ;i < N; i++){
		for(int j = 0; j < N -i-1; j++){	
			if(strcmp(d[j].loc1, d[j+1].loc1) > 0){
				Data temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	}
	for(int i = 0; i < N; i++){
		printData(d[i]);
	}
	printf("Press Enter to Continue...\n");
	getchar();
}

void menu(){
	while(1){
		printf("MENU\n");
	    printf("1. Describe\n");
	    printf("2. Search\n");
	    printf("3. Sort\n");
	    printf("4. Exit\n");
	    printf("Choose: ");
	    
	    int menu;
	    scanf("%d", &menu); getchar();
	    if(menu == 1){
	        describe();
	    }
		else if(menu == 2){
	        search();
	    }
		else if(menu == 3){
	        sort();
	    }
		else if(menu == 4){
	        break;
	    }
	    else{
	    	continue;
		}
	}
}

int main(){
	
	
	inputData();
	
	menu();
	
	
	return 0;
}
