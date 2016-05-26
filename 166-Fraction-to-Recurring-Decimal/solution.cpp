class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return "";
        if(numerator == 0) return "0";
        
        string decimal = "";
        decimal += string((denominator < 0) ^ (numerator < 0), '-');
        long intPart = abs((long)numerator / (long)denominator);
        decimal += to_string(intPart);
        long rem = abs((long)numerator % (long)denominator);
        if(rem == 0)
            return decimal;
        
        decimal += ".";
        unordered_map<long, int> appears;
        while(rem != 0){
            appears[rem] = decimal.size();
            rem *= 10;
            long intPart = rem / abs((long)denominator);
            decimal += to_string(intPart);
            rem = rem % abs((long)denominator);
            if(appears.find(rem) != appears.end()){
                decimal.insert(appears[rem], "(");
                decimal += ")";
                break;
            }
        }
        
        return decimal;
    }
};