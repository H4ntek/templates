/*
CHANGE op AND neutral BEFORE USING
OPTIONAL beggining array a (if there is one uncomment "build" function in init)
Seg_tree st;
st.init(n) - initializes a segment tree for array of size n
st.query(1, 0, n - 1, l, r) - returns query on [l, r]
st.update(1, 0, n - 1, l, r, v) - updates (adds or sets) v on [l, r]
*/
struct Seg_tree{
    const int INF_INT = 1e9 + 3;
    const lli INF_LL = 1e18 + 3;
    int base;
    vector <lli> st, lazy;

    lli op(lli a, lli b){ //max, min, sum, xor, gcd...
        return max(a, b);
    }

    lli neutral(){ //0 for sum, xor, gcd, -INF for max, INF for min
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
        lazy.assign(2 * base, 0);
        //build(1, 0, n - 1);
    }

    void propagate(int si, int ss, int se, lli val){ //for other queries / += for add updates, = for set updates
        st[si] = val;
        if (ss != se){
            lazy[2 * si] = val;
            lazy[2 * si + 1] = val;
        }
    }

    void propagate_sum(int si, int ss, int se, lli val){ //for sum queries / += for add updates, = for set updates
        st[si] = val * (se - ss + 1);
        if (ss != se){
            lazy[2 * si] = val;
            lazy[2 * si + 1] = val;
        }
    }

    lli query(int si, int ss, int se, int qs, int qe){ 
        if (lazy[si] != 0){
            propagate(si, ss, se, lazy[si]);
            lazy[si] = 0;
        }

        if (ss > qe || se < qs){
            return neutral();
        }
        if (ss >= qs && se <= qe){
            return st[si];
        }

        int mid = (ss + se) / 2;
        return op(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
    }

    void update(int si, int ss, int se, int us, int ue, lli val){ 
        if (lazy[si] != 0){
            propagate(si, ss, se, lazy[si]);
            lazy[si] = 0;
        }

        if (ss > ue || se < us){
            return;
        }
        if (ss >= us && se <= ue){
            propagate(si, ss, se, val);
            return;
        }

        int mid = (ss + se) / 2;
        update(2 * si, ss, mid, us, ue, val);
        update(2 * si + 1, mid + 1, se, us, ue, val);
        st[si] = op(st[2 * si], st[2 * si + 1]);
    }
};
