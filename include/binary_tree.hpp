#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <cmath>
#include <queue>
#include <iostream>
#include "binary_tree.h"
#include "algorithm.h"

namespace syo {

    template <typename T>
    BinaryTreeNode<T>::BinaryTreeNode(T const& data, pNode left, pNode right) :
        data_(data),
        left_(left),
        right_(right)
    {

    }

    template <typename T>
    void BinaryTree<T>::preOrderTraversal(std::function<void (T&)> func)
    {
        pNode p = root_;
        Stack<pNode> s;
        s.push(nullptr);
        while (p) {
            func(p->data_);
            if (p->right_) {
                s.push(p->right_);
            }
            if (p->left_) {
                p = p->left_;
            }
            else {
                p = s.top();
                s.pop();
            }
        }
    }

    template <typename T>
    void BinaryTree<T>::inOrderTraversal(std::function<void (T&)> func)
    {
        pNode p = root_;
        Stack<pNode> s;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left_;
            }
            if (!s.empty()) {
                p = s.top();
                s.pop();
                func(p->data_);
                p = p->right_;
            }
        }
    }

    template <typename T>
    void BinaryTree<T>::postOrderTraversal(std::function<void (T&)> func)
    {
        Stack<pNode> reverse;
        pNode p = root_;
        Stack<pNode> s;
        s.push(nullptr);
        while (p) {
            reverse.push(p);
            if (p->left_) {
                s.push(p->left_);
            }
            if (p->right_) {
                p = p->right_;
            }
            else {
                p = s.top();
                s.pop();
            }
        }
        while (!reverse.empty()) {
            p = reverse.top();
            reverse.pop();
            func(p->data_);
        }
    }

    template <typename T>
    void BinaryTree<T>::levelOrderTraversal(std::function<void (T&)> func)
    {
        if (empty()) return;

        std::queue<pNode> q;
        q.push(root_);
        while (!q.empty()) {
            pNode p = q.front();
            q.pop();
            func(p->data_);
            if (p->left_) q.push(p->left_);
            if (p->right_) q.push(p->right_);
        }
    }

    template <typename T>
    size_t BinaryTree<T>::nodeNum() const
    {
        if (empty()) return 0;

        return left().nodeNum() + right().nodeNum() + 1;
    }

    template <typename T>
    size_t BinaryTree<T>::height() const
    {
        if (empty()) return 0;

        return max(left().height(), right().height()) + 1;
    }

    template <typename T>
    void BinaryTree<T>::print(size_t space) const
    {
        if (empty()) return;

        right().print(space + 5);
        std::cout << std::string(space, ' ') << root_->data_ << std::endl;
        left().print(space + 5);
    }

}

#endif // BINARY_TREE_HPP
