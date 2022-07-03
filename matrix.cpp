const int SZ = 2, MOD = 1e9 + 7;

using Mat = vector <vector <lli>>;

lli madd(lli a, lli b){
	return (a + b) % MOD;
}

lli mmul(lli a, lli b){
	return (a * b) % MOD;
}

Mat mat_mmul(Mat A, Mat B){
	Mat res(SZ, vector <lli> (SZ));
	for (int i = 0; i < SZ; i++){
		for (int j = 0; j < SZ; j++){
			for (int k = 0; k < SZ; k++){
				res[i][j] = madd(res[i][j], mmul(A[i][k], B[k][j]));
			}
		}
	}
	return res;
}

Mat mat_mpow(Mat A, lli n){
	Mat res(SZ, vector <lli> (SZ));
	for (int i = 0; i < SZ; i++){
		res[i][i] = 1;
	}
	while (n){
		if (n % 2 == 1){
			res = mat_mmul(res, A);
		}
		A = mat_mmul(A, A);
		n /= 2;
	}
	return res;
}

void mat_print(Mat A){
	for (int i = 0; i < SZ; i++){
		for (int j = 0; j < SZ; j++){
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}
