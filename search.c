#include <stdio.h>

#define ElemType int
typedef struct
{
    ElemType* elem;
    int len;
}SSTable;

/* int search(SSTable S,ElemType key){
    for (int i = 0; i < S.len; i++)
    {
        if(S.elem[i] == key){
            return i;
        }
    }
    return -1;
} */

/* int search(SSTable S,ElemType key){
    int i = 0;
    while (i < S.len && S.elem[i] != key)
    {
        i++;
    }
    return (S.len == i ? -1 : i);
} */

int search_beta(SSTable S,ElemType key){
    S.elem[0] = key;
    int i = S.len;
    while (S.elem[0] != S.elem[i])
    {
        i--;
    }
    return i;
}

int main(void){
    ElemType arr[] = {-1,56,23,18,-7,9,72,0,};
    int len = sizeof(arr)/sizeof(arr[0])-1;

    SSTable S;
    S.elem = arr;
    S.len = len;
    int result = search_beta(S,18);
    if(result == 0){
        printf("can not found it!\n");
    }else{
        printf("found it at %d\n",result);
    }
}

