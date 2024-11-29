#include<cstddef>
#include<string>

class AbstractFile {
	public:
		virtual size_t getSize() = 0;

		void setName(std::string value);

		std::string getName(); 
	private:
		std::string name;
		size_t size;
};
