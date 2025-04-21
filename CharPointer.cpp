#include<iostream>
using namespace std;
char* getFirstStr(char* str){
    int i=0;
    while(str[i] != ' ' && str[i] != '\0'){
        i++;
    }
    str[i] = '\0';
    return str;
}
int main(){
    char str[100];
    cin.getline(str, 100);
    char* result = getFirstStr(str);
    cout<<"First word of the input string: "<<result<<endl;
    return 0;
}