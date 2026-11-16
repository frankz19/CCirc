#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "ccirc_lexer.hpp"
#include "ccirc_parser.hpp"
#include "tree_printer.hpp"

std::string read_file(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open input file: " + path);
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::string default_input()
{
    return
        "// Basic RC charging circuit\n"
        "circuit MyRCCircuit {\n"
        "    source V1;\n"
        "    source V1.volt = 12;\n"
        "    source V1.wave = sine;\n"
        "    resistor R1 = 100 ohm;\n"
        "    capacitor C1 = 0.000001;\n"
        "    switch S1 = true;\n"
        "\n"
        "    // Series connection forming a closed loop\n"
        "    V1.positivePole => S1.poleAlpha;\n"
        "    S1.poleBeta => R1.poleAlpha;\n"
        "    R1.poleBeta => C1.poleAlpha;\n"
        "    C1.poleBeta => V1.negativePole;\n"
        "}\n";
}

int main(int argc, char* argv[])
{
    try
    {
        const std::string input = (argc > 1) ? read_file(argv[1]) : default_input();

        Grammar grammar = make_grammar();
        LLParser parser(grammar);
        Lexer lexer = make_lexer();

        DynArray<Token> tokens = tokenize_without_spaces(lexer, input);
        ParseTreeNode* tree = parser.parse(tokens);

        std::cout << "Input:\n" << input << '\n';

        std::cout << "Syntax tree per expression:\n";
        nat_t expression_count = 0;
        print_expression_trees(tree, expression_count);

        std::cout << "Full program parse tree:\n";
        print_tree(tree);

        ParseTreeNode::destroy_tree(tree);
    }
    catch (const std::runtime_error& error)
    {
        std::cerr << "Error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}