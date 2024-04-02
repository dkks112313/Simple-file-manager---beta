#pragma once

#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <algorithm>

namespace fs = std::filesystem;

std::string print(std::vector<std::string>& files);
void switch_command();
