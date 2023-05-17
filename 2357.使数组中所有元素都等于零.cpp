/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
 *
 * https://leetcode.cn/problems/make-array-zero-by-subtracting-equal-amounts/description/
 *
 * algorithms
 * Easy (74.24%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    22.1K
 * Total Submissions: 28.7K
 * Testcase Example:  '[1,5,0,3,5]'
 *
 * 给你一个非负整数数组 nums 。在一步操作中，你必须：
 *
 *
 * 选出一个正整数 x ，x 需要小于或等于 nums 中 最小 的 非零 元素。
 * nums 中的每个正整数都减去 x。
 *
 *
 * 返回使 nums 中所有元素都等于 0 需要的 最少 操作数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,5,0,3,5]
 * 输出：3
 * 解释：
 * 第一步操作：选出 x = 1 ，之后 nums = [0,4,0,2,4] 。
 * 第二步操作：选出 x = 2 ，之后 nums = [0,2,0,0,2] 。
 * 第三步操作：选出 x = 2 ，之后 nums = [0,0,0,0,0] 。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：0
 * 解释：nums 中的每个元素都已经是 0 ，所以不需要执行任何操作。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        //int ans = 0;
        unordered_set<int> cnt;
        for (auto n : nums){
            if(n!=0)
            
            cnt.insert(n);
        }
        return cnt.size();
    }
};
// @lc code=end
