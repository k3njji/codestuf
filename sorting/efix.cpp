#include<stdio.h>
#include<string.h>
struct cuaca{
	char kota[1005];
	char derajat;
	float suhu;
	float suhuGanti;
};

int main(){
	
	FILE *ptr;
	
	ptr=fopen("testdata.in","r");
	
	struct cuaca weather[1005];
	int count=0;
	while(fscanf(ptr,"%[^#]#%f#%c\n",&weather[count].kota, &weather[count].suhu, &weather[count].derajat)!=EOF){
		count++;
	}
	for(int i=0;i<count;i++){
		weather[i].suhuGanti=weather[i].suhu;
	}
	//check buat fahrenheit ama ganti jadi selsius
	
	for(int i=0;i<count;i++){
		if(weather[i].derajat=='F'){
			weather[i].suhuGanti=(weather[i].suhu-32)*5/9;
		}
	}
	
	//sorting by temperature
	
	
	for(int i=0;i<count-1;i++){
		for(int j=0;j<count-1-i;j++){
			if(weather[j].suhuGanti>weather[j+1].suhuGanti){
				struct cuaca temp=weather[j];
				weather[j]=weather[j+1];
				weather[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<count-1;i++){
		for(int j=0;j<count-1-i;j++){
			if(strcmp(weather[j].kota,weather[j+1].kota)>0 && weather[j].suhuGanti==weather[j+1].suhu){
				struct cuaca temp=weather[j];
				weather[j]=weather[j+1];
				weather[j+1]=temp;
			}
		}
	}
	
	for(int i=0;i<count;i++){
	printf("%s is %.2f%c\n", weather[i].kota,weather[i].suhu,weather[i].derajat);
	}

	fclose(ptr);
	
	return 0;
}
