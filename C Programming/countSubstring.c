#include <stdio.h>
#include <string.h>
#include <ctype.h>

int wordBoundary(char c){
    return c==' ' || c=='\n' || c=='\0';
}

int getNumSubString(char* sstr, char* str){
    int count = 0;
    char* pos = str;
    for (int i = 0; i<strlen(str); i++){
        str[i]=tolower(str[i]);
    }
    while((pos=strstr(pos, sstr))!=NULL){
        int i = pos-str;
        if((i==0 || wordBoundary(str[i-1]))&& wordBoundary(str[i+strlen(sstr)])){
            count++;
            
        }
        pos+=strlen(sstr);
    }
    
    return count;
}

int main (){
    char sstr[50];
    char str[256];
    printf("Enter a string: ");
    fgets(str, 256, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter substring you want to search for: ");
    scanf("%s", sstr);



    printf("Occurence: %d", getNumSubString(sstr, str));

    
}