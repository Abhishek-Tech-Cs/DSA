class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int arr[10]={0};
        for(auto i:digits) arr[i]++;

        int ans=0;
        for(int i=1;i<10;i++){
            if(arr[i] == 0) continue;
            for(int j=0;j<10;j++){
                if(arr[j]==0 || (i == j && arr[j] <= 1)) continue;
                for(int k=0;k<9;k+=2){
                    if(arr[k]==0 || (i==k && arr[k]<=1) || (j==k && arr[k]<=1) || (i==k && i==j && arr[i]<=2)) continue;
                    ans+=1; 
                }
            }
        }
        return ans;
    }
};