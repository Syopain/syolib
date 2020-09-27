#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
#include <initializer_list>
#include <string>
#include <stdexcept>
#include <memory>
#include <list>

namespace syo {

    template <typename T> struct ListNode {
        T data{};
        std::shared_ptr<ListNode> next = nullptr;
        ListNode(const T& data = T{}, std::shared_ptr<ListNode> next = nullptr)
            : data(data), next(next) { }
    };

    template <typename T> class ForwardList {
    public:
        using size_type = unsigned long long;

        ForwardList();
        ForwardList(const ForwardList<T>& from);
        ForwardList(size_type size, const T& val = T{});
        ForwardList(std::initializer_list<T> il);
        ForwardList& operator=(const ForwardList& from);
    private:
        ListNode<T> head_;

        void copy(const ForwardList<T>& from);

        //TODO
    };

}

#endif // FORWARD_LIST_H
