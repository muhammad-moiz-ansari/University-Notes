////#include <iostream>
////#include <string>
////using namespace std;
////
///////////////////////////// Q-5 //////////////////////////////
////
////class Publication {
////protected:
////    std::string title;
////    float price;
////
////public:
////    Publication() : title(""), price(0.0) {}
////    virtual ~Publication() = default;
////
////    virtual void getdata() {
////        std::cout << "Enter title: ";
////        std::getline(std::cin, title);
////        std::cout << "Enter price: ";
////        std::cin >> price;
////        std::cin.ignore(); // Clear newline character from the buffer
////    }
////
////    virtual void putdata() const {
////        std::cout << "Title: " << title << ", Price: " << price << std::endl;
////    }
////};
////
////class Book : public Publication {
////private:
////    int page_count;
////
////public:
////    Book() : page_count(0) {}
////
////    void getdata() override {
////        Publication::getdata();
////        std::cout << "Enter page count: ";
////        std::cin >> page_count;
////        std::cin.ignore(); // Clear newline character from the buffer
////    }
////
////    void putdata() const override {
////        Publication::putdata();
////        std::cout << "Page Count: " << page_count << std::endl;
////    }
////};
////
////class Tape : public Publication {
////private:
////    float playing_time;
////
////public:
////    Tape() : playing_time(0.0) {}
////
////    void getdata() override {
////        Publication::getdata();
////        std::cout << "Enter playing time (in minutes): ";
////        std::cin >> playing_time;
////        std::cin.ignore(); // Clear newline character from the buffer
////    }
////
////    void putdata() const override {
////        Publication::putdata();
////        std::cout << "Playing Time: " << playing_time << " minutes" << std::endl;
////    }
////};
////
////
////int main() 
////{
////    const int size = 5;
////    Publication** pubArray=new Publication*[size]; // Array of pointers to Publication
////
////    for (int i = 0; i < size; ++i) {
////        char choice;
////        std::cout << "Enter data for book or tape (b/t): ";
////        std::cin >> choice;
////        std::cin.ignore(); // Clear newline character from the buffer
////
////        if (choice == 'b') {
////            pubArray[i] = new Book();
////        }
////        else if (choice == 't') {
////            pubArray[i] = new Tape();
////        }
////        else {
////            std::cout << "Invalid choice, try again." << std::endl;
////            --i;
////            continue;
////        }
////
////        pubArray[i]->getdata();
////    }
////
////    std::cout << "\nDisplaying Publication Data:" << std::endl;
////    for (int i = 0; i < size; ++i) {
////        pubArray[i]->putdata();
////        delete pubArray[i]; // Clean up memory
////    }
////
////    return 0;
////}
//
//
/////////////////////////// Q-6 ////////////////////////////
//
//
//
//#include <iostream>
//using namespace std;
//
//class Bank {
//protected:
//    double balance;
//    int numDeposits;
//    int numWithdrawals;
//    double annualInterestRate;
//    double monthlyServiceCharges;
//
//public:
//    Bank(double bal, double annualRate)
//        : balance(bal), numDeposits(0), numWithdrawals(0),
//        annualInterestRate(annualRate), monthlyServiceCharges(0) {}
//
//    virtual ~Bank() = default;
//
//    virtual void deposit(double amount) {
//        balance += amount;
//        numDeposits++;
//    }
//
//    virtual void withdraw(double amount) {
//        balance -= amount;
//        numWithdrawals++;
//    }
//
//    virtual void calcInt() {
//        double monthlyInterestRate = annualInterestRate / 12.0;
//        double monthlyInterest = balance * monthlyInterestRate;
//        balance += monthlyInterest;
//    }
//
//    virtual void monthlyReport() {
//        balance -= 850; // Monthly service charge
//        calcInt();
//        numDeposits = 0;
//        numWithdrawals = 0;
//        monthlyServiceCharges = 0;
//    }
//
//    virtual void display() const {
//        std::cout << "Balance: " << balance << "\n";
//        std::cout << "Number of Deposits: " << numDeposits << "\n";
//        std::cout << "Number of Withdrawals: " << numWithdrawals << "\n";
//        std::cout << "Annual Interest Rate: " << annualInterestRate << "\n";
//        std::cout << "Monthly Service Charges: " << monthlyServiceCharges << "\n";
//    }
//};
//
//class Savings : public Bank {
//private:
//    bool status;
//
//public:
//    Savings(double bal, double annualRate)
//        : Bank(bal, annualRate), status(bal >= 25) {}
//
//    void withdraw(double amount) override {
//        if (!status) {
//            std::cout << "Account is inactive. Withdrawal denied.\n";
//            return;
//        }
//        if (balance - amount < 25) {
//            status = false;
//        }
//        Bank::withdraw(amount);
//    }
//
//    void deposit(double amount) override {
//        if (!status && balance + amount >= 25) {
//            status = true;
//        }
//        Bank::deposit(amount);
//    }
//
//    void monthlyReport() override {
//        if (numWithdrawals > 4) {
//            monthlyServiceCharges += (numWithdrawals - 4);
//        }
//        Bank::monthlyReport();
//        if (balance < 25) {
//            status = false;
//        }
//    }
//
//    void display() const override 
//    {
//        Bank::display();
//        std::cout << "Account Status: " << (status ? "Active" : "Inactive") << "\n";
//    }
//};
//
//class Checking : public Bank 
//{
//public:
//    Checking(double bal, double annualRate)
//        : Bank(bal, annualRate) {}
//
//    void withdraw(double amount) override {
//        if (balance - amount < 0) {
//            balance -= 15; // Overdraft fee
//            std::cout << "Insufficient funds. Overdraft fee charged.\n";
//            return;
//        }
//        Bank::withdraw(amount);
//    }
//
//    void monthlyReport() override 
//    {
//        monthlyServiceCharges += 5 + (0.10 * numWithdrawals); // Monthly fee + per withdrawal fee
//        Bank::monthlyReport();
//    }
//
//    void display() const override 
//    {
//        Bank::display();
//    }
//};
//
//int main() 
//{
//    int accountType;
//    double balance, annualInterestRate;
//
//    std::cout << "Enter account type (1 for Savings, 2 for Checking): ";
//    std::cin >> accountType;
//    std::cout << "Enter initial balance: ";
//    std::cin >> balance;
//    std::cout << "Enter annual interest rate: ";
//    std::cin >> annualInterestRate;
//
//    Bank* account = nullptr;
//    if (accountType == 1) {
//        account = new Savings(balance, annualInterestRate);
//    }
//    else if (accountType == 2) {
//        account = new Checking(balance, annualInterestRate);
//    }
//    else {
//        std::cout << "Invalid account type.\n";
//        return 1;
//    }
//
//    int choice;
//    do {
//        std::cout << "\n1. Deposit\n2. Withdraw\n3. Generate Monthly Report\n4. Display\n5. Exit\n";
//        std::cout << "Enter your choice: ";
//        std::cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//        {
//            double amount;
//            std::cout << "Enter amount to deposit: ";
//            std::cin >> amount;
//            account->deposit(amount);
//            break;
//        }
//        case 2:
//        {
//            double amount;
//            std::cout << "Enter amount to withdraw: ";
//            std::cin >> amount;
//            account->withdraw(amount);
//            break;
//        }
//        case 3:
//            account->monthlyReport();
//            break;
//        case 4:
//            account->display();
//            break;
//        case 5:
//            std::cout << "Exiting...\n";
//            break;
//        default:
//            std::cout << "Invalid choice. Try again.\n";
//            break;
//        }
//    } while (choice != 5);
//
//    delete account;
//    return 0;
//}
//
//
//////////////////////////////  Q - 3  ///////////////////////////////
//
//
//#include <iostream>
//using namespace std;
//
//template <typename T>
//void printArrayRange(T* arr, int count, int l, int h)
//{
//	if (l < 0 || h >= count || h <= l)
//	{
//		cout << "\nRange error.\n";
//		return;
//	}
//	else
//	{
//		cout << "\nArray Range: ";
//		for (int i = l; i <= h; ++i)
//		{
//			cout << arr[i] << "  ";
//		}
//		cout << endl;
//	}
//}
////
////int main()
////{
////	const int size = 26;
////	int intarr[size];
////	float flarr[size];
////	char charr[size];
////
////	for (int i = 0; i < size; ++i)
////	{
////		intarr[i] = i;
////		flarr[i] = 0.1 + i;
////		charr[i] = 97 + i;
////	}
////
////	printArrayRange(intarr, size, 0, 26);
////	printArrayRange(flarr, size, 3, 24);
////	printArrayRange(charr, size, 2, 25);
////
////
////
////	return 0;
////}
//
////////////////////// Q-1 ///////////////////////
//
//
//#include <iostream>
//using namespace std;
//
//void flip(int* x, int* y, int*& z)
//{
//	z = y;
//	y = x;
//	*x = 200;
//}
//
////int main()
////{
////	int i = 10;
////	int j = 20;
////	int* p = &j;
////	flip(&i, &j, p);
////	cout << "i is =" << i << endl;
////	cout << "j is =" << j << endl;
////	cout << "p is =" << --(*p) << endl;
////}
//
//
////////////////////// Q-2 //////////////////////
//
//#include <iostream>
//using namespace std;
//
//class Home 
//{
//	Home* p;
//	int NoOfRoom;
//
//public:
//	Home()
//	{
//		NoOfRoom = 6;
//	}
//
//	Home(int NoOfRoom) : NoOfRoom(4)
//	{
//		cout << NoOfRoom << endl;
//	}
//
//	Home(Home* x, const int NoOfRoom) : p(x)
//	{
//		this->NoOfRoom = NoOfRoom;
//		cout << NoOfRoom << endl;
//	}
//
//	Home& XYZ()
//	{
//		return *p;
//	}
//
//	void display();
//
//};
//
//void Home::display()
//{
//	cout << p->NoOfRoom << endl;
//}
//
////int main()
////{
////	Home r1, r2(3);
////	Home* obj = &r2;
////	Home r3(obj, 8);
////	r3.XYZ() = r1;
////	r3.display();
////
////	return 0;
////}
