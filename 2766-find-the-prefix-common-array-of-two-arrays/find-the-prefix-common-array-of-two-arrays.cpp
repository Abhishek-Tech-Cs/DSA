class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            m[A[i]]++;
            m[B[i]]++;
            int count=0;
            if(m[A[i]]>=2) count++;
            if(A[i]!=B[i] && m[B[i]]>=2) count++;
            if(i==0) ans.push_back(count);
            else ans.push_back(count+ans[i-1]);
        }
        return ans;
    }
};