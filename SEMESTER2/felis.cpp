#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100

struct Node{
    char name[100];
    char phoneNo[100];
    int age;
    char roomType[100];
    int stayDays;
    struct Node *next;
} *table[SIZE];

void cls(){
    for(int i = 0; i < 25; i++){
        puts("");
    }
}

void mainMenu(){
    puts("+--------------------+");
    puts("| Hotel GrAnsylvania |");
    puts("+--------------------+");

    puts("1. Booking Hotel");
    puts("2. View Bookings");
    puts("3. Delete Bookings");
    puts("4. Exit");
    printf(">>");
}

int hashingFunction(char booking[]){
    int lenBookingID = strlen(booking);
    int key = 0;

    for(int i = 2; i < lenBookingID; i++){
        key += booking[i];
    }

    key = key - 1;

    return key % SIZE;
}

void bookingHotel(){
    char tempName[100];
    char tempPhoneNumber[100];

    // name validation
    printf("Input Full Name [3..30] : ");
    scanf("%[^\n]", tempName); getchar();

    while(strlen(tempName) < 3 || strlen(tempName) > 30){
        printf("Full name length must be between 3 and 30\n");
        printf("Input Full Name [3..30] : ");
        scanf("%[^\n]", tempName); getchar();
    }

    // phone number validation
    printf("Input Phone Number : ");
    scanf("%[^\n]", tempPhoneNumber); getchar();

    int lenPN = strlen(tempPhoneNumber);
    int countSpace = 0, counterInitial = 0;

    for(int i = 0; i < lenPN; i++){
        if(tempPhoneNumber[i] == ' '){
            countSpace++;
        }
    }

    if(tempPhoneNumber[0] == '+', tempPhoneNumber[1] == '6', tempPhoneNumber[2] == '2'){
        counterInitial = 1;
    }

    while(countSpace == 0 || counterInitial == 0 || (lenPN - countSpace - 3) != 11){
        printf("Phone number must begin with '+62', contains at least 1 space and the length must be 11 (Exclude +62 and space)\n");
        printf("Input Phone Number : ");
        scanf("%[^\n]", tempPhoneNumber); getchar();

        int lenPN = strlen(tempPhoneNumber);
        int countSpace = 0, counterInitial = 0;
        
        for(int i = 0; i < lenPN; i++){
            if(tempPhoneNumber[i] == ' '){
                countSpace++;
            }
        }

        if(tempPhoneNumber[0] == '+' && tempPhoneNumber[1] == '6' && tempPhoneNumber[2] == '2'){
            counterInitial = 1;
        }
    }

    // age validation
    int x = 0;
    int tempAge;

    do{
        if(x != 0){
            printf("Age must be minimum 18\n");
        }
        printf("Input Age [Minimum 18] : ");
        scanf("%d", &tempAge); getchar();
        x = 1;
    } while(tempAge < 18);

    // room type validation
    char tempRoomType[100];

    printf("Input Room Type [Regular | Deluxe | Suite] (Case Sensitive) : ");
    scanf("%s", tempRoomType); getchar();

    while(strcmp(tempRoomType, "Regular") != 0 && strcmp(tempRoomType, "Deluxe") != 0 && strcmp(tempRoomType, "Suite") != 0){
        printf("Room type must be either Regular or Deluxe or Suite (Case Sensitive)\n");
        printf("Input Room Type [Regular | Deluxe | Suite] (Case Sensitive) : ");
        scanf("%s", tempRoomType); getchar();
    }

    // stay duration validation
    int tempStayDays;
    printf("Input How Many Night You Will Stay : ");
    scanf("%d", &tempStayDays); getchar();

    while(tempStayDays < 1 || tempStayDays > 30){
        printf("You can't stay less than 1 night or more than 30 nights\n");
        printf("Input How Many Night You Will Stay : ");
        scanf("%d", &tempStayDays); getchar();
    }

    // generate booking ID
    srand(time(NULL));

    int a = rand() % 999;

    char booking[5];
    if(strcmp(tempRoomType, "Deluxe") == 0){
        sprintf(booking, "DE%03d", a);
    }else if(strcmp(tempRoomType, "Regular") == 0){
        sprintf(booking, "RR%03d", a);
    }else if(strcmp(tempRoomType, "Suite") == 0){
        sprintf(booking, "SU%03d", a);
    }
 
    printf("Booking ID: %s\n", booking);
}

int main(){
    int choice;

    do{
        cls();
        mainMenu();
        printf("Insert your choice: ");
        scanf("%d", &choice); getchar();

        switch(choice){
            case 1: 
                bookingHotel();
                break;
            case 2:
                break;
            case 3: 
                break;
        }
        getchar();
    } while(choice != 4);
    
}
