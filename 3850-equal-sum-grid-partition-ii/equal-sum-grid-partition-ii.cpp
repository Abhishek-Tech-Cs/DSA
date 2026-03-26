class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        long long totalSum = 0;
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                totalSum += grid[i][j];
            }
        }

        //Single row
        if (r == 1) {
            vector<int>& arr = grid[0];
            long long sum = 0;

            for (int i = arr.size() - 1; i >= 0; i--) {
                sum += arr[i];
                if (sum == totalSum - sum || 
                    sum - arr[arr.size() - 1] == totalSum - sum ||
                    sum - arr[i] == totalSum - sum) {
                    return true;
                }
            }

            sum = 0;
            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i];
                if (sum == totalSum - sum || 
                    sum - arr[0] == totalSum - sum || 
                    sum - arr[i] == totalSum - sum) {
                    return true;
                }
            }
            return false;
        }

        //Single column
        if (c == 1) {
            vector<int> arr(r);
            for (int i = 0; i < r; i++) arr[i] = grid[i][0];

            long long sum = 0;

            for (int i = arr.size() - 1; i >= 0; i--) {
                sum += arr[i];
                if (sum == totalSum - sum || 
                    sum - arr[arr.size() - 1] == totalSum - sum ||
                    sum - arr[i] == totalSum - sum) {
                    return true;
                }
            }

            sum = 0;
            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i];
                if (sum == totalSum - sum || 
                    sum - arr[0] == totalSum - sum || 
                    sum - arr[i] == totalSum - sum) {
                    return true;
                }
            }
            return false;
        }

        // Horizontal (top → down)
        long long rowSum = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < r - 1; i++) {

            for (int j = 0; j < c; j++) {
                rowSum += grid[i][j];
                mp[grid[i][j]]++;
            }

            if (rowSum == totalSum - rowSum) return true;

            if (i == 0) {
                if (rowSum - grid[i][0] == totalSum - rowSum) return true;
            } else {
                long long diff = 2 * rowSum - totalSum;

                int rows = i + 1;
                int cols = c;

                if (rows == 1) {
                    if (grid[0][0] == diff || grid[0][c - 1] == diff) return true;
                } else if (cols == 1) {
                    if (grid[0][0] == diff || grid[i][0] == diff) return true;
                } else {
                    if (diff <= INT_MAX && mp.count((int)diff)) return true;
                }
            }
        }

        //Horizontal (bottom → up)
        rowSum = 0;
        mp.clear();

        for (int i = r - 1; i > 0; i--) {

            for (int j = c - 1; j >= 0; j--) {
                rowSum += grid[i][j];
                mp[grid[i][j]]++;
            }

            if (rowSum == totalSum - rowSum) return true;

            if (i == r - 1) {
                if (rowSum - grid[i][c - 1] == totalSum - rowSum) return true;
            } else {
                long long diff = 2 * rowSum - totalSum;

                int rows = r - i;
                int cols = c;

                if (rows == 1) {
                    if (grid[r - 1][0] == diff || grid[r - 1][c - 1] == diff) return true;
                } else if (cols == 1) {
                    if (grid[i][0] == diff || grid[r - 1][0] == diff) return true;
                } else {
                    if (diff <= INT_MAX && mp.count((int)diff)) return true;
                }
            }
        }

        //Vertical (left → right)
        long long colSum = 0;
        mp.clear();

        for (int i = 0; i < c - 1; i++) {

            for (int j = 0; j < r; j++) {
                colSum += grid[j][i];
                mp[grid[j][i]]++;
            }

            if (colSum == totalSum - colSum) return true;

            if (i == 0) {
                if (colSum - grid[0][0] == totalSum - colSum) return true;
            } else {
                long long diff = 2 * colSum - totalSum;

                int rows = r;
                int cols = i + 1;

                if (rows == 1) {
                    if (grid[0][0] == diff || grid[0][i] == diff) return true;
                } else if (cols == 1) {
                    if (grid[0][0] == diff || grid[r - 1][0] == diff) return true;
                } else {
                    if (diff <= INT_MAX && mp.count((int)diff)) return true;
                }
            }
        }

        // Vertical (right → left)
        colSum = 0;
        mp.clear();

        for (int i = c - 1; i > 0; i--) {

            for (int j = r - 1; j >= 0; j--) {
                colSum += grid[j][i];
                mp[grid[j][i]]++;
            }

            if (colSum == totalSum - colSum) return true;

            if (i == c - 1) {
                if (colSum - grid[r - 1][c - 1] == totalSum - colSum) return true;
            } else {
                long long diff = 2 * colSum - totalSum;

                int rows = r;
                int cols = c - i;

                if (rows == 1) {
                    if (grid[0][i] == diff || grid[0][c - 1] == diff) return true;
                } else if (cols == 1) {
                    if (grid[0][i] == diff || grid[r - 1][i] == diff) return true;
                } else {
                    if (diff <= INT_MAX && mp.count((int)diff)) return true;
                }
            }
        }

        return false;
    }
};