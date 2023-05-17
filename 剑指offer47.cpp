#include<vector>
#include<math.h>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
    
public:
    
    multimap<pair<int,int>,int> map;
    int maxValue(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        return DFS(n-1,m-1,grid);
    }

    int DFS(int i,int j,vector<vector<int>>& grid){
        if(i<0||j<0) return 0;
        if(map.find(make_pair(i,j))->second!=0){
            return map.find(make_pair(i,j))->second;
        }
        else if(map.find(make_pair(i,j))->second==0){

            map.insert(make_pair(make_pair(i,j),max(DFS(i-1,j,grid),DFS(i,j-1,grid))+grid[i][j]));
            return map.find(make_pair(i,j))->second;
        }
        
    }
};