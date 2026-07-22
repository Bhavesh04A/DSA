class Solution {
  public:
    int maxArea(vector<int> &height) {
        int n= height.size();
        int lp=0, rp=n-1, maxArea=0;
        while(lp<rp){
            int w=rp-lp-1;
            int ht= min(height[lp], height[rp]);
            int currArea= w*ht;
            maxArea= max(maxArea, currArea);
            height[lp]<height[rp] ? lp++ : rp--;
        }
        return maxArea;
        
    }
};
