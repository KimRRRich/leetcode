/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-consistent-strings/description/
 *
 * algorithms
 * Easy (82.10%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    43.8K
 * Total Submissions: 51.1K
 * Testcase Example:  '"ab"\n["ad","bd","aaab","baa","badab"]'
 *
 * 给你一个由不同字符组成的字符串 allowed 和一个字符串数组 words 。如果一个字符串的每一个字符都在 allowed 中，就称这个字符串是
 * 一致字符串 。
 * 
 * 请你返回 words 数组中 一致字符串 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
 * 输出：2
 * 解释：字符串 "aaab" 和 "baa" 都是一致字符串，因为它们只包含字符 'a' 和 'b' 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
 * 输出：7
 * 解释：所有字符串都是一致的。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
 * 输出：4
 * 解释：字符串 "cc"，"acd"，"ac" 和 "d" 是一致字符串。
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
 * allowed 中的字符 互不相同 。
 * words[i] 和 allowed 只包含小写英文字母。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        int isOk=0;
        for(int i=0;i<words.size();i++){
            isOk=0;
            for(int j=0;j<words[i].size();j++){
                for(int k=0;k<allowed.size();k++){
                    if(words[i][j]==allowed[k]){
                        isOk+=1;
                        break;
                    }
                    if(k==allowed.size()-1){
                        j=words[i].size();
                    }
                }
            }
            if(isOk==words[i].size()){
                count+=1;
            }
        }
        return count;

    }
};
// @lc code=end

