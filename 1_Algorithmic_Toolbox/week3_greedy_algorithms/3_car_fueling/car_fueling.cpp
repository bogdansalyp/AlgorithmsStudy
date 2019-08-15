#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);
    // cout << "Vector: \n";
    // for (int i = 0; i < stops.size(); i++) {
    //     cout << stops[i] << " ";
    // }
    // cout << "\n";
    int numRefills = 0;
    int currentRefill = 0;
    int lastRefill = 0;
    while (currentRefill <= stops.size()) {
        lastRefill = currentRefill;
        while((currentRefill <= stops.size()) && (stops[currentRefill + 1] - stops[lastRefill] <= tank)) {
            currentRefill++;
        }
        // cout << "Refilled at " << stops[currentRefill] << "\n";
        if (currentRefill == lastRefill) {
            return -1;
        }
        if (currentRefill <= stops.size()) {
            numRefills++;
        }
    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
