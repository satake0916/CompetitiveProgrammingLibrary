class dsu {
 public:
  vector<int> p;
  int n;
 
  // コンストラクタ
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
 
  // 頂点xの根を求める(所属する集合を求める)
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
 
  // 頂点xとyを同じ集合に入れる
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
