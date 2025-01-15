#include "lexer.hpp"

bool Lexer::set_line_number(size_t num)
{
    if (num < this->m_lines.size()) {
        this->m_current = num;
        return true;
    }
    return false;
}

size_t Lexer::increment_line()
{
    return ++this->m_current;
}

my::string Lexer::current_line()
{
    if (this->m_current >= this->m_lines.size()) {
        throw std::runtime_error("Current line index out of bounds.");
    }
    return this->m_lines[this->m_current];
}

size_t Lexer::count_current_tabs()
{
    my::string current_line = this->current_line();
    size_t result = 0;
    //! eventually figure out why range loop can't find begin() for my::string
    for (char c : current_line.str()) {
        if (c != '\t') break;
        result++;
    }
    return result;
}
