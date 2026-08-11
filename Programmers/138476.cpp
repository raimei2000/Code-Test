// https://school.programmers.co.kr/learn/courses/30/lessons/138476
// 138476 귤 고르기

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
  int answer = 0;
  unordered_map<int, int> mp;
  for (int n : tangerine) mp[n]++;
  vector<pair<int, int>> lst(mp.begin(), mp.end());
  sort(lst.begin(), lst.end(), [](const auto& a, const auto& b) -> bool {
    return a.second > b.second;
  });
  for (const auto [size, cnt] : lst) {
    k -= cnt;
    answer++;
    if (k <= 0) break;
  }
  return answer;
}