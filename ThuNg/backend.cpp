#include "backend.h"

std::vector<int> searchIndexFormList(ShippingFormList& List, std::string search_str) {
	std::vector<int> index;
	for (int i = 0; i < (int)List.FormList.size(); i++) {
        if (List.FormList[i]->to_address.find(search_str) != STRING_NOT_FOUND) {
			(index).push_back(i);
		}
	}

	return std::vector<int>(index);
}

std::vector<int> searchDateIndexFormList(ShippingFormList& List, int start_date, int end_date) {
	std::vector<int> index;
	for (int i = 0; i < (int)List.FormList.size(); i++) {
		if (start_date < List.FormList[i]->received_date && List.FormList[i]->received_date < end_date) {
			(index).push_back(i);
		}
	}
	return std::vector<int>(index);
}
