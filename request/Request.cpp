#include "Request.hpp"

void Request::initMethods() {
	this->httpMethods.push_back("GET");
	this->httpMethods.push_back("POST");
	this->httpMethods.push_back("DELETE");
	this->httpMethods.push_back("PUT");
	this->httpMethods.push_back("HEAD");
	this->httpMethods.push_back("OPTIONS");
	this->httpMethods.push_back("TRACE");
}

Request::Request(std::string &req) {
	size_t firstPos = req.find('\n');
	std::string firstStr = req.substr(0, firstPos);
	this->returnReq = 0;

	if (firstPos <= 0) {
		std::cout << "Error: Request method not found" << std::endl;
		this->returnReq = PARSE_ERROR;
		return;
	}
	Request::initMethods();
	this->method = firstStr.substr(0, firstStr.find_first_of(' '));
	parsePath(firstStr);
	parseNext(req);
}

void Request::parseNext(std::string &req) {
	std::string str;
	std::string key, value;
	std::pair<std::string, std::string> pair;
	size_t i;

	i = req.find_first_of('\n');
	if (i == std::string::npos) {
		this->returnReq = PARSE_ERROR;
		return;
	}
	while ((str = getNextLine(req, i)) != "NULL"
		   && this->returnReq != PARSE_ERR_GNL) {
		pair = headerCreatePair(str);
		if (pair.first == "NULL" | pair.second == "NULL") {
			this->returnReq = PARSE_ERR_PAIR;
			return;
		}
	}
}

std::pair<std::string, std::string>
Request::headerCreatePair(std::string &str) {
	size_t posSplitter = str.find_first_of(':');
	size_t startPos = str.find_first_not_of('\n');
	size_t secPos;

	if (posSplitter == std::string::npos | startPos == std::string::npos) {
		this->returnReq = PARSE_ERR_PAIR;
		return std::pair<std::string, std::string>("NULL", "NULL");
	}

	std::string key = str.substr(startPos, posSplitter - 1);
	std::string val = str.substr(posSplitter + 1);

	secPos = val.find_first_not_of(' ');
	val = str.substr(posSplitter + secPos + 1);

	return std::pair<std::string, std::string>(key, val);
}

std::string Request::getNextLine(std::string &str, size_t &i) {
	size_t endPos = str.find_first_of('\n', i + 1);
	if (endPos == std::string::npos) {
		this->returnReq = PARSE_ERR_GNL;
		return "NULL";
	}
	std::string currentLine = str.substr(i, endPos - i);
	i = endPos;
	return currentLine;
}

void Request::parsePath(std::string &path) {
	size_t pt;

	pt = path.find_first_not_of(' ', path.find_first_of(' '));
	if (pt == std::string::npos) {
		this->returnReq = PARSE_ERROR;
		std::cout << "Error: parse path method" << std::endl;
		return;
	}
	size_t i;

	if ((i = path.find_first_of(' ', pt)) == std::string::npos) {
		this->returnReq = PARSE_ERROR;
		std::cout << "Error: parse HTTP version" << std::endl;
	}
	this->path = path.substr(pt, i - pt);
	parseVersion(path);
}

void Request::parseVersion(std::string &path) {
	size_t i = path.find_last_of('/');

	if (i == std::string::npos) {
		this->returnReq = PARSE_ERROR;
		std::cout << "Error: parse HTTP token" << std::endl;
		return;
	}
	if (path[i - 1] == 'P' && path[i - 2] == 'T'
		&& path[i - 3] == 'T' && path[i - 4] == 'H') {
		this->version = path.substr(i + 1, 3);
	} else {
		this->returnReq = PARSE_ERROR;
		std::cout << "Error: not have a HTTP version" << std::endl;
		return;
	}
	parseMethod();
}

void Request::parseMethod() {
	for (int i = 0; i < this->httpMethods.size(); ++i) {
		if (this->method == httpMethods[i]) {
			this->returnReq = 200;
			return;
		}
	}
	std::cout << "Error: not found HTTP method" << std::endl;
	this->returnReq = PARSE_ERROR;
	return;
}

Request::Request() {}

Request::~Request() {}