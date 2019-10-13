#include "BitParzystosci.h"
#include "CRC.h"

int main()
{
	BitParzystosci TEST;
	TEST.get_file_contents("test.txt");
	TEST.show_bits();
	TEST.generate_errors(20);
	TEST.show_bits();
	TEST.is_it_odd();
	TEST.check();
	TEST.set_file_contents("test3.txt");

	CRC TEST2;
	TEST2.get_file_contents("test.txt");
	TEST2.add_CRC_key(std::vector<bool>{1, 0, 1, 0, 1});
	TEST2.show_bits();
	TEST2.generate_errors(5);
	TEST2.check(std::vector<bool>{1, 0, 1, 0, 1});


	return 0;
}