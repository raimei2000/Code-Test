// https://school.programmers.co.kr/learn/courses/30/lessons/17683
// 17683 [3차] 방금그곡

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string parsed_m = "";
    int l = 0;
    while (l < m.length()) {
        if (l + 1 < m.length() && m[l + 1] == '#') {
            switch (m[l]) {
                case 'C': { parsed_m += "1"; break; }
                case 'D': { parsed_m += "2"; break; }
                case 'F': { parsed_m += "3"; break; }
                case 'G': { parsed_m += "4"; break; }
                case 'A': { parsed_m += "5"; break; }
            }
            l += 2;
        }
        else {
            parsed_m += m[l];
            l += 1;
        }
    }
    
    string answer = "";
    int answer_length = 0;
    
    for (int n = 0; n < musicinfos.size(); n++) {
        istringstream iss(musicinfos[n]);
        string token;
        int i = 0;
        int start_time = 0;
        int music_length = 0;
        string music_title = "";
        string music_notes = "";
        while (getline(iss, token, ',')) {
            if (i <= 1) { // 첫 두 개의 시간정보
                int length = stoi(token.substr(0, 2)) * 60;
                length += stoi(token.substr(3, 2));
                if (i == 0) { // 12:00
                    start_time = length;
                } else { // 12:10
                    length -= start_time;
                    music_length = length;
                }
            }
            else if (i == 2) { // title
                music_title = token;
            }
            else { // note per minute
                int j = 0;
                while (j < token.length()) {
                    if (j + 1 < token.length() && token[j + 1] == '#') {
                        switch (token[j]) {
                            case 'C': { music_notes += "1"; break; }
                            case 'D': { music_notes += "2"; break; }
                            case 'F': { music_notes += "3"; break; }
                            case 'G': { music_notes += "4"; break; }
                            case 'A': { music_notes += "5"; break; }
                        }
                        j += 2;
                    }
                    else {
                        music_notes += token[j];
                        j += 1;
                    }
                }
            }
            i++;
        }
        int n_repeat = music_length / music_notes.length();
        int n_remain = music_length % music_notes.length();
        string full_notes = "";
        for (int k = 0; k < n_repeat; k++) {
            full_notes += music_notes;
        }
        if (n_remain > 0) {
            full_notes += music_notes.substr(0, n_remain);
        }
        if (full_notes.find(parsed_m) != string::npos) {
            if (answer_length < music_length) {
                answer = music_title;
                answer_length = music_length;
            }
        }
    }
    
    return answer_length == 0 ? "(None)" : answer;
}
