#include <iostream>
using namespace std;
//
//class Base
//{
//public:
//    Base() 
//    {
//        initialize(); // Call virtual initialization method
//    }
//
//    virtual void initialize() 
//    {
//        cout << "Base class initialized" << endl
//            <<"x = base\n\n";
//    }
//};
//
//class Derived : public Base
//{
//public:
//    Derived() 
//    {
//        initialize();
//    }
//
//    virtual void initialize() 
//    {
//        cout << "Derived class initialized" << endl
//            << "x = der\n\n";
//    }
//};
//
//int main()
//{
//    Derived d; // Output: "Derived class initialized"
//    return 0;
//}







//  Inheritance Example //
//Car "IS-A" Vehicle
//
//class Vehicle
//{
//protected:
//	int speed;
//public:
//	Vehicle()
//	{
//		speed = 0;
//		cout << "\nVehicle constructor" << endl;
//
//	}
//
//	void setSpeed(int spd)
//	{
//		speed = spd;
//	}
//	int getSpeed()
//	{
//		return speed;
//	}
//	void start()
//	{
//		cout << "\nStart Vehicle" << endl;
//	}
//	void stop()
//	{
//		cout << "\nStop Vehicle" << endl;
//
//	}
//
//};
//
//class Car : public Vehicle
//{
//private:
//	int wheels;
//public:
//	Car()
//	{
//		wheels = 0;
//		cout << "\nCar constructor" << endl;
//	}
//	void accelerate()
//	{
//		 speed++;
//		// X
//		// cannot be accessed directly, private
//		// use setters and getters of
//		// base class to access private members
//		cout << "\nCar accelerating" << endl;
//	}
//
//};

//int main()
//{
//
//	Car c1;
//	c1.start();
//	c1.accelerate();
//	c1.stop();
//	return 0;
//}

///////////////////////////////////////////////////////////////////

class PoweredDevice
{
public:
	PoweredDevice(int nPower = 0)
	{
		cout << "PoweredDevice: " <<
			nPower << endl;
	}
};

class Scanner : public virtual PoweredDevice {
public:
	Scanner(int nScanner, int nPower) : PoweredDevice(nPower)
	{
		cout << "Scanner: " << nScanner << endl;
	}
};

class Printer : public virtual PoweredDevice {
public:
	Printer(int nPrinter, int nPower) : PoweredDevice(nPower)
	{
		cout << "Printer: " << nPrinter << endl;
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int nScanner, int nPrinter, int nPower) : PoweredDevice(nPower), Scanner(nScanner, nPower), Printer(nPrinter, nPower)
	{
	}
};

//int main()
//{
//	Copier cCopier(1, 2, 3);
//}

///////////////////////////////////////////////////////////////////////////////////////

class Shape {
public:
	virtual void sayHi()
	{
		cout << "Just hi! \n";
	}
};

class Triangle : public Shape {
public:
	// overrides Shape: : sayHi (), automatically virtual
	void sayHi() { cout << "Hi from a triangle!\n"; }
};

void print(Shape obj, Shape* ptr, Shape& ref)
{

	ptr->sayHi();		// bound at run time
	ref.sayHi();		// bound at run time
	obj.sayHi();		// bound at compile time
}

//int main()
//{
//	Triangle mytri;
//	print(mytri, &mytri, mytri);
//
//	return 0;
//}