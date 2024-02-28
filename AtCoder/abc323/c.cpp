#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int main(){
    int n, m;
    cin >> n >> m;
    vector<PII>points;
    vector<int>pp(m,0 );
    for (int i = 0; i < m; ++i){
	cin >> pp[i];
	points.emplace_back(pp[i], i);
    }
    sort(points.begin(), points.end());
    reverse(points.begin(), points.end());
    int max_score = 0;
    vector<int> curr_scores;
    vector<string> records;
    for (int i = 0; i < n; ++i){
	string s;
	cin >> s;
	records.push_back(s);
	int score = i + 1;
	for (int i = 0; i < m;++i){
	    if (s[i] == 'o'){
		score += pp[i]; 
	    }
	}
	curr_scores.push_back(score);
    }
    max_score = *max_element(curr_scores.begin(), curr_scores.end());
    for (int i = 0; i < n; ++i){
	int curr_score = curr_scores[i];
	if (curr_score == max_score)cout <<0 <<endl;
	else{
	    int ret = 0;
	    for (auto [s, idx]: points){
		if (records[i][idx] == 'o')continue;
                curr_score += s;
		ret++;
		if (curr_score >= max_score){
		    break;
		}
	    }
	    cout << ret<< endl;
	}
    }
    cout << endl;
return 0;
  }
