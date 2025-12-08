#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
   if (ac != 4) {
    std::cerr << "Usage: ./Sed <filename> <s1> <s2>\n";
    return 1;
   }

   std::string filename = av[1];
   std::string s1 = av[2];
   std::string s2 = av[3];
   if (s1.empty()) {
    std::cerr << "Error: s1 cannot be empty\n";
    return 1;
   }

   std::ifstream inputfile(filename.c_str());
   if (!inputfile.is_open()) {
    std::cerr << "Error: cannot open input file\n";
    return 1;
   }

   std::string content;
   std::string line;
   while (std::getline(inputfile, line)) {
    content += line;
    if (!inputfile.eof())
        content += "\n";
   }
   inputfile.close();

   size_t pos = 0;
   while ((pos = content.find(s1, pos)) != std::string::npos) {
    content.erase(pos, s1.length());
    content.insert(pos, s2);
    pos += s2.length();
   }

   std::string outname = filename + ".replcae";
   std::ofstream outputfile(outname.c_str());
   if (!outputfile.is_open()) {
    std::cerr << "Error: cannot open output file\n";
    return 1;
   }
   outputfile << content;
   outputfile.close();
   return 0;
}