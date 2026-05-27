#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;

public:
  
    DynamicArray() {
        size = 0;
        data = nullptr;
    }


    DynamicArray(int n) {
        size = n;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }


    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

   
    ~DynamicArray() {
        delete[] data;
    }

    
    int& operator[](int index) {
        return data[index];
    }

    int getSize() const {
        return size;
    }
};
int main() {
    DynamicArray a(3);
    a[0] = 10;

    DynamicArray b = a; 
    b[0] = 20;

    cout << a[0];
    return 0;
}

