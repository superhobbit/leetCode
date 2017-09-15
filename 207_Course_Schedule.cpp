There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> in(numCourses);
        vector<vector<int>> out(numCourses);
        stack<int> s;
        for (auto in_nodes:prerequisites){
            in[in_nodes.first].push_back(in_nodes.second);
            out[in_nodes.second].push_back(in_nodes.first);
        }
        for (int i =0; i <numCourses;i++){
            if (in[i].empty()){
                s.push(i);
            }
        }
        while (!s.empty()){
            int temp = s.top();
            s.pop();
            for (auto out_nodes:out[temp]){
                for (auto in_nodes = in[out_nodes].begin();in_nodes != in[out_nodes].end(); in_nodes++) {
                    if (*in_nodes == temp) {
                        in[out_nodes].erase(in_nodes);
                        if (in[out_nodes].empty()){
                            s.push(out_nodes);
                        }
                        break;
                    }
                }
            }
        }
        for (int i = 0;i < numCourses; i++){
            if (in[i].empty()){
                continue;
            }
            return false;
        }
        return true;
    }
};
