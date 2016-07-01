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
        
        queue<UndirectedGraphNode *> oriQueue;
        unordered_map<int, UndirectedGraphNode *> nodeMap;
        oriQueue.push(node);
        UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
        nodeMap[res->label] = res;
        while(!oriQueue.empty()){
            UndirectedGraphNode *ori = oriQueue.front();
            oriQueue.pop();
            UndirectedGraphNode *copy = nodeMap[ori->label];
            for(auto next : ori->neighbors){
                if(nodeMap.find(next->label) == nodeMap.end()){
                    nodeMap[next->label] = new UndirectedGraphNode(next->label);
                    oriQueue.push(next);
                }
                copy->neighbors.push_back(nodeMap[next->label]);
            }
        }
        return res;
    }
};