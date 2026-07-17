class Solution {
public:
    int trap(vector<int>& arr) {
        int left=1, right= arr.size()-2;

        int lmax= arr[left-1];
        int rmax= arr[right+1];

        int res=0;
        while(left<=right){
            if(rmax<=lmax){
                res+= max(0, rmax- arr[right]);
                rmax= max(rmax, arr[right]);
                right--;
            }
            else{
                res+= max(0, lmax- arr[left]);
                lmax= max(lmax, arr[left]);
                left++;
            }
        }
        return res;
    }
};
