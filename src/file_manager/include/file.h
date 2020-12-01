#pragma once
#include <optional>

class File
{
    std::string filename;

public:
    File(std::string filename);
    std::optional<std::string> read();
    bool write(std::string text);
    bool read_with_pattern(std::string text);
};
