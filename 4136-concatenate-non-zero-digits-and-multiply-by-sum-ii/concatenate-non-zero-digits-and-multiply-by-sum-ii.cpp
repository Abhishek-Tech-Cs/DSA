class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m=1000000007;
        int size=s.size();
        vector<long long>preSum(size,0);
        preSum[0]=s[0]-'0';
        for(int i=1;i<size;i++){
            preSum[i]=preSum[i-1]+(s[i]-'0');
        }

        vector<long long>pow10(size+1,0);
        pow10[0]=1;
        for(int i=1;i<size;i++){
            pow10[i]=(pow10[i-1]*10)%m; 
        }

        vector<long long>numTillNow(size,0);
        numTillNow[0]=s[0]-'0';
        for(int i=1;i<size;i++){
            numTillNow[i]=numTillNow[i-1];
            if(s[i]!='0'){
                numTillNow[i]=(numTillNow[i-1]*long(10)+(s[i]-'0'))%m;
            }
        }

        vector<long long>nonZero(size,0);
        nonZero[0]=(s[0]!='0')?1:0;
        for(int i=1;i<size;i++){
            if(s[i]!='0') nonZero[i]=nonZero[i-1]+1;
            else nonZero[i]=nonZero[i-1];
        }

        vector<int>ans;
        for(auto i:queries){
            int l=i[0];
            int r=i[1];
            if(l==0){
                long long sum=preSum[r];
                long long x=numTillNow[r];
                int multiply=(sum*x)%m;
                ans.push_back(multiply);
            }else{
                int sum=preSum[r]-preSum[l-1];
                 long long numTillR=numTillNow[r];
                 long long numTillL=numTillNow[l-1];
                long long k=nonZero[r]-((l==0)?0:nonZero[l-1]);
                long long x=(numTillR-(numTillL*pow10[k]%m)+m)%m;
                int multiply=(sum*x)%m;
                ans.push_back(multiply); 
            }
        }
        return ans;
    }
}; 