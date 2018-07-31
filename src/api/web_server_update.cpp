

#include <utils/headers.h>
#include <common/general.h>
#include <common/private_key.h>
#include <main/configure.h>

#include "web_server.h"

namespace chain {
	void WebServer::UpdateLogLevel(const http::server::request &request, std::string &reply) {
		std::string levelreq = request.GetParamValue("level");
		utils::LogLevel loglevel = utils::LOG_LEVEL_ALL;
		std::string loglevel_info = "LOG_LEVEL_ALL";
		if (levelreq == "1") {
			loglevel = (utils::LogLevel)(utils::LOG_LEVEL_ALL & ~utils::LOG_LEVEL_TRACE);
			loglevel_info = "LOG_LEVEL_ALL & ~utils::LOG_LEVEL_TRACE";
		}

		utils::Logger::Instance().SetLogLevel(loglevel);
		reply = utils::String::Format("set log level to %s", loglevel_info.c_str());
	}
}