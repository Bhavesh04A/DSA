#include <iostream>
using namespace std;

int sum(int arr[], int sz){
    int sum=0;
    for(int i=0;i<sz;i++){
        sum+=arr[i];
    }
    return sum;
}
int product(int arr[], int sz){
    int product=1;
    for(int i=0;i<sz;i++){
        product*=arr[i];
    }
    return product;
}

int main(){

    int arr[]= {1,2,3,1,2,3,4};
    int sz=7;

    cout<<"Sum of elements is: "<<sum(arr, sz)<<endl;
    cout<<"Product of elements is: "<<product(arr, sz)<<endl;
    return 0;
}
