class dsu {
 public:
  vector<int> p;
  int n;
 
  // コンストラクタ
  dsu(int _n){
    n = _n;
    p.resize(n, -1);
  }
 
  // 頂点xの根を求める
  inline int get(int x) {
    return (p[x] < 0 ? x : (p[x] = get(p[x])));
  }

  // 頂点xを含む集合のサイズを求める
  inline int size(x){
    return -p[get(x)];
  }
 
  // 頂点xとyを同じ集合に入れる
  // サイズが小さい方を大きい方にマージする
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      if(p[y] < p[x]) swap(x, y);
      p[x] += p[y];
      p[y] = x;
      return true;
    }
    return false;
  }
};
