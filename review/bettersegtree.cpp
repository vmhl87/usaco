// tree is just an array
pair<int, int> t[4*MAXN];

// combine two into one
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) 
        return a;
    if (b.first > a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}

// build from root index (v=1, tl=0, tr=n-1)
void build(int a[], int v, int tl, int tr) {
	// ending node
    if (tl == tr) {
        t[v] = make_pair(a[tl], 1);
    } else {
    	// split on index
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

// range max
pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
	// process out of bounds
    if (l > r)
        return make_pair(-INF, 0);
    // if matches exactly
    if (l == tl && r == tr)
        return t[v];
    // split on index
    int tm = (tl + tr) / 2;
    return combine(get_max(v*2, tl, tm, l, min(r, tm)), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r));
}

// update value at pos
void update(int v, int tl, int tr, int pos, int new_val) {
	// if at pos, update it
    if (tl == tr) {
        t[v] = make_pair(new_val, 1);
    } else {
    	// split on index
        int tm = (tl + tr) / 2;
        // find side to update
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
