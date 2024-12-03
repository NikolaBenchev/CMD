#pragma once

#include<map>
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

		typedef void (*TerminalCommand) (std::string commandLine);

		void enterFolder(std::string commandLine);
		void createFile(std::string commandLine);
		void createFolder(std::string commandLine);
		void removeFile(std::string commandLine);
		void removeFolder(std::string commandLine);
		void copy(std::string commandLine);
		static void getSize(std::string commandLine);
		static void printContent(std::string commandLine);

		std::map<std::string, TerminalCommand> runCommand{
			{ "cd", enterFolder }
		};


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
