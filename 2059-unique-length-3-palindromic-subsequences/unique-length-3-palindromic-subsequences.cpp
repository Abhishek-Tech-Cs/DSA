class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>maxIndex(26,INT_MIN);
        vector<int>minIndex(26,INT_MAX);
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            maxIndex[idx]=max(maxIndex[idx],i);
            minIndex[idx]=min(minIndex[idx],i);
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(maxIndex[i]==INT_MIN || minIndex[i]==INT_MAX) continue;

            unordered_map<char,int>uniqueChars;
            for(int j=minIndex[i]+1;j<maxIndex[i];j++){
                uniqueChars[s[j]]++;
            }
            ans+=uniqueChars.size();
        }

        return ans;
    }
};