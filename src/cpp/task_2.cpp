#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Problem2 {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) {
            return false;
        }
        int targetSum = totalSum / 2;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(targetSum + 1, false));
        for (int i = 0; i <= nums.size(); ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= targetSum; ++j) {
                dp[i][j] = dp[i - 1][j];

                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][targetSum];
    }
};