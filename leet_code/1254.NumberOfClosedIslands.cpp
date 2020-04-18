// https://leetcode.com/problems/number-of-closed-islands/
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y]==0) {
            grid[x][y] = -1;
            dfs(grid, x-1, y);
            dfs(grid, x+1, y);
            dfs(grid, x, y-1);
            dfs(grid, x, y+1);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) && grid[i][j] == 0) {
                    dfs(grid, i, j);
                }
            }
        }

        int num = 0;   
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    ++num;
                }
            }
        }

        return num;
    }
};

