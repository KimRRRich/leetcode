/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 *
 * https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
 *
 * algorithms
 * Medium (32.80%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    23.6K
 * Total Submissions: 65.1K
 * Testcase Example:  '[1,1,4,2,3]\n5'
 *
 * 给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要
 * 修改 数组以供接下来的操作使用。
 * 
 * 如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,4,2,3], x = 5
 * 输出：2
 * 解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,6,7,8,9], x = 4
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,2,20,1,1,3], x = 10
 * 输出：5
 * 解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * 
 * 
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int SUM=0;
        if(nums[0]>x&&nums[n-1]>x) return -1;
        if(nums[0]==x||nums[n-1]==x) return 1;
        for(int i=0;i<n;i++){
            SUM+=nums[i];
        }
        if(SUM<x) return -1;
        if(SUM==x) return n;
        int ans=0;
        ans=Window(nums,SUM-x);
        //cout<<SUM-x<<endl;
        return ans;
    }

    int Window(vector<int>& nums, int x){
        int left=0,right=0;
        int sum=0;
        int ans=-1;
        int n=nums.size();
        while(right<n){
            sum+=nums[right];
            //cout<<sum<<endl;
            while(sum>x){
                sum-=nums[left];
                left++;
            }
            if(sum==x){
                ans=max(ans,right-left+1);
            }
            right++;
        }
        return n-ans;

       
    }
};
// @lc code=end

