// https://school.programmers.co.kr/learn/courses/30/lessons/42583
// 42583 다리를 지나는 트럭

#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int second = 0;
  queue<int> on_bridge;
  queue<int> time_off;
  int load = 0;
  int idx = 0;
  while (idx < truck_weights.size() || !on_bridge.empty()) {
    second++;
    if (!time_off.empty() && time_off.front() <= second) {
      time_off.pop();
      load -= on_bridge.front();
      on_bridge.pop();
    }
    if (idx < truck_weights.size() && load + truck_weights[idx] <= weight) {
      on_bridge.push(truck_weights[idx]);
      load += truck_weights[idx];
      idx++;
      time_off.push(second + bridge_length);
    }
  }
  return second;
}