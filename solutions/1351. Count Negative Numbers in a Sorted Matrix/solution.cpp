#include <vector>

using namespace std;

/*Решение 1: -----------------------------------------------------------------*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] < 0) {
                    res += grid[i].size() - j;
                    break;
                }
            }
        }
        return res;
    }
};

/*Решение 2: -----------------------------------------------------------------*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int line = grid.size() - 1;
        int elem = 0;
        int res = 0;

        while (line >= 0 && elem < grid[line].size()) {
            if (grid[line][elem] < 0) {
                res += grid[line].size() - elem;
                --line;
            } else {
                ++elem;
            }
        }
        return res;
    }
};