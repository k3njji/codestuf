#include<stdio.h>
#include<string.h>

struct suhu{
	char kota[1001];
	double temp;
	char type;
	double ganti;
};

int main()
{
	FILE *fp;
	fp = fopen("testdata.in", "r");
	struct suhu input[101];
	int count=0;
	while(fscanf(fp, "%[^#]#%lf#%c\n", &input[count].kota, &input[count].temp, &input[count].type)!=EOF){
		count++;
	}
	
	for(int i=0; i<count; i++){
		input[i].ganti=input[i].temp;
	}
	
	for(int i=0; i<count; i++){
		if(input[i].type=='F'){
			input[i].ganti = (input[i].ganti-32)*5/9;
		}
	}
	
	for(int i=0; i<count-1; i++){
		for(int j=0; j<count-i-1; j++){
			if(input[i].ganti<input[i+1].ganti){
				struct suhu temp=input[i];
				input[i]=input[i+1];
				input[i+1]=input[i];
			}
		}
	}
	
//	for(int i=0;i<count-1;i++){
//		for(int j=0;j<count-1-i;j++){
//			if(strcmp(weather[j].kota,weather[j+1].kota)>0 && weather[j].suhuGanti==weather[j+1].suhu){
//				struct cuaca temp=weather[j];
//				weather[j]=weather[j+1];
//				weather[j+1]=temp;
//			}
//		}
//	}
	
	for(int i=0;i<count;i++){
	printf("%s is %.2lf%c\n", input[i].kota, input[i].temp, input[i].type);
	}
	fclose(fp);
	
	return 0;
}
