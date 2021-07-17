#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define int long long
using namespace std;

const int N = 3e5 + 5;
const int mod = 1e9 + 7;
const int INF = 1e15 + 5;	 

int sim_dur, n_intersections, n_streets, n_cars, n_points;

struct street{
	int b, e;
	int l;
	string s;
} st[N];

vector<string> inc_streets[N];
map<string, int> mp;

void solve(){
	cin >> sim_dur >> n_intersections >> n_streets >> n_cars >> n_points;

	for(int i=0; i<n_streets; i++){
		cin >> st[i].b >> st[i].e >> st[i].s >> st[i].l;
		inc_streets[st[i].e].push_back(st[i].s);
	}
	
	for(int i=0; i<n_cars; i++){
		int p;
		cin >> p;
		vector<string> paths;
		for(int j=0; j<p; j++){
			string s;
			cin >> s;
			paths.push_back(s);
			if(j!=0)
				mp[s]++;
		}
	}
	
	int useful_intersections = 0;
	
	for(int i=0; i<n_intersections; i++){
		int cnt = 0;
		for(auto j:inc_streets[i]){
			if(mp[j]) cnt++;
		}
		if(cnt) useful_intersections++;
	}
	
	cout << useful_intersections << endl;
	
	for(int i=0; i<n_intersections; i++){
		int cnt = 0;
		int sum = 0;
		for(auto j:inc_streets[i]){
			if(mp[j]) cnt++;
			sum += mp[j];
		}
		if(!cnt) continue;
		cout << i << endl;
		cout << cnt << endl;
		for(auto j:inc_streets[i]){		
			if(mp[j])
				cout << j << " " << sim_dur * mp[j] / sum << endl;
		}
	}
		
}
			

int32_t main(){
	fast;
	int t;
	//cin  >> t;
	t = 1;
	while(t--){
		solve();	
	}
}
