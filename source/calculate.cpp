#include <string>
#include <map>
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <vector>
#include "stack.h"

namespace syo {

    /**
     * @brief 返回运算符的优先级
     */
    static inline int precedence(char oper) {
        switch (oper) {
            case '+':
            case '-': return 1;
            case '*':
            case '/': return 2;
            case '^': return 4;
            case '(': return 100;
            default: throw std::invalid_argument(std::string("invalid operator ") + oper + "!");
        }
    }

    /**
     * @brief 把中缀表达式转为后缀表达式
     * @param infix: 中缀表达式
     * @return 后缀表达式
     */
    std::string toSuffix(std::string const& infix)
    {
        std::string ret;
        Stack<char> operator_stack;
        for (auto iter = infix.begin(); iter != infix.end(); ++iter) {
            if (isdigit(*iter) || *iter == '.') {
                ret += *iter;
                while (++iter != infix.end() && (isdigit(*iter) || *iter == '.')) {
                    ret += *iter;
                }
                ret += ' ';
                if (iter == infix.end()) {
                    break;
                }
            }
            switch (*iter) {
                case ')': {
                    while (operator_stack.top() != '(') {
                        ret += operator_stack.top();
                        operator_stack.pop();
                        ret += ' ';
                    }
                    operator_stack.pop();   //pop '('
                    break;
                }
                case '+':
                case '-':
                case '*':
                case '/': {     //左结合率运算符
                    while (!operator_stack.empty()
                           && operator_stack.top() != '('
                           && precedence(operator_stack.top()) >= precedence(*iter)) {
                        ret += operator_stack.top();
                        operator_stack.pop();
                        ret += ' ';
                    }
                    operator_stack.push(*iter);
                    break;
                }
                case '(':
                case '^': {     //右结合率运算符
                    while (!operator_stack.empty()
                           && operator_stack.top() != '('
                           && precedence(operator_stack.top()) > precedence(*iter)) {
                        ret += operator_stack.top();
                        operator_stack.pop();
                        ret += ' ';
                    }
                    operator_stack.push(*iter);
                    break;
                }
                case ' ':
                case '=':
                    break;
                default: throw std::invalid_argument(std::string("invalid operator \"") + *iter + "\"!");
            }
        }
        // 将运算符栈剩余元素弹出
        while (!operator_stack.empty()) {
            ret += operator_stack.top();
            operator_stack.pop();
            ret += ' ';
        }

        return ret;
    }

    double calculate(std::string const& expr)
    {
        std::string suffix = toSuffix(expr);
        std::istringstream iss(suffix);
        Stack<double> result_stack;
        double lhs, rhs;
        double number;
        char op;
        while (iss.peek() != EOF) {
            if (isdigit(iss.peek()) || iss.peek() == '.') {
                iss >> number >> std::ws;
                result_stack.push(number);
            }
            else {
                iss >> op >> std::ws;
                rhs = result_stack.top();
                result_stack.pop();
                lhs = result_stack.top();
                result_stack.pop();
                switch (op) {
                    case '+': result_stack.push(lhs + rhs);
                        break;
                    case '-': result_stack.push(lhs - rhs);
                        break;
                    case '*': result_stack.push(lhs * rhs);
                        break;
                    case '/': result_stack.push(lhs / rhs);
                        break;
                    case '^': result_stack.push(pow(lhs, rhs));
                        break;
                    default: throw std::invalid_argument(std::string("invalid operator \"") + op + "\"!");
                        break;
                }
            }
        }

        return result_stack.top();
    }

}
