class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m=mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto i:asteroids){
            if(m>=i) m+=i;
            else return false;
        }
        return true;
    }
};