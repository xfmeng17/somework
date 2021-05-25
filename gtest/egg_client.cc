#include "egg_client.h"

namespace GTestDemo {

std::string EggClient::Get(const std::string& key) {
  return key;
}
int EggClient::Post(const std::string& key, const std::string& val) {
  return 0;
}

}