#include <iostream>
#include <string>
using namespace std;

class Photographer {
protected:
    std::string name;
    double remuneration;

public:
    Photographer(const std::string& name) : name(name), remuneration(0) {}
    virtual ~Photographer() {}

    std::string getName() const {
        return name;
    }

    virtual void calRemuneration() = 0;
    virtual double getRemuneration() const {
        return remuneration;
    }
};

#ifndef PRODUCT_PHOTOGRAPHER_H
#define PRODUCT_PHOTOGRAPHER_H

class ProductPhotographer : virtual public Photographer {
protected:
    std::string productType;
    int nProducts;

public:
    ProductPhotographer(const std::string& name, const std::string& productType, int nProducts)
        : Photographer(name), productType(productType), nProducts(nProducts) {}

    void calRemuneration() override {
        remuneration = nProducts * 3000;
    }

    double getRemuneration() const override {
        return remuneration;
    }
};

#endif


class ArtPhotographer : virtual public Photographer {
protected:
    std::string artType;
    int nHours;

public:
    ArtPhotographer(const std::string& name, const std::string& artType, int nHours)
        : Photographer(name), artType(artType), nHours(nHours) {}

    void calRemuneration() override {
        remuneration = nHours * 1800;
    }

    double getRemuneration() const override {
        return remuneration;
    }
};


class FashionPhotographer : public ProductPhotographer, public ArtPhotographer {
public:
    FashionPhotographer(const std::string& name, int nProducts, int nHours)
        : Photographer(name), ProductPhotographer(name, "", nProducts), ArtPhotographer(name, "", nHours) {}

    void calRemuneration() override {
        remuneration = (ProductPhotographer::nProducts * 2000) + (ArtPhotographer::nHours * 1000);
    }

    double getRemuneration() const override {
        return remuneration;
    }
};


void displayEarnings(Photographer* photographer) {
    photographer->calRemuneration();
    std::cout << photographer->getName() << " earned: " << photographer->getRemuneration() << std::endl;
}
//
//int main() {
//    Photographer* productPhotographer = new ProductPhotographer("USMAN", "Furniture", 7);
//    Photographer* artPhotographer = new ArtPhotographer("AHMED", "Performing Arts", 8);
//    Photographer* fashionPhotographer = new FashionPhotographer("DAUD", 15, 4);
//
//    std::cout << "Product Photographer ";
//    displayEarnings(productPhotographer);
//    std::cout << "---------------------------------------------" << std::endl;
//
//    std::cout << "Art Photographer ";
//    displayEarnings(artPhotographer);
//    std::cout << "---------------------------------------------" << std::endl;
//
//    std::cout << "Fashion Photographer ";
//    displayEarnings(fashionPhotographer);
//    std::cout << "---------------------------------------------" << std::endl;
//
//    delete productPhotographer;
//    delete artPhotographer;
//    delete fashionPhotographer;
//
//    return 0;
//}
