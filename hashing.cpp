struct Hash{
    const int MOD1 = 1564540969, MOD2 = 1330201709, P1 = 73, P2 = 79; //77,777,777th and 66,666,666th prime
    string s;
    int n;

    vector <lli> pot1, pot2;
    vector <lli> hsh1, hsh2;

    void init(string s_){
        s = s_;
        n = s.size();
        hsh1.resize(n + 1);
        hsh2.resize(n + 1);
        pot1.push_back(1);
        pot2.push_back(1);
        for (int i = 1; i < n; i++){
            pot1.push_back((pot1.back() * P1) % MOD1);
            pot2.push_back((pot2.back() * P2) % MOD2);
        }
        for (int i = 0; i < n; i++){
            hsh1[i + 1] = (hsh1[i] + (s[i] - 'a' + 1) * pot1[i]) % MOD1;
            hsh2[i + 1] = (hsh2[i] + (s[i] - 'a' + 1) * pot2[i]) % MOD2;
        }
    }

    pair <lli, lli> get_hash(const string &t){
        int m = t.size();
        lli hsh_t1 = 0, hsh_t2 = 0;
        for (int i = 0; i < m; i++){
            hsh_t1 += ((t[i] - 'a' + 1) * pot1[i]) % MOD1;
            hsh_t2 += ((t[i] - 'a' + 1) * pot2[i]) % MOD2;
        }
        return {hsh_t1, hsh_t2};
    }

    bool compare(lli h1, lli h2, int i, int m){
        return ((hsh1[i + m] - hsh1[i] + MOD1) % MOD1 == (h1 * pot1[i]) % MOD1) && ((hsh2[i + m] - hsh2[i] + MOD2) % MOD2 == (h2 * pot2[i]) % MOD2);
    }

    vector <int> get_occs(string &t){
        vector <int> occs;
        int m = t.size();
        pair <lli, lli> temp = get_hash(t);
        lli hsh_t1 = temp.first, hsh_t2 = temp.second;
        for (int i = 0; i < n - m + 1; i++){
            if (compare(hsh_t1, hsh_t2, i, m)){
                occs.push_back(i);
            }
        }
        return occs;
    }

    int count_unique(){ //returns count of unique substrings of s
        int cnt = 0;
        for (int l = 1; l <= n; l++) {
            set <lli> hs;
            for (int i = 0; i <= n - l; i++) {
                lli cur_h = (hsh1[i + l] + MOD1 - hsh1[i]) % MOD1;
                cur_h = (cur_h * pot1[n - i - 1]) % MOD1;
                hs.insert(cur_h);
            }
            cnt += hs.size();
        }
        return cnt;
    }
};
