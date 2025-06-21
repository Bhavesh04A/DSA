#include<iostream>
#include<vector>
using namespace std;

void changeA(int* ptr){ //pass by reference using pointers
    *ptr= 20;
}

int main(){
    int a=  10;
    changeA(&a);
    int* ptr1 = &a;
    int** parPtr= &ptr1;

    int arr[] = {10,20,30,40};
    int* ptr = arr;
    cout<<*(ptr+1)<<endl;
    cout<<*(ptr+3)<<endl;
    ptr++;
    cout<<*ptr<<endl;
    
    cout<<&ptr<<endl;
    cout<<parPtr<<endl;
    cout<<*(&a)<<endl;
    cout<<*(ptr)<<endl;

    cout<<" Inside main fnx: "<<a<<endl;
    return 0;
}

