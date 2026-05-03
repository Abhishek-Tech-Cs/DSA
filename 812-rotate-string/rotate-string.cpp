class Solution {
public:
    bool rotateString(string s, string goal) {
        int size=s.size();
        for(int i=0;i<size;i++){
            if(s==goal) return true;
            s.push_back(s.front());
            s.erase(s.begin());
        }
        if(s==goal) return true;
        return false;
    }
};