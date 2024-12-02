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

		Node(const Node<T>& other) : value(other.value) {
			copyFrom(other);
		}

		Node<T>& operator=(const Node<T>& other) {
			this->value = other->value;
			free();
			copyFrom(other);
			return *this;
		}
	
		Node(Node<T>&& other) : value(other.value), childNodes(other.childNodes) {
			delete other;
		}

		Node<T>& operator=(Node<T>&& other) {
			this->value = other->value;
			this->childNodes = other->childNodes;
			delete other;
			return *this;
		}

		//TODO: add(const vector<Node<T>*> toAdd)
		void add(Node<T>* toAdd) {
			this->childNodes.push_back(toAdd);
		}

		void remove(const Node<T>* toRemove) {
			for(
					typename std::vector<Node<T>*>::iterator it = this->childNodes.begin(); 
					it != this->childNodes.end();
					it++
			   ) {
				if(it == toRemove) {
					this->childNodes.erase(it);
					break;
				}
			}
		}

		T& getValue() {
			return this->value;
		}

		std::vector<Node<T>*> getChildNodes() {
			return this->childNodes;
		}
	private:
		T value;
		typename std::vector<Node<T>*> childNodes;

		void free() {
			for(Node<T>* currChild : this->childNodes) {
				delete currChild;
			}
			this->childNodes.clear();
		}
		
		void copyFrom(Node<T>& other) {
			for(Node<T>* currChild : other->childNodes) {
				this->childNodes.push_back(currChild);
			}
		}
};
