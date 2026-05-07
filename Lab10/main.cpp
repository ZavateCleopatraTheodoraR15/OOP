#include <iostream>
#include <exception>

using namespace std;

class ExceptieIndex : public exception {
    virtual const char* what() const throw() {
        return "Index out of bounds!";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
    T** List;
    int Current;
    int Size;
public:
    ArrayIterator() : List(nullptr), Current(0), Size(0) {}
    ArrayIterator(T** list, int size, int current) : List(list), Size(size), Current(current) {}
    
    ArrayIterator& operator++() {
        if (Current < Size) Current++;
        return *this;
    }
    ArrayIterator& operator--() {
        if (Current > 0) Current--;
        return *this;
    }
    bool operator=(const ArrayIterator<T>& other) {
        this->List = other.List;
        this->Current = other.Current;
        this->Size = other.Size;
        return true;
    }
    bool operator!=(const ArrayIterator<T>& other) {
        return (this->Current != other.Current);
    }
    T* GetElement() {
        if (Current < Size) return List[Current];
        return nullptr;
    }
};

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}
    
    ~Array() {
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
    }

    Array(int capacity) {
        this->Capacity = capacity;
        this->Size = 0;
        this->List = new T*[Capacity];
    }

    Array(const Array<T>& other) {
        this->Capacity = other.Capacity;
        this->Size = other.Size;
        this->List = new T*[Capacity];
        for (int i = 0; i < Size; i++) this->List[i] = new T(*other.List[i]);
    }

    T& operator[](int index) {
        if (index < 0 || index >= Size) throw ExceptieIndex();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity) {
            int newCap = (Capacity == 0) ? 1 : Capacity * 2;
            T** newList = new T*[newCap];
            for (int i = 0; i < Size; i++) newList[i] = List[i];
            delete[] List;
            List = newList;
            Capacity = newCap;
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) throw ExceptieIndex();
        if (Size >= Capacity) {
            int newCap = (Capacity == 0) ? 1 : Capacity * 2;
            T** newList = new T*[newCap];
            for (int i = 0; i < Size; i++) newList[i] = List[i];
            delete[] List;
            List = newList;
            Capacity = newCap;
        }
        for (int i = Size; i > index; i--) List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T>& otherArray) {
        if (index < 0 || index > Size) throw ExceptieIndex();
        while (Size + otherArray.Size > Capacity) {
            int newCap = (Capacity == 0) ? otherArray.Size : Capacity * 2;
            T** newList = new T*[newCap];
            for (int i = 0; i < Size; i++) newList[i] = List[i];
            delete[] List;
            List = newList;
            Capacity = newCap;
        }
        for (int i = Size - 1; i >= index; i--) List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; i++) List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) throw ExceptieIndex();
        delete List[index];
        for (int i = index; i < Size - 1; i++) List[i] = List[i + 1];
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& other) {
        if (this != &other) {
            for (int i = 0; i < Size; i++) delete List[i];
            delete[] List;
            Capacity = other.Capacity;
            Size = other.Size;
            List = new T*[Capacity];
            for (int i = 0; i < Size; i++) List[i] = new T(*other.List[i]);
        }
        return true;
    }

    void Sort() {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j]) { T* temp = List[i]; List[i] = List[j]; List[j] = temp; }
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0) { T* temp = List[i]; List[i] = List[j]; List[j] = temp; }
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0) { T* temp = List[i]; List[i] = List[j]; List[j] = temp; }
    }

    int BinarySearch(const T& elem) {
        int l = 0, r = Size - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (*List[m] == elem) return m;
            if (*List[m] < elem) l = m + 1; else r = m - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int l = 0, r = Size - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int res = compare(*List[m], elem);
            if (res == 0) return m;
            if (res < 0) l = m + 1; else r = m - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int l = 0, r = Size - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            int res = comparator->CompareElements(List[m], (void*)&elem);
            if (res == 0) return m;
            if (res < 0) l = m + 1; else r = m - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) if (*List[i] == elem) return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++) if (compare(*List[i], elem) == 0) return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++) if (comparator->CompareElements(List[i], (void*)&elem) == 0) return i;
        return -1;
    }

    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(List, Size, 0); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(List, Size, Size); }
};

int main() {
    try {
        Array<int> a(2);
        a += 10;
        a += 5;
        a.Insert(1, 7);
        
        for (int i = 0; i < a.GetSize(); i++) cout << a[i] << " ";
        cout << endl;

        a.Sort();
        for (int i = 0; i < a.GetSize(); i++) cout << a[i] << " ";
        cout << endl;

        cout << a[10] << endl;
    }
    catch (exception& e) {
        cout << "Exceptie: " << e.what() << endl;
    }
    return 0;
}
