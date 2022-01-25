namespace math{
    const int SIEVE_SZ = 10e6 + 3;
    bool prime[SIEVE_SZ];

    bool is_prime(lli n){
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; (lli) i * i <= n; i += 6){
            if (n % i == 0 || n % (i + 2) == 0){
                return false;
            }
        }
        return true;
    }
    
    void sieve(int n){
        prime[0] = prime[1] = false;
        for (int i = 2; i <= n; i++){
            prime[i] = true;
        }
        for (int i = 2; i * i <= n; i++){
            if (prime[i]){
                for (int j = i * i; j <= n; j += i){
                    prime[j] = false;
                }
            }
        }
    }

    bool generated = false;
    vector <lli> primes;
    void gen_primes(int n){
        generated = true;
        sieve(n);
        for (int i = 2; i <= n; i++){
            if (prime[i]){
                primes.push_back((lli) i);
            }
        }
    }

    vector <pair <lli, int>> factorize(lli n){ 
        vector <pair <lli, int>> v;
        if (!generated){
            cout << "Primes not generated.\n";
            return v;
        }
        int cnt;
        for (int i = 0; primes[i] * primes[i] <= n; i++){
            cnt = 0;
            while (n % primes[i] == 0){
                cnt++;
                n /= primes[i];
            }
            if (cnt){
                v.push_back({primes[i], cnt});
            }
        }
        if (n > 1){
            v.push_back({n, 1});
        }
        return v;
    }

    vector <lli> get_divs(lli n){ //unsorted
        vector <lli> v;
        for (lli i = 1; i * i <= n; i++){
            if (i * i == n){
                v.push_back(i);
            }
            else if (n % i == 0){
                v.push_back(i);
                v.push_back(n / i);
            }
        }
        return v;
    }
}
using namespace math;
