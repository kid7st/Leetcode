class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector< vector<int> > edges(numCourses, vector<int>{});
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        
        for(auto edge : prerequisites){
            edges[edge.first].push_back(edge.second);
            indegree[edge.second]++;
        }
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) q.push(i);
        int count = 0;
        while(!q.empty()){
            int vertix = q.front();
            q.pop();
            ++count;
            for(int next : edges[vertix]){
                if((--indegree[next]) == 0)
                    q.push(next);
            }
        }
        return count == numCourses;
    }
};