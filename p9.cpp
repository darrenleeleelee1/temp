#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int box[6];
	while(cin >> box[0] >> box[1] >> box[2] >> box[3] >> box[4] >> box[5]){
		if(!box[0] && !box[1] && !box[2] && !box[3] && !box[4] && !box[5]) break;
		int ans = box[5];
		while(box[4] > 0){
			ans += 1;
			box[4]--;
			int temp = 0;
			while(box[0] > 0 && temp <= 11){
				temp++;
				box[0]--;
			}
		}
		while(box[3] > 0){
			ans += 1;			
			box[3]--;
			int temp = 0;
			while(box[1] > 0 && temp <= 5){
				box[1]--;
				temp++;
			}
			temp *= 4;
			while(box[0] > 0 && temp <= 20){
				temp++;
				box[0]--;
			}
		}
		ans += box[2] / 4;
		box[2] = box[2] % 4;
		while(box[2] > 0){
			ans++;
			box[2]--;
			int temp1 = 0;
			while(box[2] > 0 && temp1 <= 3){
				box[2]--;
				temp1++;
			}

			if(temp1 == 1){
				int temp2 = 0;
				while(box[1] > 0 && temp2 <= 3){
					box[1]--;
					temp2++;
				}
				int temp3 = 0;
				while(box[0] > 0 && temp3 <= temp2 * 4 + temp1 * 9){
					temp3++;
					box[0]--;
				}
			}
			else if(temp1 == 2){
				int temp2 = 0;
				while(box[1] > 0 && temp2 <= 1){
					box[1]--;
					temp2++;
				}
				int temp3 = 0;
				while(box[0] > 0 && temp3 <= temp2 * 4 + temp1 * 9 && temp2 * 4 + temp1 * 9 < 25){
					temp3++;
					box[0]--;
				}
			}
			else if(temp1 == 0){
				int temp2 = 0;
				while(box[1] > 0 && temp2 <= 5){
					box[1]--;
					temp2++;
				}
				int temp3 = 0;
				while(box[0] > 0 && temp3 <= temp2 * 4 + temp1 * 9 && temp2 * 4 + temp1 * 9 < 25){
					temp3++;
					box[0]--;
				}
			}
		}
		ans += box[1] / 9;
		box[1] = box[1] % 9;
		while(box[1] > 0){
			ans++;
			box[1]--;
			int temp = 0;
			while(box[1] >= 0 && temp != 32){
				box[1]--;
				temp += 4;
			}
			while(box[0] >= 0 && temp != 32){
				temp++;
				box[0]--;
			}
		}
		while(box[0] > 0){
			ans++;
			box[0]--;
			int temp = 0;
			while(box[0] >= 0 && temp != 35){
				box[0]--;
				temp++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}