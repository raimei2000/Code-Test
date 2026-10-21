// https://school.programmers.co.kr/learn/courses/30/lessons/42888
// 42888 오픈채팅방

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> parse_record(const string& r) {
  vector<string> result;
  istringstream iss(r);
  string part;
  while (iss >> part) {
    result.push_back(part);
  }
  return result;
}

vector<string> solution(vector<string> record) {
  vector<vector<string>> parsed_record;
  parsed_record.reserve(record.size());
  for (const string& r : record) {
    parsed_record.push_back(parse_record(r));
  }

  unordered_map<string, string> umap;
  for (auto it = parsed_record.rbegin(); it != parsed_record.rend(); it++) {
    const vector<string>& row = *it;
    if (row[0] != "Leave" && !umap.contains(row[1])) {
      umap.insert({row[1], row[2]});
    }
  }

  vector<string> answer;
  for (const vector<string>& row : parsed_record) {
    if (row[0] == "Change") {
      continue;
    }
    string s = umap[row[1]];
    s += (row[0] == "Enter") ? "님이 들어왔습니다." : "님이 나갔습니다.";
    answer.push_back(s);
  }
  return answer;
}