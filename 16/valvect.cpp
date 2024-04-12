#include <iostream>
#include <vector>
#include <valarray>
#include <algorithm>

int main() {
    using namespace std;
    vector<double> data;
    double temp;

    cout << "Enter numbers (<= 0 to quit):\n";
    while(cin >> temp && temp > 0) {
        data.push_back(temp);
    }
    sort(data.begin(), data.end());
    int size = data.size();
    valarray<double> numbers(size);
    int i;
    for(i = 0; i < size; i++) {
        numbers[i] = data[i];
    }
    valarray<double> sq_rts(size);
    sq_rts = sqrt(numbers);
    valarray<double> results(size);
    results = numbers + 2.0 * sq_rts;
    cout.setf(ios::fixed);
    cout.precision(2);
    for(i = 0; i < size; i++) {
        cout.width(5);
        cout << numbers[i] << ": ";
        cout.width(5);
        cout << results[i] << endl;
    }
    cout << "Done\n";
    return 0;
}