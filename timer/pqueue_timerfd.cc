// https://gist.github.com/baixiangcpp/b2199f1f1c7108f22f47d2ca617f6960

#include <functional>
#include <iostream>
#include <algorithm>
#include <sys/epoll.h>
#include <sys/time.h>
#include <unistd.h>
#include <queue>
#include <vector>

class Timer
{
  public:
    Timer(unsigned long long expire, std::function<void(void)> fun, void *args)
        : expire_(expire), fun(fun)
    {
    }

    inline void active() { fun(); }

    inline unsigned long long getExpire() const{ return expire_; }

  private:
    std::function<void(void)> fun;
    void *args;

    unsigned long long expire_;
};


class TimerManager
{
public:
    TimerManager() {}

    Timer *addTimer(int timeout, std::function<void(void)> fun, void *args = NULL)
    {
        if (timeout <= 0) {
            return NULL;
        }

        unsigned long long now = getCurrentMillisecs();
        Timer* timer = new Timer(now + timeout, fun, args);

        queue_.push(timer);

        return timer;
    }

    void delTimer(Timer* timer)
    {
        std::priority_queue<Timer*, std::vector<Timer*>, cmp> newqueue;

        while( !queue_.empty() )
        {
            Timer* top = queue_.top();
            queue_.pop();
            if ( top != timer ) {
                newqueue.push(top);
            }
        }

        queue_ = newqueue;
    }

    unsigned long long getRecentTimeout()
    {
        unsigned long long timeout = -1;
        if( queue_.empty() ) {
            return timeout;
        }

        unsigned long long now = getCurrentMillisecs();
        timeout = queue_.top()->getExpire() - now;
        if(timeout < 0) {
            timeout = 0;
        }

        return timeout;
    }

    void takeAllTimeout()
    {   
        unsigned long long now = getCurrentMillisecs();

        while ( !queue_.empty() )
        {
            Timer* timer = queue_.top();
            if( timer->getExpire() <= now )
            {
                queue_.pop();
                timer->active();
                delete timer;

                continue;
            }

            return;
        }
    }

    unsigned long long getCurrentMillisecs()
    {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
        return ts.tv_sec * 1000 + ts.tv_nsec / (1000 * 1000);
    }

private:

    struct cmp
    {
        bool operator()(Timer*& lhs, Timer*& rhs) const { return lhs->getExpire() > rhs->getExpire(); }
    };

    std::priority_queue<Timer*,std::vector<Timer*>,cmp> queue_;
};

int dispatch_epoll() {
    struct epoll_event event;
    event.data.fd = 0;
    event.events = EPOLLOUT;

    int epfd = epoll_create1(0);
    epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &event);

    struct epoll_event event_vec[1];
    int events_num = 1;
    
    TimerManager tm;
    tm.addTimer(1000, []() { std::cout << "hello world1000" << std::endl; }, NULL);
    tm.addTimer(2000, []() { std::cout << "hello world2000" << std::endl; }, NULL);
    tm.addTimer(3000, []() { std::cout << "hello world3000" << std::endl; }, NULL);
    tm.addTimer(4000, []() { std::cout << "hello world4000" << std::endl; }, NULL);
    tm.addTimer(5000, []() { std::cout << "hello world5000" << std::endl; }, NULL);
    tm.addTimer(6000, []() { std::cout << "hello world6000" << std::endl; }, NULL);
    tm.addTimer(7000, []() { std::cout << "hello world7000" << std::endl; }, NULL);
    tm.addTimer(8000, []() { std::cout << "hello world8000" << std::endl; }, NULL);
    tm.addTimer(9000, []() { std::cout << "hello world9000" << std::endl; }, NULL);

    for(;;)
    {
      int ret = epoll_wait(epfd, event_vec, 1, tm.getRecentTimeout());
      tm.takeAllTimeout();
    }

    return 0;
}

int main()
{
  // epoll
  dispatch_epoll();

  // timerfd
  // dispatch_timefd();

  return 0;    
}