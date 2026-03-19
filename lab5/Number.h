class Number
{
private:
    char* value;
    int base;
    int digitCount;

    int convertToBase10() const;
    void convertFromBase10(int number, int newBase);

public:
    Number(const char* value, int base);
    Number(int number);
    ~Number();

    Number(const Number& other);
    Number(Number&& other);
    Number& operator=(Number&& other);
    Number& operator=(int number);
    Number& operator=(const char* str);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

    char operator[](int index) const;

    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    Number& operator+=(const Number& other);

    Number& operator--();
    Number operator--(int);
};