class Solution {
public:
    void f(int indx, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans){
        if(indx > candidates.size()-1){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[indx] <= target){
            ds.push_back(candidates[indx]);
            f(indx,target-candidates[indx],candidates, ds, ans);
            ds.pop_back();
        }
        
        f(indx+1,target,candidates, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,target,candidates, ds, ans);
        return ans;
    }
};
