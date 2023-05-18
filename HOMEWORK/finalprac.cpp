#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

std::istream& read(std::istream& is, std::vector<std::string>& vec)
{
    vec.clear();
    std::string s;
    while (is >> s)
        vec.push_back(s);
    is.clear();
    return is;
}

struct Data{
    std::string name;
    std::string address;
    Data(std::string name, std::string address) : name(name), address(address){}
};

class Person{
    private:
        std::string name;
        
    protected:
        std::string address;
        std::string getAddress() const {return address;}
    public:
        // constructor
        Person() = delete;
        Person(std::string name, std::string address) : name(name), address(address){}
        
        // copy constructor
        Person(const Person& p) : name(p.name), address(p.address){}

        // operation
        Person& operator=(const Person& p){
            name = p.name;
            address = p.address;
            return *this;
        }

        bool operator==(const Person& p){
            return name == p.name && address == p.address;
        }
        
        // method
        std::string getName() const {return name;}
        virtual void print() const {std::cout << name << address << "{No class}" << std::endl;}
};

class Worker: public Person{
    private:
        std::string company;
    public:
        Worker() = delete;
        Worker(std::string name, std::string address, std::string company) : Person(name, address), company(company){}
        Worker(Person p, std::string company) : Person(p), company(company){}

        std::string getCompany() const {return company;}
        virtual void print() const override {std::cout << getName() << getAddress() << getCompany() << std::endl;}
};

class Student: public Person{
    private:
        std::string school;
    public:
        Student() = delete;
        Student(std::string name, std::string address, std::string school) : Person(name, address), school(school){}
        Student(Person p, std::string school) : Person(p), school(school){}
        std::string getSchool() const {return school;}
        virtual void print() const override {std::cout << getName() << getAddress() << getSchool() << std::endl;}
};

void split(std::string& s, std::vector<std::string>& v, char delim = ' '){
    std::stringstream ss(s);
    std::string item;
    while(getline(ss, item, delim)){
        v.push_back(item);
    }
}

int main(){

    using PersonPtr = std::unique_ptr<Person>;

    // std::vector<std::string> v;
    // read(std::cin, v);
    // for (int i = 0; i < v.size(); i++){
    //     std::cout << v[i] << std::endl;
    // }

    // std::stringstream ss("1 2 3;4 5 6;7 8 9 10");
    // std::vector<std::string> v2;
    // std::string line;
    // while(getline(std::cin, line, ';')){
    //     v2.push_back(line);
    // }

    // for (int i = 0; i < v2.size(); i++){
    //     std::cout << v2[i] << std::endl;
    // }

    Worker w("John", "123", "Google");
    Student s("Jane", "456", "MIT");

    PersonPtr p1 = std::make_unique<Worker>(w);
    PersonPtr p2 = std::make_unique<Student>(s);

    std::vector<PersonPtr> v3;
    v3.push_back(std::move(p1));
    v3.push_back(std::move(p2));

    for (int i = 0; i < v3.size(); i++){
        v3[i]->print();
    }

    Data data("John", "123");

    Person a("John", "123");
    Person b("John", "123");

    Person c(a);

    Person d = a;

    std::cout << (a == b) << std::endl;

    return 0;
}