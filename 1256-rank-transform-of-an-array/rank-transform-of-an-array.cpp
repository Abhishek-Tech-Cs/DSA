class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>m;
        int rank=1;
        for(auto i:temp){
            if(m.count(i)==0){
                m[i]=rank;
                rank++;
            }
        }
        vector<int>ans;
        for(auto i:arr){
            ans.push_back(m[i]);
        }
        return ans;
    }
};