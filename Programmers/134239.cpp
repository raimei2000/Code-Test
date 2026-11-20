// https://school.programmers.co.kr/learn/courses/30/lessons/134239
// 134239 우박수열 정적분

#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
  vector<double> answer;
  answer.reserve(ranges.size());
  vector<int> y;
  y.push_back(k);

  while (k > 1) {
    if (k % 2 == 0) k /= 2;
    else k = k * 3 + 1;
    y.push_back(k);
  }

  int n = y.size() - 1;
  vector<double> integral(n, 0.0);  // [index, index + 1] 넓이

  for (const vector<int>& r : ranges) {
    int a = r[0], b = n + r[1];
    if (b < a) answer.push_back(-1);
    else {
      double sum = 0.0;
      for (int i = a; i < b; i++) {
        if (integral[i] == 0.0) {
          integral[i] = (double)(y[i] + y[i + 1]) / 2.0;
        }
        sum += integral[i];
      }
      answer.push_back(sum);
    }
  }

  return answer;
}
