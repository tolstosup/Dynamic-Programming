#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

void odp(std::vector<std::vector<unsigned int>> dp) {
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[i].size(); j++) {
			std::cout << dp[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

unsigned int count_score(std::vector<std::vector<unsigned int>> mount);

int main() {
	std::ifstream in("slalom.in");
	if (!in) {
		std::cout << "slalom.in was not opened\n";
		return 1;
	}


	std::vector<std::vector<unsigned int>> mount;
	unsigned int n = 0;
	in >> n;
	for (int i = 1; i < n + 1; i++) {
		mount.push_back(std::vector<unsigned int>(i, 0));
		for (int j = 0; j < i; j++) {
			in >> mount[i - 1][j];
		}
	}
	in.close();

	std::ofstream out("slalom.out");
	if (!out) {
		std::cout << "slalom.in was not opened\n";
		return 1;
	}

	out << count_score(mount);
	out.close();

	return 0;
}

unsigned int count_score(std::vector<std::vector<unsigned int>> mount) {
	std::vector<std::vector<unsigned int>> dp;

	for (int i = 1; i < mount.size() + 1; i++)
		dp.push_back(std::vector<unsigned int>(i, 0));
	
	dp[0][0] = mount[0][0];

	for (int i = 1; i < mount.size(); i++) {
		for (int j = 0; j < mount[i].size(); j++) { // вниз влево mount[i + 1][j] вниз вправо mount[i + 1][j + 1]
			std::cout << i << " " << j << '\n';
			odp(dp);

			if (i - 1 > -1 && j < mount[i - 1].size()) {
				dp[i][j] = std::max(dp[i][j], dp[i][j] + mount[i - 1][j]);
			}
			if (i - 1 > -1 && j - 1 > - 1) {
				dp[i][j] = std::max(dp[i][j], dp[i][j] + mount[i - 1][j - 1]);
			}
		}
	}
	odp(dp);

	return *std::max_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
}