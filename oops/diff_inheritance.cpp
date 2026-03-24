#include <bits/stdc++.h>
using namespace std;

class A {
public:
    void showA() { cout << "Class A\n"; }
};

class B : public A {
public:
    void showB() { cout << "Class B (public inheritance)\n"; }
};

class C : virtual protected A {
public:
    void showC() {
        cout << "Class C (protected inheritance)\n";
        showA();
    }
};

class D : private A {
public:
    void showD() {
        cout << "Class D (private inheritance)\n";
        showA();
    }
};

class E : public B {
public:
    void showE() {
        cout << "Class E (multilevel)\n";
        showA();
        showB();
    }
};

class F :virtual public A, public C {
public:
    void showF() {
        cout << "Class F (multiple)\n";
        showA();
        showC();
    }
};

class G : public A {
public:
    void showG() { cout << "Class G (hierarchical)\n"; }
};

int main() {
    B b;
    b.showA();
    b.showB();

    C c;
    c.showC();

    D d;
    d.showD();

    E e;
    e.showE();

    F f;
    f.showF();

    G g;
    g.showA();
    g.showG();

    return 0;
}
