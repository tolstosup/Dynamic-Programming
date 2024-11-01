#include <iostream>
#include <vector>
#include <algorithm>

unsigned int count_score(std::vector<std::vector<unsigned int>> mount);

int main() {
	std::vector<std::vector<unsigned int>> mount;
	unsigned int n = 0;
	std::cin >> n;
	for (int i = 1; i < n + 1; i++) {
		mount.push_back(std::vector<unsigned int>(i, 0));
		for (int j = 0; j < i; j++) {
			std::cin >> mount[i - 1][j];
		}
	}

	std::cout << count_score(mount);

	return 0;
}

unsigned int count_score(std::vector<std::vector<unsigned int>> mount) {
	std::vector<std::vector<unsigned int>> dp;

	for (int i = 1; i < mount.size() + 1; i++)
		dp.push_back(std::vector<unsigned int>(i, 0));
	
	dp[0][0] = mount[0][0];

	for (size_t i = 0; i < mount.size(); i++) {
		for (size_t j = 0; j < mount[i].size(); j++) {
			if (i + 1 < mount.size() && j < mount[i].size()) {
				dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j] + mount[i + 1][j]);
			}
			if (i + 1 < mount.size() && j + 1 < mount[i + 1].size()) {
				dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j] + mount[i + 1][j + 1]);
			}
		}
	}

	return *std::max_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
}