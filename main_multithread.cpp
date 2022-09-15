#include <array>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <execution>
#include <iostream>


std::array<double, 10000> make_data() {
    std::array<double, 10000> big_data = {};
    std::generate(big_data.begin(), big_data.end(), [n = 0.1]() mutable { return n += 0.0001; });
    return big_data;
}

int main() {

    auto bd1 = make_data();
    auto res = bd1;

    auto do_maths = [](double x) { return std::beta(std::expint(x), x) + std::beta(x, x) + std::legendre(12u, x); };

    // seq
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        std::transform(std::execution::seq, bd1.begin(), bd1.end(), res.begin(), do_maths);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::cout << "Time taken seq:\t\t" << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
                  << '\n';
    }

    // par
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        std::transform(std::execution::par, bd1.begin(), bd1.end(), res.begin(), do_maths);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::cout << "Time taken par:\t\t" << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
                  << '\n';
    }

    // unseq
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        std::transform(std::execution::unseq, bd1.begin(), bd1.end(), res.begin(), do_maths);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::cout << "Time taken unseq:\t\t" << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
                  << '\n';
    }

    // par_unseq
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        std::transform(std::execution::par_unseq, bd1.begin(), bd1.end(), res.begin(), do_maths);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::cout << "Time taken par_unseq:\t\t"
                  << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()
                  << '\n';
    }

    std::cout << res.at(9500);

    return 0;
}
