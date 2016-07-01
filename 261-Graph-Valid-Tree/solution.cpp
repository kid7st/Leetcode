class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        for(int i = 0; i < n; i++)
            setRoot.push_back(i);
        for(auto edge : edges){
            int root1 = unionFind(edge.first);
            int root2 = unionFind(edge.second);
            if(root1 == root2){
                return false;
            }else{
                unionMerge(root1, root2);          
            }
        }
        for(int i = 1; i < n; i++)
            if(unionFind(i - 1) != unionFind(i)) return false;
        
        return true;
    }
    
private:
    vector<int> setRoot;
    int unionFind(int node){
        int root = node;
        while(setRoot[root] != root)
            root = setRoot[root];
        while(node != root){
            int up = setRoot[node];
            setRoot[node] = root;
            node = up;
        }
        return root;
    }
    int unionMerge(int root1, int root2){
        setRoot[root1] = root2;
        return setRoot[root1];
    }
};