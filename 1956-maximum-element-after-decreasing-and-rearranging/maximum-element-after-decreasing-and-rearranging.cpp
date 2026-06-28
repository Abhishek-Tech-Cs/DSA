class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(i==0) arr[i]=1;
            else{
                if((arr[i]-arr[i-1])>1) arr[i]=arr[i-1]+1;
            }
            ans=max(ans,arr[i]);
        }
        return ans;
    }
};