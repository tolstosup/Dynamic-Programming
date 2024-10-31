//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <fstream>
//
//int find_sum(const std::vector<int> a, const int n);
//
//int main() {
//	std::ifstream in("ladder.in");
//	if (!in) {
//		std::cout << "ladder.in was not opened\n";
//		return 1;
//	}
//
//	unsigned int n = 0;
//	in >> n;
//
//	std::vector<int> a;
//	int temp = 0;
//	while (in >> temp)
//		a.push_back(temp);
//	in.close();
//
//	std::ofstream out("ladder.out");
//	if (!out) {
//		std::cout << "ladder.out was not opened\n";
//		return 1;
//	}
//
//	out << find_sum(a, n);
//	out.close();
//
//	return 0;
//}
//
//int find_sum(const std::vector<int> a, const int n) {
//	std::vector<int> dp(n + 1);
//	dp[0] = 0;
//	dp[1] = a[0];
//	if (n == 0) {
//		return 0;
//	}
//	if (n == 1) {
//		return a[0];
//	}
//	else if (n == 2) {
//		return a[1] + std::max(dp[0], dp[1]);
//	}
//	else {
//		for (auto i = 1; i < n; i++) {
//			dp[i + 1] = a[i] + std::max(dp[i], dp[i - 1]);
//		}
//
//		return dp[n];
//	}
//}