#include <iostream>
#include <sstream>
#include <numeric>
#include "vector.h"

std::string split_string(std::string const& str)
{
    std::istringstream iss(str);
    std::ostringstream oss;
    syo::Vector<double> dvec;
    syo::Vector<std::string> svec;
    double d;
    char c;
    std::string s;

    while(iss.peek() != EOF) {
        if (isdigit(iss.peek())) {
            if (!s.empty()) {
                svec.push_back(s);
                s.clear();
            }
            iss >> d;
            dvec.push_back(d);
        }
        if (iss.peek() != EOF) {
            iss >> c;
            s += c;
        }
    }

    if (!s.empty()) {
        svec.push_back(s);
        s.clear();
    }

    oss << "Ô­Ê¼×Ö·û´®: " + str << std::endl;
    oss << "×ÖÄ¸´®: ";
    for (auto const& word : svec) {
        oss << word << ' ';
    }
    oss << std::endl;
    oss << "Êý×Ö´®: ";
    for (auto const& d : dvec) {
        oss << d << ' ';
    }
    oss << std::endl;
    oss << "Êý×Ö´®µÄºÍ: " << std::accumulate(dvec.begin(), dvec.end(), 0.0) << std::endl;
    return oss.str();
}

static void design_7_1()
{
    std::cout << "Design_7_1:\n" << std::endl;
    std::cout << split_string("CAT50.2DOG200.9TIGER2LION73.5") << std::endl;
    std::cout << split_string(".pai3.14159.abc12.34.567xyz58.9uv") << std::endl;
}

void design_7()
{
    design_7_1();
}
