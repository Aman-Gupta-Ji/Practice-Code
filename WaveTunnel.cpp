#include <bits/stdc++.h>
using namespace std;

int calculateMinTime(vector<vector<int>>& samples) {
    int n = samples.size(), m = samples[0].size();
    int i, j;
    queue<vector<int>> q;
    int min = 0, count = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(samples[i][j] == 2)//if infected
                q.push({i, j, 0}); // i, j, time
            else if(samples[i][j] == 1)
                count++;
        }
    }
    int r[] = {-1, 0, 1, 0}, c[] = {0, -1, 0, 1};
    int ni, nj, k, t;
    vector<int> temp;
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        i = temp[0];
        j = temp[1];
        t = temp[2];
        if(min < t)
            min = t;
        for(k = 0; k < 4; k++) {
            ni = i + r[k];
            nj = j + c[k];
            if(ni >=0 && ni < n && nj >= 0 && nj < m) {
                if(samples[ni][nj] == 1) {
                    count--;
                    samples[ni][nj] = 2;
                    q.push({ni, nj, t + 1});
                }
            }
        }
    }
    if(count)
        return -1;
    return min;
}

int findWaveCount(string& tunnel) {
	int n = tunnel.size();
	int waves = 0;
	vector<int> left(n), right(n);
	int l, r;
	l = r = 0;
	for(int i = 0; i < n; i++) {
		if(tunnel[i] == '>')
			r++;
		right[i] = r;
	}
	for(int i = n - 1; i >= 0; i--) {
		if(tunnel[i] == '<')
			l++;
		left[i] = l;
	}
	for(int i = 0; i < n; i++) {
		switch(tunnel[i]) {
			case '<': //left
				waves += right[i];
				break;
			case '>': //right
				waves += left[i];
				break;
		}
	}
	return waves;
}

int findStudnetCount(vector<int>& arr) {
	int n = arr.size();
	int set2 = 0;
	for(int i = 1; i < n - 1; i++)
		if(arr[i] < arr[i + 1] || arr[i] < arr[i - 1])
				set2++;
	return set2;
}

int maximumSeating(vector<int>& seats) {
	int seating = 0;
	int n = seats.size();
	vector<bool> cansit(n, false);
	int count = 2;
	for(int i = 0; i < n; i++) {
		switch(seats[i]) {
			case 1:
				count = 0;
				break;
			case 0:
				if(count == 2) {
					cansit[i] = true;
					count = 0;
				}
				else
					count++;
				break;
		}
	}
	count = 2;
	for(int i = n - 1; i >= 0; i--) {
		switch(seats[i]) {
			case 1:
				count = 0;
				break;
			case 0:
				if(count >= 2 && cansit[i]) {
					seating++;
					count = 0;
				}
				else
					count++;
				break;
		}
	}
	return seating;
}

int main(void) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	cout<<maximumSeating(arr)<<endl;
}