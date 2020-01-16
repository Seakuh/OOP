#include <iostream>
#include <fstream>
#include <streambuf>
#include <sstream>
#include <regex>
#include <string>

int main(int argc, char **argv)
{
    std::ofstream prot("webseiten.txt");
    std::string check = "<a href=\"";
    std::smatch m;
    const std::regex txt_regex("https?:\\/\\/(?:www\\.|(?!www))[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\\.[^\\s]{2,}|www\\.[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\\.[^\\s]{2,}|https?:\\/\\/(?:www\\.|(?!www))[a-zA-Z0-9]+\\.[^\\s]{2,}|www\\.[a-zA-Z0-9]+\\.[^\\s]{2,}");
    std::ifstream t("bookmarks_22.10.19.html");
    std::stringstream buffer;
    buffer << t.rdbuf();

    std::string textBig = buffer.str();
    std::string *ref = &textBig;

    while (std::regex_search(*ref, m, txt_regex))
    {
        for (std::string x : m)
        {
            std::cout << x << " ";
            prot << x << " " << std::endl;
            std::cout << std::endl;
            textBig = m.suffix().str();
        }
    }
}
