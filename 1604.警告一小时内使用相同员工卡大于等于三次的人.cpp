/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 *
 * https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/
 *
 * algorithms
 * Medium (42.45%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    17.8K
 * Total Submissions: 36K
 * Testcase Example:  '["daniel","daniel","daniel","luis","luis","luis","luis"]\n' +
  '["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]'
 *
 * 
 * 力扣公司的员工都使用员工卡来开办公室的门。每当一个员工使用一次他的员工卡，安保系统会记录下员工的名字和使用时间。如果一个员工在一小时时间内使用员工卡的次数大于等于三次，这个系统会自动发布一个
 * 警告 。
 * 
 * 给你字符串数组 keyName 和 keyTime ，其中 [keyName[i], keyTime[i]] 对应一个人的名字和他在 某一天
 * 内使用员工卡的时间。
 * 
 * 使用时间的格式是 24小时制 ，形如 "HH:MM" ，比方说 "23:51" 和 "09:49" 。
 * 
 * 请你返回去重后的收到系统警告的员工名字，将它们按 字典序升序 排序后返回。
 * 
 * 请注意 "10:00" - "11:00" 视为一个小时时间范围内，而 "23:51" - "00:10"
 * 不被视为一小时内，因为系统记录的是某一天内的使用情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"],
 * keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
 * 输出：["daniel"]
 * 解释："daniel" 在一小时内使用了 3 次员工卡（"10:00"，"10:40"，"11:00"）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime =
 * ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
 * 输出：["bob"]
 * 解释："bob" 在一小时内使用了 3 次员工卡（"21:00"，"21:20"，"21:30"）。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
 * 输出：[]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"],
 * keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
 * 输出：["clare","leslie"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * keyName.length == keyTime.length
 * keyTime 格式为 "HH:MM" 。
 * 保证 [keyName[i], keyTime[i]] 形成的二元对 互不相同 。
 * 1 
 * keyName[i] 只包含小写英文字母。
 * 
 * 
 */
#include <vector>
#include <string>
#include<unordered_map>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        for(int i=0;i<keyName.size();i++){
            int hour=(keyTime[i][0]-'0')*10+keyTime[i][1]-'0';
            int minute=(keyTime[i][3]-'0')*10+keyTime[i][4]-'0';
            m[keyName[i]].push_back(hour*60+minute);
        }
        vector<string> res;
        for(auto it=m.begin();it!=m.end();it++){
            sort(it->second.begin(),it->second.end());
            for(int i=2;i<it->second.size();i++){
                if(it->second[i]-it->second[i-2]<=60&&it->second[i]-it->second[i-2]>=0){
                    res.push_back(it->first);
                    break;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

