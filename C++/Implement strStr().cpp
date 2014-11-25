#include <iostream>
#include <cstring>

void getnext(int *next,char *needle){
    int plen=strlen(needle);
    next[0]=-1;
    int k=-1,j=0;
    while(j<plen-1){
        if(k==-1||needle[k]==needle[j]){
            ++j;
            ++K;
            next[j]=k;
        }
        else{
            k=next[k];
        }
    }
}

char *strStr(char *haystack, char *needle) {
    int i=0,j=0;
    int slen=strlen(haystack),plen=strlen(needle);
    int *next=new int[plen];
    getnext(next, needle);
    while(i<slen&j<plen){
        if(j==-1||haystack[i]==needle[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }
    }
    if(j==plen) return haystack+(i-j);
    else return NULL;
}