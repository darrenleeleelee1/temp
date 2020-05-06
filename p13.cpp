#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int N, L, U, temp, res;
	while(cin >> N >> L >> U){
		res = 0;
		for(int i = 31; i >= 0; i--){
			temp =(long long)1 << i;

			if((N & temp) == 0){
				//printf("res: %lld temp: %lld r+t: %lld L: %lld U: %lld\n", res, temp, res + temp, L, U);
				if(res + temp <= U){
					res += temp;
				}

			}
			else{
				if(temp + res - 1 < L) res += temp;
			}
		}
		printf("%lld\n", res);
	}
	
	return 0;
}