
#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <string>

namespace utils {

	int64_t GetPerformanceCounter();
	void MemoryClean(void *ptr, size_t len);
	void RandAddSeed();
	bool GetRandBytes(unsigned char* buf, int num);
	bool GetOSRand(unsigned char *buf, int num);
	bool GetStrongRandBytes(std::string & out);

}
#endif
