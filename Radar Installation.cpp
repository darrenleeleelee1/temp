#include <bits/stdc++.h>
using namespace std;
struct Coordinate
{
	int x, y;
	double right, left;

	bool operator<(Coordinate const other) const{
		return right < other.right;
	}
};

int main(int argc, char const *argv[])
{
	int n, d, cnt = 1;
	bool out;
	Coordinate cor[1010];
	while(cin >> n >> d){
		if(n == 0 && d == 0) break;
		out = false;
		for(int i = 0; i < n; i++){
			cin >> cor[i].x >> cor[i].y;
			if(abs(cor[i].y )> d) out = true;
			else{
				cor[i].left = cor[i].x - sqrt(pow(d, 2) - pow(cor[i].y, 2));
				cor[i].right = cor[i].x + sqrt(pow(d, 2) - pow(cor[i].y, 2));
			}
		}
		if(out){ 
			printf("Case %d: -1\n", cnt++);
			continue;
		}
		sort(cor, cor + n);
		int ans = 1, sp = cor[0].right;
		for(int i = 1; i < n; i++){
			if(sp >= cor[i].left) continue;
			else {
				ans++;
				sp = cor[i].right;
			}
		}
		printf("Case %d: %d\n", cnt++, ans);
	}
	return 0;
}