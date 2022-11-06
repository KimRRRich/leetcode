/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.03%)
 * Likes:    8382
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 5.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */
#include <iostream>

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size();
        int left = 0;
        int right = 1;
        int maxLen = 0;
        int curLen = 0;
        //for(int i=0;i<length;i++){
            //left = i;
            for(int j=right;j<length;j++){
                if(j==length-1){
                    curLen=j-left;
                    if(curLen>maxLen){
                        maxLen = curLen;
                    }
                     for(int k=left;k<j;k++){
                       if(s[k]==s[j]){
                           left = k+1;
                           break;
                       }
                   }
                    curLen=j-left+1;
                    if(curLen>maxLen){
                        maxLen = curLen;
                    }
                    break;
                }
               for(int k=left;k<j;k++){
                if(s[k]==s[j]){
                    curLen=j-left;
                    if(curLen>maxLen){
                        maxLen=curLen;
                    }
                    left = k+1;
                    break;
                }
               }
                right = j+1;
            }
        //}
        if(maxLen==0){
            maxLen=length;
        }
        return maxLen;

    }
};
// @lc code=end

