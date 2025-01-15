#pragma once

#include "mystl.hpp"
#include <exception>

class Lexer
{
private:
    // Fields
    my::string m_text;
    my::vector<my::string> m_lines;
    size_t m_current;

public:
    // Constructor, Copy/Move Constructors, Destructor
    Lexer(const my::string& text) 
        : m_text(text), m_lines(m_text.split("\n")), m_current(0) 
    {}
    Lexer(const Lexer& l) 
        : m_text(l.m_text), m_lines(l.m_lines), m_current(l.m_current) 
    {}
    Lexer(Lexer&& l) noexcept : 
        m_text(std::move(l.m_text)), 
        m_lines(std::move(l.m_lines)), 
        m_current(std::move(l.m_current)) 
    {}
    ~Lexer() = default;

    // Methods
    my::string current_line();
    size_t count_current_tabs();
    size_t increment_line();
    bool set_line_number(size_t num);
};

