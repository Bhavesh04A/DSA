class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n=forts.size();
        int prev=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(forts[i]==0){
                continue;
            }
            if(prev!=-1 && forts[i]!= forts[prev]){
                ans= max(ans, i-prev-1);
            }
            prev=i;
        }
        return ans;
    }
};
