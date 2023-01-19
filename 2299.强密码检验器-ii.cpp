/*
 * @lc app=leetcode.cn id=2299 lang=cpp
 *
 * [2299] 强密码检验器 II
 *
 * https://leetcode.cn/problems/strong-password-checker-ii/description/
 *
 * algorithms
 * Easy (61.41%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    16.6K
 * Total Submissions: 25.2K
 * Testcase Example:  '"IloveLe3tcode!"'
 *
 * 如果一个密码满足以下所有条件，我们称它是一个 强 密码：
 * 
 * 
 * 它有至少 8 个字符。
 * 至少包含 一个小写英文 字母。
 * 至少包含 一个大写英文 字母。
 * 至少包含 一个数字 。
 * 至少包含 一个特殊字符 。特殊字符为："!@#$%^&*()-+" 中的一个。
 * 它 不 包含 2 个连续相同的字符（比方说 "aab" 不符合该条件，但是 "aba" 符合该条件）。
 * 
 * 
 * 给你一个字符串 password ，如果它是一个 强 密码，返回 true，否则返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：password = "IloveLe3tcode!"
 * 输出：true
 * 解释：密码满足所有的要求，所以我们返回 true 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：password = "Me+You--IsMyDream"
 * 输出：false
 * 解释：密码不包含数字，且包含 2 个连续相同的字符。所以我们返回 false 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：password = "1aB!"
 * 输出：false
 * 解释：密码不符合长度要求。所以我们返回 false 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= password.length <= 100
 * password 包含字母，数字和 "!@#$%^&*()-+" 这些特殊字符。
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size()<8) return false;
        bool hasLower = false, hasUpper = false, hasDigit = false;
        bool hasSpecial = false, hasRepeat = false;
        string special = "!@#$%^&*()-+";
        for(int i=0;i<password.size();i++){
            if(password[i]>='a' && password[i]<='z') hasLower = true;
            else if(password[i]>='A' && password[i]<='Z') hasUpper = true;
            else if(password[i]>='0' && password[i]<='9') hasDigit = true;
            else if(special.find(password[i]) != string::npos) hasSpecial = true;
            if(i>0 && password[i]==password[i-1]) hasRepeat = true;
        }
        if(hasLower&&hasUpper&&hasDigit&&hasSpecial&&!hasRepeat) return true;
        else return false;
        
        
    }
};
// @lc code=end

