class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,bool>m;
        unordered_map<char,bool>check;
        for(auto i:word){
            m[i]=true;
            if(i>='a' && i<='z' && !check[i] && m[toupper(i)]) check[i]=true;
        }
        int ans=0;
        for(auto i:word){
            if(m[tolower(i)] && m[toupper(i)] && !check[tolower(i)]){
                ans++;
                check[tolower(i)]=true;
            }
        }
        return ans;
    }
};