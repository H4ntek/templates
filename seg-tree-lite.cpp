/*
CHANGE op AND neutral BEFORE USING
OPTIONAL beggining array a (if there is one uncomment "build" function)
Seg_tree st;
st.init(n) - initializes a segment tree for array of size n
st.query(l, r) - returns query on [l, r]
st.update(i, v) - updates (adds or sets) v at index i
st.print() - print for debugging
*/
struct Seg_tree{
    const int INF_INT = 1e9 + 3;
    const lli INF_LL = 1e18 + 3;
    int base;
    vector <int> st;

    int op(int a, int b){ //max, min, sum, xor, gcd...
        return __gcd(a, b);
    }

    int neutral(){ //0 for sum, xor, gcd, -INF for max, INF for min
        return 0;
    }

    void build(int n){
        for (int i = 0; i < n; i++){
            //st[base + i] = a[i];
        }
        for (int si = base - 1; si >= 1; si--){
            st[si] = op(st[2 * si], st[2 * si + 1]);
        }
    }

    void init(int n){
        base = 1;
        while (base < n){
            base *= 2;
        }
        st.assign(2 * base, neutral());
        //build(n);
    }

    int query(int qs, int qe){
        int si_l = base + qs, si_r = base + qe, res = st[si_l];
        if (si_l != si_r){
            res = op(res, st[si_r]);
        }
        while (si_l / 2 != si_r / 2){
            if (si_l % 2 == 0){
                res = op(res, st[si_l + 1]);
            }
            si_l /= 2;
            if (si_r % 2 == 1){
                res = op(res, st[si_r - 1]);
            }
            si_r /= 2;
        }
        return res;
    }

    void update(int ui, int val){
        int si = base + ui;
        st[si] = val;
        while (si > 1){
            si /= 2;
            st[si] = op(st[2 * si], st[2 * si + 1]);
        }
    }

    void print(){
        int p = 1;
        while (p <= base){
            for (int i = 0; i < p; i++){
                cout << st[i + p] << " ";
            }
            cout << "\n";
            p *= 2;
        }
    }
};
