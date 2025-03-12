#include <algorithm>
#include <vector>

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size(), pivot);
        size_t begin = 0;
        size_t end = nums.size() - 1;
        for (int num : nums) {
            if (num < pivot) {
                res[begin++] = num;
            } else if (num > pivot) {
                res[end--] = num;
            }
        }
        reverse(res.begin() + end + 1, res.end());
        return res;
    }
};
