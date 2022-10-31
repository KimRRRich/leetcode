/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        digits[length - 1] += 1;
        for(int i=0;i<length;i++){
            if(digits[length-i-1]>=10){
                digits[length-i-1]-=10;
                if(length-i-2>=0){
                    digits[length-i-2]+=1;
                }else{
                    digits.insert(digits.begin(),1);
                }
            }
        }
        return digits;
    }
};
// @lc code=end

