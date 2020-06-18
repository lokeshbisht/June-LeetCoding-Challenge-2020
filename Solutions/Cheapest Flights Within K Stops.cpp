class Solution {
public:
    
    void help(vector<pair<int, int>> *g, int src, int dst, int k, int &min,int cost,int *rem) {
        
        if( k < 0)
            return;
        
        if(cost > min)
            return;
        
        if(src == dst) {
            if(min > cost && k >= 0)
                min = cost;
            return;
        }
        
        rem[src]=1;
        for(int i=0; i < g[src].size(); i++) {
            
            if(rem[g[src][i].first]==0)
            help(g,g[src][i].first,dst,k-1,min,cost+g[src][i].second,rem);
            
            
        }
        
        rem[src]=0;
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<pair<int, int>> *g = new vector<pair<int,int>>[n];
        int min=INT_MAX;
        int cost = 0;
        int *rem;
        
        rem = (int *)calloc(sizeof(int),n);
        
        for(int i=0; i<flights.size(); i++) {
            
            g[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }

        for(int i=0; i<n; i++) {
          
            rem[i]=0;
        }
        
        help(g,src,dst,K+1,min,cost,rem);
        
        if(min == INT_MAX)
            return -1;
        else
            return min;
    }
};
