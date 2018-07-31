

#ifndef BROADCAST_H_
#define BROADCAST_H_

#include <unordered_map>
namespace chain{

	class IBroadcastDriver{
	public:
		IBroadcastDriver(){};
		virtual ~IBroadcastDriver(){};

		//Virtual bool SendMessage(int64_t peer_id, WsMessagePointer msg) = 0;
		virtual bool SendRequest(int64_t peer_id, int64_t type, const std::string &data) = 0;
		virtual std::set<int64_t> GetActivePeerIds() = 0;
	};

	class BroadcastRecord{
	public:
		typedef std::shared_ptr<BroadcastRecord> pointer;

		BroadcastRecord(int64_t type, const std::string &data, int64_t);
		~BroadcastRecord();

		int64_t type_;
		int64_t time_stamp_;
		std::set<int64_t> peers_;
	};

	typedef std::map<int64_t, std::string> BroadcastRecordCoupleMap;
	typedef std::unordered_map<std::string, BroadcastRecord::pointer> BroadcastRecordMap;

	class Broadcast {
	private:
		BroadcastRecordCoupleMap    records_couple_;
		BroadcastRecordMap records_;
		utils::Mutex mutex_msg_sending_;
		IBroadcastDriver *driver_;

	public:
		Broadcast(IBroadcastDriver *driver);
		~Broadcast();

		bool Add(int64_t type, const std::string &data, int64_t peer_id);
		void Send(int64_t type, const std::string &data);
		bool IsQueued(int64_t type, const std::string &data);
		void OnTimer();
		size_t GetRecordSize() const { return records_.size(); };
	};
};

#endif
