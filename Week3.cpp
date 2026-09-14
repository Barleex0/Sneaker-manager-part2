#include <iostream>
#include <string>
#include <map>

const char  Guide1[] = "Select a brand :\n"
"\n"
"1. Nike\n"
"2. Adidas\n"
"3. Jordan\n"
"4. New Balance\n"
"5. Puma\n";

const char Guide2[] = "Select a condition :\n"
"\n"
"1. New\n"
"2. Excellent\n"
"3. Good\n"
"4. Fair\n"
"5. Poor\n";

enum Brand {Nike=1,Adidas,Jordan,NewBalance,Puma};
std::map<int, std::string> brandz{ {1,"Nike"},{2,"Adidas"},{3,"Jordan"},{4,"New Balance"},{5,"Puma"} };

enum Cond {New=1,Excellent,good,Fair,Poor};
std::map<int, std::string> condz{ {1,"New"},{2,"Excellent"},{3,"Good"},{4,"Fair"},{5,"Poor"} };

// getting an Enum back out is non trivially difficult to do.


struct Shoes
{
	std::string name;
	Brand brand;
	Cond cond;
	float size,price,value,Diff;
};

void CaDi(Shoes& S) { S.Diff = S.value - S.price; };

void Pout(Shoes &S) {
	std::cout << "Brand :" << brandz.at(S.brand) << "\n";
	std::cout << "Condition :" << condz.at(S.cond) << "\n";
	std::cout << "Name :" << S.name << "\n";
	std::cout << "Size :" << S.size << "\n";
	std::cout << "Starting Price :" << S.price << "\n";
	std::cout << "Current Value :" << S.value << "\n";
	CaDi(S);
	std::cout << "Difference :" << S.Diff << "\n";
};

//there is so much repitition with all of this.
void main() {
	Shoes col[3];
	for (Shoes& S : col)
	{
		int interm;
		std::cout << Guide1;
		std::cin >> interm;
		S.brand = static_cast<Brand>(interm);
		std::cout << Guide2;
		std::cin >> interm;
		S.cond = static_cast<Cond>(interm);
		std::cout << "Please enter the name " << "\n";
		std::cin >> S.name;
		std::cout << "Please enter the size" << "\n";
		std::cin >> S.size;
		std::cout << "Please enter the price" << "\n";
		std::cin >> S.price;
		std::cout << "Please enter the value " << "\n";
		std::cin >> S.value;

	};
	float rT = 0,rD = 0;

	for (Shoes& S : col) {

		Pout(S);
		rT += S.price;
		rD += S.value;
	};
	std::cout << "Total Price" << rT << '\n' << "Total Value" << rD << '\n' << "total Diff :" << rD - rT;


}
