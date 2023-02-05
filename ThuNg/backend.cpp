#include "backend.h"

std::vector<int> searchIndexFormList(ShippingFormList& List, std::string search_str) {
    std::vector<int> index;
	for (int i = 0; i < List.FormList.size(); i++) {
		if (List.FormList[i]->from_address.find(search_str) != STRING_NOT_FOUND || List.FormList[i]->to_address.find(search_str) != STRING_NOT_FOUND) {
			(index).push_back(i);
		}
	}

    return std::vector<int>(index);
}