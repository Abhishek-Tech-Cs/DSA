class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if (words[startIndex] == target)
            return 0;

        int n = words.size();
        int left=1,right=1;

        int i = (startIndex + 1) % n;
        while (i != startIndex){
            if(words[i]==target) break;
            i = (i + 1) % n;
            right++;
        }
        if (i == startIndex) return -1;

        if(startIndex==0) i=n-1;
        else i=startIndex-1;
        
        while(i!=startIndex){
            if(words[i]==target) break;
            if(i==0) i=n-1;
            else i--;
            left++;
        }

        return min(left,right);
    }
};