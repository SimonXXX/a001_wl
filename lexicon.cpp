#include "include/lexicon.h"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <unordered_set>

using namespace std;

void Error(const std::string& message) {
  std::cout << message << std::endl;
  std::cin.get();
  std::exit(1);
}