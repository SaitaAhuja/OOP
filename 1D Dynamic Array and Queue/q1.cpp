#include <iostream>
using namespace std;

class ArrayMultiplier {
public:
    virtual void input() = 0;
    virtual void calculate() = 0;
    virtual ~ArrayMultiplier() {}
};

// ================= 1D =================
class ArrayMultiplier1D : public ArrayMultiplier {
    int n1, n2;
    int *A, *B;

public:
    ArrayMultiplier1D(int n1, int n2) {
        this->n1 = n1;
        this->n2 = n2;

        if(n1 == n2) {
            A = new int[n1];
            B = new int[n2];
        } else {
            A = B = nullptr;
        }
    }

    void input() override {
        if(n1 != n2) return;

        cout << "Enter 1D Array A:\n";
        for(int i = 0; i < n1; i++)
            cin >> A[i];

        cout << "Enter 1D Array B:\n";
        for(int i = 0; i < n2; i++)
            cin >> B[i];
    }

    void calculate() override {
        if(n1 != n2) {
            cout << "1D multiplication not possible\n";
            return;
        }

        cout << "\n1D Result:\n";
        for(int i = 0; i < n1; i++)
            cout << A[i] * B[i] << " ";
        cout << endl;
    }

    ~ArrayMultiplier1D() {
        delete[] A;
        delete[] B;
    }
};

// ================= 2D =================
class ArrayMultiplier2D : public ArrayMultiplier {
    int r1, c1, r2, c2;
    int **A, **B;

public:
    ArrayMultiplier2D(int r1, int c1, int r2, int c2) {
        this->r1 = r1;
        this->c1 = c1;
        this->r2 = r2;
        this->c2 = c2;

        A = new int*[r1];
        B = new int*[r2];

        for(int i = 0; i < r1; i++)
            A[i] = new int[c1];

        for(int i = 0; i < r2; i++)
            B[i] = new int[c2];
    }

    void input() override {
        cout << "Enter Matrix A:\n";
        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c1; j++)
                cin >> A[i][j];

        cout << "Enter Matrix B:\n";
        for(int i = 0; i < r2; i++)
            for(int j = 0; j < c2; j++)
                cin >> B[i][j];
    }

    void calculate() override {

        if(c1 != r2) {
            cout << "2D multiplication not possible (c1 != r2)\n";
            return;
        }

        int **C = new int*[r1];

        for(int i = 0; i < r1; i++) {
            C[i] = new int[c2];
            for(int j = 0; j < c2; j++)
                C[i][j] = 0;
        }

        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c2; j++) {
                for(int k = 0; k < c1; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "\n2D Result:\n";
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c2; j++)
                cout << C[i][j] << " ";
            cout << endl;
        }

        for(int i = 0; i < r1; i++)
            delete[] C[i];
        delete[] C;
    }

    ~ArrayMultiplier2D() {
        for(int i = 0; i < r1; i++)
            delete[] A[i];
        delete[] A;

        for(int i = 0; i < r2; i++)
            delete[] B[i];
        delete[] B;
    }
};

// ================= MAIN (POLYMORPHISM) =================
int main() {

    ArrayMultiplier *ptr;

    // -------- 1D --------
    int n1, n2;
    cout << "Enter size of 1D A and B: ";
    cin >> n1 >> n2;

    ArrayMultiplier1D obj1(n1, n2);
    ptr = &obj1;
    ptr->input();
    ptr->calculate();

    // -------- 2D --------
    int r1, c1, r2, c2;
    cout << "\nEnter A (r c): ";
    cin >> r1 >> c1;

    cout << "Enter B (r c): ";
    cin >> r2 >> c2;

    ArrayMultiplier2D obj2(r1, c1, r2, c2);
    ptr = &obj2;
    ptr->input();
    ptr->calculate();

    return 0;
}