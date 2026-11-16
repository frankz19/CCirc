#include "ccirc_lexer.hpp"

Lexer make_lexer()
{
    Lexer lexer;

    const std::string digit = "(0|1|2|3|4|5|6|7|8|9)";
    const std::string lower = "(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z)";
    const std::string upper = "(A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z)";
    const std::string letter = "(" + lower + "|" + upper + ")";
    const std::string alnum = "(" + lower + "|" + upper + "|" + digit + ")";

    lexer.add_token("TYPE_TOKEN",
                    "circuit|source|resistor|capacitor|inductor|switch|time");
    lexer.add_token("POLE_TOKEN",
                    "poleAlpha|poleBeta|positivePole|negativePole");
    lexer.add_token("UNIT_TOKEN",
                    "volt|ohm|faraday|henry|ampere|second");
    lexer.add_token("SCALE_TOKEN",
                    "mili|micro");
    lexer.add_token("WAVE_TOKEN",
                    "sine|square|triangle");
    lexer.add_token("CONTROL_TOKEN",
                    "if|while|true|false");

    lexer.add_token("COMMENT",
                    "//(" + lower + "|" + upper + "|" + digit + "| |_|-|\\.|,|:|;)*");

    lexer.add_token("CONNECT_TO_TOKEN", "=>");
    lexer.add_token("EQUAL_TOKEN", "=");
    lexer.add_token("PLUS_TOKEN", "\\+");
    lexer.add_token("MINUS_TOKEN", "-");
    lexer.add_token("TIMES_TOKEN", "\\*");
    lexer.add_token("DIV_TOKEN", "/");
    lexer.add_token("DOT_TOKEN", "\\.");
    lexer.add_token("LPAREN", "\\(");
    lexer.add_token("RPAREN", "\\)");
    lexer.add_token("LBRACE", "\\{");
    lexer.add_token("RBRACE", "\\}");
    lexer.add_token("SEMI_TOKEN", ";");

    lexer.add_token("NUMBER_TOKEN",
                    digit + "+(\\." + digit + "+)?");
    lexer.add_token("IDENTIFIER_TOKEN",
                    letter + alnum + "*");
    lexer.add_token("WS", "( |\t|\n|\r)+");

    return lexer;
}

DynArray<Token> tokenize_without_spaces(const Lexer& lexer,
                                        const std::string& input)
{
    DynArray<Token> all = lexer.tokenize(input);
    DynArray<Token> tokens;

    for (nat_t i = 0; i < all.size(); ++i)
    {
        if (all[i].name != "WS" && all[i].name != "COMMENT")
        {
            tokens.append(all[i]);
        }
    }

    return tokens;
}