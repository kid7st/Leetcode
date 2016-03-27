/* Union-Find Set
 * Time complexity: O(n)
 * union-find set union operation average costs O(1)
 */
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        setids.resize(n, 0);
        weights.resize(n, 1);
        num_sets = n;
        
        for(int i = 0; i < n; i++){
            setids[i] = i;
        }
        
        for(auto it = edges.begin(); it != edges.end(); it++){
            unionSets(it->first, it->second);
        }
        
        return num_sets;
    }
    
private:
    vector<int> setids;
    vector<int> weights;
    int num_sets;
    
    int find(int idx){
        if(idx == setids[idx])
            return idx;
            
        setids[idx] = find(setids[idx]);
        return setids[idx];
    }
    
    void unionSets(int idx1, int idx2){
        int set1 = find(idx1);
        int set2 = find(idx2);
        
        if(set1 != set2){
            if(weights[set1] > weights[set2]){
                setids[set2] = set1;
                weights[set2] += weights[set1];
            }else{
                setids[set1] = set2;
                weights[set1] += weights[set2];
            }
            num_sets--;
        }
    }
};