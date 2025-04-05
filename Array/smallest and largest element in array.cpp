#include <iostream>
using namespace std;

int main(){
    int nums[]= {5,15,22,1,-15,24};
    int size=6;
    int smallest= INTMAX_MAX;
    int largest= INTMAX_MIN;

    for(int i=0;i<size;i++){
       smallest= min(nums[i], smallest);
       largest= max(nums[i], largest);
    }
    cout<<"smallest value is: "<<smallest<<endl;
    cout<<"largest value is: "<<largest<<endl;

    return 0;
}
