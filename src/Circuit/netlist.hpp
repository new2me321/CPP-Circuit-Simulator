#ifndef __NETLIST_H__
#define __NETLIST_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>

class NetlistFile{
public:
  NetlistFile(std::istream& is);

  std::vector<std::vector<std::string>> GetAllLines();

private:
  std::vector<std::string> GetTokensFromLine(std::string line);

  bool GetNextLine(std::string& line);

private:
  std::istream& is_;

};

#endif // __NETLIST_H__