
#include    <iostream>
#include    <fstream>
#include    <cctype>

#include    "token.h"
#include    "functions.h"

using namespace std;
int lineno = 1;
extern ifstream ifs;     // input file stream to read from


Token lexan(ifstream &ifs) {                // lexical analyzer
	int     t;
	int		t1;
	int		t2;
	int		t3;
	int		t4;
	int		t5;
	int		t6;
	int		t7;
	int		t8;
	int		t9;
	string  tokstr;                         // empty tokstr

	while (1) {
		t = ifs.get();                     // get next character

		if (t == '\n') {
			lineno++;
		}
		
		else if (isspace(t)) {				  // handle whitespace chars and line number
			if (t == '\n') {
				lineno++;
			}
			continue;
		}
							  
		// handle int constants with a single digit
		else if (isdigit(t)) {             // t is a digit
			tokstr.push_back(t);
			t3 = ifs.get();
			while (1) {
				if (t3 == '\n') {
					lineno++;
					return Token(tokstr, NUM, stoi(tokstr), lineno);
					break;
				}
				else if (isspace(t3) || isalpha(t3)) {
					return Token(tokstr, NUM, stoi(tokstr), lineno);
					break;
				}
				else {
					tokstr.push_back(t3);
					t3 = ifs.get();
					continue;
				}
			}
		}

		// handle id with a single char
		else if (isalpha(t)) {            // t is a letter
			tokstr.push_back(t);
			t2 = ifs.get();
			while (1) {
				if (t2 == '\n') {
					lineno++;
					return Token(tokstr, ID, 0, lineno);
					break;
				}
				else if (isspace(t2)) {
					return Token(tokstr, ID, 0, lineno);
					break;
				}
				else {
					tokstr.push_back(t2);
					t2 = ifs.get();
					continue;
				}
			}
		}

		else if (t == '/') {
			t1 = ifs.get();
			while (1) {
				if (t1 == '\n') {
					lineno++;
					break;
				}
				else {
					t1 = ifs.get();
					continue;
				}
			}
		}

		else if (t == '=') {
			tokstr.push_back(t);
			t4 = ifs.get();
			if (isspace(t4)) {
				return Token(tokstr, OPER, 0, lineno);
				break;
			}
			else if (t4 == '=') {
				tokstr.push_back(t4);
				return Token(tokstr, EQ_OPER, EQ_EQUAL, lineno);
				break;
			}
		}

		else if (t == '!') {
			tokstr.push_back(t);
			t5 = ifs.get();
			if (t5 == '=') {
				tokstr.push_back(t5);
				return Token(tokstr, EQ_OPER, EQ_NOTEQUAL, lineno);
				break;
			}
			else {
				cerr << "lexan( ): ignoring invalid eq_oper '" << char(t) << "'\n"
					<< "in line " << lineno << '\n';
			}
		}

		else if (t == '<') {
			tokstr.push_back(t);
			t6 = ifs.get();
			if (isspace(t6)) {
				return Token(tokstr, REL_OPER, LESS, lineno);
				break;
			}
			else if (t6 == '=') {
				tokstr.push_back(t6);
				return Token(tokstr, REL_OPER, LESS_EQ, lineno);
				break;
			}
			else {
				cerr << "lexan( ): ignoring invalid rel_oper '" << char(t) << "'\n"
					<< "in line " << lineno << '\n';
			}
		}

		else if (t == '>') {
			tokstr.push_back(t);
			t7 = ifs.get();
			if (isspace(t7)) {
				return Token(tokstr, REL_OPER, GREATER, lineno);
				break;
			}
			else if (t7 == '=') {
				tokstr.push_back(t7);
				return Token(tokstr, REL_OPER, GREATER_EQ, lineno);
				break;
			}
			else {
				cerr << "lexan( ): ignoring invalid rel_oper '" << char(t) << "'\n"
					<< "in line " << lineno << '\n';
			}
		}

		else if (t == '&') {
			tokstr.push_back(t);
			t8 = ifs.get();
			if (isspace(t8)) {
				cerr << "lexan( ): ignoring invalid logic_oper '" << char(t) << "'\n"
					<< "in line " << lineno << '\n';
			}
			else if (t8 == '&') {
				tokstr.push_back(t8);
				return Token(tokstr, LOGIC_OPER, LOGIC_AND, lineno);
				break;
			}
			else {
				cerr << "lexan( ): ignoring invalid logic_oper '" << char(t) << "'\n"
					<< "in line " << lineno << '\n';
			}
		}

		else if (t == '|') {
			tokstr.push_back(t);
			t9 = ifs.get();
			if (isspace(t9)) {
				cerr << "lexan( ): ignoring invalid logic_oper '" << char(t) << "'\n"
					<< "in line " << lineno << '\n';
			}
			else if (t9 == '|') {
				tokstr.push_back(t9);
				return Token(tokstr, LOGIC_OPER, LOGIC_OR, lineno);
				break;
			}
			else {
				cerr << "lexan( ): ignoring invalid logic_oper '" << char(t) << "'\n"
					<< "in line " << lineno << '\n';
			}
		}

		else if (t == EOF)
		{                                   // EOF ends the input
			return Token("", DONE, 0, lineno);
		}
		else
		{
			tokstr.push_back(t);
			return Token(tokstr, OPER, t, lineno);
		}
	}
}

ifstream get_ifs()                         // get input file stream
{
	string filename;                        // input file name

	cerr << "name of file to read from? ";
	cin >> filename;

	ifstream ifs(filename, ifstream::in);
	if (!ifs)                             // cannot open file infilen
	{
		cerr << "cannot open input file '" << filename << "'\n";
		exit(1);
	}

	return ifs;                             // return input file stream
}

