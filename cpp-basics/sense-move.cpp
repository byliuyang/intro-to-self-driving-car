#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<float> p(5, 0.2);
vector<string> world = {"green", "red", "red", "green", "green"};
vector<string> measurements = {"red", "green"};
vector<int> motions = {1, 1};
float pHit = 0.6;
float pMiss = 0.2;
float pExact = 0.8;
float pOvershoot = 0.1;
float pUndershoot = 0.1;

vector<float> sense(vector<float> p, string Z);
vector<float> move(vector<float> p, int U);

int main() {

	for(int i = 0; i < measurements.size(); i++) {
		p = sense(p, measurements[i]);
		p = move(p, motions[i]);
	}

	for(float pI: p)
		cout << pI << endl;

	return 0;
}

vector<float> sense(vector<float> p, string Z) {
	vector<float> q;
	float sum = 0.0;

	for(int i = 0; i < p.size(); i++) {
		bool hit = (Z == world[i]);
		float pI = p[i] * (hit * pHit + (1 - hit) * pMiss);
		q.push_back(pI);
		sum += pI;
	}

	for(int i = 0; i < q.size(); i++)
		q[i] /= sum;
	return q;
}


vector<float> move(vector<float> p, int U) {
	vector<float> q;
	int N = p.size();
	for(int i = 0; i < p.size(); i++) {
		float s = pExact * p[(i - U) % N];
		s += pOvershoot * p[(i - U - 1) % N];
		s += pUndershoot * p[(i - U + 1) % N];
		q.push_back(s);
	}
	return q;
}
