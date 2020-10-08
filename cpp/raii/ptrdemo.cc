// https://blog.csdn.net/qingdujun/article/details/74858071

#include <iostream>
#include <string>
#include <memory>
#include <utility>  //std::move()

class demo {
 public:
  demo() : uptr(std::make_unique<int[]>(10)) {
    printf("demo\n");
    for (int i = 0; i < 10; ++i) {
      uptr[i] = i;
    }
  }
  ~demo() { printf("~demo\n"); }
  void show() { printf("%d\n", uptr[9]); }
 private:
  std::unique_ptr<int[]> uptr;
};

void my_unique_ptr() {
  auto uptr = std::make_unique<int[]>(10);
  uptr[5] = 17;
  printf("%d\n", uptr[5]);
}
void my_unique_ptr2() {
  auto uptr = std::make_unique<demo>();
  uptr->show();
  std::unique_ptr<demo> uptr2(new demo());  //等效写法
  uptr2->show();
}
void my_unique_ptr3() {
  auto uptr = std::make_unique<int>(42);
  printf("%d\n", *uptr);  // 42
  /// std::unique_ptr<int> uptr1 = uptr; ///unique_ptr无拷贝构造函数
  /// std::unique_ptr<int> uptr1(uptr);  ///等效写法
  std::unique_ptr<int> uptr2 = std::move(uptr);
  /// printf("%d\n",*uptr); ///error 所有权已交给uptr2
  printf("%d\n", *uptr2);
}

void my_shared_ptr() {
  /// unique_ptr是唯一可以适用于旧C风格数组的指针，shared_ptr等其他智能指针不能。
  /// auto sptr = std::make_shared<int[]>(10); //error
  /// sptr[6] = 20;
  auto sptr = std::make_shared<demo>();
  sptr->show();
}

void auto_run_fun(FILE* f) {
  printf("auto running.\n");
  fclose(f);
}
void my_shared_ptr2() {
  FILE* f = fopen("data.txt", "w");
  std::shared_ptr<FILE> file_ptr(f, auto_run_fun);
}
///糟糕！只调用一次构造函数，却调用了两次析构函数
///正确的使用方式应该是使用make_shared和拷贝构造函数建立副本
void my_shared_ptr3() {
  /*demo* d = new demo();
    std::shared_ptr<demo> sptr1(d);
    std::shared_ptr<demo> sptr2(d);//~demo() error
   */
  auto sptr3 = std::make_shared<demo>();
  std::shared_ptr<demo> sptr4(sptr3);  /// shared_ptr拷贝构造函数
}
std::shared_ptr<demo> my_shared_ptr4() {
  auto sptr = std::make_shared<demo>();
  return sptr;
}
/// weak_ptr -> shared_ptr
void my_weak_ptr() {
  std::weak_ptr<demo> wptr;
  {
    auto sptr = std::make_shared<demo>();
    printf("sptr->use_count()=%lu\n", sptr.use_count());
    wptr = sptr;
    auto sptr2 = wptr.lock();
    if (!wptr.expired()) {  ///等价于sptr2 != nullptr
      printf("shared_ptr ok\n");
      sptr2->show();
    }
  }
  if (wptr.expired()) {
    printf("shared_ptr deleted\n");
  }
}

int main() {
  printf("=========\n");
  my_unique_ptr();
  printf("=========\n");
  my_unique_ptr2();
  printf("=========\n");
  my_unique_ptr3();
  printf("=========\n");
  my_shared_ptr();
  printf("=========\n");
  my_shared_ptr2();
  printf("=========\n");
  my_shared_ptr3();
  printf("=========\n");
  my_shared_ptr4();
  printf("=========\n");
  my_weak_ptr();
  printf("=========\n");
  std::unique_ptr<std::string> p1();
  std::cout << "p1=" << *p1 << std::endl;
}
