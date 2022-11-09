/*
 * @lc app=leetcode.cn id=764 lang=cpp
 *
 * [764] 最大加号标志
 *
 * https://leetcode.cn/problems/largest-plus-sign/description/
 *
 * algorithms
 * Medium (49.76%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    19.7K
 * Total Submissions: 37.1K
 * Testcase Example:  '5\n[[4,2]]'
 *
 * 在一个 n x n 的矩阵 grid 中，除了在数组 mines 中给出的元素为 0，其他每个元素都为 1。mines[i] = [xi, yi]表示
 * grid[xi][yi] == 0
 * 
 * 返回  grid 中包含 1 的最大的 轴对齐 加号标志的阶数 。如果未找到加号标志，则返回 0 。
 * 
 * 一个 k 阶由 1 组成的 “轴对称”加号标志 具有中心网格 grid[r][c] == 1 ，以及4个从中心向上、向下、向左、向右延伸，长度为
 * k-1，由 1 组成的臂。注意，只有加号标志的所有网格要求为 1 ，别的网格可能为 0 也可能为 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入: n = 5, mines = [[4, 2]]
 * 输出: 2
 * 解释: 在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入: n = 1, mines = [[0, 0]]
 * 输出: 0
 * 解释: 没有加号标志，返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 500
 * 1 <= mines.length <= 5000
 * 0 <= xi, yi < n
 * 每一对 (xi, yi) 都 不重复​​​​​​​
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        const int size = n;
        vector<vector<int>> grid(size, vector<int>(size, 1));
        for (auto& mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        vector<vector<int>> left(size, vector<int>(size, 0));
        vector<vector<int>> right(size, vector<int>(size, 0));
        vector<vector<int>> up(size, vector<int>(size, 0));
        vector<vector<int>> down(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (grid[i][j] == 1) {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                    
                }
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = size - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    right[i][j] = (j == size - 1 ? 0 : right[i][j + 1]) + 1;
                }
            }
        }
        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < size; ++i) {
                if (grid[i][j] == 1) {
                    up[i][j] = (i == 0 ? 0 : up[i - 1][j]) + 1;
                }
            }
        }
        for (int j = 0; j < size; ++j) {
            for (int i = size - 1; i >= 0; --i) {
                if (grid[i][j] == 1) {
                    down[i][j] = (i == size - 1 ? 0 : down[i + 1][j]) + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int len = min({left[i][j], right[i][j], up[i][j], down[i][j]});
                ans = max(ans, len);
            }
        }
        return ans;

    }
};
// @lc code=end

