#include <array>
#include <iostream>


int main() {

    // Almost always const
    {
        const double x = 1.23;
        double const y = 1.23;
    }

    // Cost and pointers
    {
        double *a;
        const double *b;
        double const *c;
        double *const d = new double;
        const double *const e = new double;
        double const *const f = new double;
    }

    return 0;
}

class Thing {
private:
    std::array<int, 3> m_data;

public:

    void update_data() {
        m_data.at(1) = 2;
    }

    void print_data() const {
        std::cout << m_data.at(0) << '\n';
        std::cout << m_data.at(1) << '\n';
        std::cout << m_data.at(2) << '\n';
    }
};