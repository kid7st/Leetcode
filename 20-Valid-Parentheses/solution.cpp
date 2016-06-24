class Solution {
public:
    bool isValid(string s) {
        stack<char> chStack;
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                chStack.push(ch);
            }else if(chStack.empty()){
                return false;
            }else if( (chStack.top() == '(' && ch == ')') 
                    ||(chStack.top() == '[' && ch == ']')
                    ||(chStack.top() == '{' && ch == '}') 
            ){
                chStack.pop();
            }else{
                return false;
            }
        }
        return chStack.empty();
    }
};