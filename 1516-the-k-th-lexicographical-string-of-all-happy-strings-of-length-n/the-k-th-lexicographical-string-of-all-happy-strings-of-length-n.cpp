class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> happy;
        string temp = "";
        solve(n, k, happy, temp);
        for (int i = 0; i < happy.size() && i < k; i++) {
            if ((i + 1) == k)
                return happy[i];
        }
        return "";
    }
    void solve(int n, int k, vector<string>& happy, string temp) {
        if (temp.size() >= n) {
            happy.push_back(temp);
            return;
        }

        if (temp != "" && temp.back() != 'a') {
            temp.push_back('a');
            solve(n, k, happy, temp);
            temp.pop_back();
        } else if (temp == "") {
            temp.push_back('a');
            solve(n, k, happy, temp);
            temp.pop_back();
        }

        if (temp != "" && temp.back() != 'b') {
            temp.push_back('b');
            solve(n, k, happy, temp);
            temp.pop_back();
        } else if (temp == "") {
            temp.push_back('b');
            solve(n, k, happy, temp);
            temp.pop_back();
        }

        if (temp != "" && temp.back() != 'c') {
            temp.push_back('c');
            solve(n, k, happy, temp);
            temp.pop_back();
        } else if (temp == "") {
            temp.push_back('c');
            solve(n, k, happy, temp);
            temp.pop_back();
        }
    }
};