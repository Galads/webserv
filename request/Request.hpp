#pragma once
#ifndef REQUEST_HPP
#define REQUEST_HPP

# include <iostream>
# include <map>
#include <vector>

# define PARSE_ERROR -1

class Request {
public:
	Request();
	Request(std::string &req);
	~Request();
	void initMethods();
	void parsePath(std::string &path);
	void parseVersion(std::string &path);
	void parseMethod();
	void parseNext(std::string &req);

private:
	std::map<std::string, std::string> mapHeader;
	std::string method;
	std::string path;
	std::string version;
	std::vector<std::string> httpMethods;
	int returnReq;
};


#endif
