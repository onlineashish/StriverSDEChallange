class Solution {
public:
    void f(int indx, string s, vector<string> &ds, vector<vector<string>> &ans){
        if(indx == s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = indx; i < s.size(); i++){
            if(isPalindrom(s,indx,i)){
                ds.push_back(s.substr(indx, i - indx + 1));
                f(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrom(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        f(0,s,ds,ans);
        return ans;
    }
};
