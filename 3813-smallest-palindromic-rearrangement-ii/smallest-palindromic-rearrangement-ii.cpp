class Solution {
public:
    string smallestPalindrome(string s, int k) {
        if(k==1 && s.size()==1) return s;
        vector<int>m(26,0);
        for(auto i:s) m[i-'a']++;

        char middle='-';
        for(int i=0;i<26;i++){
            if(m[i]%2!=0) middle=i+'a';
            m[i]=m[i]/2;
        }

        string str1;
        int len=s.size()/2;
        for(int i=0;i<26;i++){
            if(m[i]>0){
                len--;
                str1.push_back(i+'a');
                m[i]--;
                long long cnt = 1;
                    int letters = 0;
                    for(int c = 0; c < 26; c++) {
                        letters += m[c];
                    }

                    for(int c = 0; c < 26; c++) {
                        if(m[c] > 0) {
                            cnt *= nCr(letters, m[c], k); //log2(k)
                            letters -= m[c];
                        }

                        if(cnt >= k) {
                            break;
                        }
                    }
                if(cnt<k){
                    k-=cnt;
                    str1.pop_back();
                    len++;
                    m[i]++;
                }else{
                    i=-1;
                }
            }
        }
        if(str1.empty()) return str1;
        string str2=str1;
        reverse(str2.begin(),str2.end());
        if(middle!='-') str1.push_back(middle);
        return str1+str2;
    }
    long long nCr(int n, int r, int k) {
        r = min(r, n-r); //nCr == nC(n-r)

        long long result = 1;

        for(int i = 1; i <= r; i++) {
            result = result * (n - r + i)/i; 

            if(result >= k) 
                return k;
        }

        return result;
    }
};