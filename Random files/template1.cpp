#include <iostream>
using namespace std;

template <class T1, class T2>

class MyClass{

    public:
        T1 data1;
        T2 data2;
        MyClass(T1 a, T2 b){
            data1 = a;
            data2 = b;
        }

        void display(){
            cout << this -> data1 << endl << this -> data2 << endl;
        }
};

int main(){

    MyClass <int , char> myClass(3, 'c');
    myClass.display();

    return 0;
}