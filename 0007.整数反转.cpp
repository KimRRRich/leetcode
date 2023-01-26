/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode.cn/problems/reverse-integer/description/
 *
 * algorithms
 * Medium (35.39%)
 * Likes:    3676
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 3.2M
 * Testcase Example:  '123'
 *
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 
 * 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 123
 * 输出：321
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = -123
 * 输出：-321
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 120
 * 输出：21
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：x = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 
 * 
 * 
 */
#include<iostream>
#include<limits.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        bool isPositive = x >= 0;
        long long result = 0;
        if(x==INT_MIN) return 0;
        if(!isPositive) x = -x;
        while(x > 0){
            result = result * 10 + x % 10;
            x /= 10;
        }
        if(!isPositive) result = -result;
        if(result > (long long)INT_MAX || result < (long long)INT_MIN) return 0;
        return result;

    }
};
// @lc code=end

