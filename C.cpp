//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <fstream>
//
//unsigned int count_ways(unsigned int m, unsigned int n);
//
//int main() {
//	std::ifstream in("knight.in");
//	if (!in) {
//		std::cout << "knight.in was not opened\n";
//		return 1;
//	}
//
//	unsigned int m = 0, n = 0;
//	in >> m >> n; 
//	in.close();
//
//	std::ofstream out("knight.out");
//	if (!out) {
//		std::cout << "knight.in was not opened\n";
//		return 1;
//	}
//
//	out << count_ways(m, n);
//	out.close();
//
//	return 0;
//}
//
//unsigned int count_ways(unsigned int m, unsigned int n) {
//	std::vector<std::vector<unsigned int>> dp(m, std::vector<unsigned int>(n, 0));
//	dp[0][0] = 1;
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i + 1 < m && j + 2 < n) {
//				dp[i + 1][j + 2] += dp[i][j];
//			}
//			if (i + 2 < m && j + 1 < n) {
//				dp[i + 2][j + 1] += dp[i][j];
//			}
//		}
//	}
//
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			std::cout << dp[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//
//	return dp[m - 1][n - 1];
//}