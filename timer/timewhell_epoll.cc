#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sys/epoll.h>
#include <sys/time.h>
#include <unistd.h>

class Timer
{
  public:
    Timer(int rotations, int slot, std::function<void(void)> fun, void *args)
        : rotations_(rotations), slot_(slot), fun(fun)
    {
    }

    inline int getRotations() { return rotations_; }

    inline void decreaseRotations() { --rotations_; }

    inline void active() { fun(); }

    inline int getSlot() { return slot_; }

  private:
    int rotations_;
    int slot_;

    std::function<void(void)> fun;
    void *args;
};

class TimeWheel
{
  public:
    TimeWheel(int nslots)
        : nslosts_(nslots), curslot_(0),
          slots_(nslosts_, std::vector<Timer *>()), starttime_(getCurrentMillisecs())
    {
    }

    ~TimeWheel()
    {
        for (std::vector<Timer *> vect : slots_)
            for (Timer *timer : vect)
                delete timer;
    }

    unsigned long long getCurrentMillisecs()
    {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
        return ts.tv_sec * 1000 + ts.tv_nsec / (1000 * 1000);
    }

    Timer *addTimer(unsigned long long timeout, std::function<void(void)> fun, void *args)
    {
        int slot = 0;
        Timer *timer = NULL;

        if (timeout < 0)
            return NULL;

        slot = (curslot_ + (timeout % nslosts_)) % nslosts_;

        timer = new Timer(timeout / nslosts_, slot, fun, args);
        slots_[slot].push_back(timer);
        return timer;
    }

    void delTimer(Timer *timer)
    {
        if (!timer)
            return;

        std::vector<Timer *>::iterator it = std::find(slots_[timer->getSlot()].begin(), slots_[timer->getSlot()].end(), timer);
        if (it != slots_[timer->getSlot()].end())
        {
            slots_[timer->getSlot()].erase(it);

            //delete timer;
        }
    }

    void tick()
    {
        for (auto it = slots_[curslot_].begin(); it != slots_[curslot_].end();)
        {
            if ((*it)->getRotations() > 0)
            {
                (*it)->decreaseRotations();
                ++it;
                continue;
            }
            else
            {
                Timer *timer = *it;
                timer->active();
                it = slots_[curslot_].erase(it);
                delete timer;
            }
        }

        curslot_ = ++curslot_ % nslosts_;
    }

    void takeAllTimeout()
    {
        int now = getCurrentMillisecs();
        int cnt = now - starttime_;
        std::cout << "now=" << now << ",cnt=" << cnt << std::endl;
        for (int i = 0; i < cnt; ++i)
        {
          tick();
        }
        starttime_ = now;
    }

  private:
    int nslosts_;
    int curslot_;

    unsigned long long starttime_;

    std::vector<std::vector<Timer *>> slots_;
};

int dispatch() {
    struct epoll_event event;
    event.data.fd = 0;
    // event.events = EPOLLOUT;
    event.events = EPOLLIN; //只读

    int epfd = epoll_create1(0);
    epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &event);

    struct epoll_event event_vec[1];
    int events_num = 1;
    
    TimeWheel tw(60 * 1000);
    tw.addTimer(1000, []() { std::cout << "hello world1000" << std::endl; }, NULL);
    tw.addTimer(2000, []() { std::cout << "hello world2000" << std::endl; }, NULL);
    tw.addTimer(3000, []() { std::cout << "hello world3000" << std::endl; }, NULL);
    tw.addTimer(4000, []() { std::cout << "hello world4000" << std::endl; }, NULL);
    tw.addTimer(5000, []() { std::cout << "hello world5000" << std::endl; }, NULL);
    tw.addTimer(6000, []() { std::cout << "hello world6000" << std::endl; }, NULL);
    tw.addTimer(7000, []() { std::cout << "hello world7000" << std::endl; }, NULL);
    tw.addTimer(8000, []() { std::cout << "hello world8000" << std::endl; }, NULL);
    tw.addTimer(9000, []() { std::cout << "hello world9000" << std::endl; }, NULL);

    for(;;)
    {
      int ret = epoll_wait(epfd, event_vec, 1, 1000);
      tw.takeAllTimeout();
    }

    return 0;
}

int main()
{
  dispatch();

  return 0;    
}