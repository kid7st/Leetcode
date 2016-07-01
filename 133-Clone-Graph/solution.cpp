/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        
        unordered_set<int> visited;
        queue<UndirectedGraphNode *> copyQueue;
        queue<UndirectedGraphNode *> oriQueue;
        unordered_map<int, UndirectedGraphNode *> nodeMap;
        oriQueue.push(node);
        UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
        nodeMap.insert(pair<int, UndirectedGraphNode *>(res->label, res));
        copyQueue.push(res);
        while(!oriQueue.empty()){
            UndirectedGraphNode *ori = oriQueue.front();
            oriQueue.pop();
            UndirectedGraphNode *copy = copyQueue.front();
            copyQueue.pop();
            
            if(visited.find(ori->label) == visited.end()){
                visited.insert(ori->label);
            
                for(auto next : ori->neighbors){
                    oriQueue.push(next);
                    if(nodeMap.find(next->label) == nodeMap.end()){
                        copy->neighbors.push_back(new UndirectedGraphNode(next->label));
                        nodeMap.insert(pair<int, UndirectedGraphNode *>(next->label, copy->neighbors.back()));
                    }else{
                        copy->neighbors.push_back(nodeMap[next->label]);
                    }
                    copyQueue.push(copy->neighbors.back());
                }
            }
        }
        
        return res;
    }
};