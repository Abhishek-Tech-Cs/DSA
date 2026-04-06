struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, hash_pair> s;
        for (int i = 0; i < obstacles.size(); i++) {
            s.insert({obstacles[i][0], obstacles[i][1]});
        }

        string pos = "+y";
        int x = 0, y = 0;
        int ans = 0;

        bool check = true;

        for (int i = 0; i < commands.size(); i++) {
            if (check) {
                if (commands[i] == -1)
                    pos = "+x";
                else if (commands[i] == -2)
                    pos = "-x";
                else {
                    int temp = commands[i];
                    while (temp--) {
                        y++; // since initial is +y

                        if (s.count({x, y})) {
                            y--;
                            break;
                        }

                        ans = max(ans, x * x + y * y);
                    }
                }
                check = false;
            } else if (commands[i] == -1 || commands[i] == -2) {
                if (commands[i] == -1) { // right turn
                    if (pos == "+y")
                        pos = "+x";
                    else if (pos == "+x")
                        pos = "-y";
                    else if (pos == "-y")
                        pos = "-x";
                    else if (pos == "-x")
                        pos = "+y";
                } else if (commands[i] == -2) { // left turn
                    if (pos == "+y")
                        pos = "-x";
                    else if (pos == "-x")
                        pos = "-y";
                    else if (pos == "-y")
                        pos = "+x";
                    else if (pos == "+x")
                        pos = "+y";
                }
            } else {
                int temp = commands[i];
                while (temp--) {
                    if (pos == "+y")
                        y++;
                    else if (pos == "-y")
                        y--;
                    else if (pos == "+x")
                        x++;
                    else
                        x--;

                    if (s.count({x, y})) {
                        if (pos == "+y")
                            y--;
                        else if (pos == "-y")
                            y++;
                        else if (pos == "+x")
                            x--;
                        else
                            x++;
                        break;
                    }

                    ans = max(ans, x * x + y * y);
                }
            }

            ans = max(ans, x * x + y * y);
        }

        return ans;
    }
};