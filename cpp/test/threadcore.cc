#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>

#include <vector>

void *thread(void *arg) {
  // 设置线程名称
  
  char tname[256];
  // snprintf(tname, sizeof(tname), "thread_%#x", (uint32_t)pthread_self());
  // prctl(PR_SET_NAME, tname);
  // printf("thread: '%s' run..\n", tname);
  
  char np_name[16];
  snprintf(np_name, sizeof(np_name), "thread_%#x", (uint32_t)pthread_self());
  pthread_setname_np(pthread_self(), np_name);
  printf("thread: '%s' run..\n", np_name);

  bool generalcore = (bool)arg;
  if (generalcore) {
    printf("thread tname:   '%s' general core\n", tname);
    printf("thread np_name: '%s' general core\n", np_name);
    *(char *)(arg) = 0x00;
  }

  return NULL;
}
int main(int argc, char *argv[]) {
  if (argc != 2) return -1;

  /*
   * 传入需要生成coredump的线程id参数
   * 在选择的相应线程中触发生成core
   */
  int coredump_thread = atoi(argv[1]);
  if (coredump_thread < 0 || coredump_thread > 3) {
	return -1;
	}

  // 1-3 是线程core
  std::vector<pthread_t> tids;
  for (int32_t i = 1; i < 4; i++) {
    pthread_t newtid;
    bool generalcore = (coredump_thread == i) ? true : false;
    pthread_create(&newtid, NULL, thread, (void *)generalcore);
    tids.push_back(newtid);
  }
  // 0 是进程core
  int xxx = atoi(argv[coredump_thread-1]);

  for (uint32_t i = 0; i < tids.size(); i++) {
    pthread_t tid = tids[i];
    pthread_join(tid, NULL);
  }

  return 0;
}
