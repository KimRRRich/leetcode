/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=s.length();
        int maxLength=0;
        int currentLength=0;
        for(int i=0;i<length;i++){
            if(s[i]!=' '){
                if(i==length-1){
                    currentLength+=1;
                    if(0<currentLength) maxLength=currentLength;
                }else currentLength+=1;
            }else{
                if(0<currentLength) maxLength=currentLength;
                currentLength=0;
            }
        }
        return maxLength;

    }
};
// @lc code=end

