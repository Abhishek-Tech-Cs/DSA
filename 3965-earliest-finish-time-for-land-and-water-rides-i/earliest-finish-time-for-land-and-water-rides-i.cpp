class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int m = landStartTime.size();
        int n = waterStartTime.size();

        vector<pair<int,int>> land, water;

        for(int i = 0; i < m ; i++)
            land.push_back({landStartTime[i],landDuration[i]});

        

        for(int j = 0; j < n ; j++)
            water.push_back({waterStartTime[j],waterDuration[j]});

        sort(land.begin(),land.end());
        sort(water.begin(),water.end());

        int ans = 20000;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int s1 = land[i].first;
                int e1 = s1 + land[i].second;

                int s2 = water[j].first;
                int e2 = s2 + water[j].second;

                if(e1 <= s2 || e2 <= s1)
                    ans = min(ans, max(e1,e2));
                else  
                {
                    if(s1 <= s2)
                        ans = min(ans, e1 + e2 - s2);
                    else 
                        ans = min(ans, e2 + e1 - s1);

                }

            }

        }

        return ans;
        
    }
};