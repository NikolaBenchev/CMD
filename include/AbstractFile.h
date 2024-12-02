#include<string>
#include<cstddef>

class AbstractFile {
	public:
		AbstractFile(std::string name, std::string path);
		virtual size_t getSize() = 0;

		void setName(std::string value);

		std::string getName() const;
		
		std::string getPath() const; 
	private:
		std::string name;
		size_t size;
		std::string path;
};
