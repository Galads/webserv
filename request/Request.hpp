#pragma once
#ifndef REQUEST_HPP
#define REQUEST_HPP

# include <iostream>
# include <map>
# include <vector>

# define PARSE_ERROR -1
# define PARSE_ERR_GNL -2
# define PARSE_ERR_PAIR -3


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

	std::string getNextLine(std::string &str, size_t &i);
	std::pair<std::string, std::string> headerCreatePair(std::string &str);

private:
	std::map<std::string, std::string> mapHeader;
	std::string method;
	std::string path;
	std::string version;
	std::vector<std::string> httpMethods;

	int returnReq;
};


#endif
