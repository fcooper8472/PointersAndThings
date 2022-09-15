#include <array>
#include <iostream>
#include <map>
#include <memory>
#include <vector>


class BigThing {
private:
    std::array<double, 4096> m_big_data = {};
    std::string m_name;

public:
    explicit BigThing(std::string name = "") : m_name(std::move(name)) {
        std::cout << "BigThing constructor: " << m_name << '\n';
    }

    virtual ~BigThing() {
        std::cout << "BigThing destructor: " << m_name << '\n';
    }

    void print_name() {
        std::cout << m_name << '\n';
    }

    void print_address() {
        std::cout << this << '\n';
    }
};

void do_something(BigThing* bt) {
    std::cout << "Doing something with... ";
    bt->print_name();
}

int main() {

    // Creating some instances of a BigThing
    BigThing bt1("first");
    BigThing bt2("second");
    bt1.print_name();







    // Creating a pointer to a BigThing
    BigThing* p_bt;
    std::cout << p_bt << '\n';
    std::cout << &p_bt << '\n';






    // Construct a new big thing
    p_bt = new BigThing("pointer thing");
    std::cout << p_bt << '\n';
    p_bt->print_address();

    std::cout << &p_bt << '\n';


    (*p_bt).print_name();
    p_bt->print_name();






    // Destroy the big thing
    delete p_bt;








    // Use unique pointers at the point of creation
    std::unique_ptr<BigThing> up_bt(new BigThing("Unique ptr thing"));

    auto mu_bt = std::make_unique<BigThing>("make_unique thing");
    do_something(mu_bt.get());







    // Probably don't use shared pointers ***
    auto ms_bt = std::make_shared<BigThing>("make_shared thing");
    do_something(ms_bt.get());
    std::cout << ms_bt.use_count() << '\n';
    {
        auto ms_bt2 = ms_bt;
        std::cout << ms_bt.use_count() << '\n';
    }
    std::cout << ms_bt.use_count() << '\n';








    // But wherever possible, don't do your own memory management!
    std::array<double, 5> my_arr;
    std::vector<double> my_vec;
    std::map<int, std::string> my_map;


    return 0;
}
