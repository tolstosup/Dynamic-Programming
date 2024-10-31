//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <fstream>
//
//unsigned int count_cost(std::vector<std::vector<unsigned int>> deck);
//
//int main() {
//	std::ifstream in("king2.in");
//	if (!in) {
//		std::cout << "kung2.in was not opened\n";
//		return 1;
//	}
//
//	std::vector<std::vector<unsigned int>> deck(8, std::vector<unsigned int>(8, 0));
//	for (int i = 0; i < 8; i++) {
//		for (int j = 0; j < 8; j++) {
//			in >> deck[i][j];
//		}
//	}
//	in.close();
//
//	std::ofstream out("king2.out");
//	if (!out) {
//		std::cout << "king2.in was not opened\n";
//		return 1;
//	}
//
//	out << count_cost(deck);
//	out.close();
//
//	return 0;
//}
//
//unsigned int count_cost(std::vector<std::vector<unsigned int>> cost) {
//	std::vector<std::vector<int>> dp(8, std::vector<int>(8, 0));
//
//	dp[7][0] = cost[7][0];
//
//	for (int i = 6; i >= 0; i--) {
//		dp[i][0] = dp[i + 1][0] + cost[i][0];
//	}
//
//	for (int j = 1; j < 8; j++) {
//		dp[7][j] = dp[7][j - 1] + cost[7][j];
//	}
//
//	for (int i = 6; i >= 0; i--) {
//		for (int j = 1; j < 8; j++) {
//			dp[i][j] = std::min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]}) + cost[i][j];
//		}
//	}
//
//	return dp[0][7];
//}