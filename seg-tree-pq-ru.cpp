/*
CHANGE op AND neutral BEFORE USING
OPTIONAL beggining array a (if there is one uncomment "build" function)
Seg_tree st;
st.init(n) - initializes a segment tree for array of size n
st.query(i) - returns query on i
st.update(l, r, v) - updates (adds or sets) v in range [l, r]
st.print() - print for debugging
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

    int query(int qi){ 
        int si = base + qi, ans = 0;
        ans += st[si];
        while (si > 1){
            si /= 2;
            ans += st[si];
        }
        return ans;
    }

    void update(int us, int ue, int val){ 
        int si_l = base + us, si_r = base + ue;
        st[si_l] += val;
        if (si_l != si_r){
            st[si_r] += val;
        }
        while (si_l / 2 != si_r / 2){
            if (si_l % 2 == 0){
                st[si_l + 1] = op(st[si_l + 1], val);
            }
            si_l /= 2;
            if (si_r % 2 == 1){
                st[si_r - 1] = op(st[si_r - 1], val);
            }
            si_r /= 2;
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
