class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0,maxi = 0;
        for(auto i : s){
            if(i == '('){
                maxi++,mini++;
            }else if(i == ')'){
                maxi--,mini--;
            }else{
                maxi++,mini--;                
            }

            if(maxi<0) return false;

            mini = max(mini, 0);
        }
        return mini == 0;
    }
}; 