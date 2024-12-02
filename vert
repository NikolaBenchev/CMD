class Terminal {
	public:
		Terminal();
		~Terminal();
		Terminal(const Terminal& other);
		Terminal(Terminal&& other);
		Terminal& operator=(const Terminal& other);
		Terminal& operator=(Terminal&& other);
		static void run() const; 
	private:
		static bool isRunning;
		static Folder* currentFolder;
		static Folder* root;
		
		void processCommand(std::string command);
		void copyFrom(const Terminal& other);
		void moveFrom(Terminal& other);
		void free();
};
