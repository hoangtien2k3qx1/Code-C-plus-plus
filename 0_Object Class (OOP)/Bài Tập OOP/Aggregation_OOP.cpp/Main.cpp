
#include "Customer.cpp"
#include "Invoice.cpp"

int main() {
	Customer customer1(1000, "Hoang Anh Tien", 20);
	Invoice invoice1(1000, customer1, 100000);
	cout << "Customer name: " << invoice1.getCustomerName() << endl;
	cout << "Invoice after discount: " << invoice1.getAmountAfterDiscount() << endl;

	return 0;
}
