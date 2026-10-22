#include <vector>

void makeVector();
void vectorAccess();
void vectorPassing(std::vector<int> expensive, std::vector<int> &cheap, const std::vector<int> &cheapConst);