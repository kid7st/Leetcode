class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(records.find(message) == records.end()){
            records[message] = timestamp;
            return true;
        }else if(timestamp - records[message] >= 10){
            records[message] = timestamp;
            return true;
        }else{
            return false;
        }
        
        return true;
    }
    
private:
    unordered_map<string, int> records;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */