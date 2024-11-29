#include<vector>

template <typename T>
class Node {
	public:
		Node() {}
		~Node() {
			this->free();	
		}

		Node(const T& value) {
			this->value = value;
		}

		Node(const Node& other) : value(other.value) {
			copyFrom(other);
		}

		Node& operator=(const Node& other) : value(other.value) {
			free();
			copyFrom(other);
			return *this;
		}
	
		Node(Node&& other) : value(other.value), childNodes(other.childNodes) {
			delete other;
		}

		Node& operator=(Node&& other): value(other.value), childNodes(other.childNodes) {
			delete other;
		}

		//TODO: add(const vector<Node*> toAdd)
		void add(const Node* toAdd) {
			childNodes.push_back(toAdd);
		}

		void remove(const Node* toRemove) {
			for(
					std::vector<Node*>::iterator it = childNodes.begin(); 
					it != childNodes.end();
					it++
			   ) {
				if(it == toRemove) {
					childNodes.erase(it);
					break;
				}
			}
		}

		T& getValue() {
			return this->value;
		}

		vector<Node*> getChildNodes() {
			return this->childNodes;
		}
	private:
		T value;
		vector<Node*> childNodes;

		void free() {
			for(Node* currChild : this->childNodes) {
				delete currChild;
			}
			childNodes.clear();
		}
		
		void copyFrom(Node& other) {
			for(Node* currChild : other->childNodes) {
				childNodes.push_back(currChild);
			}
		}
};
