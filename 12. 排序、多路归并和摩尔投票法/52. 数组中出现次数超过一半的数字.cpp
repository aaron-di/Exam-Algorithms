#include <vector>

using namespace std;

class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int cnt = 0, val;
        for (auto x: nums) {
            if (!cnt) val = x, cnt++;
            else if (x == val) cnt++;
            else cnt--;
        }
        
        cnt = 0;
        for (auto x: nums) {
            if (x == val) {
                cnt++;
            }
        }
        if (cnt <= nums.size() / 2) return -1;
        
        return val;
    }
};