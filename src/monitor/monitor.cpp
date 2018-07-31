

#include <common/general.h>
#include "monitor.h"

namespace chain {
	Monitor::Monitor(chain::server *server_h, chain::client *client_h, chain::tls_server *tls_server_h, chain::tls_client *tls_client_h,
		chain::connection_hdl con, const std::string &uri, int64_t id) : 
		Connection(server_h, client_h, tls_server_h, tls_client_h, con, uri, id), active_time_(0){
	}

	void Monitor::SetSessionId(const std::string &session_id) {
		session_id_ = session_id;
	}

	void Monitor::SetActiveTime(int64_t current_time) {
		active_time_ = current_time;
	}

	int64_t Monitor::GetActiveTime() const {
		return active_time_;
	}

	bool Monitor::IsActive() const {
		return active_time_ > 0;
	}

	utils::InetAddress Monitor::GetRemoteAddress() const {
		utils::InetAddress address = GetPeerAddress();
		return address;
	}

	std::string Monitor::GetPeerNodeAddress() const {
		return chain_node_address_;
	}

	void Monitor::SetChainInfo(const protocol::ChainStatus &hello) {
		monitor_version_ = hello.monitor_version();
		chain_ledger_version_ = hello.ledger_version();
		chain_version_ = hello.chain_version();
		chain_node_address_ = hello.self_addr();
	}

	bool Monitor::SendHello(int32_t listen_port, const std::string &node_address, std::error_code &ec) {
		protocol::ChainStatus hello;
		hello.set_monitor_version(chain::General::MONITOR_VERSION);
		hello.set_ledger_version(chain::General::LEDGER_VERSION);
		hello.set_chain_version(chain::General::CHAIN_VERSION);
		hello.set_self_addr(node_address);

		return SendRequest(protocol::CHAIN_HELLO, hello.SerializeAsString(), ec);
	}
}

