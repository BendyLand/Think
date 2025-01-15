#include "mystl.hpp"
#include "utils.hpp"
#include "lexer.hpp"

using std::cout;
using std::endl;

int main()
{
    my::string test = read_file("../test.th");
    Lexer lexer(test);

    cout << lexer.current_line() << endl;
    lexer.set_line_number(9);
    cout << lexer.current_line() << endl;

    return 0;
}

