#include <iostream>
#include <string>
#include <stdexcept>

#include <polygon.hpp>
#include <algorithm.hpp>

using rhombus = basic_polygon<point2d, 4>;
using pentagon = basic_polygon<point2d, 5>;
using hexagon = basic_polygon<point2d, 6>;

using rhombus_tuple = std::tuple<point2d, point2d, point2d, point2d>;
using pentagon_tuple = std::tuple<point2d, point2d, point2d, point2d, point2d>;
using hexaagon_tuple = std::tuple<point2d, point2d, point2d, point2d, point2d, point2d>;

void read_rhombus(std::istream& in, rhombus& rhomb) {
    auto constexpr precision = 0.000000001L;
    for (auto& p : rhomb) {
        in >> p;
    }
    if (in.fail()) {
        return;
    }

    double dist = distance(rhomb[0], rhomb[rhomb.size() - 1]);
    for (size_t i = 0; i < rhomb.size() - 1; i++) {
        double next = distance(rhomb[i], rhomb[i + 1]);
        if (std::abs(dist - next) > precision) {
            in.setstate(std::ios::failbit);
            break;
        }
    }
}

void process_tuple(std::istream& in, std::ostream& out) {
    size_t num_of_angles;

    in >> num_of_angles;
    switch (num_of_angles) {
    case 4: {
        rhombus r;
        read_rhombus(in, r);
        if (in.fail()) {
            throw std::runtime_error("tetragon is not a rhombus");
        }

        auto [a, b, c, d] = r;
        print2d(out, std::tuple{ a, b, c, d });

        break;
    }

    case 5: {
        pentagon fig(in);

        auto [a, b, c, d, e] = fig;
        print2d(out, std::tuple{ a, b, c, d, e });

        break;
    }

    case 6: {
        hexagon fig(in);

        auto [a, b, c, d, e, f] = fig;
        print2d(out, std::tuple{ a, b, c, d, e, f });

        break;
    }

    default:
        throw std::runtime_error("incorrect number of angles");
    }
}

void process_type(std::istream& in, std::ostream& out) {
    std::string type;
    
    in >> type;
    if (type == "rhombus") {
        rhombus r;
        read_rhombus(in, r);
        if (in.fail()) {
            throw std::runtime_error("tetragon is not a rhombus");
        }
        print2d(out, r);
    }
    else if (type == "pentagon") {
        pentagon fig(in);
        print2d(out, fig);
    }
    else if (type == "hexagon") {
        hexagon fig(in);
        print2d(out, fig);
    } else {
        throw std::runtime_error("unknown type");
    }
}

int main() {
    using std::string;
    using std::cin;
    using std::cout;
    using std::cerr;
    using std::endl;

    string mode;
    while (cin) {
        mode.clear();
        cin >> mode;
        try {
            if (mode == "tuple") {
                process_tuple(cin, cout);
            }
            else if (mode == "type") {
                process_type(cin, cout);
            }
            else {
                cout << "incorrect mode: " << mode << endl;
            }
        }
        catch (std::exception& e) {
            cerr << "error: " << e.what() << endl;
        }
    }
}
