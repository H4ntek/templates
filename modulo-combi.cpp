const int MOD = 1e9 + 7, FACT_SZ = 2e6 + 3;

namespace modop{
    lli fact[FACT_SZ], inv_fact[FACT_SZ];

    lli madd(lli a, lli b){
        return (a + b) % MOD;
    }

    lli msub(lli a, lli b){
        return ((a - b) % MOD + MOD) % MOD;
    } 

    lli mmul(lli a, lli b){
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    lli mpow(lli a, lli b){
        lli res = 1;
        a %= MOD;
        while (b){
            if (b % 2 == 1){
                res = mmul(res, a);
            }
            b /= 2;
            a = mmul(a, a);
        }
        return res;
    }
    
    lli minv(lli a){
        return mpow(a, MOD - 2); //works only when modulo is prime
    }

    lli mdiv(lli a, lli b){
        return mmul(a, minv(b));
    }

    bool generated = false;
    void gen_fact(int n){
        generated = true;
        fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
        for (int i = 2; i <= n; i++){
            fact[i] = mmul(fact[i - 1], (lli) i);
        }
        inv_fact[n] = minv(fact[n]);
        for (int i = n - 1; i >= 2; i--){
            inv_fact[i] = mmul(inv_fact[i + 1], (lli) (i + 1));
        }
    }

    lli nck(lli n, lli k){
        if (!generated || n < 0 || k > n){
            cout << "Error, invalid argument or factorials not generated.\n";
            return 0;
        }
        lli denom = mmul(inv_fact[k], inv_fact[n - k]);
        return mmul(fact[n], denom);
    }
}
using namespace modop;
