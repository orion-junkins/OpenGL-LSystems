#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<char, string> BasePairMap;

string substitute(char input, BasePairMap rules) {
  string result = "";
  if ( rules.find(input) == rules.end() ) {
    result += input;
  } else {
    result += rules[input];;
  }
  return result;
}

string generateLSysInstruction(string inputSeq, BasePairMap rules, int recursionDepth) {
  int nextRecursionDepth;
  if (recursionDepth <= 0){
    return inputSeq;
  } else {
    nextRecursionDepth = recursionDepth - 1;
  }
  string nextSeq = "";
  for(char& curChar : inputSeq) {
    nextSeq += substitute(curChar, rules);
  }
  string finalSeq = generateLSysInstruction(nextSeq, rules, nextRecursionDepth);
  return finalSeq;
}
