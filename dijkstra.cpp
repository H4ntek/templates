/*
Requires adj (pairs {child, wgt})
*/
struct Dijkstra{
    const lli INF = 1e18 + 3;
    int n, src;
    vector <lli> dist;
    vector <int> pre;

    void init(int n_){
        n = n_;
        dist.assign(n + 1, INF);
        pre.assign(n + 1, -1);
    }

    void run(int src_){
        src = src_;
        priority_queue <pair <lli, int>> pq;
        pq.push({0, src});
        dist[src] = 0;
        int v;
        lli d;
        while (!pq.empty()){
            pair <lli, int> cur = pq.top();
            pq.pop();
            v = cur.ss;
            d = -cur.ff;

            if (d != dist[v]){
                continue;
            }

            for (pair <int, lli> child : adj[v]){
                if (dist[v] + child.ss < dist[child.ff]){
                    dist[child.ff] = dist[v] + child.ss;
                    pq.push({-dist[child.ff], child.ff});
                    pre[child.ff] = v;
                }
            }
        }
    }

    vector <int> recover_path(int v){
        vector <int> path;
        while (v != -1){
            path.push_back(v);
            v = pre[v];
        }
        reverse(path.begin(), path.end());
        return path;
    }

    lli get_path_len(int v){
        return dist[v];
    }
};
