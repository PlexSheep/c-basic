#include <stdio.h>

int main() {
	char s[100];
    //gets(s);
    /*
     * Never use gets().  Because it is impossible to tell without knowing the data in advance how many characters gets() will read,  and  be‐
     * cause gets() will continue to store characters past the end of the buffer, it is extremely dangerous to use.  It has been used to break
     * computer security.  Use fgets() instead.
     *
     * For more information, see CWE-242 (aka "Use of Inherently Dangerous Function") at http://cwe.mitre.org/data/definitions/242.html
     *
     */
    fgets(s, sizeof(s), stdin);
	printf("%s\n", s);
	return 0;
}
