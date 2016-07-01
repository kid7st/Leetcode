class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto e : tickets)
            graph[e.first].push(e.second);
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> result;
    
    void dfs(string vtex){
        auto &edges = graph[vtex];
        while(!edges.empty()){
            string to_vtex = edges.top();
            edges.pop();
            dfs(to_vtex);
        }
        result.push_back(vtex);
    }
    
};