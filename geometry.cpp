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

int sgn(lli x){
    if (x == 0) return 0;
    return (x > 0 ? 1 : -1);
}

bool proj(lli a, lli b, lli c, lli d){
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}

bool intersect(P A, P B, P C, P D){
    int o1 = sgn(A.orient(B, C)), o2 = sgn(A.orient(B, D)), o3 = sgn(C.orient(D, A)), o4 = sgn(C.orient(D, B));
    if (o1 != o2 && o3 != o4){
        return true;
    }
    if (o1 == 0 && o4 == 0){
        if (proj(A.x, B.x, C.x, D.x) && proj(A.y, B.y, C.y, D.y)){
            return true;
        }
    }
    return false;
}

lli area(vector <P> &poly){ //actually 2 * area
    lli res = 0;
    int n = poly.size();
    for (int i = 0, j = n - 1; i < n; j = i++){
        res += poly[i] * poly[j];
    }
    return abs(res);
}

vector <P> convex_hull(vector <P> points){
    if ((int) points.size() <= 3){
        return points;
    }
    vector <P> ch;
    sort(points.begin(), points.end());
    for (P p : points){
        while ((int) ch.size() >= 2 && p.orient(ch[ch.size() - 2], ch[ch.size() - 1]) > 0){
            ch.pop_back();
        }
        ch.emplace_back(p);
    }
    ch.pop_back();
    int sz = ch.size();
    reverse(points.begin(), points.end());
    for (P p : points){
        while ((int) ch.size() >= sz + 2 && p.orient(ch[ch.size() - 2], ch[ch.size() - 1]) > 0){
            ch.pop_back();
        }
        ch.emplace_back(p);
    }
    ch.pop_back();
    return ch;
}
