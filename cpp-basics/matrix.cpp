#include <iostream>
#include <vector>
using namespace std;


vector<vector<float>> multiply(vector<vector<float>> first, vector<vector<float>> second);

int main() {

	vector<vector<float>> first = {
		{1, 2, 3},
		{4, 5, 6}
	};

	vector<vector<float>> second = {
		{7, 8},
		{9, 10},
		{11, 12}
	};

	vector<vector<float>> product = multiply(first, second);

	for(vector<float> row: product) {
		for(float item: row)
			cout << item << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<float>> multiply(vector<vector<float>> first, vector<vector<float>> second) {
	if(first.size() == 0 || second.size() == 0 || first.size() != second[0].size() || first[0].size() != second.size())
		return {};

	int H = first.size();
	int W = second[0].size();

	vector<vector<float>> product(H, vector<float>(W));

	for(int row = 0; row < first.size(); row++) {
		for(int col2 = 0; col2 < second[0].size(); col2++) {
			float sum = 0.0;
			for(int col = 0; col < first[0].size(); col++) {
				sum += first[row][col] * second[col][col2];
			}
			product[row][col2] = sum;
		}
	}

	return product;
}