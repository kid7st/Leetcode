// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int len = 0;
        int size = 0;
        for(len = 0; len < n; len += size){
            size = read4(buf + len);
            if(size < 4){
                len += size;
                break;
            }
        }
        
        if(len > n){
            for(int j = len; j > n; j--) buf[j] = 0;
        }
        
        return min(len, n);
        
    }
};