#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxNext(const char *s, int _next[]){
    _next[0] = -1;
    int i = 0;
    int j = -1;
    int max = 0;
    int len = strlen(s);
    while(i < len){
        if(j == -1 || s[i] == s[j]){
            i++;
            j++;
            _next[i] = j;
            if(j > max){
                max = j;
            }
        }else{
            j = _next[j];
        }
    }
    return max;
}

int LRS_KMP(const char *str){
    int len = strlen(str);
    int index = 0;
    int max = 0;
    int maxindex = 0;
    int *_next = (int *)malloc(len * sizeof(int));
    int i;
    for(i = 0; i < len - 1; i++){
        int curmax = maxNext(str + i, _next);
        if(curmax > max){
            max = curmax;
            maxindex = i;
        }
    }
    for(i = 0; i < max; i++){
        printf("%c", *(str + maxindex + i));
    }
    return max;
}

int main(){
    char *str = "abaabaaabaaaab";
    int len = LRS_KMP(str);
    printf("Max LRS = %d\n", len);
}
