#include<iostream>
#include<vector>
using namespace std;
bool check_row(string& row, vector<string>& solution){
    const int n = solution.size();
    for (int i = 0; i < n; ++i){
	for (int j = 0; j < n; ++j){
	    if (solution[i][j] != '.'){
		if (solution[i][j] != row[i])return false;
		else break;
	    }
	}
    }
    return true;
}

bool check_col(string& col, vector<string>& solution){
    const int n = solution.size();
    for (int j = 0; j < n; ++j){
	for (int i = 0; i < n; ++i){
	    if (solution[i][j] != '.'){
		if (solution[i][j] != col[j])return false;
		else break;
	    }
	}
    }
    return true;
}

bool check_ABC_row(vector<string>& solution){
    const int n = solution.size();
    for (int i = 0 ; i <n;++i){
	int a = 0, b =0 , C = 0;
	for (auto c: solution[i]){
	    if (c == 'A'){
		if (a == 1)return false;
		else a++;
	    }
	    if (c == 'B'){
		if (b == 1)return false;
		else b++;
	    }
	    if (c == 'C'){
		if (C == 1)return false;
		else C++;
	    }
	}
    }
    return true;
}

bool check_ABC_col(vector<string>& solution){
    const int n = solution.size();                                                      
    for (int j = 0 ; j <n;++j){                                                         
	int a = 0, b =0 , C = 0;                                                        
	for (int i = 0; i <n;++i){ 
	    char c = solution[i][j];	    
	    if (c == 'A'){                                                              
		if (a == 1)return false;                                                
		else a++;                                                               
	    }                                                                           
	    if (c == 'B'){                                                              
		if (b == 1)return false;                                                
		else b++;                                                               
	    }                                                                           
	    if (c == 'C'){                                                              
		if (C == 1)return false;                                                
		else C++;                                                               
	    }                                                                           
	}                                                                               
    }                                                                                   
    return true; 
}


bool check_ABC_row_(vector<string>& solution){                                           
    const int n = solution.size();                                                      
    int a = 0, b =0 , C = 0;                                                        
    for (int i = 0 ; i <n;++i){                                                         
	a = 0; b =0 ; C = 0;                                                        
	for (auto c: solution[i]){                                                      
	    if (c == 'A'){                                                              
		if (a == 1)return false;                                                
		else a++;                                                               
	    }                                                                           
	    if (c == 'B'){                                                              
		if (b == 1)return false;                                                
		else b++;                                                               
	    }                                                                           
	    if (c == 'C'){                                                              
		if (C == 1)return false;                                                
		else C++;                                                               
	    }                                                                           
	}   
	if (!(a==1 &&b==1&&C==1))return false;	
    }
    return true;    
}                                                                                       

bool check_ABC_col_(vector<string>& solution){                                           
    const int n = solution.size();                                                      
    int a = 0, b =0 , C = 0;                                                        
    for (int j = 0 ; j <n;++j){                                                         
	a = 0; b =0; C = 0;                                                        
	for (int i = 0; i <n;++i){                                                      
	    char c = solution[i][j];                                                    
	    if (c == 'A'){                                                              
		if (a == 1)return false;                                                
		else a++;                                                               
	    }                                                                           
	    if (c == 'B'){                                                              
		if (b == 1)return false;                                                
		else b++;                                                               
	    }                                                                           
	    if (c == 'C'){                                                              
		if (C == 1)return false;                                                
		else C++;                                                               
	    }                                                                           
	}                                                                               
	if (!(a==1 &&b==1&&C==1))return false;	
    }
    return true;    
}            



bool good(string& row, string& col, vector<string>& solution){
    // check row
    if (!check_row(row, solution))return false;
    if (!check_col(col, solution))return false;
    if (!check_ABC_row(solution))return false;
    if (!check_ABC_col(solution))return false;
    return true;
}

bool perfect(string& row, string& col, vector<string>& solution){
    if (!check_row(row, solution))return false;
    if (!check_col(col, solution))return false;
    if (!check_ABC_row_(solution))return false;
    if (!check_ABC_col_(solution))return false;
    return true;
}
void backtrack(int n, string& row, string& col, bool& found, int i, int j,  vector<string>& solution){
    if (found)return;
    string candidate = "ABC.";
    if (i == n-1 && j == n-1){
	/*
	for (auto s: solution){
	    cout << s<<endl;
	}*/
	if (perfect(row, col, solution)){
	    found = true;
	}
	return;
    }
    if (!good(row, col, solution)){
	return;
    }
    int new_i = i, new_j = j;
    if (j < n-1){
	new_j = j + 1;
    } else {
	new_i = i + 1;
	new_j = 0;
    }
    //cout << new_i <<" "<<new_j<<endl;
    for (auto c : candidate){
	auto old = solution[new_i][new_j];
	solution[new_i][new_j] = c;
	/*
	cout << new_i <<"------"<<new_j<<endl;
	for (auto s: solution){
            cout << s<<endl;
        }*/
	backtrack(n, row, col, found, new_i, new_j, solution);
	if (found)return;
	solution[new_i][new_j] = old;
    }
}
int main(){
    int n;
    cin>>n;
    string row, col;
    cin >> row;
    cin >> col;
    bool found = false;
    int i = 0;
    int j = -1;
    string empty_s;
    for (int i =0; i <n;++i)empty_s.push_back('.');
    vector<string> solution(n, empty_s);
    backtrack(n, row, col, found, i, j, solution);
    if (found){
	cout <<"Yes"<<endl;
	for (auto s: solution)cout << s<<endl;
    }else{
	cout << "No" << endl;
    }
    return 0;
}
