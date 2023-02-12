/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 *
 * https://leetcode.cn/problems/alphabet-board-path/description/
 *
 * algorithms
 * Medium (44.46%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    19.8K
 * Total Submissions: 39.3K
 * Testcase Example:  '"leet"'
 *
 * 我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。
 * 
 * 在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]，如下所示。
 * 
 * 
 * 
 * 我们可以按下面的指令规则行动：
 * 
 * 
 * 如果方格存在，'U' 意味着将我们的位置上移一行；
 * 如果方格存在，'D' 意味着将我们的位置下移一行；
 * 如果方格存在，'L' 意味着将我们的位置左移一列；
 * 如果方格存在，'R' 意味着将我们的位置右移一列；
 * '!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
 * 
 * 
 * （注意，字母板上只存在有字母的位置。）
 * 
 * 返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：target = "leet"
 * 输出："DDR!UURRR!!DDD!"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：target = "code"
 * 输出："RR!DDRR!UUL!R!"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= target.length <= 100
 * target 仅含有小写英文字母。
 * 
 * 
 */
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        int currentX=0;
        int currentY=0;
        int targetX;
        int targerY;
        char lastTarget='a';
        for(int i=0;i<target.size();i++){
            int targetX=(target[i]-'a')/5;
            int targerY=(target[i]-'a')%5;
            if(lastTarget=='z'&&target[i]!='z'){
                currentX-=1;
                ans+="U";
            }
            while(currentY<targerY){
                currentY++;
                ans=ans+"R";
            }
            while(currentY>targerY){
                currentY--;
                ans=ans+"L";
            }
            while(currentX<targetX){
                currentX++;
                ans=ans+"D";
            }
            while(currentX>targetX){
                currentX--;
                ans=ans+"U";
            }
            lastTarget=target[i];
            ans+="!";
        }
        return ans;
    }
};
// @lc code=end

