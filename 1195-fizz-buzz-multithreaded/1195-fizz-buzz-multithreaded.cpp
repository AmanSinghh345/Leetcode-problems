class FizzBuzz {
private:
    int n;
    binary_semaphore sem{1};
    int i=1;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for(;i<=n;){
            if(i%3==0 && i%5!=0){
                sem.acquire();
                printFizz();
                i++;
                sem.release();
            
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
         for(;i<=n;){
            if(i%3!=0 && i%5==0){
                sem.acquire();
                printBuzz();
                i++;
                sem.release();
            
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
         for(;i<=n;){
            if(i%3==0 && i%5==0){
                sem.acquire();
                printFizzBuzz();
                i++;
                sem.release();
            
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
         for(;i<=n;){
            if(i%3!=0 && i%5!=0){
                sem.acquire();
                printNumber(i);
                i++;
                sem.release();
            
            }
        }
    }
};