class Solution {
  public:
    int maxProduct(vector<int>& arr) {
        int n= arr.size();
        if(n<2){
            return -1;
        }
        
        int max1=INT_MIN, max2= INT_MIN;
        for(int i=0;i<n;i++){
            int x= arr[i];
            
            if(x> max1){
                max2= max1;
                max1= x;
            }
            else if(x>max2){
                max2= x;
            }
        }
        return max1* max2;
        
    }
};
