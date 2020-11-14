#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP
#include <cmath>
#include <queue>
#include <iostream>
#include <map>
#include <sstream>
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
    void BinaryTree<T>::printVertical(size_t d, size_t h, size_t space) const
    {
        if (h == 0) {
            h = height();
        }
        if (empty()) {
            if (d < h) {
                printVertical(d + 1, h, space + 5);
                printVertical(d + 1, h, space + 5);
                std::cout << std::endl;
            }
            return;
        }

        right().printVertical(d + 1, h, space + 5);
        std::cout << std::string(space, ' ') << root_->data_ << std::endl;
        left().printVertical(d + 1, h, space + 5);
    }

    template <typename T>
    void BinaryTree<T>::printIndex() const
    {
        std::map<int, pNode> all_nodes;
        all_nodes[0] = root_;
        for (auto iter = all_nodes.begin(); iter != all_nodes.end(); ++iter) {
            if (iter->second->left_)
                all_nodes[iter->first * 2 + 1] = iter->second->left_;
            if (iter->second->right_)
                all_nodes[iter->first * 2 + 2] = iter->second->right_;
            std::cout << "  " << iter->first << ": " << iter->second->data_ << std::endl;
        }
    }

    template <typename T>
    void BinaryTree<T>::printHorizontal() const
    {
        std::map<int, pNode> all_nodes;
        all_nodes[0] = root_;
        size_t row = 0, col = 0;
        for (auto iter = all_nodes.begin(); iter != all_nodes.end(); ++iter) {
            if (iter->second->left_)
                all_nodes[iter->first * 2 + 1] = iter->second->left_;
            if (iter->second->right_)
                all_nodes[iter->first * 2 + 2] = iter->second->right_;

            if (row < static_cast<size_t>(std::log2(iter->first + 1))) {
                std::cout << std::endl << std::endl;
                ++row;
                col = 0;
            }
            if (col == 0) {
                auto space = std::pow(2, height() - 1 - row) - 1;
                std::cout << std::string(space * 3, ' ');
            }
            auto offset = iter->first - (std::pow(2, row)-1);
            auto step = std::pow(2, height() - row);
            std::cout << std::string((offset * step - col) * 3, ' ');
            std::cout << " " << iter->second->data_ << " ";
            col = offset * step + 1;
        }
        std::cout << '\n' << std::endl;
    }

    template <typename T>
    void BinaryTree<T>::printWireframe() const
    {
        std::ostringstream frame_buf;
        std::ostringstream node_buf;

        std::map<int, pNode> all_nodes;
        all_nodes[0] = root_;
        size_t row = 0, col = 0;
        for (auto iter = all_nodes.begin(); iter != all_nodes.end(); ++iter) {
            if (iter->second->left_)
                all_nodes[iter->first * 2 + 1] = iter->second->left_;
            if (iter->second->right_)
                all_nodes[iter->first * 2 + 2] = iter->second->right_;

            if (row < static_cast<size_t>(std::log2(iter->first + 1))) {
                std::cout << frame_buf.str() << std::endl << node_buf.str() << std::endl;
                frame_buf.str("");
                node_buf.str("");
                ++row;
                col = 0;
            }
            if (col == 0) {
                auto space = std::pow(2, height() - 1 - row) - 1;
                frame_buf << std::string(space * 3, ' ');
                node_buf << std::string(space * 3, ' ');
            }
            if (iter->first == 0) {
                node_buf << " " << iter->second->data_ << " ";
                continue;
            }

            int offset = iter->first - (iter->first + 1) % 2 - (std::pow(2, row)-1);
            auto step = std::pow(2, height() - row);
            if (offset * step > col) {
                frame_buf << std::string((offset * step - col) * 3, ' ');
                node_buf << std::string((offset * step - col) * 3, ' ');
                col = offset * step;
            }

            if (iter->first % 2) {
                frame_buf << " ┌─";
                node_buf << " " << iter->second->data_ << " ";
                ++col;
                for (int i = 0; i < step / 2 - 1; ++i) {
                    frame_buf << "───";
                    node_buf << "   ";
                    ++col;
                }
                frame_buf << (all_nodes.find(iter->first + 1) == all_nodes.end() ? "─┘ " : "─┴─");
                node_buf << "   ";
                ++col;
            }
            else {
                if (all_nodes.find(iter->first - 1) == all_nodes.end()) {
                    for (int i = 0; i < step / 2; ++i) {
                        frame_buf << "   ";
                        node_buf << "   ";
                        ++col;
                    }
                    frame_buf << " └─";
                    node_buf << "   ";
                    ++col;
                }

                for (int i = 0; i < step / 2 - 1; ++i) {
                    frame_buf << "───";
                    node_buf << "   ";
                    ++col;
                }
                frame_buf << "─┐ ";
                node_buf << " " << iter->second->data_ << " ";
                ++col;
            }
        }
        std::cout << frame_buf.str() << std::endl << node_buf.str() << '\n' << std::endl;
    }
}

#endif // BINARY_TREE_HPP
