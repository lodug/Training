#include <iostream>

// Loop between 5 and 1
int main()
{
	int outer{ 5 };
	while (outer >= 1)
	{
		// loop between outer and 1
		int inner{ outer };
		while (inner >= 1)
        {
			std::cout << inner-- << ' ';
        }

		// print a newline at the end of each row
		std::cout << '\n';
		--outer;
	}

	return 0;
}