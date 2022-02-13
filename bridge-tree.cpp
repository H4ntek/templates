/*
Bridge tree - condenses graph into a tree, where vertices are 2-edge-connected components and edges <==> bridges from the original graph.
REQUIRES adj (graph) with pairs {u, edge_id}, list of edges, is_bridge, in, low, comp, comp_no, timer
MEMSET in and comp to -1, remember to initialize edges array while reading input.
*/
void DFS_bridges(int v, int par){
    in[v] = low[v] = timer++;
    int u, id;
    for (auto child : adj[v]){
        u = child.ff;
        id = child.ss;
        if (u == par){
            continue;
        }
        else if (in[u] != -1){
            low[v] = min(low[v], in[u]);
        }
        else{
            DFS_bridges(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > in[v]){
                is_bridge[id] = true;
            }
        }
    }
}

void DFS_comp(int v){
    comp[v] = comp_no;
    int u, id;
    for (auto child : adj[v]){
        u = child.ff;
        id = child.ss;
        if (is_bridge[id]){
            continue;
        }
        if (comp[u] == -1){
            DFS_comp(u);
        }
    }
}

void build_brige_tree(int &m){
    for (int i = 1; i <= m; i++){
        if (is_bridge[i]){
            adj_bridge_tree[comp[edges[i].ff]].push_back(comp[edges[i].ss]);
            adj_bridge_tree[comp[edges[i].ss]].push_back(comp[edges[i].ff]);
        }
    }
}
