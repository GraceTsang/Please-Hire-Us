#include "gtest/gtest.h"
#include "httpRequest.hpp"
#include "httpResponse.hpp"
#include <iostream>


TEST(HttpRequestTest, ValidParseRequest){
  std::string valid_request = 
  "/static/dogs.gif GET /home/gil/cs130/Please-Hire-Us/www/static/dogs.gif HTTP/1.1"
  "Host: localhost:8080"
  "User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:44.0) Gecko/20100101 Firefox/44.0"
  "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"
  "Accept-Language: en-US,en;q=0.5"
  "Accept-Encoding: gzip, deflate"
  "Connection: keep-alive";

  HttpRequest httpReq(valid_request);
  bool success = httpReq.parse();
  EXPECT_TRUE(success);
}

TEST(HttpRequestTest, InvalidParseRequest){
  std::string invalid_request = 
  "/static/dogs.gif GET";

  HttpRequest httpReq(invalid_request);
  bool success = httpReq.parse();
  EXPECT_FALSE(success);
}


