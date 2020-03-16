#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	vector <string> s[52];
	string str;
	while(cin >> str && str != "#"){
		for(int i = 0; i < 52; i++){
			s[i].clear();
		}
		s[0].push_back(str); 
		for(int i = 1; i < 52; i++){
			cin >> str;
			s[i].push_back(str);
		}
		while(true){
			for(int i = 1; i < 52; i++){
				string cur = s[i].back();
				if(s-3 >= 0){
					string cmp = s[i-3].back();
					if(cmp[0] == cur[0] || cmp[1] == cur[1]){
						
					}
				}
				
				if(s-1 >= 0){
					string cmp = s[i-1].back();
					if(cmp[0] == cur[0] || cmp[1] == cur[1]){

					}
				}
			}
		}
	}
	return 0;
}