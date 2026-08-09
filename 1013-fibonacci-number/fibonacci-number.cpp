class Solution {
public:
    int fib(int n) {
        vector<int>memory(n+1,-1);
        return findFib(n,memory);
    }
    int findFib(int n, vector<int> &memory){
        if(n<=1) return n;
        if(memory[n]!=-1) return memory[n];

        int fibSum=findFib(n-1,memory)+findFib(n-2,memory);
        memory[n]=fibSum;
        return fibSum;
    }
};