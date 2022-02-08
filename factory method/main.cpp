#include<iostream>
using namespace std;
class Product {
public:
	virtual void show() = 0;
};

class AProduct
	:public Product {
public:
	void show() override {
		std::cout << "A Product\n";
	}
};


class Test {
public:
	virtual void showProduct() {
		product = createProduct();
		product->show();
	}
protected:
	virtual Product* createProduct() = 0;
private:
	Product* product;
};

class ConTest
	:public Test {
protected:
	Product* createProduct() override{
		return new AProduct;
	}
};


int main() {
	ConTest a;
	a.showProduct();
}
