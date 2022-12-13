/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 *
 * https://leetcode.cn/problems/check-if-the-sentence-is-pangram/description/
 *
 * algorithms
 * Easy (81.79%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    37.4K
 * Total Submissions: 43.9K
 * Testcase Example:  '"thequickbrownfoxjumpsoverthelazydog"'
 *
 * 全字母句 指包含英语字母表中每个字母至少一次的句子。
 * 
 * 给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。
 * 
 * 如果是，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
 * 输出：true
 * 解释：sentence 包含英语字母表中每个字母至少一次。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：sentence = "leetcode"
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * sentence 由小写英语字母组成
 * 
 * 
 */
#include<stdlib.h>
#include<iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int length=sentence.size();
        if(length<26) return false;
        int exist[26]={0};
        for(int i=0;i<length;i++){
            int a=sentence[i]-'a';
            //cout<<a<<endl;
            exist[a]+=1;
        }

        for(int i=0;i<26;i++){
            if(exist[i]==0) return false;
        }
        return true;

    }
};
// @lc code=end

