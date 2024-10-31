//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <fstream>
//
//int count_grass(std::vector<char> a, unsigned int n);
//void print_array(std::vector<int> a) {
//	for (int i = 0; i < a.size(); i++)
//		std::cout << a[i] << " ";
//	std::cout << std::endl;
//}
//
//int main() {
//	std::ifstream in("lepus.in");
//	if (!in) {
//		std::cout << "lepus.in was not opened\n";
//		return 1;
//	}
//
//	unsigned int n = 0;
//	in >> n;
//
//	std::vector<char> a;
//	char temp = 'a';
//	while (in >> temp)
//		a.push_back(temp);
//	in.close();
//
//	std::ofstream out("lepus.out");
//	if (!out) {
//		std::cout << "lepus.out was not opened\n";
//		return 1;
//	}
//
//	out << count_grass(a, n);
//	out.close();
//
//	return 0;
//}
//
//int count_grass(std::vector<char> a, unsigned int n) {
//	std::vector<int> dp(n, -1);
//	print_array(dp);
//	dp[0] = 0;
//	print_array(dp);
//	for (int i = 0; i < n; i++) {
//		if (dp[i] == -1)
//			continue;
//
//		for (int j = 1; j <= 5; j += 2) {
//			int next = i + j;
//			if (next >= n)
//				break;
//
//			if (a[next] == '.')
//				dp[next] = std::max(dp[next], dp[i]);
//			else if (a[next] == '"')
//				dp[next] = std::max(dp[next], dp[i] + 1);
//		}
//		print_array(dp);
//	}
//
//	return dp[n - 1];
//}