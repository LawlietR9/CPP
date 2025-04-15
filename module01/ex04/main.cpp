#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void replaceString(std::string &content, const std::string &s1, const std::string &s2) {
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char **argv) {
    if (argc != 4)
    {
        std::cout << "Invalid number of arguments" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream ifs(filename);
    if (!ifs.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }
    std::ostringstream buf;
    buf << ifs.rdbuf();
    std::string content = buf.str();
    ifs.close();
    replaceString(content, s1, s2);
    std::ofstream ofs(filename + ".replace");
    if (!ofs.is_open())
    {
        std::cout << "Failed to create file" << std::endl;
        return 1;
    }
    ofs << content;
    ofs.close();
    return 0;
}