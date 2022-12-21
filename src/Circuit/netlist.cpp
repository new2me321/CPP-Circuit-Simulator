#include "netlist.hpp"

NetlistFile::NetlistFile(std::istream& is) :
  is_(is)
{
}

std::vector<std::vector<std::string>> NetlistFile::GetAllLines() {
  std::vector<std::vector<std::string>> result;

  std::string line;
  while(GetNextLine(line)){
    result.push_back(GetTokensFromLine(line));
  }

  return result;
}

std::vector<std::string> NetlistFile::GetTokensFromLine(std::string line) {
  std::vector<std::string> result;

  std::stringstream ss(line);
  std::string token;
  while(std::getline(ss, token, ' ')){
    result.push_back(token);
  }
  
  return result;
}

bool NetlistFile::GetNextLine(std::string& line) {
  return std::getline(is_, line, '\n').good();
}
