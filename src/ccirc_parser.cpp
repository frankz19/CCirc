#include "ccirc_parser.hpp"

Grammar make_grammar()
{
    Grammar g;
    g.set_start_symbol("Program");

    g.add_production("Program", Grammar::Sequence({"StmtList"}));

    g.add_production("StmtList", Grammar::Sequence({"Stmt", "StmtList"}));
    g.add_production("StmtList", Grammar::Sequence());

    g.add_production("Stmt",
                     Grammar::Sequence({"TYPE_TOKEN", "IDENTIFIER_TOKEN", "TypeStmtTail"}));
    g.add_production("Stmt",
                     Grammar::Sequence({"CONTROL_TOKEN", "LPAREN", "Expr", "RPAREN",
                                        "LBRACE", "StmtList", "RBRACE"}));

                                        
    g.add_production("Stmt",
                     Grammar::Sequence({"IDENTIFIER_TOKEN", "OptMember", "IdStmtTail"}));
    g.add_production("Stmt",
                     Grammar::Sequence({"NUMBER_TOKEN", "OptUnit", "TermPrime",
                                        "ExprPrime", "SEMI_TOKEN"}));
    g.add_production("Stmt",
                     Grammar::Sequence({"LPAREN", "Expr", "RPAREN", "TermPrime",
                                        "ExprPrime", "SEMI_TOKEN"}));
    g.add_production("Stmt",
                     Grammar::Sequence({"MINUS_TOKEN", "Factor", "TermPrime",
                                        "ExprPrime", "SEMI_TOKEN"}));

    g.add_production("TypeStmtTail",
                     Grammar::Sequence({"LBRACE", "StmtList", "RBRACE"}));
    g.add_production("TypeStmtTail",
                     Grammar::Sequence({"SEMI_TOKEN"}));
    g.add_production("TypeStmtTail",
                     Grammar::Sequence({"EQUAL_TOKEN", "Expr", "SEMI_TOKEN"}));
    g.add_production("TypeStmtTail",
                     Grammar::Sequence({"DOT_TOKEN", "Member", "EQUAL_TOKEN",
                                        "Expr", "SEMI_TOKEN"}));

    g.add_production("IdStmtTail",
                     Grammar::Sequence({"CONNECT_TO_TOKEN", "IDENTIFIER_TOKEN",
                                        "OptMember", "SEMI_TOKEN"}));
    g.add_production("IdStmtTail",
                     Grammar::Sequence({"EQUAL_TOKEN", "Expr", "SEMI_TOKEN"}));
    g.add_production("IdStmtTail",
                     Grammar::Sequence({"TermPrime", "ExprPrime", "SEMI_TOKEN"}));

    g.add_production("Expr", Grammar::Sequence({"Term", "ExprPrime"}));

    g.add_production("ExprPrime",
                     Grammar::Sequence({"PLUS_TOKEN", "Term", "ExprPrime"}));
    g.add_production("ExprPrime",
                     Grammar::Sequence({"MINUS_TOKEN", "Term", "ExprPrime"}));
    g.add_production("ExprPrime", Grammar::Sequence());

    g.add_production("Term", Grammar::Sequence({"Factor", "TermPrime"}));

    g.add_production("TermPrime",
                     Grammar::Sequence({"TIMES_TOKEN", "Factor", "TermPrime"}));
    g.add_production("TermPrime",
                     Grammar::Sequence({"DIV_TOKEN", "Factor", "TermPrime"}));
    g.add_production("TermPrime", Grammar::Sequence());

    g.add_production("Factor", Grammar::Sequence({"NUMBER_TOKEN", "OptUnit"}));
    g.add_production("Factor", Grammar::Sequence({"WAVE_TOKEN"}));
    g.add_production("Factor", Grammar::Sequence({"CONTROL_TOKEN"}));
    g.add_production("Factor", Grammar::Sequence({"IDENTIFIER_TOKEN", "OptMember"}));
    g.add_production("Factor", Grammar::Sequence({"TYPE_TOKEN"}));
    g.add_production("Factor", Grammar::Sequence({"MINUS_TOKEN", "Factor"}));
    g.add_production("Factor", Grammar::Sequence({"LPAREN", "Expr", "RPAREN"}));

    g.add_production("OptUnit", Grammar::Sequence({"SCALE_TOKEN", "OptUnitTail"}));
    g.add_production("OptUnit", Grammar::Sequence({"UNIT_TOKEN"}));
    g.add_production("OptUnit", Grammar::Sequence());

    g.add_production("OptUnitTail", Grammar::Sequence({"UNIT_TOKEN"}));
    g.add_production("OptUnitTail", Grammar::Sequence());

    g.add_production("OptMember", Grammar::Sequence({"DOT_TOKEN", "Member"}));
    g.add_production("OptMember", Grammar::Sequence());

    g.add_production("Member", Grammar::Sequence({"POLE_TOKEN"}));
    g.add_production("Member", Grammar::Sequence({"UNIT_TOKEN"}));
    g.add_production("Member", Grammar::Sequence({"WAVE_TOKEN"}));
    g.add_production("Member", Grammar::Sequence({"IDENTIFIER_TOKEN"}));

    return g;
}