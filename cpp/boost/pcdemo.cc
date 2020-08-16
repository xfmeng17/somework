// g++ pcdemo.cc -pthread -lboost_system -lboost_thread

#include <boost/bind.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/threadpool.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

class Info {
 public:
  time_t a;
  int b;
  string c;
  Info(time_t aa, int bb, string cc) : a(aa), b(bb), c(cc) {}
  void ToString() { cout << "a=" << a << ",b=" << b << ",c=" << c << endl; }
};

class Task {
 public:
  boost::lockfree::queue<Info*> queue_;
  boost::atomic_int produced_cnt_;
  boost::atomic_int consumed_cnt_;
  Task() : queue_(64), produced_cnt_(0), consumed_cnt_(0) {}
};

void Produce(void* args) {
  Task* taskp = (Task*)args;
  while (true) {
    sleep(1);
    time_t t = time(NULL);
    Info* info = new Info(t, taskp->produced_cnt_++, "");
    taskp->queue_.push(info);
  }
  return;
}

void Consume(void* args) {
  Task* taskp = (Task*)args;
  while (true) {
    Info* info_p = NULL;
    while (taskp->queue_.pop(info_p)) {
      info_p->ToString();
      cout << "produced_cnt_=" << taskp->produced_cnt_--;
      cout << ", consumed_cnt_=" << taskp->consumed_cnt_++ << endl;
      delete info_p;
      info_p = NULL;
    }
  }
}

int main() {
  Task* task_p = new Task();
  boost::threadpool::pool tp(12);

  for (int i = 0; i < 10; i++) {
    tp.schedule(boost::bind(Produce, task_p));
  }
  for (int i = 0; i < 1; i++) {
    tp.schedule(boost::bind(Consume, task_p));
  }
  cout << "main() finish init" << endl;
  tp.wait();

  return 0;
}
