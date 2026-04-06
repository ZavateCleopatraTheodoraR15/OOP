#include "tree.h"

template<typename T>
Tree<T>::Node::Node(const T& val) : value(val), children(nullptr), childCount(0), capacity(0) {}

template<typename T>
Tree<T>::Node::~Node() {
    for (size_t i = 0; i < childCount; ++i) {
        delete children[i];
    }
    delete[] children;
}

template<typename T>
Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Tree<T>::~Tree() {
    if (root) {
        deleteSubtree(root);
    }
}

template<typename T>
void Tree<T>::resizeChildren(Node* node) {
    if (node->childCount >= node->capacity) {
        size_t newCapacity = (node->capacity == 0) ? 2 : node->capacity * 2;
        Node** newChildren = new Node*[newCapacity];
        
        for (size_t i = 0; i < node->childCount; ++i) {
            newChildren[i] = node->children[i];
        }
        
        delete[] node->children;
        node->children = newChildren;
        node->capacity = newCapacity;
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::findNode(Node* current, const T& value, bool (*compare)(const T&, const T&)) {
    if (!current) return nullptr;
    
    if (compare(current->value, value)) {
        return current;
    }
    
    for (size_t i = 0; i < current->childCount; ++i) {
        Node* result = findNode(current->children[i], value, compare);
        if (result) return result;
    }
    
    return nullptr;
}

template<typename T>
size_t Tree<T>::countChildrenRecursive(Node* node) {
    if (!node) return 0;
    
    size_t total = node->childCount;
    for (size_t i = 0; i < node->childCount; ++i) {
        total += countChildrenRecursive(node->children[i]);
    }
    return total;
}

template<typename T>
void Tree<T>::deleteSubtree(Node* node) {
    if (!node) return;
    for (size_t i = 0; i < node->childCount; ++i) {
        deleteSubtree(node->children[i]);
    }
    delete node;
}

template<typename T>
void Tree<T>::add_node(Node* parent, const T& value) {
    Node* newNode = new Node(value);
    
    if (parent == nullptr) {
        if (root) {
            deleteSubtree(root);
        }
        root = newNode;
    } else {
        resizeChildren(parent);
        parent->children[parent->childCount++] = newNode;
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::get_node(Node* parent) {
    if (parent == nullptr) {
        return root;
    }
    return parent;
}

template<typename T>
void Tree<T>::delete_node(Node* node) {
    if (!node) return;
    deleteSubtree(node);
    if (node == root) {
        root = nullptr;
    }
}

template<typename T>
typename Tree<T>::Node* Tree<T>::find(Node* startNode, const T& value, bool (*compare)(const T&, const T&)) {
    Node* searchStart = (startNode == nullptr) ? root : startNode;
    if (!compare) {
        return nullptr;
    }
    return findNode(searchStart, value, compare);
}

template<typename T>
void Tree<T>::insert(Node* parent, size_t index, const T& value) {
    if (!parent || index > parent->childCount) return;
    
    Node* newNode = new Node(value);
    resizeChildren(parent);
    
    for (size_t i = parent->childCount; i > index; --i) {
        parent->children[i] = parent->children[i - 1];
    }
    
    parent->children[index] = newNode;
    parent->childCount++;
}

template<typename T>
void Tree<T>::sort(Node* node, bool (*compare)(const T&, const T&)) {
    if (!node || node->childCount <= 1) return;
    
    for (size_t i = 0; i < node->childCount - 1; ++i) {
        for (size_t j = 0; j < node->childCount - i - 1; ++j) {
            bool shouldSwap;
            if (compare) {
                shouldSwap = compare(node->children[j + 1]->value, node->children[j]->value);
            } else {
                shouldSwap = node->children[j + 1]->value < node->children[j]->value;
            }
            
            if (shouldSwap) {
                Node* temp = node->children[j];
                node->children[j] = node->children[j + 1];
                node->children[j + 1] = temp;
            }
        }
    }
}

template<typename T>
size_t Tree<T>::count(Node* node) {
    if (node == nullptr) {
        return countChildrenRecursive(root);
    }
    return countChildrenRecursive(node);
}
