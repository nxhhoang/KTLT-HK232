#include<vector>
#include <limits>
void process(string fileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		return;
	}
	int N, M;
	file >> N >> M;
	double maxOverall = -numeric_limits<double>::max();
	vector<double> maxInRow(N);
	for (int i = 0; i < N; i++) {
		maxInRow[i] = -numeric_limits<double>::max();
		for (int j = 0; j < M; j++) {
			double val;
			file >> val;
			maxInRow[i] = max(maxInRow[i], val);
			maxOverall = max(maxOverall, val);
		}
	}
	file.close();
	for (int i = 0; i < N; i++) {
		cout << maxInRow[i] << " ";
	}
	cout << maxOverall << endl;
}
