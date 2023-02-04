#ifndef INIT_H
#define INIT_H

#include "data_structure.h"
#include "file.h"

#include <fstream>

class FormManagementSystemInit {
    public:
        ShippingFormList* pList;
        std::string form_info_file;
        std::string price_info_file;
        Price* cur_price;

        FormManagementSystemInit();
        FormManagementSystemInit(ShippingFormList& pList, std::string form_info_file = INFOR_FILE, std::string price_info_file = MONEY_FILE, Price* cur_price = &current_price);

        void init();
};

#endif