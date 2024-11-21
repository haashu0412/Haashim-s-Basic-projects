#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

struct BS {
    unordered_map<int, int> map;
    int fpos;

    bool n(int pos) const {
        return map.find(pos) == map.end();
    }

    int a(int pos) const {
        return n(pos) ? pos : map.at(pos);
    }

    bool R(const vector<int>& DR) const {
        int position = 1;
        for (int roll : DR) {
            position += roll;
            if (position > 100) break;
            position = a(position);
        }
        return position == fpos;
    }
};

string fault(const BS& org, const vector<int>& DR) {
    for (const auto& [c, d] : org.map) {
        BS change = org;
        change.map.erase(c);
        if (change.R(DR)) {
            string res = (d < c) ? "SNAKE" : "LADDER";
            return res + " (" + to_string(c) + "->" + to_string(d) + ")";
        }
    }
    if (org.R(DR)) {
        return "Not Affected";
    }
    return "Not Reachable";
}

int main() {
    int num;
    cin >> num;

    BS b;
    for (int i = 0; i < num; ++i) {
        int s, e;
        cin >> s >> e;
        b.map[s] = e;
    }

    vector<int> DR;
    string line;
    cin.ignore();
    getline(cin, line);
    stringstream S(line);
    int roll;
    while (S >> roll) {
        DR.push_back(roll);
    }

    cin >> b.fpos;
    cout << fault(b, DR) << endl;
    return 0;
}
