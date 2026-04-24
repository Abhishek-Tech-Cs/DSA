class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int R = 0, L = 0;
        int size=moves.size();
        for (auto i : moves){
            if (i == 'R') R++;
            else if (i == 'L') L++;
        }

        int leftOut=size-(R+L);
        if(R>L) return R-L+leftOut;
        else return L-R+leftOut;
    }
};