const int SZ = 7, MOD = 1e9 + 7;

/*
Mat m;
m2 = m.pow(m, k) - m2 becomes m^k
m.m[i][j] - element in i-th row, j-th column
*/
struct Mat{
    vector<vector<lli>> m = vector<vector<lli>>(SZ, vector <lli>(SZ));
    Mat operator *(Mat& m2){
        Mat prod;
        for (int i = 0; i < SZ; i++){
            for (int j = 0; j < SZ; j++){
                for (int k = 0; k < SZ; k++){
                    prod.m[i][k] = (prod.m[i][k] + m[i][j] * m2.m[j][k]) % MOD;
                }
            }
        }
        return prod;
    }
    Mat pow(Mat a, lli b){
        Mat prod;
        for (int i = 0; i < SZ; i++){
            prod.m[i][i] = 1;
        }
        while (b){
            if (b % 2 == 1){
                prod = prod * a;
            }
            a = a * a;
            b /= 2;
        }
        return prod;
    }
};
