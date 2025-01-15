#include "ast.hpp"

void Ast::print_tree(Node* node, int depth = 0) const 
{
    if (!node) return;
    print_tree(node->right.get(), depth + 1);
    std::cout << std::string(depth * 4, ' ') << node->value << std::endl;
    print_tree(node->left.get(), depth + 1);
}

void Ast::init(const std::string& root)
{
    this->m_root = std::make_unique<Node>(root);
}

void Ast::add_children_to_root(const std::string& left_val, const std::string& right_val)
{
    if (!this->m_root) {
        throw std::runtime_error("Root is not initialized.");
    }
    m_root->add_left(left_val);
    m_root->add_right(right_val);
}

void Ast::traverse(const Node* node, void (*visit)(const Node*)) const
{
    if (!node) return;
    visit(node);
    this->traverse(node->left.get(), visit);
    this->traverse(node->right.get(), visit);
}

void Ast::print() const
{
    if (!m_root) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }
    print_tree(m_root.get(), 0);
}

const Node* Ast::get_root() const
{
    return m_root.get();
}