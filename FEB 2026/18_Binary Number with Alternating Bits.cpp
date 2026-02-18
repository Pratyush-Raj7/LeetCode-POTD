class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        unsigned int result = n ^ (n >> 1);

        return (result & (result + 1)) == 0;
    }
};
