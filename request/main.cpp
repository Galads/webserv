#include <iostream>
#include "Request.hpp"

int main() {
	std::string req = "GET /path HTTP/1.1\n"
					  "Host: localhost:8000\n"
					  "Connection: keep-alive\n"
					  "Cache-Control: max-age=0\n"
					  "sec-ch-ua: \"Google Chrome\";v=\"95\", \"Chromium\";v=\"95\", \";Not A Brand\";v=\"99\"\n"
					  "sec-ch-ua-mobile: ?0\n"
					  "sec-ch-ua-platform: \"Linux\"\n"
					  "Upgrade-Insecure-Requests: 1\n"
					  "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.69 Safari/537.36\n"
					  "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9\n"
					  "Sec-Fetch-Site: none\n"
					  "Sec-Fetch-Mode: navigate\n"
					  "Sec-Fetch-User: ?1\n"
					  "Sec-Fetch-Dest: document\n"
					  "Accept-Encoding: gzip, deflate, br\n"
					  "Accept-Language: en-US,en;q=0.9,ru-RU;q=0.8,ru;q=0.7\n";

	Request request(req);
//	std::cout << req[18];
//	std::cout << "Hello, World!" << std::endl;
	return 0;
}
