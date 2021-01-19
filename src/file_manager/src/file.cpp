#include <iostream>
#include <fstream>
#include "file.h"

File::File(std::string set_filename) : filename(set_filename) {}

std::optional<std::string> File::read()
{
    std::string text;
    std::ifstream file;

    file.open(filename.c_str());

    if (file.good()) {
        file >> text;
    }
    else {
        std::cout << "File " << filename << " can't be opened correctly" << std::endl;
        return std::nullopt;
    }

    file.close();
    return text;
}

bool File::write(std::string text)
{
    std::ofstream file;
    file.open(filename.c_str());

    if (file.good()) {
        file << text;
    }
    else {
        std::cout << "File can't be opened correctly" << std::endl;
        return false;
    }
    file.close();
    return true;
}

bool File::read_with_pattern(std::string text)
{
    std::ifstream file;
    file.open(filename.c_str());

    if( file.good() ){
        std::string filecontent;
        while( std::getline( file, filecontent ) )
            if (filecontent.find(text) != std::string::npos) {
                std::cout << filecontent << std::endl;
            }
        }
    else{
        return false;
    }
    file.close();
    return true;
}
