class ZeroEvenOdd {
private:
    int n;
    binary_semaphore zero_sem{1};
    binary_semaphore odd_sem{0};
    binary_semaphore even_sem{0};
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){zero_sem.acquire();
        printNumber(0);
        if(i&1)
        odd_sem.release();
        else even_sem.release();}
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2){even_sem.acquire();
        printNumber(i);
        zero_sem.release();}
    }

    void odd(function<void(int)> printNumber) {
      for(int i=1;i<=n;i+=2) { odd_sem.acquire();
        printNumber(i);
        zero_sem.release();}
    }
};