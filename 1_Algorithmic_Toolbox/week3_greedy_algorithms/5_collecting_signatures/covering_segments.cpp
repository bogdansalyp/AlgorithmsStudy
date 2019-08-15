#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  while(segments.size() != 0) {
    // find a minimum end
    int min_end = 0;
    for (int i = 1; i < segments.size(); i++) {
      if (segments[i].end < segments[min_end].end) {
        min_end = i;
      }
    }
    points.push_back(segments[min_end].end);

    // delete all used segments
    vector<Segment> temp_segments;
    for (int i = 0; i < segments.size(); i++) {
      if ((segments[i].end < segments[min_end].end) || (segments[i].start > segments[min_end].end)) {
        temp_segments.push_back(segments[i]);
      }
    }
    segments = temp_segments;
  }
  
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
