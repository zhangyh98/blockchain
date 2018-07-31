

#ifndef KV_TRIE_H_
#define KV_TRIE_H_

#include <common/storage.h>
#include "trie.h"

namespace chain{

	class KVTrie :public Trie{
		KeyValueDb* mdb_;
		std::string prefix_;
	public:
		std::shared_ptr<WRITE_BATCH> batch_;
		int64_t time_;
	public:
		KVTrie();
		~KVTrie();
		bool Init(chain::KeyValueDb* db, std::shared_ptr<WRITE_BATCH>, const std::string& prefix, int depth);

		//int LeafCount();
		bool AddToDB();
	private:
		void Load(NodeFrm::POINTER node, int depth);
	    std::string Location2DBkey(const Location& location, bool leaf);
	protected:
		virtual void StorageSaveNode(NodeFrm::POINTER node) override;
		virtual void StorageSaveLeaf(NodeFrm::POINTER node) override;
		
		virtual void StorageDeleteNode(NodeFrm::POINTER node) override;
		virtual void StorageDeleteLeaf(NodeFrm::POINTER node) override;

		virtual bool storage_load(const Location& location, protocol::Node& info) override;
		virtual bool StorageGetLeaf(const Location& location, std::string& value)override;
		virtual std::string HashCrypto(const std::string& input) override;
	};
}

#endif
