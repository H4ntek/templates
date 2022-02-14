struct KMP{
    int n;
    string s;
    vector <int> pi;

    void init(string s_){
        s = s_;
        n = s.size();
        pi.resize(n);
        for (int i = 1; i < n; i++){
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]){
                j = pi[j - 1];
            }
            if (s[i] == s[j]){
                j++;
            }
            pi[i] = j;
        }
    }

    pair <int, int> occ(string p){ //{index of 1st occurence, how many times}
        pair <int, int> res = {-1, 0};
        bool found = false;
        int m = p.size();
        for (int i = m; i < n; i++){
            if (pi[i] == m){
                res.second++;
                if (!found){
                    found = true;
                    res.first = i - 2 * m;
                }
            }
        }
        return res;
    }

    string compress(){ //returns shortest such string x s.t. s consists of repetions of x
        if (n % (n - pi[n - 1]) == 0){
            return s.substr(0, n - pi[n - 1]);
        }
        return s;
    }
};
