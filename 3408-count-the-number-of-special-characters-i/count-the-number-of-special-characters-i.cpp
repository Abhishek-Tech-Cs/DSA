class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,bool>m;
        unordered_map<char,int>check;
        int ans=0;
        for(auto i:word){
            m[i]=true;
            if(m[tolower(i)] && m[toupper(i)] && check[tolower(i)]<1){
                cout<<i<<" ";
                ans++;
                check[tolower(i)]++;
            }            
        }
        return ans;
    }
};