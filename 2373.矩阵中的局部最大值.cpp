/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
 *
 * https://leetcode.cn/problems/largest-local-values-in-a-matrix/description/
 *
 * algorithms
 * Easy (84.77%)
 * Likes:    38
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 20.4K
 * Testcase Example:  '[[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]'
 *
 * 给你一个大小为 n x n 的整数矩阵 grid 。
 * 
 * 生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：
 * 
 * 
 * maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
 * 
 * 
 * 换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。
 * 
 * 返回生成的矩阵。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
 * 输出：[[9,9],[8,6]]
 * 解释：原矩阵和生成的矩阵如上图所示。
 * 注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
 * 输出：[[2,2,2],[2,2,2],[2,2,2]]
 * 解释：注意，2 包含在 grid 中每个 3 x 3 的矩阵中。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == grid.length == grid[i].length
 * 3 <= n <= 100
 * 1 <= grid[i][j] <= 100
 * 
 * 
 */
#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
// @lc code=start
class Solution {
    int max(int a,int b,int c,int d,int e,int f,int g,int h,int i){
            int Max=a;
            if(b>Max) Max=b;
            if(c>Max) Max=c;
            if(d>Max) Max=d;
            if(e>Max) Max=e;
            if(f>Max) Max=f;
            if(g>Max) Max=g;
            if(h>Max) Max=h;
            if(i>Max) Max=i;
            return Max;
        }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                int Max=max(grid[i][j],grid[i][j+1],grid[i][j+2],grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2],grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]);
                ans[i][j]=Max;
            }
        }
        return ans;

        
        
    }
};
// @lc code=end

