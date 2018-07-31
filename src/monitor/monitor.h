

#ifndef MONITOR_H_
#define MONITOR_H_

#include <proto/cpp/monitor.pb.h>
#include <proto/cpp/overlay.pb.h>
#include <common/network.h>

namespace chain {
	typedef std::shared_ptr<protocol::WsMessage> WsMessagePointer;

	class Monitor : public chain::Connection {
	private:

		bool state_changed_;              /* state changed */
		int64_t active_time_;             /* the active time of monitor */
		std::string session_id_;          /* session id */
		std::string peer_node_address_;   /* peer node address */
		
		std::string chain_version_;        /* chain version */
		int64_t monitor_version_;         /* monitor version */
		int64_t chain_ledger_version_;     /* chain ledger version */
		std::string chain_node_address_;   /* chain node address */

	public:
		Monitor(chain::server *server_h, chain::client *client_h, chain::tls_server *tls_server_h, chain::tls_client *tls_client_h, 
			chain::connection_hdl con, const std::string &uri, int64_t id);

		void SetSessionId(const std::string &session_id);
		void SetActiveTime(int64_t current_time);
		bool IsActive() const;
		int64_t GetActiveTime() const;

		utils::InetAddress GetRemoteAddress() const;
		std::string GetPeerNodeAddress() const;

		bool SendHello(int32_t listen_port, const std::string &node_address, std::error_code &ec);
		void SetChainInfo(const protocol::ChainStatus &hello);
	};
}

#endif