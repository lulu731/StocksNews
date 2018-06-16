#include "src/stocks_news.hpp"
#include <iostream>
#include <string>

using namespace std;

const int update(1), display(2);

void help() {
		cout << "usage : ./stocksnews Paris --update" << endl;
		cout << "./stocksnews Paris --display 3" << endl;
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		help();
		return EXIT_FAILURE;
	};

	string Argv1(argv[1]);
	StocksNews sn(Argv1);
	string Argv2(argv[2]);
	int ArgValue;
	if (Argv2 == "--update") {
		ArgValue = update;
	}
	if (Argv2 == "--display") {
		ArgValue = display;
	}

	switch(ArgValue){
		case update : {
			sn.UpdateNews();
			break;
		}
		case display : {
			string Argv3(argv[3]);
			cout <<  sn.Results(stoi(Argv3)) ;
			break;
		}
		default : help();
			break;
	}
	return EXIT_SUCCESS;
}