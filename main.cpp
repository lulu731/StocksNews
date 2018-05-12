#include "src/stocks_news.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    StocksNews sn("Paris");
	sn.UpdateNews();
	std::cout <<  sn.Results(3);
	//std::cout << "Hello World" << std::endl;
    return 0;
}
