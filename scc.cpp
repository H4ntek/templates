/*
REQUIRES adj (graph) and adj_t (transposed graph), comp, comp_sz, comp_no
SCC scc;
scc.init(n) - init for a graph with n vertices
scc.run() - returns vector of vectors (SCCs)
*/
struct SCC{
    int n, comp_no = 0;
    vector <int> preorder, component;
    vector <bool> vis;

    void init(int n_){
        n = n_;
        preorder.clear();
        component.clear();
    }

    void DFS1(int v){
        vis[v] = true;
        for (int child : adj[v]){
            if (!vis[child]){
                DFS1(child);
            }
        }
        preorder.push_back(v);
    }

    void DFS2(int v){
        vis[v] = true;
        comp[v] = comp_no;
        comp_sz[comp_no]++;
        component.push_back(v);
        for (int child : adj_t[v]){
            if (!vis[child]){
                DFS2(child);
            }
            else{
                if (adj_cc[comp[child]].empty() || adj_cc[comp[child]].back() != comp_no){
                    if (comp[child] != comp_no){
                        adj_cc[comp[child]].push_back(comp_no);
                    }
                }
            }
        }
    }

    vector <vector <int>> run(){
        vector <vector <int>> components;
        vis.assign(n + 1, false);
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                DFS1(i);
            }
        }
        vis.assign(n + 1, false);
        for (int i = n - 1; i >= 0; i--){
            if (!vis[preorder[i]]){
                comp_no++;
                DFS2(preorder[i]);
                components.push_back(component);
                component.clear();
            }
        }
        return components;
    }
};
