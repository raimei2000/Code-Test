// https://school.programmers.co.kr/learn/courses/30/lessons/87946
// 87946 피로도

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void dfs(int stamina, int cnt, int& best, const vector<vector<int>>& dungeons,
         vector<bool>& used) {
  best = max(best, cnt);
  for (int i = 0; i < (int)dungeons.size(); i++) {
    if (used[i]) continue;
    if (stamina < dungeons[i][0]) continue;
    used[i] = true;
    dfs(stamina - dungeons[i][1], cnt + 1, best, dungeons, used);
    used[i] = false;
  }
}

int solution(int k, vector<vector<int>> dungeons) {
  int answer = 0;
  vector<bool> used(dungeons.size());
  dfs(k, 0, answer, dungeons, used);
  return answer;
}

// #include <algorithm>
// #include <numeric>
// #include <string>
// #include <vector>

// using namespace std;

// int solution(int k, vector<vector<int>> dungeons) {
//   int answer = 0;

//   vector<int> order(dungeons.size());
//   iota(order.begin(), order.end(), 0);
//   do {
//     int stamina = k;
//     int num_dungeon = 0;
//     for (const int& idx : order) {
//       if (stamina >= dungeons[idx][0]) {
//         num_dungeon++;
//         stamina -= dungeons[idx][1];
//       } else
//         break;
//     }
//     answer = max(answer, num_dungeon);
//     if (answer == dungeons.size()) return answer;
//   } while (next_permutation(order.begin(), order.end()));

//   return answer;
// }