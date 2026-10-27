#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
 
void monedas(int d, vector<int>m, vector<int>& s){
	int n = m.size();
    	int inf_val = numeric_limits<int>::max();
	s.assign(n,0);

	vector<vector<int>> T(n, vector<int>(d+1, inf_val));
	for (int i=0;i<n;i++){
		T[i][0]=0;
	
	}

	for(int j=1;j<=d;j++){
		if(j >= m[0] && T[0][j - m[0]] != inf_val){
			T[0][j] = 1 +T[0][j-m[0]];
		
		}
	}
	
	for (int i = 1; i < n; i++) {
        	for (int j = 1; j <= d; j++) {
           		if (j < m[i]) {
                		T[i][j] = T[i - 1][j];
            		} else {
				if(T[i][j - m[i]] != inf_val){
					T[i][j] = min(T[i-1][j] , 1 + T[i][j-m[i]]);
				} else {
					T[i][j]=T[i-1][j];
				
				}
			}
		}
	}
	
	if (T[n - 1][d] == inf_val) {
    		// No existe solución
    		return;
	}

	int i = n - 1;
	int j = d;

	while (j > 0) {
    		if (i > 0 && T[i][j] == T[i - 1][j]) {
        		i--;
    		} else {
        		s[i]++;
        		j -= m[i];
    		}
	}	
}

int main(){
	return 0;
