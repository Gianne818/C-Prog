#include <stdio.h>
#include <string.h>

char* pushDominoes(char* dom) {
    int s = strlen(dom);
    char* res = strdup(dom);
    for (int i = 0; i<s; i++){
        if(dom[i]=='L' && i!=0){
            res[i-1]='L';
            i++;
        }

        if(dom[i]=='R' && i!=s-1){
            res[i+1] = 'R';
            i++;
        }
 
    }
    for (int i = 1; i<s-1; i++){
        if(dom[i]=='.'){
                if(dom[i+1] == 'L' && dom[i-1] == 'R'){
                    res[i] = '.';
                }
            }
    }
    strcpy(dom, res);
    return dom;
}

int main (){
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    printf("The result: %s", pushDominoes(str));
}