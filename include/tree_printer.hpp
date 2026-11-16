#ifndef TREE_PRINTER_HPP
#define TREE_PRINTER_HPP

#include <llparser.hpp>

using namespace Designar;

void print_tree(ParseTreeNode* node, nat_t depth = 0);

void print_expression_trees(ParseTreeNode* node, nat_t& index);

#endif