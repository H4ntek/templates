//Query min/max on a sliding window of some length
struct SlidingWin{
    vector <pair <int, int>> s1, s2;
    
    int op(int a, int b){
        return max(a, b);
    }
    
    void push(int x){
        if (!s2.empty()){
            s2.emplace_back(x, op(x, s2.back().ff));
        }
        else{
            s2.emplace_back(x, x);
        }
    }
    
    void move(){
        if (s1.empty()){
            if (!s2.empty()){
                s1.emplace_back(s2.back().ff, s2.back().ff);
                s2.pop_back();
            }
            while (!s2.empty()){
                s1.emplace_back(s2.back().ff, op(s2.back().ff, s1.back().ss));
                s2.pop_back();
            }
        }
    }
    
    void pop(){
        move();
        s1.pop_back();
    }
    
    int query(){
        move();
        if (!s2.empty()){
            return op(s1.back().ss, s2.back().ss);
        }
        return s1.back().ss;
    }
};
