#define ll long long
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int len=0;
        int preFr=-1,preSc=-1;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            int fr=intervals[i][0];
            int sc=intervals[i][1];
            if(preSc!=-1 && preSc>=fr){
                preSc=max(preSc,sc);
                preFr=min(preFr,fr);
            }else{
                if(preSc!=-1) len=len+preSc-preFr+1;
                preSc=sc;
                preFr=fr;
            }
        }
        len=len+preSc-preFr+1;
        int req=brightness/3;
        if(brightness%3!=0) req++;

        return (ll)req*len;
    }
};