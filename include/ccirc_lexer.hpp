#ifndef CCIRC_LEXER_HPP
#define CCIRC_LEXER_HPP

#include <string>
#include <lexer.hpp>

using namespace Designar;

Lexer make_lexer();

DynArray<Token> tokenize_without_spaces(const Lexer& lexer,
                                        const std::string& input);

#endif