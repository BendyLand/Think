#include "utils.hpp"

my::string read_file(const my::string& path)
{
    my::string result = "";
    std::fstream file(path);
    if (!file.is_open()) {
        std::cout << "There was a problem opening the file." << std::endl;
        exit(1);
    }
    char c;
    while (file.get(c)) result.push(c);
    return result;
}

