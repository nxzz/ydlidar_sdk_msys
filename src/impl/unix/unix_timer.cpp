#if !defined(_WIN32)
#include "timer.h"

namespace impl{
	uint32_t getHDTimer() {
		struct timespec t;
		t.tv_sec = t.tv_nsec = 0;
		clock_gettime(CLOCK_MONOTONIC, &t);
		return t.tv_sec*1000L + t.tv_nsec/1000000L;
	}
    TTimeStamp getCurrentTime()
    {
        struct timespec  tim;
        clock_gettime(CLOCK_REALTIME, &tim);
        return  (TTimeStamp)(tim.tv_sec*1000000000LL + tim.tv_nsec);
    }
}
#endif
