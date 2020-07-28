#include <iostream>
#include <thread>
using namespace std;
void download1() {
  cout << "开始下载第一个视频..." << endl;
  for (int i = 0; i < 100; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout << "第一个视频下载进度:" << i << endl;
  }
  cout << "第一个视频下载完成..." << endl;
}

void download2() {
  cout << "开始下载第二个视频..." << endl;
  for (int i = 0; i < 100; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
    cout << "第二个视频下载进度:" << i << endl;
  }
  cout << "第二个视频下载完成..." << endl;
}
void process() { cout << "开始处理两个视频" << endl; }

int main() {
  cout << "主线程开始运行\n";
  std::thread d2(download2);
  download1();
  d2.join();
  process();
}
