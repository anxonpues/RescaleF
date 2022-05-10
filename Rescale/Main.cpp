#include <iostream>
#include <cstdlib>
#include <limits>

double rescale(double value, double int_low, double int_high, double out_low, double out_high);
void skip();

int main(int argc, char** argv)
{
	char  np = ' ';
	char* npp = &np;
	char** nppp = &npp;
	double value{4};
	double in_low{4};
	double in_high{20};
	double out_low{-273.15};
	double out_high{860.8};
	if (argc > 1)
	{
		for (int i = 0; i < argc; i++)
		{
			std::cout.width(4);
			std::cout << i;
			std::cout << ' ';
			std::cout << argv[i] << '\n';
		}

		double value = strtod(argv[1], nppp);
		double in_low = strtod(argv[2], nppp);
		double in_high = strtod(argv[3], nppp);
		double out_low = strtod(argv[4], nppp);
		double out_high = strtod(argv[5], nppp);
	}
	else
	{
		std::cout << "\n Enter actual value : ";
		std::cin >> value;
		std::cout << "\n Enter low input : ";
		std::cin >> in_low;
		std::cout << "\n Enter high input : ";
		std::cin >> in_high;
		std::cout << "\n Enter low output : ";
		std::cin >> out_low;
		std::cout << "\n Enter high output : ";
		std::cin >> out_high;
		std::cout << "\n";
	}
	std::cout << '\n' << value << " becomes -> "
		      << rescale(value, in_low, in_high, out_low, out_high) 
		      << '\n';
	skip();
	std::cin.get();
	return 0;
}


double rescale(double value, double int_low, double int_high, double out_low, double out_high)
{
	double ind_term = (int_low * out_high - int_high * out_low) / (int_high - int_low);
	double slope = (out_high - out_low) / (int_high - int_low);
	double out_value =  slope * value - ind_term;
	return out_value;
}

void skip()
{
	for (;;) {
		int nada;
		std::cout << "\n\n  any number key to finish  ";
		std::cin >> nada;
		if (std::cin.bad() || std::cin.eof())
		{
			break;
		}
		else if (std::cin.fail()) {
			std::cin.clear(); // unset failbit
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
		}
		else {
			break;
		}
	}
}
