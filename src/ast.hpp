#pragma once

#include "mystl.hpp"
#include <memory>

class Node
{
public:
    my::string value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    // Constructor, Copy/Move Constructors, Destructor
    Node(const std::string& val) : value(val) {}
    Node(const Node& n) : value(n.value) {}
    Node(Node&& n) noexcept : value(std::move(n.value)) {}
    ~Node() = default;

    // Methods
    void add_left(const my::string& val) 
    {
        left = std::make_unique<Node>(val);
    }
    void add_right(const my::string& val) 
    {
        right = std::make_unique<Node>(val);
    }
};


class Ast
{
private:
    std::unique_ptr<Node> m_root;
    void print_tree(Node* node, int depth) const;

public:
    Ast() = default;
    void init(const std::string& rootValue);
    void add_children_to_root(const std::string& leftValue, const std::string& rightValue);
    void traverse(const Node* node, void (*visit)(const Node*)) const;
    void print() const;
    const Node* get_root() const;
};
