#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <unordered_map>

class action {
 public:
  action() { std::cout << "$action" << std::endl; }
  virtual ~action() { std::cout << "~action" << std::endl; }

  virtual void do_action() { std::cout << "do_action......" << std::endl; }
};

class login_action : public action {
 public:
  login_action() { std::cout << "$login_action" << std::endl; }
  virtual ~login_action() { std::cout << "~login_action" << std::endl; }

  virtual void do_action() { std::cout << "login_action->do_action()" << std::endl; }
};

class register_action : public action {
 public:
  register_action() { std::cout << "$register_action" << std::endl; }
  virtual ~register_action() { std::cout << "~register_action" << std::endl; }
  virtual void do_action() { std::cout << "register_action->do_action()" << std::endl; }
};

class deleter_action : public action {
 public:
  deleter_action() = delete;
  deleter_action(const uint64_t& a, const std::string& s) {
    std::cout << "$deleter_action, a=" << a << ",s=" << s << std::endl;
    aaa = a;
    str = s;
  }
  virtual ~deleter_action() {
    std::cout << "~deleter_action, aaa=" << aaa << ",str=" << str << std::endl;
  }
  virtual void do_action() {
    std::cout << "deleter_action->do_action(), aaa=" << aaa << ",str=" << str << std::endl;
  }

 private:
  uint64_t aaa = 1;
  std::string str = "empty";
};

class factory {
 public:
  template <typename T>
  struct Register {
    Register(const std::string& key) {
      factory::get().m_map.emplace(key, [] { return new T(); });
      std::cout << "factory Register key=" << key << std::endl;
    }

    template <typename... Args>
    Register(const std::string& key, Args... args) {
      factory::get().m_map.emplace(key, [args...] { return new T(args...); });
      std::cout << "factory Register(args) key=" << key << std::endl;
    }
  };

  static action* produce(const std::string& key) {
    auto map = factory::get().m_map;
    auto it = map.find(key);
    if (it == map.end()) {
      std::cout << "!!error no key=" << key << std::endl;
      throw std::invalid_argument("error");
    }

    std::cout << "produce() find key=" << key << " and then do new" << std::endl;
    // return map[key]();
    // std::function<action*(void)>& construct_f = it->second;
    // return construct_f();
  }

 private:
  factory() = default;
  factory(const factory&) = delete;
  factory(factory&&) = delete;

  static factory& get() {
    static factory instance;
    return instance;
  }

  std::map<std::string, std::function<action*(void)>> m_map;
};

#define REGISTER_ACTION_NAME(T) msg_name_##T##_
#define REGISTER_ACTION(T, key, ...) \
  static factory::Register<T> REGISTER_ACTION_NAME(T)(key, ##__VA_ARGS__)

REGISTER_ACTION(login_action, "login_action");
REGISTER_ACTION(register_action, "register_action");
REGISTER_ACTION(deleter_action, "deleter_action", 100, "123456789");
