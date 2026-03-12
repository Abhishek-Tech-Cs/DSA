class Solution {
public:
    bool areAdjacent(char a, char b) {
        return abs(a - b) == 1;
    }
    string resultingString(string s) {
        for (int i = 0; i < s.size() ;) {
            if ((i+1)<s.size() && (s[i] == 'a' && s[i + 1] == 'z') || (s[i] == 'z' && s[i + 1] == 'a') || areAdjacent(s[i],s[i+1])) {
                s.erase(i, 2);
                if (i != 0) i--;
            } else i++;
        }
        return s;
    }
};