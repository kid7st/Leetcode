class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int start = 0;
        while(str[start] == ' ')
            start++;
            
        if(str[start] == '-'){
            sign = -1;
            start += 1;
        }else if(str[start] == '+'){
            sign = 1;
            start += 1;
        }
        int count = 0;
        int tenth=INT_MAX/10;
        for(int i = start; i < str.length() && str[i] >= '0' && str[i] <= '9'; i++){
            if(count <= tenth){
                count = (count*10) + (int)(str[i] - '0');
                if(count < 0){
                    if(sign == -1){
                        return INT_MIN;
                    }else{
                        return INT_MAX;
                    }   
                }
            }else{
                if(sign == -1){
                    return INT_MIN;
                }else{
                    return INT_MAX;
                }
            }
        }
        
        return count * sign;
    }
};