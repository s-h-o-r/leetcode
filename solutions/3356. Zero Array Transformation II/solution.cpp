#include <vector>

using namespace std;

/*Solution 1: -----------------------------------------------------------------*/

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int zero_amount = 0;
        for (int i : nums) {
            if (i == 0) ++zero_amount;
        }

        int query = 0;
        while (query < queries.size() && zero_amount < nums.size()) {
            for (int left = queries[query][0], right = queries[query][1]; left <= right; ++left) {
                if (nums[left] != 0) {
                    nums[left] = max(0, nums[left] - queries[query][2]);
                    if (nums[left] == 0) ++zero_amount;
                }
            }
            ++query;
        }

        return zero_amount == nums.size() ? query : -1;
    }
};

/*Solution 2: -----------------------------------------------------------------*/

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int left = 0;
        int right = queries.size();

        while (left <= right) {
            int mid = (right - left) / 2;


            if (isNumsZeroArray(nums, makePrefixSumOfQuery(queries, nums.size(), left + mid))) {
                right -= mid + 1;
            } else {
                left += mid + 1;
            }
        }
        return left > queries.size() ? -1 : left;
    }

private:
    bool isNumsZeroArray(const vector<int>& nums, const vector<int>& prefix) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] - prefix[i] > 0) return false;
        }
        return true;
    }

    vector<int> makePrefixSumOfQuery(const vector<vector<int>>& queries, size_t size_nums, size_t end_queries) {
        vector<int> difference_array(size_nums + 1, 0);
        for (int i = 0; i < end_queries; ++i) {
            difference_array[queries[i][0]] += queries[i][2];
            difference_array[queries[i][1] + 1] -= queries[i][2];
        }

        for (int i = 1; i < difference_array.size(); ++i) {
            difference_array[i] += difference_array[i - 1];
        }
        difference_array.pop_back();
        return difference_array;
    }
};
