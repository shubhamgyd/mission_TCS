#include<vector>
#include<queue>
#include<utility>
#include<iostream>
using namespace std;

void input(vector<int> &v, int n) {
	for (int i = 0 ; i < n ; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> segments;
	input(segments,n);

	long long total_sum = 0;

	for (int i = 0 ; i < n ; i++) {
		if (segments[i] == 0)
			segments[i] = -1;

		total_sum += segments[i];
	}

	int curr_sum = 0;

	if (curr_sum > total_sum - curr_sum)
		return 0;

	int idx = -1;
 	for (int i = 0 ; i < n ; i++){
 		curr_sum += segments[i];

 		if (curr_sum > total_sum - curr_sum) {
 			idx = i;
 			break;
 		} 
 	}

 	cout << idx+1 << "\n"; 
}