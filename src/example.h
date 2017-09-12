#pragma once
#include <string>
#include <map>

using Currencies = std::map<std::string, float>;

bool read_logged_currencies(const std::string& input, Currencies& currencies);



