

#ifndef SYSTEM_MANAGER_H_
#define SYSTEM_MANAGER_H_

#include <utils/system.h>
#include <common/general.h>
#include <proto/cpp/monitor.pb.h>

namespace chain {
	class SystemManager {
	public:
		SystemManager();
		~SystemManager();

	public:
		void OnSlowTimer(int64_t current_time);

		bool GetSystemMonitor(std::string paths, monitor::SystemStatus* &system_status);

	private:
		utils::System system_;      // os
		double cpu_used_percent_;   // cpu percentage
		int64_t check_interval_;    // timer interval
		int64_t last_check_time_;   // last check time
	};
}

#endif
