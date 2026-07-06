class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans=intervals.size();
        sort(intervals.begin(),intervals.end());
        int preI=intervals[0][0];
        int preII=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int currI=intervals[i][0];
            int currII=intervals[i][1];
            if((currI<=preI && currII>=preII) || (currI>=preI && currII<=preII)){
                preI=min(currI,preI);
                preII=max(currII,preII);
                ans--;
            }else{
                preI=currI;
                preII=currII;
            }
        }
        return ans;
    }
};