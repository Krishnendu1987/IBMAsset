#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex.h>

using namespace std;

char* checkRegularExpressionMatch(char* source,char* regexString)
{
//char * source = "___ abc123def ___ ghi456 ___";
////char * regexString = "[a-z]*([0-9]+)([a-z]*)";
size_t maxMatches = 2;
size_t maxGroups = 3;
char * returnstr;
 regex_t regexCompiled;
 regmatch_t groupArray[maxGroups];
 unsigned int m;
 char * cursor;
 unsigned int flag = 1;
  returnstr = new char[1];
  strcpy(returnstr , "");

  if (regcomp(&regexCompiled, regexString, REG_EXTENDED))
  {
 // char returnstr[1];
 // strcpy(returnstr , "");
  flag = 3;
  return returnstr;
  };

   m = 0;
   cursor = source;
   for (m = 0; m < maxMatches; m ++)
   {
   if (regexec(&regexCompiled, cursor, maxGroups, groupArray, 0))
    break; // No more matches

    unsigned int g = 0;
    unsigned int offset = 0;
    for (g = 0; g < maxGroups; g++)
    {
    if (groupArray[g].rm_so == (size_t)-1)
    break; // No more groups

     if (g == 0)
     offset = groupArray[g].rm_eo;
      char cursorCopy[strlen(cursor) + 1];
      strcpy(cursorCopy, cursor);
      cursorCopy[groupArray[g].rm_eo] = 0;
      //printf("Match %u, Group %u: [%2u-%2u]: %s\n", m, g, groupArray[g].rm_so, groupArray[g].rm_eo, cursorCopy + groupArray[g].rm_so);
   if (m == 0){
       returnstr = new char[strlen(cursorCopy) + 1];
       strcpy(returnstr,cursorCopy);
       flag=2;
      }

}
      cursor += offset;
      //flag=2;
      }

       regfree(&regexCompiled);

        return returnstr;
     }
