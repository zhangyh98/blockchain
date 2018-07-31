

#ifndef PEER_H_
#define PEER_H_

#include <proto/cpp/overlay.pb.h>
#include <common/network.h>

namespace chain {
	typedef std::shared_ptr<protocol::WsMessage> WsMessagePointer;

	// Provide p2p network interface
	class IPeerManagerNotify {
	public:
		IPeerManagerNotify();
		~IPeerManagerNotify();

		virtual void OnNetworkPrepared() = 0;
		virtual void OnMessage() = 0;
	};

	typedef std::list<IPeerManagerNotify *> PeerManagerNotifier;

	class Peer : public Connection {
	private:
		int64_t active_time_;
		int64_t delay_;

		//Peer infomation
		std::string peer_version_;
		int64_t peer_ledger_version_;
		int64_t peer_overlay_version_;
		int64_t peer_listen_port_;
		std::string peer_node_address_;
	public:
		Peer(server *server_h, client *client_h, tls_server *tls_server_h, tls_client *tls_client_h, connection_hdl con, const std::string &uri, int64_t id);
		virtual ~Peer();

		utils::InetAddress GetRemoteAddress() const;
		bool IsActive() const;
		std::string GetPeerNodeAddress() const;
		int64_t GetActiveTime() const;
		int64_t GetDelay() const;

		bool SendPeers(const protocol::Peers &db_peers, std::error_code &ec);
		void SetPeerInfo(const protocol::Hello &hello);
		void SetActiveTime(int64_t current_time);
		bool SendHello(int32_t listen_port, const std::string &node_address, const int64_t &network_id, const std::string &node_rand, std::error_code &ec);

		virtual void ToJson(Json::Value &status) const;
		virtual bool OnNetworkTimer(int64_t current_time);
	};
}

#endif
