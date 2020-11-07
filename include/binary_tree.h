#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <string>
#include <stdexcept>
#include <memory>
#include <functional>
#include "stack.h"

namespace syo {

    template <typename T>
    class BinaryTree;

    template<typename T>
    class BinaryTreeNode {
    public:
        using pNode = std::shared_ptr<BinaryTreeNode<T>>;
        BinaryTreeNode(T const& data = T{}, pNode left = nullptr, pNode right = nullptr);
    private:
        T data_{};
        pNode left_;
        pNode right_;

        friend class BinaryTree<T>;
    };

    template <typename T>
    class BinaryTree {
    public:
        using pNode = std::shared_ptr<BinaryTreeNode<T>>;
        BinaryTree() = default;
        BinaryTree(T const& data) : root_(std::make_shared<BinaryTreeNode<T>>(data)) { }

        bool empty() const { return root_ == nullptr; }
        bool isLeaf() const { return root_->left_ == nullptr && root_->right_ == nullptr; }
        BinaryTree left() const { return BinaryTree(root_->left_); }
        BinaryTree right() const { return BinaryTree(root_->right_); }
        BinaryTree setLeft(BinaryTree<T> const& tree) { return BinaryTree(root_->left_ = tree.root_); }
        BinaryTree setRight(BinaryTree<T> const& tree) { return BinaryTree(root_->right_ = tree.root_); }
        void preOrderTraversal(std::function<void (T&)> func);
        void inOrderTraversal(std::function<void (T&)> func);
        void postOrderTraversal(std::function<void (T&)> func);
        void levelOrderTraversal(std::function<void (T&)> func);
        size_t nodeNum() const;
        size_t height() const;
        void print(size_t space = 0) const;

    private:
        pNode root_;

        BinaryTree(pNode node) : root_(node) { }

    };

}

#include "binary_tree.hpp"
#endif // BINARY_TREE_H
