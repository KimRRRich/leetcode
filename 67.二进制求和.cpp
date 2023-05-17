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
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int lengthA=a.size();
        int lengthB=b.size();
        if(a.size()>b.size()){
            string temp=a;
            a=b;
            b=temp;
        }
        int update=0;
        for(int i=0;i<lengthA;i++){
            int va=a[lengthA-i-1]-'0';
            int vb=b[lengthA-i-1]-'0';
            if(va+vb+update==0){
                ans="0"+ans;
                update=0;
            }else if(va+vb+update==1){
                ans="1"+ans;
                update=0;
            }
            else if(va+vb+update==2){
                ans="0"+ans;
                update=1;
            }
            else if(va+vb+update==3){
                ans="1"+ans;
                update=1;
            }
            
        }
        cout<<update<<endl;
        for(int i=lengthA;i<lengthB;i++){
            int vb=b[lengthB-i-1]-'0';
            if(vb+update==0){
                ans="0"+ans;
                update=0;
            }
            else if(vb+update==1){
                ans="1"+ans;
                update=1;
            }
            else if(vb+update==2){
                ans="0"+ans;
                update=1;
            }
        }
        if(update==1) ans="1"+ans;
        return ans;
    }
};
// @lc code=end

