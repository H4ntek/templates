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

vector <lli> v_mat_mmul(vector <lli> v, Mat A){
	vector <lli> res(SZ);
	for (int i = 0; i < SZ; i++){
		for (int j = 0; j < SZ; j++){
			res[i] = madd(res[i], mmul(A[i][j], v[j]));
		}
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

// Fibonacci: v_0 = {F_0, F_1} = {0, 1}, A = {{0, 1}, {1, 1}}, v_n = {F_n, F_(n+1)} = v_0 * A^n
// Recursion: F_n = c_(k-1)*F_(n-1) + c_(k-2)*F_(n-2) + ... + c_0*F_(n-k)
// bottom row of transformation matrix = {c_0, c_1, ..., c_(k-1)}
// other rows = {0, 0, ..., 1, ..., 0, 0} - '1' in (k-i)-th position if the row is i-th from the bottom
