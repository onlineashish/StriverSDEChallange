#include <bits/stdc++.h> 

bool comp(vector<int> a, vector<int> b){
        return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();
    

    sort(jobs.begin(), jobs.end(), comp);

    int maxi =0;
    for(int i = 0; i<n; i++){
        maxi = max(maxi, jobs[i][0]);
    }
    vector<int> arr(maxi+1, -1);
    int profit = 0;
     for( int i = 0; i <n ; i++ ){
         for(int j = jobs[i][0]; j>0; j--){
             if(arr[j] == -1){
                 profit +=  jobs[i][1];
                 arr[j] = 1;
                 break;
             }
         }
     }
     return profit;
}
