#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int max_pile = accumulate(candies.begin(), candies.end(), 0L) / k;
        int begin = 1;

        while (max_pile > 0) {
            int pile = max_pile / 2;
            long long happy_children = 0;
            for (int candies_pile : candies) {
                happy_children += candies_pile / (begin + pile);
            }
            if (happy_children >= k) {
                begin += pile + 1;
            }
            max_pile = pile;
        }

        return begin - 1;
    }
};
