#include <cstddef>

template<typename T>
class Tree {
private:
    struct Node {
        T value;
        Node** children;
        size_t childCount;
        size_t capacity;
        
        Node(const T& val);
        ~Node();
    };
    
    Node* root;
    
    void resizeChildren(Node* node);
    Node* findNode(Node* current, const T& value, bool (*compare)(const T&, const T&));
    size_t countChildrenRecursive(Node* node);
    void deleteSubtree(Node* node);
    
public:
    Tree();
    ~Tree();
    
    void add_node(Node* parent, const T& value);
    Node* get_node(Node* parent = nullptr);
    void delete_node(Node* node);
    Node* find(Node* startNode, const T& value, bool (*compare)(const T&, const T&));
    void insert(Node* parent, size_t index, const T& value);
    void sort(Node* node, bool (*compare)(const T&, const T&) = nullptr);
    size_t count(Node* node = nullptr);
};
