#include "BitParzystosci.h"
#include "CRC.h"
#include "SumaModulo.h"

int main()
{
	std::cout << "------- Bit Parzystosci";
	BitParzystosci TEST;
	TEST.get_file_contents("test.txt");
	TEST.show_bits();
	TEST.generate_errors(20);
	TEST.is_it_odd();
	TEST.check();
	TEST.set_file_contents("test3.txt");

	std::cout << "------- Suma Modulo";
	SumaModulo TEST2;
	TEST2.get_file_contents("test.txt");
	TEST2.calculateModulo(128);
	TEST2.addModulo();
	TEST2.show_bits();
	TEST2.generate_errors(20);
	TEST2.check(128);

	std::cout << "------- Cykliczny kod nadmiarowy";
	CRC TEST3;
	TEST3.get_file_contents("test.txt");
	TEST3.add_CRC_key(std::vector<bool>{1, 0, 1, 0, 1});
	TEST3.show_bits();
	TEST3.generate_errors(5);
	TEST3.check(std::vector<bool>{1, 0, 1, 0, 1});

	return 0;
}