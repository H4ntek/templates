struct P{
    lli x, y;
    void read(){
        cin >> x >> y;
    }
    void print(){
        cout << "(" << x << ", " << y << ")\n";
    }
    bool operator <(const P &a){ //
        return x < a.x || (x == a.x && y < a.y);
    }
    bool operator ==(const P &a){
        return x == a.x && y == a.y;
    }
    P operator -(const P& b) const{
        return P{x - b.x, y - b.y};
    }
    lli operator *(const P& b) const{
        return x * b.y - y * b.x;
    }

    //returns x, |x| = 2 * area of triangle, x > 0 <==> when going A->B->C we turn ccwise (+ve angle)
    lli orient(const P& b, const P& c) const { 
        return (b - *this) * (c - *this);
    }
};

lli area(vector <P> &poly){ //actually 2 * area
    lli res = 0;
    int n = poly.size();
    for (int i = 0, j = n - 1; i < n; j = i++){
        res += poly[i] * poly[j];
    }
    return abs(res);
}
