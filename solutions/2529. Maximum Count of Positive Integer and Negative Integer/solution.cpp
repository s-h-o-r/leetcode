#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lower_bound = [&nums] (int value) {
            size_t size = nums.size();
            auto begin = nums.begin();

            while (size > 0) {
                size_t step = size / 2;
                auto it = begin + step;

                if (*it < value) {
                    begin = it + 1;
                    size -= step + 1;
                } else {
                    size = step;
                }
            }
            return begin;
        };

        return max(distance(nums.begin(), lower_bound(0)), distance(lower_bound(1), nums.end()));
    }
};
