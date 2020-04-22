#include <bits/stdc++.h>
using namespace std;
const int maxn = 300+10;
long long int d[maxn][maxn];
char tape[maxn];
long long int dp(int i, int j){
	long long int &ans = d[i][j];
	if(i == j) return ans;
	if(tape[i] != tape[j]) return 0;
	if(ans >= 0) return ans; 
	ans = 0;
	for(int k = i + 1; k <= j; k++)
		ans += dp(i + 1, k - 1) * dp(k, j);
	return ans;
} 
void draw(int length){

}
int main(int argc, char const *argv[])
{
	while(scanf("%s", tape) != EOF){
		memset(d, -1, sizeof(tape));
		for(int i = 0; i < strlen(tape); i++)
			d[i][i] = 1;
		printf("%d\n", dp(0, strlen(tape)-1));
	}
	return 0;
}