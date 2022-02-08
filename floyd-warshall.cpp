/*
Requires adjacency matrix and a defined INF (long long)
*/
struct Floyd{
    int n;
    vector<vector<lli>> dist;
    
    void init(int n_){
        n = n_;
        dist.resize(n + 1);
        for (int i = 0; i <= n; i++){
            dist[i].assign(n + 1, INF);
        }
    }
    
    bool run(){ //false if -ve cycle found
        for (int i = 1; i <= n; i++){
            dist[i][i] = 0;
            for (int j = 1; j <= n; j++){
                if (adj[i][j]) dist[i][j] = adj[i][j];
            }
        }
        for (int k = 1; k <= n; k++){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    if (dist[i][k] < INF && dist[k][j] < INF){
                        dist[i][j] = max(-INF, min(dist[i][j], dist[i][k] + dist[k][j]));
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++){
            if (dist[i][i] < 0) return false;
        }
        return true;
    }
    
    lli get_path_len(int u, int v){
        return dist[u][v];
    }
};
