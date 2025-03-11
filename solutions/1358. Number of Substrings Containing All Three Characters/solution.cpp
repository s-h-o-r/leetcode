#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        unordered_map<char, int> abc_counting;

        for (int left = 0, right = 0; right < s.size(); ++right) {
            ++abc_counting[s[right]];

            while (abc_counting.size() == 3) {
                res += s.size() - right;
                if (--abc_counting[s[left]] == 0) {
                    abc_counting.erase(s[left]);
                }
                ++left;
            }
        }
        return res;
    }
};
