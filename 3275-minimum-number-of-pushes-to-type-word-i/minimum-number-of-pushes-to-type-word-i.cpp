class Solution {
public:
    int minimumPushes(string word) {
        if(word.size()<=8) return word.size();
        else if(word.size()<=16) return 8+(word.size()-8)*2;
        else if(word.size()<=24) return 8+8*2+(word.size()-16)*3;
        else return 8+8*2+8*3+(word.size()-24)*4;
    }
};