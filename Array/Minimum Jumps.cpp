class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (arr[0] == 0)
            return -1;
    
        int maxReach = 0;
        int currReach = 0;
        int jump = 0;
        
        for (int i = 0; i < n; i++){
            maxReach = max(maxReach, i + arr[i]);
            if (maxReach >= n - 1){
                return jump + 1;
            }
    

            if (i == currReach){
    

                if (maxReach == i){
                    return -1;
                }
    

                else{
                    jump++;
                    currReach = maxReach;
                }
            }
        }
    
        return -1;
        
    }
};
