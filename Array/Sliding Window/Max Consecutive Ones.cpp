class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0, r=0, maxLen=0;
        while(r<nums.size()){
            if(nums[r]==0){
                l=r+1;
            }
            else{
                int len= r-l+1;
                maxLen= max(len,maxLen);
            }
            r++;
        }
        return maxLen;
    }
};
