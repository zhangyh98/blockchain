
#ifndef TRANSACTION_SET_
#define TRANSACTION_SET_

#include <proto/cpp/overlay.pb.h>
#include <proto/cpp/chain.pb.h>
#include <ledger/transaction_frm.h>

namespace chain {

	
	class TransactionSetFrm {
		protocol::TransactionEnvSet raw_txs_;
		std::map<std::string, int64_t> topic_seqs_;
	public:
		TransactionSetFrm();
		TransactionSetFrm(const protocol::TransactionEnvSet &env);
		~TransactionSetFrm();
		int32_t Add(const TransactionFrm::pointer &tx);
		std::string GetSerializeString() const;
		int32_t Size() const;
		const protocol::TransactionEnvSet &GetRaw() const;
	};
	typedef std::map<int64_t, TransactionFrm::pointer> TransactionFrmMap;

	//Topic key
	class TopicKey {
		std::string topic_;
		int64_t sequence_;
	public:
		TopicKey();
		TopicKey(const std::string &topic, int64_t sequence);
		~TopicKey();

		const std::string &GetTopic() const;
		const int64_t GetSeq() const;

		bool operator<(const TopicKey &key) const;
	};

	typedef std::map<TopicKey, TransactionFrm::pointer> TransactionMap;
}

#endif
