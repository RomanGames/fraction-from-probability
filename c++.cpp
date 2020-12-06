#include <iostream>
#include <string>
#include <cmath>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool starts_with(const std::string& s, const std::string& prefix) {
   auto size = prefix.size();
   if (s.size() < size) return false;
   return std::equal(std::begin(prefix), std::end(prefix), std::begin(s));
}

int main() {
	// input
	long underNumber;
	std::string underString;
	std::string numberString = "0.";
	std::cout << "勝率: 0.";
	std::cin >> underNumber;
	underNumber /= 10;
	underString = std::to_string(underNumber);
	numberString += underString.substr(0, std::min((size_t)12, underString.length()));
	// loop
	std::cout << std::endl;
	std::string format = "%." + std::to_string(underString.length() + 2) + "f";
	for (unsigned int d = 1; d != 0; d++) {
		unsigned int n = d * underNumber / std::pow(10, underString.length());
		for (char i = 0; ; i++) {
			// format
			char *c_result = new char[numberString.length() + 2 + 1];
			std::sprintf(c_result, format.c_str(), (double)(n + i) / d);
			std::string result = c_result;
			// check
			if (starts_with(result, numberString)) {
				std::cout << n + i << " / " << d << " = " << result << std::endl;
			} else if (i > 0) break;
		}
	}
	// end
	return 0;	
}
