/*
 * @lc app=leetcode.cn id=1799 lang=cpp
 *
 * [1799] N 次操作后的最大分数和
 *
 * https://leetcode.cn/problems/maximize-score-after-n-operations/description/
 *
 * algorithms
 * Hard (54.30%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 14.2K
 * Testcase Example:  '[1,2]'
 *
 * 给你 nums ，它是一个大小为 2 * n 的正整数数组。你必须对这个数组执行 n 次操作。
 * 
 * 在第 i 次操作时（操作编号从 1 开始），你需要：
 * 
 * 
 * 选择两个元素 x 和 y 。
 * 获得分数 i * gcd(x, y) 。
 * 将 x 和 y 从 nums 中删除。
 * 
 * 
 * 请你返回 n 次操作后你能获得的分数和最大为多少。
 * 
 * 函数 gcd(x, y) 是 x 和 y 的最大公约数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2]
 * 输出：1
 * 解释：最优操作是：
 * (1 * gcd(1, 2)) = 1
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [3,4,6,8]
 * 输出：11
 * 解释：最优操作是：
 * (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,3,4,5,6]
 * 输出：14
 * 解释：最优操作是：
 * (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 7
 * nums.length == 2 * n
 * 1 <= nums[i] <= 10^6
 * 
 * 
 */


/*
不能按照每次都找公约数最大的情况

*/
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size()/2;
        //int backup[14][14]={0};
        int Visited[14]={0};
        vector<int> max;
        int ans=0;
        for(int i=0;i<n;i++){
            max.push_back(getMax(nums,Visited));
        }
         for(int i=1;i<=n;i++){
            ans=ans+i*max[n-i];
        }
        for(int i=0;i<n;i++){
            cout<<max[n-i-1]<<"*"<<i+1<<endl;
        }
        return ans;

    }

    int gcd(int x,int y){
        if (x == 0) return y;
        if (y==0) return x;
        return gcd(y, x % y);
    }

    int getMax(vector<int>& nums,int *Visited){
        int max=0;
        int a=0;
        int b=0;
        for(int i=0;i<nums.size();i++){
            if(Visited[i]==0){
                for(int j=i+1;j<nums.size();j++){
                    if(Visited[j]==0){
                        int temp=gcd(nums[i],nums[j]);
                        if(temp>max) {
                            max=temp;
                            a=i;
                            b=j;
                        }
                    }
                }
            }
            
        }
        // nums.erase(nums.begin()+a);
        // nums.erase(nums.begin()+b);
        Visited[a]=1;
        Visited[b]=1;

        return max;
    }
};
// @lc code=end

