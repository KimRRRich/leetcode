/*
 * @lc app=leetcode.cn id=1764 lang=cpp
 *
 * [1764] 通过连接另一个数组的子数组得到一个数组
 *
 * https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/description/
 *
 * algorithms
 * Medium (47.77%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 17.2K
 * Testcase Example:  '[[1,-1,-1],[3,-2,0]]\n[1,-1,0,1,-1,-1,3,-2,0]'
 *
 * 给你一个长度为 n 的二维整数数组 groups ，同时给你一个整数数组 nums 。
 * 
 * 你是否可以从 nums 中选出 n 个 不相交 的子数组，使得第 i 个子数组与 groups[i] （下标从 0 开始）完全相同，且如果 i > 0
 * ，那么第 (i-1) 个子数组在 nums 中出现的位置在第 i 个子数组前面。（也就是说，这些子数组在 nums 中出现的顺序需要与 groups
 * 顺序相同）
 * 
 * 如果你可以找出这样的 n 个子数组，请你返回 true ，否则返回 false 。
 * 
 * 如果不存在下标为 k 的元素 nums[k] 属于不止一个子数组，就称这些子数组是 不相交 的。子数组指的是原数组中连续元素组成的一个序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
 * 输出：true
 * 解释：你可以分别在 nums 中选出第 0 个子数组 [1,-1,0,1,-1,-1,3,-2,0] 和第 1 个子数组
 * [1,-1,0,1,-1,-1,3,-2,0] 。
 * 这两个子数组是不相交的，因为它们没有任何共同的元素。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
 * 输出：false
 * 解释：选择子数组 [1,2,3,4,10,-2] 和 [1,2,3,4,10,-2] 是不正确的，因为它们出现的顺序与 groups 中顺序不同。
 * [10,-2] 必须出现在 [1,2,3,4] 之前。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
 * 输出：false
 * 解释：选择子数组 [7,7,1,2,3,4,7,7] 和 [7,7,1,2,3,4,7,7] 是不正确的，因为它们不是不相交子数组。
 * 它们有一个共同的元素 nums[4] （下标从 0 开始）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * groups.length == n
 * 1 
 * 1 3
 * 1 
 * -10^7 
 * 
 * 
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        // int n=nums.size(),m=groups.size(),i,j,k=0;
        // if(m>n) return false;
        // for(i=0;i<m;){
        //     int l=groups[i].size();
        //     if(k+l>n)return false;

        //     for(j=0;j<l;j++)if(nums[k+j]!=groups[i][j])break;//尝试匹配
        //     if(j==l)i++,k+=l;//匹配成功
        //     else k++;//匹配失败
        // }
        // return true;

        int n=nums.size();
        int m=groups.size();
        int i=0;
        int k=0;
        int count=0;
        if(m>n) return false;
        while(i<m){
            int l=groups[i].size();
            if(k+l>n) return false;
            for(count=0;count<l;count++){
                if(nums[k+count]!=groups[i][count]) break;
            }
            if(count==l){
                k=k+count;
                i++;
            }
            else k++;
            //if(k>n) return false;
        }
        return true;
    }
};
// @lc code=end

