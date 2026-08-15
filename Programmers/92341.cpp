// https://school.programmers.co.kr/learn/courses/30/lessons/92341
// 92341 주차 요금 계산

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
  int base_min = fees[0];
  int base_fee = fees[1];
  int add_min = fees[2];
  int add_fee = fees[3];

  unordered_map<string, string> in_out_map;
  map<string, int> total_time_map;

  for (const string& row : records) {
    string number = row.substr(6, 4);
    if (row.substr(11) == "IN") {
      string time = row.substr(0, 5);
      in_out_map[number] = time;
    } else {  // "OUT"
      string in_time = in_out_map[number];
      string out_time = row.substr(0, 5);

      int out_hour = stoi(out_time.substr(0, 2));
      int out_min = stoi(out_time.substr(3, 2));
      int out_sum = out_hour * 60 + out_min;

      int in_hour = stoi(in_time.substr(0, 2));
      int in_min = stoi(in_time.substr(3, 2));
      int in_sum = in_hour * 60 + in_min;

      total_time_map[number] += out_sum - in_sum;
      in_out_map[number] = "24:00";  // out flag
    }
  }
  // "24:00"가 아닌 것들 골라서 출차처리
  int midnight = 23 * 60 + 59;
  for (const auto& row : in_out_map) {
    string in_time = row.second;
    if (in_time != "24:00") {
      int in_hour = stoi(in_time.substr(0, 2));
      int in_min = stoi(in_time.substr(3, 2));
      int in_sum = in_hour * 60 + in_min;

      total_time_map[row.first] += midnight - in_sum;
    }
  }

  vector<int> answer;
  answer.reserve(total_time_map.size());
  for (const auto& [number, time] : total_time_map) {
    if (time <= base_min) answer.push_back(base_fee);
    else {
      int rest = time - base_min;
      int add = rest % add_min == 0 ? (rest / add_min) : (rest / add_min + 1);
      answer.push_back(base_fee + add * add_fee);
    }
  }
  return answer;
}