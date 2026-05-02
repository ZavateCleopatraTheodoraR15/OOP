template<typename K, typename V>
class Map
{
private:
    struct Node
    {
        K key;
        V value;
        Node* next;
        Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int size;
    
public:
    Map() : head(nullptr), tail(nullptr), size(0) {}
    
    ~Map()
    {
        Clear();
    }
    
    V& operator[](const K& key)
    {
        Node* current = head;
        while (current)
        {
            if (current->key == key)
                return current->value;
            current = current->next;
        }
        
        Node* newNode = new Node(key, V());
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        return tail->value;
    }
    
    void Set(const K& key, const V& value)
    {
        (*this)[key] = value;
    }
    
    bool Get(const K& key, V& value)
    {
        Node* current = head;
        while (current)
        {
            if (current->key == key)
            {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    int Count() const
    {
        return size;
    }
    
    void Clear()
    {
        Node* current = head;
        while (current)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }
    
    bool Delete(const K& key)
    {
        if (!head) return false;
        
        if (head->key == key)
        {
            Node* temp = head;
            head = head->next;
            if (!head) tail = nullptr;
            delete temp;
            size--;
            return true;
        }
        
        Node* current = head;
        while (current->next)
        {
            if (current->next->key == key)
            {
                Node* temp = current->next;
                current->next = temp->next;
                if (!current->next) tail = current;
                delete temp;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    bool Includes(const Map<K,V>& map) const
    {
        Node* current = map.head;
        while (current)
        {
            bool found = false;
            Node* search = head;
            while (search)
            {
                if (search->key == current->key)
                {
                    found = true;
                    break;
                }
                search = search->next;
            }
            if (!found) return false;
            current = current->next;
        }
        return true;
    }
    
    class Iterator
    {
    private:
        Node* current;
        int idx;
        
    public:
        Iterator(Node* node, int index) : current(node), idx(index) {}
        
        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }
        
        void operator++()
        {
            current = current->next;
            idx++;
        }
        
        auto operator*() const
        {
            return std::tuple<K, V, int>(current->key, current->value, idx);
        }
    };
    
    Iterator begin() const
    {
        return Iterator(head, 0);
    }
    
    Iterator end() const
    {
        return Iterator(nullptr, size);
    }
};
