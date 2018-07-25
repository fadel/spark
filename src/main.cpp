#include <cmath>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

const char *TICKS[] = {"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█"};
const size_t NUM_TICKS = 8;
const double EPSILON = 1e-8;

template<typename T>
void sparkify(const std::vector<T> &values, std::ostream &out) {
    auto minmax = std::minmax_element(values.begin(), values.end());
    auto min = *minmax.first,
         max = *minmax.second;
    auto values_range = max - min;

    if (abs(values_range) < EPSILON) {
        auto it = std::ostream_iterator<const char *>(out);
        std::fill_n(it, values.size(), TICKS[0]);
    } else {
        auto coef = (NUM_TICKS - 1) / values_range;
        for (const T &x: values) {
            out << TICKS[(size_t) round((x - min) * coef)];
        }
    }
}

int main()
{
    std::vector<double> values;
    for (double value; std::cin >> value;) {
        values.push_back(value);
    }
    if (!std::cin.eof() && std::cin.fail()) {
        std::cerr << "Parse error" << std::endl;
        return 1;
    }
    if (values.empty()) {
        return 0;
    }

    sparkify(values, std::cout);
    std::cout << std::endl;
    return 0;
}
