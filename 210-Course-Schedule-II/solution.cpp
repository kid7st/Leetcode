class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>{});
        vector<int> indegree(numCourses, 0);
        for(auto edge : prerequisites){
            edges[edge.second].push_back(edge.first);
            ++indegree[edge.first];
        }
        int count = 0;
        vector<int> res;
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            ++count;
            res.push_back(v);
            for(int next : edges[v])
                if((--indegree[next]) == 0) q.push(next);
        }
        
        if(count == numCourses)
            return res;
        else
            return vector<int>{};
    }
};