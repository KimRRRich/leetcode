/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (53.96%)
 * Likes:    2725
 * Dislikes: 0
 * Total Accepted:    998.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 45
 * 
 * 
 */
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
    unordered_map<int,int> set;
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        return Count(n-1)+Count(n-2);
    }

    int Count(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        if(set[n]!=0) return set[n];
        set[n]=Count(n-1)+Count(n-2);
        
        return set[n];
    }
};
// @lc code=end

