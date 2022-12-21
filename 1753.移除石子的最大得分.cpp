/*
 * @lc app=leetcode.cn id=1753 lang=cpp
 *
 * [1753] 移除石子的最大得分
 *
 * https://leetcode.cn/problems/maximum-score-from-removing-stones/description/
 *
 * algorithms
 * Medium (63.31%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    15.5K
 * Total Submissions: 22.7K
 * Testcase Example:  '2\n4\n6'
 *
 * 你正在玩一个单人游戏，面前放置着大小分别为 a​​​​​​、b 和 c​​​​​​ 的 三堆 石子。
 * 
 * 每回合你都要从两个 不同的非空堆 中取出一颗石子，并在得分上加 1 分。当存在 两个或更多 的空堆时，游戏停止。
 * 
 * 给你三个整数 a 、b 和 c ，返回可以得到的 最大分数 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：a = 2, b = 4, c = 6
 * 输出：6
 * 解释：石子起始状态是 (2, 4, 6) ，最优的一组操作是：
 * - 从第一和第三堆取，石子状态现在是 (1, 4, 5)
 * - 从第一和第三堆取，石子状态现在是 (0, 4, 4)
 * - 从第二和第三堆取，石子状态现在是 (0, 3, 3)
 * - 从第二和第三堆取，石子状态现在是 (0, 2, 2)
 * - 从第二和第三堆取，石子状态现在是 (0, 1, 1)
 * - 从第二和第三堆取，石子状态现在是 (0, 0, 0)
 * 总分：6 分 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = 4, b = 4, c = 6
 * 输出：7
 * 解释：石子起始状态是 (4, 4, 6) ，最优的一组操作是：
 * - 从第一和第二堆取，石子状态现在是 (3, 3, 6)
 * - 从第一和第三堆取，石子状态现在是 (2, 3, 5)
 * - 从第一和第三堆取，石子状态现在是 (1, 3, 4)
 * - 从第一和第三堆取，石子状态现在是 (0, 3, 3)
 * - 从第二和第三堆取，石子状态现在是 (0, 2, 2)
 * - 从第二和第三堆取，石子状态现在是 (0, 1, 1)
 * - 从第二和第三堆取，石子状态现在是 (0, 0, 0)
 * 总分：7 分 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：a = 1, b = 8, c = 8
 * 输出：8
 * 解释：最优的一组操作是连续从第二和第三堆取 8 回合，直到将它们取空。
 * 注意，由于第二和第三堆已经空了，游戏结束，不能继续从第一堆中取石子。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int count=0;
        while(!IsGameOver(a,b,c)){
            if(a>=b&&b>=c){
                a--;
                b--;
                count++;
            }else if(a>=c&&c>=b){
                a--;
                c--;
                count++;
            }else if(b>=a&&a>=c){
                b--;
                a--;
                count++;
            }else if(b>=c&&c>=a){
                b--;
                c--;
                count++;
            }else if(c>=a&&a>=b){
                c--;
                a--;
                count++;
            }else if(c>=b&&b>=a){
                c--;
                b--;
                count++;
            }

        }
        return count;

    }

    bool IsGameOver(int a, int b, int c)
    {
        int count = 0;
        if(a==0) count++;
        if(b==0) count++;
        if(c==0) count++;
        if(count>=2) return true;
        else return false;
    }
};
// @lc code=end

