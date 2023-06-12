#include <bits/stdc++.h> 
bool comp (pair<int, int> a, pair<int, int> b){
        double s1 = (double)a.second/(double)a.first;
        double s2 = (double)b.second/(double)b.first;

        return (s1 > s2);
    }
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    
    // sort(items,items+n,comp);
    sort(items.begin(),items.end(),comp);
    double profit = 0.0;
    int curr_weight = 0;
    for(int i=0 ; i<n; i++){
        if(curr_weight+items[i].first <= w){
            profit += items[i].second;
            curr_weight += items[i].first;
        }
        else{
            int rem_weight  = w - curr_weight;
            profit += (items[i].second/(double)items[i].first) * (double)rem_weight;
            break;
        }
    }
    return profit;


    
}
