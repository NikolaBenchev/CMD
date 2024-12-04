#pragma once

#include<map>
#include<queue>
#include "./Folder.h"

class Terminal {
	public:
		Terminal();
		~Terminal();
		Terminal(const Terminal& other) = delete;
		void operator=(const Terminal& other) = delete;
		void run(); 
	private:
	bool isRunning;
		Folder* currentFolder;
		Folder* root;

		void free();
		void processCommand(std::string commandLine);

		//? Commands
		void quit();
		void enterFolder(std::string path);
		void createFile(std::string name);
		void createFolder(std::string name);
		void removeFile(std::string name);
		void removeFolder(std::string name);
		void copy(std::queue<std::string> params);
		void getSize(std::string name);
		void printFileContent(std::string name);
		void printFolderContent(std::string name);
		
	/*std::map<std::string, TerminalCommand> runCommand{
		  { "cd", enterFolder }
		  };*/


		/*		enum Commands {
				cd,
				touch,
				mkdir,
				rm,
				rmdir,
				cp,
				du,
				cat,
				};*/
};
