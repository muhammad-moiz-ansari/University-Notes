#include <iostream>
using namespace std;

//
//class A
//{
//public:
//    A()
//    {
//        cout << "A() \n";
//    }
//    ~A()
//    {
//        cout << "~A() \n";
//    }
//    virtual void  print()
//    {
//        cout << "A" << endl;
//    }
//};
//class c : public A
//{
//public:
//    int x;
//    c()
//    {
//        cout << "C()\n";
//    }
//    ~c()
//    {
//        cout << "~C()\n";
//    }
//    virtual void  print()
//    {
//        cout << "C: " << x << endl;
//    }
//};

//int  main()
//{
//    c obj;
//    obj.x = 17;
//    A& obj2 = obj;
//    obj2.print();
//
//    c obj3;
//    obj3.x = 10;
//    obj2 = obj3;
//    obj2.print();
//}






///////////////////////////////////////////////


//
//#include <iostream>
//using namespace std;
//
//int i;
//
//class LFC
//{
//    int x;
//    int y;
//
//public:
//    LFC()
//    {
//        x = 0;
//        cout << i << endl;
//    }
//    int getX()
//    {
//        return x;
//    }
//    LFC getY()
//    {
//        return *this;
//    }
//    ~LFC()
//    {
//        cout << i << endl;
//        i = 10;
//    }
//};
//int foo(LFC obj)
//{
//    i = obj.getY().getX();
//    LFC ob;
//
//    return i;
//}

//int main()
//{
//    LFC obj;
//    cout << foo(obj) << endl;
//    return 0;
//}

///////////////////////////////////////////////

//
//#include <iostream>
//using namespace std;
//
//class Num
//{
//    int n;
//    static int c;
//
//public:
//    Num() { this->n = 7; }
//
//    Num(int nn) { n = nn; c++; display(); }
//
//    int getN()const { return this->n; }
//
//    void display() { n += c; cout << n << " " << c << endl; }
//
//    ~Num() { cout << c << " " << n << endl; --c; }
//
//}nn, * ptr;
//
//int Num::c = 0;

//int main()
//{
//
//    int n = 8;
//    if (true)
//    {
//        ptr = new Num(nn.getN());
//        const Num c(n);
//    }
//        nn.display();
//
//        cout << " ------ " << endl;
//        return 0;
//}


//
//#include<iostream>
//using namespace std;
//
//class A 
//{
//public:
//    A() { cout << "A C" << endl; }
//    ~A() { cout << "A D" << endl; }
//};
//class B 
//{
//    A a1;
//public:
//    B() { cout << "B C" << endl; }
//    ~B() { cout << "B D" << endl; }
//};
//class C 
//{
//    A* a;
//    B* b;
//public:
//    C(A* a) :a(a), b(new B) { cout << "C C" << endl; }
//    C(B* b) :b(b), a(nullptr) { cout << "D C" << endl; }
//    ~C() {
//        if (a != nullptr)
//            delete b;
//        cout << "C D" << endl;
//    }
//};
//
//int main() 
//{
//    A a; B b;
//    {
//        C c(&a);
//    }
//    C c(&b);
//    cout << "------------" << endl;
//    return 0;
//}


/////////////////// Q-1(iii) ///////////////////

//
//#include<iostream>
//#include<string>
//using namespace std;
//struct Data {
//	int d;
//	Data* ptr;
//};
//class Datachain {
//	Data* here;
//public:
//	Datachain(Data* p = NULL) : here(p) {}
//	void introduce(int x)
//	{
//		Data* temp = new Data;
//		temp->d = x;
//		temp->ptr = NULL;
//
//		if (here == NULL)
//		{
//			here = temp;
//		}
//		else
//		{
//			temp->ptr = here;
//			here = temp;
//		}
//		temp = NULL;
//	}
//	Datachain& show()
//	{
//		Data* p = here;
//		while (p != NULL)
//		{
//			cout << p->d << " ";
//			p = p->ptr;
//		}
//		cout << endl;
//		return *this;
//	}
//	void wonder(Data*& abc, Data*& xyz)
//	{
//		Data* slow = here;
//		Data* fast = here->ptr;
//
//		while (fast != NULL) {
//			fast = fast->ptr;
//			if (fast != NULL) {
//				slow = slow->ptr;
//				fast = fast->ptr;
//			}
//		}
//		abc = here;
//		xyz = slow->ptr;
//		slow->ptr = NULL;
//	}
//	Datachain& magic()
//	{
//		Data* current = here;
//		Data* prev = NULL, * next = NULL;
//
//		while (current != NULL)
//		{
//			next = current->ptr;
//			current->ptr = prev;
//			prev = current;
//			current = next;
//		}
//		here = prev;
//		return *this;
//	}
//	void sooper_magic()
//	{
//		string s = "noitseuq siht fo tuptuo fo dne eht ta yraterceS tpeD fo eman eht etirw ,skram sunoB roF";
//		reverse(s.begin(), s.end());
//		cout << s;
//	}
//};
//int main()
//{
//	Datachain d;
//	d.introduce(5);
//	d.introduce(4);
//	d.introduce(3);
//	d.introduce(2);
//	d.introduce(1);
//	d.show();
//	Data* one;
//	Data* two;
//	d.wonder(one, two);
//	Datachain d2(one);
//	Datachain d3(two);
//	d2.show();
//	d.magic().show();
//	d3.show().magic().show().sooper_magic();
//}


/////////////////// Q-1(iv) ///////////////////

//#include<iostream>
//using namespace std;
//int x = 6;
//class A {
//    int x;
//public:
//    A(int x = 0) :x(x + 1) 
//    { cout << "A C " << x << endl; }
//    ~A() { cout << "~A " << this->x << endl; }
//    int& getX() { return this->x; }
//}a;
//class B {
//    A a, * aa;
//    int x;
//public:
//    B() :x(::x), a(--::x), aa(&a) 
//    { cout << "Def B C " << x << endl; }
//    B(int x) :aa(new A(3)), x(x), a(x++) 
//    { cout << "Par B C " << x << endl; }
//    ~B() { cout << "~B " << B::x << endl; }
//}b(x);
//class C {
//    A& a;
//    int x;
//public:
//    C(A& a) :x(a.getX()++), a(a) 
//    { cout << "A C" << endl; }
//    ~C() { cout << "~C " << a.getX() << " " << x << endl; }
//};
//class D {
//    C* c;
//    B* b;
//public:
//    D(C* c) :c(c), b(new B) 
//    { cout << "C C" << endl; }
//    D(B* b, A* a) :b(new B(*b)), c(new C(*a)) 
//    { cout << "D C" << endl; }
//    ~D() { cout << "~D" << endl; delete b; }
//};
//
//int main() 
//{
//    D d1(&b, &a);
//    D d(new C(a));
//    cout << "------------" << endl;
//    return 0;
//}

/////////////////// Q-1(v) ///////////////////

//Look at the following code :

//
//#include <iostream>
//using namespace std;
//class foo {
//private:
//    int* ptr;
//
//public:
//    foo(int size) {
//        ptr = new int[size];
//    }
//
//    ~foo() {
//        delete[] ptr;
//    }
//
//    int* getPtr() const {
//        return ptr;
//    }
//};
//
//int main() 
//{
//    foo obj1(5);
//    foo obj2(obj1);
//
//    int* ptr1 = obj1.getPtr();
//    for (int i = 0; i < 5; ++i) {
//        ptr1[i] = i + 1;
//    }
//
//    int* ptr2 = obj2.getPtr();
//    for (int i = 0; i < 5; ++i) {
//        ptr2[i] = i * 2;
//    }
//
//    for (int i = 0; i < 5; ++i) {
//        cout << ptr1[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

///////////////////////////////////////////////

////Look again.Something changed.
//
//#include <iostream>
//using namespace std;
//class foo {
//private:
//    int* ptr;
//
//public:
//    foo(int size) {
//        ptr = new int[size];
//    }
//
//    ~foo() {
//        delete[] ptr;
//    }
//
//    int* getPtr() const {
//        return ptr;
//    }
//};
//
//
//void globalFunction(foo obj) {
//    int* ptr = obj.getPtr();
//    for (int i = 0; i < 5; ++i) {
//        ptr[i] = ptr[i] * -2;
//    }
//    for (int i = 0; i < 5; ++i) {
//        cout << ptr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    foo obj1(5);
//
//    int* ptr1 = obj1.getPtr();
//    for (int i = 0; i < 5; ++i) {
//        ptr1[i] = i + 1;
//    }
//
//    globalFunction(obj1);
//
//    foo obj2(obj1);
//    for (int i = 0; i < 5; ++i) {
//        cout << ptr1[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

///////////////////////////////////////////////

////Oops!!Something changed Again
//
//#include <iostream>
//using namespace std;
//class foo {
//private:
//    int* ptr;
//    int size;
//
//public:
//    foo(int size) {
//        this->size = size;
//        ptr = new int[size];
//    }
//
//    ~foo() {
//        delete[] ptr;
//    }
//
//    foo(const foo& other) {
//        this->size = other.size;
//        ptr = new int[this->size];
//        for (int i = 0; i < size; i++)
//            ptr[i] = 0;
//    }
//
//    int* getPtr() const {
//        return ptr;
//    }
//};
//
//void globalFunction(foo obj) {
//    int* ptr = obj.getPtr();
//    for (int i = 0; i < 5; ++i) {
//        ptr[i] = ptr[i] * -2;
//    }
//    for (int i = 0; i < 5; ++i) {
//        cout << ptr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    foo obj1(5);
//
//    int* ptr1 = obj1.getPtr();
//    for (int i = 0; i < 5; ++i) {
//        ptr1[i] = i + 1;
//    }
//
//    globalFunction(obj1);
//
//    foo obj2(obj1);
//    for (int i = 0; i < 5; ++i) {
//        cout << ptr1[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

