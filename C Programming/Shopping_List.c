#include <stdio.h>
#include <stdlib.h>

void addList(char **str, int *count){
    str[*count] = (char*)malloc(100 * sizeof(char));
    printf("Enter an item: ");
    scanf("%s", str[*count]);
    (*count)++;

    printf("Item added successfully!\n\n");
}

void viewList(char** str, int *count){
    printf("\nCurrent Shopping List:\n");
    for (int i = 0; i<*count; i++){
        printf("%d. %s\n", i+1, str[i]);
    }
    printf("\n");
}

void removeList(char **str, int* count){
    viewList(str, count);

    int n;
    printf("Enter which item to remove: ");
    scanf("%d", &n);
    n--;

    for(int i = n; i<*count-1; i++){
        str[i] = str[i+1];
    }

    (*count)--;
    printf("Removed successfully!\n\n")
;    
}

void addToFile(FILE* f, char **str, int* count){
    for (int i = 0; i<*count; i++){
        fprintf(f, "%d. %s\n", i+1, str[i]);
    }
    
}

int main (){
    int opt = 0;
    int count = 0;
    char **str = (char**) malloc(100*sizeof(char*));

    FILE* f = fopen("shopping_list.txt", "w");
    while (opt!=4){
        printf("Menu:\n");
        printf("1. Add\n2. Remove\n3. View List\n4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &opt);

        switch (opt){
            case 1:
            addList(str, &count);
            break;

            case 2:
            removeList(str, &count);
            break;

            case 3:
            viewList(str, &count);
            break;

            case 4:
            addToFile(f, str, &count);
            break;

            default:
            printf("Invalid number.\n");
        }

    }

    
    

}