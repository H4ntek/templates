/*
DSU ds;
ds.init(n) - init a DSU with size n
ds.find(x) - parent of x
ds.merge(a, b) - merge a and b (smaller to larger)
*/
struct DSU{
    vector <int> par, sz;

    void init(int n){
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++){
            sz[i] = 1;
            par[i] = i;
        }
    }
 
    int find(int x){
        if (par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
 
    void merge(int a, int b){
        a = par[a];
        b = par[b];
        if (a == b){
            return;
        }
        if (sz[b] > sz[a]){
            swap(a, b);
        }
        sz[a] += sz[b];
        par[b] = a;
    }
};
