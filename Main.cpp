/*
Devun Schneider
CS140
Prof Hawkins
Compute a binomial coefficient with memoization
*/
#include <iostream>
#include <stdexcept>;
#include <vector>;
using namespace std;

//initializes input holder variables 
int n, k;

//creates 2d vector/pascal triangle based off of C(n,k) 
void pascalTriangle(int n, int k) {
	cout << "Start of pascalTriangle \n \n";
	vector<vector<int>> triangle; //global

	for (int i = 0; i <= n; i++) {
		//"Inside the outer for loop we will make a 1-dimensional vector:"
		vector<int> row;
		for (int j = 0; j <= i;j++) {
			//2 base cases: when j=0 then triangle[i][j]=1 
			//&& when j==i then triangle [i][j]=1
			if (j == 0 || j == i) {
				row.push_back(1);
			}
			else row.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
		}
		triangle.push_back(row);
	}

	//printing results
	cout << "\nPascal's triangle Coefficient : " << triangle[n][k];    
	cout << "\nPascal's triangle : \n";

	for (int i = 0; i <= n; i++) {       
		for ( int j = 0; j <= i; j++) {    
			cout << triangle[i][j] << " ";   
		}
		cout << "\n";          
	}
}
int main() {
	//assign values to n,k
	cout << "Please enter n: ";
	cin >> n;
	cout << "Please enter k: ";
	cin >> k;
	cout << "\n";
	//n>=k k>=0
	if (n < k || k < 0) {
		cerr << "invalid input";
		exit(1);
	}
	pascalTriangle(n, k);


}