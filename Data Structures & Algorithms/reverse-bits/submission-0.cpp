class Solution {
public:

    bool checkSetBitAtK(int i, uint32_t n){
        if((1<<(i-1) & n) != 0){
            return true;
        }
        return false;
    }

    uint32_t reverseBits(uint32_t n) {
        unsigned int res = 0;

        for(int i=1; i<=32; i++){
             if(checkSetBitAtK(i,n)){
                res = (1 << (32-i)) | res;
             }
        }

        return res;
    }
};
