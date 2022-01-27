/*
REQUIRES adj (graph)
LCA lca;
lca.init(n) - init for a tree with n vertices
lca.find_LCA(u, v) - returns LCA of u and v
lca.get_dist(u, v) - return distance from u to v
lca.get_anc(v, k) - returns k-th ancestor of v
*/
struct LCA{
    int n, lg;
    vector <int> depth;
    vector <vector <int>> up; //up[v][i] - (2^i)-th ancestor of v

    void precomp_DFS(int v, int par, int dep){
        for (int child : adj[v]){
            if (child != par){
                depth[child] = dep + 1;
                up[child][0] = v;
                for (int i = 1; i < lg; i++){
                    up[child][i] = up[up[child][i - 1]][i - 1];
                }
                precomp_DFS(child, v, dep + 1);
            }
        }
    }

    void init(int n_){
        n = n_;
        lg = 0;
        while ((1 << lg) < n){
            lg++;
        }
        up.assign(n + 1, vector <int>(lg, 0));
        depth.assign(n + 1, 0);
        precomp_DFS(1, -1, 0);
    }

    int find_LCA(int u, int v){
        if (depth[u] < depth[v]){ //u is deeper
            swap(u, v);
        }
        int diff = depth[u] - depth[v];

        for (int i = lg - 1; i >= 0; i--){
            if (diff & (1 << i)){
                u = up[u][i];
            }
        }

        if (u == v){
            return u;
        }

        for (int i = lg - 1; i >= 0; i--){
            if (up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int get_dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[find_LCA(u, v)];
    }

    int get_anc(int v, int k){
        if (depth[v] < k){
            return -1;
        }
        int u = v;
        for (int i = lg - 1; i >= 0; i--){
            if (k & (1 << i)){
                u = up[u][i];
            }
        }
        return u;
    }
};
