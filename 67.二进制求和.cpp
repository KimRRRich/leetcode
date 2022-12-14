/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.47%)
 * Likes:    907
 * Dislikes: 0
 * Total Accepted:    286K
 * Total Submissions: 534.9K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:a = "11", b = "1"
 * 输出："100"
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = "1010", b = "1011"
 * 输出："10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a 和 b 仅由字符 '0' 或 '1' 组成
 * 字符串如果不是 "0" ，就不含前导零
 * 
 * 
 */

// @lc code=start

class Solution {
public:
    string addBinary(string a, string b) {
        int Alength=a.size();
        int Blength=b.size();
        //int suma=0;
        //int sumb=0;
        int sum=0;
        for(int i=0;i<Alength;i++){
           if(a[i]=='1'){
            sum+=pow(2,(Alength-i-1));
           }
        }
        for(int i=0;i<Blength;i++){
            if(b[i]=='1'){
            sum+=pow(2,(Blength-i-1));
            }
        }
        //sum=suma;
        string result;
        if(sum==0) return "0";
        while(sum>0){
            int x=sum%2;
            sum=sum/2;
            if(x==1){
                result="1"+result;
            }else{
                result="0"+result;
            }
            
        }
        return result;
    }
};
// @lc code=end

