#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 文字列の各iについて、文字iを中心とする最長の回文の半径を求める
// O(|S|)
// 参考：https://snuke.hatenablog.com/entry/2014/12/02/235837
vector<int> manacher(const string &s){
	vector<int> radius(s.size());
	int i = 0, j = 0;
	while(i < s.size()){
		while(i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]) j++;
		radius[i] = j;
		int k = 1;
		while(i-k >= 0 && i+k < s.size() && k + radius[i-k] < j){
			radius[i+k] = radius[i-k];
			k++;
		}
		i += k;
		j -= k;
	}
	return radius;
}
