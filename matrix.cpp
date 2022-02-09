const int SZ = 2, MOD = 1e9 + 7;

using Mat = vector<vector<lli>>;

Mat mul(Mat A, Mat B) {
	Mat res(SZ);
    for (int i = 0; i < SZ; i++){
        res[i].resize(SZ, 0);
    }
	for (int i = 0; i < SZ; i++) {
		for (int j = 0; j < SZ; j++) {
			for (int k = 0; k < SZ; k++) {
				res[i][j] += A[i][k] * B[k][j];
				res[i][j] %= MOD;
			}
		}
	}
	return res;
}

Mat power(Mat A, lli b){
    Mat I(SZ);
    for (int i = 0; i < SZ; i++){
        I[i].resize(SZ, 0);
        I[i][i] = 1;
    }
    while (b){
        if (b % 2 == 1){
            I = mul(I, A);
        }
        A = mul(A, A);
        b /= 2;
    }
    return I;
}
