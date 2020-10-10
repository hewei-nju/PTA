#include <bits/stdc++.h>
using namespace std;
string temp[55];
string cards[55]={"", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", "J1", "J2"};

int main()
{
	int times;
	int order[55];
	cin >> times;
	for(int i = 1;i <= 54; ++i) {
        cin >> order[i];
    }

	for(int i = 1; i <= times; ++i){
		for(int j = 1; j <= 54; ++j){
            temp[j] = cards[j];
        }
		for(int k = 1; k <= 54; ++k){
			cards[order[k]] = temp[k];
		}
	}
	for (int i = 1; i <= 54; ++i){
		cout << cards[i];
		if(i <= 53) {
            cout <<" ";
        }
	}
	return 0;
}
