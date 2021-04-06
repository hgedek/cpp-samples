#include <iostream>
#include <thread>
#include <atomic>

std::atomic<uint32_t> data;
std::atomic<uint32_t> data2;

void run() {
 data.fetch_add(1, std::memory_order_relaxed);
  std::cout << std::this_thread::get_id() << std::endl;
}

void run2() {
  data2.fetch_add(1, std::memory_order_acq_rel);  
  std::cout << std::this_thread::get_id() << std::endl;
}


int main() {
  {
    std::thread t1 {run};
    std::thread t2 {run};
    std::thread t3 {run};

    t1.join();
    t2.join();
    t3.join();
  }

  {
    std::thread t1{run2};
    std::thread t2{run2};
    std::thread t3{run2};

    t1.join();
    t2.join();
    t3.join();
  }

  return 0;
}


