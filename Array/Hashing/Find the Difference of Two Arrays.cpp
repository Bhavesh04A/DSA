class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> first, second;

        for(int x: set1){
            if(set2.find(x)== set2.end()){
                first.push_back(x);
            }
        }
        for(int x: set2){
            if(set1.find(x)== set1.end()){
                second.push_back(x);
            }
        }
        return {first, second};


    }
};
