
#ifndef CONSOLE_H_
#define CONSOLE_H_

namespace chain {
	typedef std::function<void(const utils::StringVector &args)> ConsolePoc;
	typedef std::map<std::string, ConsolePoc> ConsolePocMap;

	class Console : public utils::Singleton<Console>, public utils::Runnable {
		friend class utils::Singleton<Console>;
	public:
		Console();
		~Console();

		bool Initialize();
		bool Exit();
		void Usage(const utils::StringVector &args);

		virtual void Run(utils::Thread *thread) override;
		void OpenWallet(const utils::StringVector &args);
		void CreateWallet(const utils::StringVector &args);
		void CloseWallet(const utils::StringVector &args);
		void RestoreWallet(const utils::StringVector &args);
		void GetBlockNumber(const utils::StringVector &args);
		void GetBalance(const utils::StringVector &args);
		void GetAddress(const utils::StringVector &args);
		void PayCoin(const utils::StringVector &args);
		void GetState(const utils::StringVector &args);
		void ShowKey(const utils::StringVector &args);
		void CmdExit(const utils::StringVector &args);

	private:
		utils::Thread *thread_ptr_;
		ConsolePocMap funcs_;

		PrivateKey *priv_key_;
		std::string keystore_path_;
		void CreateKestore(const utils::StringVector &args, std::string &private_key, std::string& errmsg);
		PrivateKey *OpenKeystore( const std::string &path, std::string& errmsg);
		bool ParseCmdline(const std::string& str, std::vector<std::string>& arr, std::string& errmsg);
	};
}

#endif