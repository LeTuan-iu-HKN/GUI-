#ifndef BACKEND_H
#define BACKEND_H

#include "data_structure.h"
#include <vector>

std::vector<int> searchIndexFormList(ShippingFormList& List, std::string search_str);
std::vector<int> searchDateIndexFormList(ShippingFormList& List, int start_date, int end_date);

#endif