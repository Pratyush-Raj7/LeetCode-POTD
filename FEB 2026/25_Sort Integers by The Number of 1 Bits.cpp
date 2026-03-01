class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        auto c = [&](int &a, int &b) {
            
            int count_a = __builtin_popcount(a);
            int count_b = __builtin_popcount(b);
            
            if(count_a == count_b)
                return a<b;
            
            return count_a < count_b;
            
        };
        
        sort(begin(arr), end(arr), c);
        
        return arr;
    }
};
