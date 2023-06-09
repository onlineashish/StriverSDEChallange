class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i<n-2; i++){
            while( i>0 && nums[i] == nums[i-1]){
                
                i++;
                if(i == n-2) break;
            }
            
            int j = i+1;
            
            int k = n-1;
           
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if( sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;

                    while( j<k && nums[k] == nums[k+1]){
                        k--;
                    }
                    while( j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }

        }
        return ans;
    }
};
