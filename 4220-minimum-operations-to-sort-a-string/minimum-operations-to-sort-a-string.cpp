class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool isSorted = true;
        char minChar = s[0], maxChar = s[0];
        for(int i = 1; i < n; i++){
            if(s[i] < s[i - 1]) isSorted = false;
            minChar = min(minChar, s[i]); 
            maxChar = max(maxChar, s[i]); 
        }
        if(isSorted) return 0;
        if(n == 2) return -1;
        if(s[0] == minChar || s[n-1] == maxChar) return 1;
        
        for(int i = 1; i < n - 1; i++){
            if(s[i] == minChar || s[i] == maxChar) return 2; 
        }
        return 3;
    }
};