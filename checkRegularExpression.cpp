#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex.h>

using namespace std;

int checkRegularExpression(char* checkData,char* regexExp)
{
	// Here we define regex to store the regex expression coming from input parameter
        regex_t reg;
        int flag =0;
		// Here we declare a matching array of 16 bit store and compare the actual data
        regmatch_t matches[16];
		// Here we are storing the regex expression as per the extended syntax 
        regcomp(&reg, regexExp, REG_EXTENDED);
		// Here we compare the actual data with the expression and if it return 0 then it gets a successful match otherwise it doesn't 
        if (regexec(&reg, checkData, 16, matches, 0) == 0) {
                flag=0;
        }
        else {
                flag=1;
        }
        return flag;
}
