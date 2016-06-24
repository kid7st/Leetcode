class Solution {
public:
    bool isValid(string s) {
        stack<char> chStack;
        for(char ch : s){
            if(chStack.empty()){
                chStack.push(ch);
            }else if( (chStack.top() == '(' && ch == ')') || chStack.top() == '[' && ch == ']' ||
                (chStack.top() == '{' && ch == '}') ){
                
                chStack.pop();
            }else{
                chStack.push(ch);
            }
        }
        
        return chStack.empty();
    }
};