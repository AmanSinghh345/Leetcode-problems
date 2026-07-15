class H2O {
private : 
mutex mtx;
condition_variable cv;
int h;
int o;
public:
    H2O() {
        h=0;
        o=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[this](){return h<2;});
        releaseHydrogen();
        h++;
        if(h==2 && o==1){
            h=0;
            o=0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[this](){return o<1;});
        releaseOxygen();
        o++;
        if(h==2 && o==1){
            h=0;
            o=0;
        }
        cv.notify_all();
    }
};