
#include    <iostream>
#include    <fstream>
#include    <cctype>

#include    "token.h"
#include    "functions.h"

using namespace std;


int main()
{
	parser();                  // parser( ) calls the first production
							   // in the grammar
	return 0;
}


void parser()
{
	ifstream ifs = get_ifs(); // input file stream w/ the sentences

	while (1)
	{
		Token t = lexan(ifs);

		if (t.toktype() == DONE)
		{
			break;
		}

		cout << t << '\n';      // display the current token
		system("pause");
	}
}

