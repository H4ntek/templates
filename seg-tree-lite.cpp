/*
CHANGE op AND neutral BEFORE USING
OPTIONAL beggining array a (if there is one uncomment "build" function in init)
Seg_tree st;
st.init(n) - initializes a segment tree for array of size n
st.query(1, 1, n, l, r) - returns query on [l, r]
st.update(1, 1, n, i, v) - updates (adds or sets) a[i] to v
*/
struct Seg_tree{
    const int INF_INT = 1e9 + 3;
    const lli INF_LL = 1e18 + 3;
    int base;
    vector <int> st;

    int op(int a, int b){ //max, min, sum, xor, gcd...
        return a + b;
    }

    int neutral(){ //0 for sum, xor, gcd, -INF for max, INF for min
        return 0;
    }

    void build(int si, int ss, int se){
        if (ss == se){
            //st[si] = a[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        st[si] = op(st[2 * si], st[2 * si + 1]);
    }

    void init(int n){
        base = 1;
        while (base < n){
            base *= 2;
        }
        st.assign(2 * base, neutral());
        //build(1, 0, n - 1);
    }

    int query(int si, int ss, int se, int qs, int qe){ 
        if (ss > qe || se < qs){
            return neutral();
        }
        if (ss >= qs && se <= qe){
            return st[si];
        }

        int mid = (ss + se) / 2;
        return op(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
    }

    void update(int si, int ss, int se, int ui, int val){ 
        if (ss == se){
            st[si] = val;
            return;
        }
        int mid = (ss + se) / 2;
        if (ui <= mid){
            update(2 * si, ss, mid, ui, val);
        }
        else{
            update(2 * si + 1, mid + 1, se, ui, val);
        }
        st[si] = op(st[2 * si], st[2 * si + 1]);
    }
};
