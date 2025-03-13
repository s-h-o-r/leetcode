#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int begin = 0;
        while (size > 0) {
            int step = size / 2;
            if (nums[begin + step] < target) {
                begin += step + 1;
                size -= step + 1;
            } else {
                size = step;
            }
        }

        return begin < nums.size() && nums[begin] == target ? begin : -1;
    }
};