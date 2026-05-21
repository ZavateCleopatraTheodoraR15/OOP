#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum class ContactType { Friend, Acquaintance, Colleague };

class Contact {
public:
    string name;
    virtual ContactType getType() const = 0;
    Contact(string n) : name(n) {}
    virtual ~Contact() {}
};

class Friend : public Contact {
public:
    string dob, phone, address;
    Friend(string n, string d, string p, string a)
        : Contact(n), dob(d), phone(p), address(a) {
    }
    ContactType getType() const override { return ContactType::Friend; }
};

class Acquaintance : public Contact {
public:
    string phone;
    Acquaintance(string n, string p) : Contact(n), phone(p) {}
    ContactType getType() const override { return ContactType::Acquaintance; }
};

class Colleague : public Contact {
public:
    string phone, company, address;
    Colleague(string n, string p, string c, string a)
        : Contact(n), phone(p), company(c), address(a) {
    }
    ContactType getType() const override { return ContactType::Colleague; }
};

class AddressBook {
    vector<Contact*> contacts;
public:
    void add(Contact* c) { contacts.push_back(c); }

    void remove(string name) {
        auto it = remove_if(contacts.begin(), contacts.end(),
            [&](Contact* c) { return c->name == name; });
        if (it != contacts.end()) {
            delete* it;
            contacts.erase(it, contacts.end());
        }
    }

    Contact* search(string name) {
        for (auto c : contacts) if (c->name == name) return c;
        return nullptr;
    }

    void listFriends() {
        for (auto c : contacts)
            if (c->getType() == ContactType::Friend) cout << c->name << endl;
    }

    ~AddressBook() { for (auto c : contacts) delete c; }
};

int main() {
    AddressBook book;
    book.add(new Friend("Ion", "01-01-1990", "0700", "Strada A"));
    book.add(new Acquaintance("Maria", "0711"));

    book.listFriends();

    Contact* c = book.search("Ion");
    if (c) cout << "Gasit: " << c->name << endl;

    book.remove("Maria");

    return 0;
}
