static bool compar(pair<int,int> a,  pair<int,int> b){
        return (a.second < b.second);
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        if(n == 0) return 0;
        if(n ==1) return 1;
        vector <pair<int,int>> vect;
        for(int i = 0 ; i<n; i++){
            vect.push_back(make_pair(start[i],end[i]));
        }
        
        sort(vect.begin(), vect.end(), compar);
         
        int count = 1;
        int curr = 0;
        
        for(int i =1; i<n;i++){
            if(vect[i].first > vect[curr].second){
                count++;
                curr = i;
            }
        }
        
        return count;
        
    }
