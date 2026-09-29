// https://school.programmers.co.kr/learn/courses/30/lessons/17680
// 17680 [1차] 캐시

#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  const int cache_hit = 1;
  const int cache_miss = 5;
  if (cacheSize == 0) return cities.size() * cache_miss;

  int answer = 0;
  unordered_map<string, int> cache;
  for (int i = 0; i < cities.size(); i++) {
    string& s = cities[i];
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return tolower(c); });

    if (cache.contains(s)) {  // cache hit
      answer += cache_hit;
      cache[s] = i;
    } else {  // cache miss
      if (cache.size() >= cacheSize) {
        auto min_it = min_element(cache.begin(), cache.end(),
                                  [](const auto& a, const auto& b) { return a.second < b.second; });
        cache.erase(min_it);
      }
      answer += cache_miss;
      cache[s] = i;
    }
  }
  return answer;
}