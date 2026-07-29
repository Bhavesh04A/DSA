class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int maxWidth=0;
        for(int i=0;i<points.size()-1;i++){
            int currWidth= points[i+1][0]-points[i][0];
            maxWidth= max(maxWidth, currWidth);
        }
        return maxWidth;
    }
};
