class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 0xFFFF0000;
        n = ((n&mask) >> 16) | ((n&(~mask)) << 16);
        mask = 0xFF00FF00;
        n = ((n&mask) >> 8) | ((n&(~mask)) << 8);
        mask = 0xF0F0F0F0;
        n = ((n&mask) >> 4) | ((n&(~mask)) << 4);
        mask = 0xCCCCCCCC;
        n = ((n&mask) >> 2) | ((n&(~mask)) << 2);
        mask = 0xAAAAAAAA;
        n = ((n&mask) >> 1) | ((n&(~mask)) << 1);
        
        return n;
    }
};