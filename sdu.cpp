struct DSU {
    std::vector<int> _t;
    DSU(int N): _t(2*N,-1) { 
        std::iota(_t.begin(),_t.begin()+N, N);
    }
    int find(int x) { return _t[x] < 0 ? x : _t[x] = find(_t[x]); }
    bool join(int x, int y) {
        auto fx = find(x), fy = find(y);
        if (is_del(x) || is_del(y) || fx == fy) return false;
        if (_t[fx] > _t[fy]) std::swap(fx,fy);
        _t[fx] += _t[fy]; _t[fy] = fx; // Ensure we do not count the extra nodes
        return true;
    }
    bool move(int x, int y) {
        // this uses the point to itself method.
        auto fx = find(x), fy = find(y);
        if (is_del(x) || is_del(y) || fx == fy) return false;
        _t[fx]++; _t[fy]--; // Note fx, fy cannot be from [0..N-1]
        _t[x] = fy;
        return true;
    }
    bool erase(int x) {
        auto fx = find(x);
        if (is_del(x)) return false;
        _t[fx]++; _t[x] = -1;
        return true;
    }
    bool is_del(int x) { return _t[x] == -1; }
    int sz(int x) { return -_t[find(x)]; }
};
