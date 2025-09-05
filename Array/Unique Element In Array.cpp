#include <iostream>
using namespace std;

int unique(int arr[], int sz){
    for(int i=0;i<sz;i++){
        int count=0;
        for(int j=0;j<sz;j++){
            if(arr[i]==arr[j]){
                 count++;
            }
        }
        if(count==1){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){

    int arr[]= {1,2,3,1,2,3,4};
    int sz=7;

    cout<<unique(arr, sz)<<endl;
    return 0;
}
