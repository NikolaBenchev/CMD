#include "./Folder.h"

class Terminal {
	public:
		Terminal();
		~Terminal();
		Terminal(const Terminal& other) = delete;
		void operator=(const Terminal& other) = delete;
		static void run(); 
	private:
		static bool isRunning;
		static Folder* currentFolder;
		static Folder* root;
		
		static void processCommand(std::string command);
		static void free();
};
