#include "header.h"
int main() {
    // Read in a line including white space
    string line;
    getline(cin, line);
    // When doing the above read numbers as follows:
    int n;
    getline(cin, line);
    stringstream ss(line);
    ss >> n;

    // Count the number of 1s in binary represnatation of a number
    ull number;
    __builtin_popcountll(number);
}

// __int128
using lll = __int128;
ostream& operator<<( ostream& o, __int128 n ) {
	auto t = n<0 ? -n : n; char b[128], *d = end(b);
	do *--d = '0'+t%10, t /= 10; while (t);
	if(n<0) *--d = '-';
	o.rdbuf()->sputn(d,end(b)-d);
	return o;
}