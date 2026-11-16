#include "tree_printer.hpp"

#include <iostream>

namespace
{
bool contains_stmt_list(ParseTreeNode* node)
{
    if (node == nullptr)
    {
        return false;
    }

    if (node->get_key().symbol == "StmtList")
    {
        return true;
    }

    ParseTreeNode* child = node->get_first_child();
    while (child != nullptr)
    {
        if (contains_stmt_list(child))
        {
            return true;
        }
        child = child->get_right_sibling();
    }

    return false;
}
}

void print_tree(ParseTreeNode* node, nat_t depth)
{
    if (node == nullptr)
    {
        return;
    }

    for (nat_t i = 0; i < depth; ++i)
    {
        std::cout << "  ";
    }

    std::cout << node->get_key().symbol;
    if (!node->get_key().lexeme.empty())
    {
        std::cout << " (\"" << node->get_key().lexeme << "\")";
    }
    std::cout << '\n';

    ParseTreeNode* child = node->get_first_child();
    while (child != nullptr)
    {
        print_tree(child, depth + 1);
        child = child->get_right_sibling();
    }
}

void print_expression_trees(ParseTreeNode* node, nat_t& index)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->get_key().symbol == "Stmt" && !contains_stmt_list(node))
    {
        ++index;
        std::cout << "Expression #" << index << ":\n";
        print_tree(node, 1);
        std::cout << '\n';
        return;
    }

    ParseTreeNode* child = node->get_first_child();
    while (child != nullptr)
    {
        print_expression_trees(child, index);
        child = child->get_right_sibling();
    }
}