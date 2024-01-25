#include<iostream>
#include<cstring>
using namespace std;
class String{
    public:
    String():buffer{nullptr}, len{0}{
        cout << "Default constructor"<<endl;
    }
    String(const char *str){
        cout << "Parameterized constructor"<<endl;
        int length = strlen(str);
        buffer = new char[length+1];
        strcpy(buffer, str);
        len = length;
    }
    String(const String& str){
        cout << "Copy constructor"<<endl;
        len = str.len;
        buffer = new char[len+1];
        strcpy(buffer, str.buffer);
    }
    String& operator=(const String& str){
        cout << "Copy Assigment"<<endl;
        if(this != &str){
            delete[] buffer;
            len = str.len;
            buffer = new char[len+1];
            strcpy(buffer, str.buffer);
        }
        return *this;
    }
    String(String&& str){
        cout << "Move constructor"<<endl;
        len = str.len;
        buffer = str.buffer;
        str.buffer = nullptr;
        str.len = 0;
    }
    String& operator=(String && str){
        cout << "Move Assigment"<<endl;
        if(this != &str){
            len = str.len;
            buffer = str.buffer;
            str.buffer = nullptr;
            str.len = 0;
        }
        return *this;
    }
    ~String(){
        cout << " Destructor"<<endl;
        delete[] buffer;
    }
    friend ostream& operator<<(ostream &out, const String &str);
    friend istream& operator>>(istream &in, String &str);
    private:
    char *buffer;
    int len;
};
ostream& operator<<(ostream &out, const String &str){
    if(str.buffer!= nullptr)
	out << str.buffer;
    return out;
}
istream& operator>>(istream &in, String &str){
    char temp[100];
    in >> temp;
    delete[] str.buffer;
    str.buffer = new char[strlen(temp)+1];
    strcpy(str.buffer,temp);
    return in;
}

int main(){
    String str1; // default constructor
    String str2 = "Hello"; // Prameterised Constructor
    String str3 = str2; // copy constrcutor
    str1 = str2; //copy assignment
    String s4 = std::move(str2); // move constructor
    str1 = std::move(str3); // move assignment
    cout << str1 << endl;
    String str6;
    string str7;
    cout << str6 << str7 << endl;
    String str8("Ram");
    String str9(str1);
    cout << str9 << " " << str8 << endl;
}
