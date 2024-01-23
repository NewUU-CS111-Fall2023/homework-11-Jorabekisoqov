#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Problem1 {
public:
    int findWays(vector<int>& nums, int target) {
        unordered_map<pair<int, int>, int, pair_hash> memo;
        return dp(nums, 0, 0, target, memo);
    }

private:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    int dp(vector<int>& nums, int index, int currentSum, int target, unordered_map<pair<int, int>, int, pair_hash>& memo) {
        // Check if the result is already memoized
        if (memo.count({index, currentSum})) {
            return memo[{index, currentSum}];
        }

        // Base case: if we have reached the end of the array
        if (index == nums.size()) {
            // Check if the current sum equals the target
            return (currentSum == target) ? 1 : 0;
        }

        // Calculate the number of ways by considering both '+' and '-' for the current number
        int ways = dp(nums, index + 1, currentSum + nums[index], target, memo)
                   + dp(nums, index + 1, currentSum - nums[index], target, memo);

        // Memoize the result
        memo[{index, currentSum}] = ways;

        return ways;
    }
};