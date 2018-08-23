#include <cmath>
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

const std::array<const char *, 8> TICKS = {"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█"};
const double EPSILON = 1e-8;

template<typename InputIterator, typename OutputIterator>
void sparkify(InputIterator first, InputIterator last, OutputIterator &out) {
    auto minmax = std::minmax_element(first, last);
    auto min = *minmax.first,
         max = *minmax.second;
    auto values_range = max - min;

    if (values_range < EPSILON) {
        std::fill_n(out, last - first, TICKS[0]);
    } else {
        auto coef = (TICKS.size() - 1) / values_range;
        std::transform(first, last, out, [&](auto x) {
            return TICKS[(size_t) round((x - min) * coef)];
        });
    }
}

int main()
{
    std::istream_iterator<double> cin_it(std::cin), eos;
    std::vector<double> values(cin_it, eos);

    if (!std::cin.eof() && std::cin.fail()) {
        std::cerr << "Parse error" << std::endl;
        return 1;
    }
    if (values.empty()) {
        return 0;
    }

    std::ostream_iterator<const char *> cout_it(std::cout);
    sparkify(values.begin(), values.end(), cout_it);
    std::cout << std::endl;
    return 0;
}
