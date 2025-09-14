class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int startIdx = 0;
        
        int currGas = 0;
        
        for(int i = 0; i < n; i++) {
            currGas = currGas + gas[i] - cost[i];
            

            if(currGas < 0) {
                startIdx = i + 1;
                currGas = 0;
            }
        }
        

        currGas = 0;
        for(int i = 0; i < n; i++) {
            
            int idx = (i + startIdx) % n;
          	currGas = currGas + gas[idx] - cost[idx];
            if(currGas < 0)
                return -1;
        }
        
        return startIdx;
        
    }
};
