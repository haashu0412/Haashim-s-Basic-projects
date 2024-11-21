#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Line {
    int x1, y1, x2, y2;
};

int calculateCells(Line line, pair<int, int> point, bool closeToPoint) {
    if (line.x1 == line.x2) {
        return closeToPoint ? min(abs(point.second - line.y1), abs(point.second - line.y2)) + 1 
                            : abs(line.y2 - line.y1) + 1;
    } else {
        return closeToPoint ? min(abs(point.first - line.x1), abs(point.first - line.x2)) + 1 
                            : abs(line.x2 - line.x1) + 1;
    }
}

bool findIntersection(Line a, Line b, pair<int, int>& intersection) {
    if (a.x1 == a.x2 && b.y1 == b.y2) {
        if (b.x1 <= a.x1 && a.x1 <= b.x2 && a.y1 <= b.y1 && b.y1 <= a.y2) {
            intersection = {a.x1, b.y1};
            return true;
        }
    }
    if (a.y1 == a.y2 && b.x1 == b.x2) {
        if (a.x1 <= b.x1 && b.x1 <= a.x2 && b.y1 <= a.y1 && a.y1 <= b.y2) {
            intersection = {b.x1, a.y1};
            return true;
        }
    }
    return false;
}

int main() {
    int numLines, targetIntersections;
    cin >> numLines;

    vector<Line> lines(numLines);
    for (int i = 0; i < numLines; ++i) {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
        if (lines[i].x1 > lines[i].x2 || (lines[i].x1 == lines[i].x2 && lines[i].y1 > lines[i].y2)) {
            swap(lines[i].x1, lines[i].x2);
            swap(lines[i].y1, lines[i].y2);
        }
    }
    cin >> targetIntersections;

    map<pair<int, int>, vector<Line>> intersections;
    for (int i = 0; i < numLines; ++i) {
        for (int j = i + 1; j < numLines; ++j) {
            pair<int, int> intersectionPoint;
            if (findIntersection(lines[i], lines[j], intersectionPoint)) {
                intersections[intersectionPoint].push_back(lines[i]);
                intersections[intersectionPoint].push_back(lines[j]);
            }
        }
    }

    int totalStars = 0;
    for (const auto& entry : intersections) {
        if (static_cast<int>(entry.second.size() / 2) == targetIntersections) {
            vector<int> cellCounts;
            for (const auto& line : entry.second) {
                cellCounts.push_back(calculateCells(line, entry.first, true));
            }
            totalStars += *min_element(cellCounts.begin(), cellCounts.end());
        }
    }

    cout << totalStars << endl;
    return 0;
}
