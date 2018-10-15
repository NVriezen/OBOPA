#include <queue>
#include <thread>
#include <iostream>

#include <condition_variable>

int c = 0;
bool done = false;
std::queue<int> goods;

std::condition_variable flag;
std::mutex mutex;

void producer() {
    for (int i = 0; i < 500; ++i) {
        goods.push(i);
        c++;
    }

	flag.notify_one();
    done = true;
}

void consumer() {
	std::unique_lock<std::mutex> lock(mutex);
    while (!done) {
		flag.wait(lock);
        while (!goods.empty()) {
            goods.pop();
            c--;
        }
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();
    std::cout << "Net: " << c << std::endl;
}
