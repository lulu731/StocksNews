#include "src/stocks_news.hpp"
#include <iostream>
#include <string>

using namespace std;

const int update(1), maxrate(2), maxnumbers(3);

void help() {
		printf("usage : ./stocksnews Paris --update\n");
		printf("./stocksnews Paris --maxrate 3\n");
		printf("./stocksnews Paris --maxnumbers 5\n");
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
	if (Argv2 == "--maxrate") {
		ArgValue = maxrate;
	}
if (Argv2 == "--maxnumbers") {
		ArgValue = maxnumbers;
	}
	switch(ArgValue){
		case update : {
			sn.UpdateNews();
			break;
		}
		case maxrate : {
			string Argv3(argv[3]);
			cout <<  sn.Results(stoi(Argv3)) ;
			break;
		}
		case maxnumbers : {
			string Argv3(argv[3]);
			cout <<  sn.Results(stoi(Argv3)) ;
			break;
		}
		default : help();
			break;
	}
	return EXIT_SUCCESS;
}