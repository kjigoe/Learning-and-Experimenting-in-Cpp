/*
assign      ->  id  =  expr

id          ->  a | b | ... | z

expr        ->  term  moreterms

moretemrs   ->  + term  moreterms | - term moreterms | Epsilon

term        ->  factor  morefactors

morefactors ->  * factor  morefactors | / factor morefactors | Epsilon

factor      ->  (expr) | id | digit

digit       ->  0 | 1 | ... | 9

*/

#include    <iostream>
#include    <string>
using namespace std;

#include    "Header.h"


char lookahead = ' ';           // lookahead token; not available yet


int main()
{
	parser();                  // parser( ) calls the first production
							   // in the grammar
	return 0;
}


void parser()
{
	match(' ');               // get first token

	assign();                  // handle assign production
	cout << lookahead;          // newline character
	system("pause");
}


void assign()
{
	id();                      // handle id
	match('=');               // assignment character
	expr();
	cout << "=\n";
	system("pause");
}


void expr()                    // expr -> term  moreterms
{
	term();
	moreterms();
}


void moreterms()               // moreterms ->  +  term  moreterms | - term moreterms
{
	while (1)
	{
		if (lookahead == '+')
		{
			match('+');       // consume '+' token and get next one
			term();            // factor must follow '+'
			cout << "+ ";       // postfix notation
			system("pause");
		}
		if (lookahead == '-')
		{
			match('-');       // consume '-' token and get next one
			term();            // factor must follow '-'
			cout << "- ";       // postfix notation
			system("pause");
		}
		else
		{
			return;             // no + or - operator
		}
	}
}


void term()                    // term -> factor  morefactors
{
	factor();
	morefactors();
}


void morefactors()             // morefactors ->  *  factor  morefactors | / factor morefactors
{
	while (1)
	{
		if (lookahead == '*')
		{
			match('*');       // consume '*' token and get next one
			factor();          // factor must follow '*'
			cout << "* ";       // postfix notation
			system("pause");
		}
		if (lookahead == '/')
		{
			match('/');       // consume '/' token and get next one
			factor();          // factor must follow '/'
			cout << "/ ";       // postfix notation
			system("pause");
		}
		else
		{
			return;             // no * or / operator
		}
	}
}


void factor()                  // factor -> (expr) | id | digit
{
	if (lookahead != '(' )     // it is an id
	{
		id();
	}
	else                        // it must be an (expr)
	{
		match('(');
		expr();
		match(')');
	}
}


void id()						//because no calculations are being done, an int (0,1,2...,9) can be considered a char in this case
{
	if (lookahead == 'a' ||
		lookahead == 'b' ||
		lookahead == 'c' ||
		lookahead == 'd' ||
		lookahead == 'e' ||
		lookahead == 'f' ||
		lookahead == 'g' ||
		lookahead == 'h' ||
		lookahead == 'i' ||
		lookahead == 'j' ||
		lookahead == 'k' ||
		lookahead == 'l' ||
		lookahead == 'm' ||
		lookahead == 'n' ||
		lookahead == 'o' ||
		lookahead == 'p' ||
		lookahead == 'r' ||
		lookahead == 's' ||
		lookahead == 't' ||
		lookahead == 'u' ||
		lookahead == 'v' ||
		lookahead == 'w' ||
		lookahead == 'x' ||
		lookahead == 'y' ||
		lookahead == 'z' ||
		lookahead == '0' ||
		lookahead == '1' ||
		lookahead == '2' ||
		lookahead == '3' ||
		lookahead == '4' ||
		lookahead == '5' ||
		lookahead == '6' ||
		lookahead == '7' ||
		lookahead == '8' ||
		lookahead == '9')
	{
		cout << lookahead << ' ';
		system("pause");
		match(lookahead);
	}
	else
	{
		error(lookahead);
	}
}

void match(char t)
{
	if (lookahead == t)
	{
		lookahead = cin.get(); // get a character or EOF
	}
	else
	{
		error(lookahead);
	}
}

void error(char t)
{
	cerr << "\nlooking for valid input";
	cerr << "\nfound ";
	if (t == '\n')
	{
		cerr << "newline";
	}
	else
	{
		cerr << t;
	}
	cerr << "\nsyntax error. self destructing in...3\n";
	system("pause");
	cerr << "2...";
	system("pause");
	cerr << "1...";
	system("pause");
	exit(1);
}