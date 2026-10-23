class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() - 1;
        stack<int>s;
        for(int i = n; i > 0; i--){
            if(s.empty()) s.push(i);
            else if(height[i] > height[s.top()]) s.push(i);
        }

        int store = 0;
        int leftHt = height[0];
        for(int i = 1; i < n; i++){
            int idx = s.top();
            if(idx != i){
                int rightHt = height[idx];
                int minHt = min(leftHt, rightHt);
                if(minHt > height[i]) store += minHt - height[i];
            }else s.pop();
            
            leftHt = max(leftHt, height[i]);
        }
        return store;
    }
};