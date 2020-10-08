// RAII（Resource Acquisition Is Initialization）

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Mutex {
 public:
  Mutex();
  ~Mutex();
  void Lock();
  void Unlock();

 private:
  pthread_mutex_t mu_;
  // No copying
  Mutex(const Mutex&);
  void operator=(const Mutex&);
};
static void PthreadCall(const char* label, int result) {
  if (result != 0) {
    fprintf(stderr, "pthread %s: %s\n", label, strerror(result));
  } else {
    printf("%s\n", label);
  }
}
Mutex::Mutex() { PthreadCall("init mutex", pthread_mutex_init(&mu_, NULL)); }
Mutex::~Mutex() { PthreadCall("destroy mutex", pthread_mutex_destroy(&mu_)); }
void Mutex::Lock() { PthreadCall("lock", pthread_mutex_lock(&mu_)); }
void Mutex::Unlock() { PthreadCall("unlock", pthread_mutex_unlock(&mu_)); }

class MutexLock {
 public:
  explicit MutexLock(Mutex* mu) : mu_(mu) { this->mu_->Lock(); }
  ~MutexLock() { this->mu_->Unlock(); }

 private:
  Mutex* const mu_;
  // No copying allowed
  MutexLock(const MutexLock&);
  void operator=(const MutexLock&);
};

#define NUM_THREADS 10000

int num = 0;
Mutex mutex;

void* count(void* args) {
  MutexLock lock(&mutex);
  num++;
}

int main() {
  int t;
  pthread_t thread[NUM_THREADS];

  for (t = 0; t < NUM_THREADS; t++) {
    int ret = pthread_create(&thread[t], NULL, count, NULL);
    if (ret) {
      return -1;
    }
  }

  for (t = 0; t < NUM_THREADS; t++) {
    pthread_join(thread[t], NULL);
  }
  printf("num=%d\n", num);
  return 0;
}
