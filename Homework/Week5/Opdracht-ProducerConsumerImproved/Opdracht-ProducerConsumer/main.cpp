#include <queue>
#include <thread>
#include <iostream>

#include <condition_variable>

int c = 0;
bool done = false;
std::queue<int> goods;

std::condition_variable consumerFlag;
std::condition_variable producerFlag;
std::mutex mutex;
std::mutex mute;

void producer() {
	std::unique_lock<std::mutex> locker(mute);
	for (int i = 0; i < 500; ++i) {
		{
			std::lock_guard<std::mutex> guard(mutex);
			goods.push(i);
			c++;

		}
		consumerFlag.notify_one();
		producerFlag.wait(locker); 
    }
    done = true;
	consumerFlag.notify_one();
}

void consumer() {
	std::unique_lock<std::mutex> lock(mutex);
    while (!done) {
		consumerFlag.wait(lock);
        while (!goods.empty()) {
			{
				std::lock_guard<std::mutex> guard(mute);
				goods.pop();
				c--;
			}
        }
		producerFlag.notify_one();
    }
}

int main() {
	for (size_t i = 0; i < 200; i++) {
		done = false;
		std::thread consumerThread(consumer);
		std::thread producerThread(producer);

		consumerThread.detach();
		producerThread.join();
		std::cout << "Net: " << c << std::endl;
	}
}
