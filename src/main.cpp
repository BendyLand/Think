#include "mystl.hpp"
#include "utils.hpp"
#include "lexer.hpp"
#include "ast.hpp"

using std::cout;
using std::endl;

int main()
{
    my::string test = read_file("../test.th");
    Lexer lexer(test);

    Ast ast;
    //todo: make the function to tokenize
    ast.init(lexer.current_line());
    lexer.increment_line();
    my::string val1 = lexer.current_line();
    lexer.increment_line();
    my::string val2 = lexer.current_line();
    ast.add_children_to_root(val1, val2);
    ast.print();

    return 0;
}

