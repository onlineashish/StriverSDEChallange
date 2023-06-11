class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone = 0;
        int cnt= 0;
        for(auto num : nums){
            if(num == 1) cnt++;
            else cnt = 0;
            maxone = max(maxone, cnt);

        }
        return maxone;
    }
};
