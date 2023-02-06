#ifndef BACKEND_H
#define BACKEND_H

#include "data_structure.h"
#include <vector>

//Tran Quang Huy
std::vector<int> searchIndexFormList(ShippingFormList& List, std::string search_str);

//Nguyen Le Tuan
std::vector<int> searchDateIndexFormList(ShippingFormList& List, int start_date, int end_date);

#endif