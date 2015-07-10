#include <string>

using namespace std;

string multiply(string num1, string num2) {
    string str;
    if(num1=="0"||num2=="0") return str="0";
    int len1=num1.size(),len2=num2.size();
    int *arry=new int[len1+len2];
    for(int i=0;i<len1+len2;i++)
        arry[i]=0;
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            arry[i+j+1]=(num1[i]-'0')*(num2[j]-'0')+arry[i+j+1];
        }
    }
    for(int i=len1+len2-1;i>=0;i--){
        if(arry[i]>=10){
            arry[i-1]=arry[i-1]+arry[i]/10;
            arry[i]=arry[i]%10;
        }
    }
    int i;
    for(i=0;i<len1+len2;i++){
        if(arry[i]!=0) break;
    }
    for(i;i<len1+len2;i++){
        char ch='0'+arry[i];
        str=str+ch;
    }
    delete[] arry;
    return str;
}