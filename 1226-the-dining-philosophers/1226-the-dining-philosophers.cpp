#include <semaphore>
#include <mutex>
class DiningPhilosophers {
public:
    counting_semaphore<4> rooms{4};
    mutex forks[5];
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                
                int left=philosopher;
                int right=(philosopher+1)%5;
                rooms.acquire();
                forks[left].lock();
                forks[right].lock();
                {
                    pickLeftFork();
                    pickRightFork();
                    eat();
                    putLeftFork();
                    putRightFork();
                }
                forks[left].unlock();
                forks[right].unlock();
                rooms.release();
    }
};