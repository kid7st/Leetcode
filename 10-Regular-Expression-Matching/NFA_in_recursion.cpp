class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }

private:
    bool matchChar(string s, string p, int s_index, int p_index){
        if(s_index >= s.size() || p_index >= p.size())
            return false;

        return s[s_index] == p[p_index] || p[p_index] == '.';
    }

    bool match(string s, string p, int s_index, int p_index){

        //archieve the end of string and pattern, match succeed
        if(p_index == p.size()){
            return s_index == s.size();
        }

        //consider the next charactor, '*' or not
        if(p_index == p.size() - 1 || p[p_index + 1] != '*'){
            //next charactor is not '*', current charactor should match
            return matchChar(s, p, s_index, p_index) &&
                    match(s, p, s_index + 1, p_index + 1);
        }else{
            //next charactor is '*'

            //match 0 charactor
            if( match(s, p, s_index, p_index + 2) )
                return true;

            //match 1 or more
            for(; matchChar(s, p, s_index, p_index); s_index++){
                if(match(s, p, s_index + 1, p_index + 2))
                    return true;
            }

            return false;
        }
    }
};
