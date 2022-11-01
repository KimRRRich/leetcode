/*
 * @lc app=leetcode.cn id=1662 lang=cpp
 *
 * [1662] 检查两个字符串数组是否相等
 *
 * https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/description/
 *
 * algorithms
 * Easy (80.92%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    49.3K
 * Total Submissions: 60.1K
 * Testcase Example:  '["ab", "c"]\n["a", "bc"]'
 *
 * 给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。
 * 
 * 数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
 * 输出：true
 * 解释：
 * word1 表示的字符串为 "ab" + "c" -> "abc"
 * word2 表示的字符串为 "a" + "bc" -> "abc"
 * 两个字符串相同，返回 true
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
 * 输出：true
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
 * word1[i] 和 word2[i] 由小写字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int lengthA=word1.size();
        int lengthB=word2.size();
        for(int i=1;i<lengthA;i++){
            word1[0]+=word1[i];
        }
         for(int i=1;i<lengthB;i++){
            word2[0]+=word2[i];
        }
        if(word1[0]==word2[0]) return true;
        else return false;

    }
};
// @lc code=end

