#include <stdio.h>
#include <string.h>

int main()
{
    char names[10][50]; // list of names
    int n = sizeof(names) / sizeof(names[0]); 
    int count[4000] = {0}; // count of each name
    int unique = 0; // number of unique names

    // fill the names array with names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // iterate through names array
    for (int i = 0; i < n; i++) {
        int flag = 0; // flag to check if name is unique
        for (int j = 0; j < unique; j++) {
            // if name already exists, increment count
            if (strcmp(names[i], names[j]) == 0) {
                count[j]++;
                flag = 1;
                break;
            }
        }
        // if name is unique, add to names array and set count to 1
        if (!flag) {
            strcpy(names[unique], names[i]);
            count[unique] = 1;
            unique++;
        }
    }

    // print frequency of each name
    for (int i = 0; i < unique; i++) {
        printf("%s: %d\n", names[i], count[i]);
    }

    return 0;
}
