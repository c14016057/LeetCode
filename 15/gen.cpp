#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	int N = 1000;
	srand(time(NULL));
	//cin >> N;
	cout << N << endl;
	for (int i = 0; i < N ;i++)
		cout << rand()%N-N/2 << endl;

	return 0;
}
