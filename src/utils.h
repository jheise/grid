#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
#include <boost/filesystem.hpp>

std::string find_file(const std::string&, const std::string&);
std::vector<std::string> split_string(const std::string&, const std::string&);
