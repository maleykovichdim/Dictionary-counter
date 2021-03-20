
#include "pch.h"
#include <string>
#include <iostream>
#include <regex>
#include <map>
#include <algorithm>

void wordCountering(std::string input){
  if (input.length() == 0) return;
  std::map<std::string,int> words;
  std::regex regex("[a-zA-Z]+");
  for (std::sregex_token_iterator it(begin(input), end(input), regex), last; it != last; ++it){
    std::string ss = it->str();
    std::transform(ss.begin(), ss.end(), ss.begin(), ::tolower);
	if (words[ss] == 0)
		words[ss] = 1;
	else
		words[ss]++;
  }
  std::vector<std::pair<int,std::string>> countedWords;
  for (auto& t : words) {
	 countedWords.emplace_back(std::pair<int,std::string>(t.second, t.first));  
  }
  if (countedWords.size() == 0) return;
  auto cmp = [](std::pair<int,std::string> const & a, std::pair<int,std::string> const & b) 
  { 
	return (a.first != b.first) ?  (a.first > b.first) : (a.second < b.second);
  };
  std::sort(countedWords.begin(), countedWords.end(), cmp);
  for (auto& t : countedWords) {
    std::cout << t.first << " " << t.second << "\n";
  }
}




int main() {
	const std::string input = "The time has come, the Walrus said, Walrus to talk Walrus of many things... qwe, rt and asdf. Hello, i am string\nHow are you?\n-All OK!";
	//const std::string input = ",,*";
	wordCountering(input);
}
