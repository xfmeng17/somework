#include <iostream>
#include <sstream>

int main() {
  std::string str =
      "algorithm_author:seanyma_v2|context_fast_session_sinfo:enable|context_"
      "mfreq:enable|mini_cat_sta:enable";
  std::istringstream iss(str);
  std::string item = "";
  size_t pos = std::string::npos;
  while (std::getline(iss, item, '|')) {
    if ((pos = item.find(':')) != std::string::npos &&
        pos + 1 < item.length()) {
      std::cout << item.substr(0, pos) << "=" << item.substr(pos + 1)
                << std::endl;
    }
  }
  return 0;
}
