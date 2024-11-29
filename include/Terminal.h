class Terminal {
	public:
		static void run() const; 
	private:
		static bool isRunning;
		static Folder* currentFolder;
		static Folder* root;
		
		void processCommand(std::string command);
};
