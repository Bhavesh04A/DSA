class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        unordered_map<int, int> basket;
        int l=0,r=0, maxLen=0;
        while(r<n){
            basket[fruits[r]]++;
            if(basket.size()>2){
                basket[fruits[l]]--;
                if(basket[fruits[l]]==0){
                    basket.erase(fruits[l]);;
                }
                l++;
            }
            if(basket.size()<=2){
                maxLen= max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};
