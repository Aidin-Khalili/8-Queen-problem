#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;

bool is_Safe_To_Insert(vector<vector<int>> board, int row, int col)
{
	int i, j;
	int N = board.size();
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQueen(vector<vector<int>>& board, int col)
{
	int N = board.size();
	if (col == N) {
		vector<int> v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 1)
					v.push_back(j + 1);
			}
		}
		result.push_back(v);
		return true;
	}
	bool res = false;
	for (int i = 0; i < N; i++) {
		if (is_Safe_To_Insert(board, i, col)) {
			board[i][col] = 1;
			res = solveNQueen(board, col + 1) || res;
			board[i][col] = 0;
		}
	}

	return res;
}

vector<vector<int>> nQueen(int n)
{
	result.clear();
	vector<vector<int> > board(n, vector<int>(n, 0));

	if (solveNQueen(board, 0) == false) {
		return {};
	}

	sort(result.begin(), result.end());
	return result;
}

int main()
{
	int n;
	cout << "Please enter the n (number of queens in n * n sheet) : ";
	cin >> n;
	cin.get();
	vector<vector<int>> v = nQueen(n);
	int i = 1;
	for (auto ar : v) {
		cout << i++ << ". { ";
		for (auto it : ar)
			cout << it << " ";
		cout << "}" << endl;
		cin.get();
	}

	return 0;
}
