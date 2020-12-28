#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

std::string parse_string(std::string const& str)
{
    std::ostringstream oss;
    oss << "Ô­Ê¼×Ö·û´®: " + str << std::endl;
    int in_string = -1;
    syo::Stack<int> s;;
    for (size_t i = 0; i < str.length(); ++i) {
        switch (str[i]) {
            case '(' :
                if (in_string == -1)
                    s.push(i);
                break;
            case ')' :
                if (in_string == -1) {
                    if (!s.empty()) {
                        oss << "  Ð¡À¨ºÅ: " << str.substr(s.top(), i - s.top() + 1) << std::endl;
                        s.pop();
                    }
                    else {
                        oss << "  È±×óÀ¨ºÅ: " << str.substr(0, i + 1) << std::endl;
                    }
                }
                break;
            case '\'':
                if (in_string != -1) {
                    oss << "  ×Ö·û´®: " << str.substr(in_string, i - in_string + 1) << std::endl;
                    in_string = -1;
                }
                else {
                    in_string = i;
                }
                break;
        }
    }

    while (!s.empty()) {
        oss << "  È±ÓÒÀ¨ºÅ: " << str.substr(s.top()) << std::endl;
        s.pop();
    }
    return oss.str();
}

static void design_6_1()
{
    std::cout << "Design_6_1:\n" << std::endl;
    std::cout << parse_string("1(2)3'He(11()o'456") << std::endl;
    std::cout << parse_string("1(2(3)4)") << std::endl;
    std::cout << parse_string("12(34(56)78") << std::endl;
    std::cout << parse_string("12(34)567)8") << std::endl;
}

void design_6()
{
    design_6_1();
}
