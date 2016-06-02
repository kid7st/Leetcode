class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        for(int i = 1; i < n; i++){
            seq = nextSeq(seq);
        }
        return seq;
    }
    
private:
    string nextSeq(string seq){
        string next = "";
        int prev = 0;
        int i = 0;
        while(i < seq.length()){
            while(i < seq.length() && seq[i] == seq[prev]){
                i++;
            }   
            next += to_string(i - prev) + seq[prev];
            prev = i;
        }
        
        return next;
    }    
};