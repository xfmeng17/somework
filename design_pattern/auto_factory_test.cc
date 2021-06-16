#include "design_pattern/auto_factory.h"

int main() {
  std::cout << "start main...." << std::endl;

  action *login = factory::produce("login_action");
  action *rter = factory::produce("register_action");
  action *dter = factory::produce("deleter_action");
  login->do_action();
  rter->do_action();
  dter->do_action();

  delete (login);
  delete (rter);
  delete (dter);

  std::cout << "finish main...." << std::endl;
}