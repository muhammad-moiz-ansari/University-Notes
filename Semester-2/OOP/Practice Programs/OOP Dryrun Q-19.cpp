//#include<iostream>
//using namespace std;
//class mystery
//{
//private:
//	int* n;
//	int arr[3];
//public:
//	mystery() :n(new int(5)), arr{ *n, *n + 1, *n + 2 }
//	{
//		(*this)(4, 2) = 8;
//	}
//	mystery(int nn) :n(new int), arr{ nn, nn + 1, nn + 2 }
//	{
//		*n = nn;
//	}
//	mystery(const mystery& n)
//	{
//		this->n = new int;
//		*this->n = *n.n;
//		this->arr[0] = n.arr[0];
//		this->arr[1] = n.arr[1];
//		this->arr[2] = n.arr[2];
//	}
//	mystery display()
//	{
//		cout << *n << " " << arr[0] << " ";
//		return *this;
//	}
//	int increase()
//	{
//		*n += 1;
//		return *n;
//	}
//	operator int()
//	{
//		return *n + 3;
//	}
//	int& operator() (int ss, int pr)
//	{
//		*n += ss;
//		return this->arr[ss - pr];
//	}
//	~mystery()
//	{
//		cout << "Bye " << *n + arr[1] << endl;
//	}
//};
//int main() 
//{
//	static mystery b(1), c = b, d;
//	b = c = d;
//	mystery a(d);
//	a.increase();
//	a.display().increase();
//	mystery l = b.display().increase();
//	l.display().increase();
//	static mystery s = l.increase();
//	s(5, 3) = 6;
//	b(4, 3) = 1;
//	a(8, 8) = 7;
//
//	return 0;
//}


/////////// Q-21 //////////////

//#include<iostream>
//using namespace std;
//class Num {
//	int* n;
//	static int c;
//public:
//	Num() :n(new int) {
//		*n = 4;
//	}
//	Num(int* nn) :n(nn) {
//		c++;
//		cout << *n << " " << c << endl;
//	}
//	Num(Num& otherNum) :n(otherNum.n) {
//		cout << *n << " " << endl;
//		*n += 4;
//		c++;
//	}
//	void display()const {
//		cout << *n << "" << endl;
//	}
//	void display(Num n)const {
//		*n.n = +1;
//		cout << *(this->n) << "" << endl;
//	}
//	~Num() {
//		cout << c << " " << *n << endl;
//		--c;
//	}
//};
//int Num::c = 0;
//int main() {
//	Num a; int n = 8;
//	Num b(&n);
//	const Num c(a);
//	c.display();
//	a.display(b);
//	cout << "--------" << endl;
//}


//////////// Q-22:

//#include<iostream>
//using namespace std;
//class A {
//	int x;
//public:
//	A(int a) :x(a) {
//		cout << x << endl;
//	};
//	~A() {
//		cout << x << endl;
//	}
//};
//A a(2);
//int main(int argc, char* argv[])
//{
//	static A b(3);
//	{
//		A c(4);
//	}
//}

///////////// Q-23:

//

/////////////////// Question – 24:

//#include<iostream>
//using namespace std;
//class Complex
//{
//	double r, i;
//public:
//	Complex(double r = 1.0, double i = 1.0)
//	{
//		set(r, i);
//	}
//	void set(double r, double i)
//	{
//		Complex::r = r;
//		this->i = i;
//	}
//	void print()
//	{
//		if (i < 0)
//			cout << r << "" << i << "i" << endl;
//		else
//			cout << r << "+" << i << "i" << endl;
//	}
//	Complex operator+(Complex R)
//	{
//		Complex tmp;
//		tmp.r = r + R.r;
//		tmp.i = i + R.i;
//		return tmp;
//	}
//	Complex operator++()
//	{
//		Complex tmp = *this;
//		r++;
//		i++;
//		return tmp;
//	}
//	Complex operator++(int)
//	{
//		++(*this);
//		return *this;
//	}
//};
//int main()
//{
//	Complex A(3, 4), B(5, -6);
//	A.print();
//	B.print();
//	Complex C;
//	C = A + B;
//	C.print();
//	(++A).print();
//	C = ++A;
//	C.print();
//	(A++).print();
//	A.print();
//}

///////////////////////// Question – 25:

//#include<iostream>
//using namespace std;
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0)
//	{
//		this->x = x;
//		Point::y = y;
//		(*this)();
//	}
//	void operator()()
//	{
//		cout << " (" << x << ", " << y << ") " << endl;
//	}
//	Point& operator()(int y)
//	{
//		this->y = y;
//		return *this;
//	}
//	~Point()
//	{
//		cout << "Point is going";
//		(*this)();
//	}
//}p3;
//int main()
//{
//	Point* p = new Point(5, 6);
//	static Point p1(p3);
//	p1(9)(8);
//	delete p;
//	Point p2(7);
//	cout << "----------" << endl;
//}

///////////////////////////////// Question – 26:

//#include<iostream>
//using namespace std;
//class ItsMagic {
//public:
//	int* value;
//	ItsMagic(int n = 8) : value(new int[n - 5] {n})
//	{
//		for (int i = 0; i < n - 7; i++)
//			*(value + i + 1) = *(value + i) + i + 3;
//		cout << "Hello <:> " << value[2] << endl;
//	}
//	ItsMagic(const ItsMagic& oh)
//	{
//		this->value = oh.value + 1;
//		*this->value = *oh.value + 5;
//		(*this)(oh.value + 1);
//		cout << "Oh Ho <:> " << value[2] << endl;
//	}
//	int& operator()(int* a)
//	{
//		*(this->value + 2) = *a++;
//		cout << "Is it you -): " << *this->value << endl;
//		return *(this->value + 1);
//	}
//	void increase(int& n)
//	{
//		static int N = 5;
//		n = N++;
//		if (n % 3 == 2)
//			this->twice(N);
//		cout << "Seriously -> " << N << endl;
//	}
//	void twice(int& n)
//	{
//		static int N = 6;
//		n = ++N;
//		if (n % 4 == 0)
//			this->increase(N);
//		cout << "Please -> " << N << endl;
//	}
//	~ItsMagic()
//	{
//		int s = 3;
//		cout << "Don't..... ";
//		this->increase(s);
//		cout << s << endl;
//	}
//};
//class NoWay {
//public:
//	ItsMagic okay;
//	int s;
//	NoWay(int a) :okay(a)
//	{
//		s = *okay.value + 3;
//		cout << *(okay.value + 2) << endl;
//		cout << "Its Okay :) " << okay(okay.value) << endl;
//	}
//	ItsMagic& neverMind()
//	{
//		okay.increase(s);
//		cout << "Never Mind :( " << s + okay(okay.value + 1) << endl;
//		return okay;
//	}
//	~NoWay()
//	{
//		int sum = 0;
//		cout << "Are you going ? \n";
//		for (int i = 0; i < 3; i++)
//			sum += okay.value[i];
//		cout << "Here take this -> " << sum << endl;
//	}
//};
//void comeHere(ItsMagic boo)
//{
//	boo(boo.value);
//	cout << "Bye :( " << *boo.value++ << endl;
//}
//int main()
//{
//	ItsMagic isIt;
//	NoWay areYou(10);
//	comeHere(areYou.neverMind());
//}

//////////////////////

#include <iostream>
using namespace std;

class A {
public:
	A(int ii = 0) : i(ii), s(new int{ i + 1 }) {}
	A(const A& abc)
	{
		this->i = abc.i;
		this->s = new int(*(abc.s));
		cout << "Out Of " << i + *s << endl;
	}
	A magic(A abc) 
	{
		A bcd(2);
		return abc;
	}
	~A() { cout << "Out A " << i << endl; }
private:
	int i;
	int* s;
};
int main()
{
	A b(3), a(4);
	a = b.magic(a).magic(b);
}