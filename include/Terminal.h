class Terminal {
	public:
		Terminal();
		~Terminal();
		Terminal(const Terminal& other);
		Terminal& operator=(const Terminal& other);
		static void run() const; 
	private:
		static bool isRunning;
		static Folder* currentFolder;
		static Folder* root;
		
		void processCommand(std::string command);
		void free();
};
