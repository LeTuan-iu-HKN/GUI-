#ifndef INIT_H
#define INIT_H

#include "data_structure.h"
#include "file.h"

#include <fstream>

//Nguyen Trong Tri Kien
class FormManagementSystemInit {
    public:
        ShippingFormList* pList;
        std::string form_info_file;
        std::string price_info_file;
        Price* cur_price;

        //Nguyen Trong Tri Kien
        FormManagementSystemInit();
        //Nguyen Trong Tri Kien
        FormManagementSystemInit(ShippingFormList& pList, std::string form_info_file = INFOR_FILE, std::string price_info_file = MONEY_FILE, Price* cur_price = &current_price);

        //Nguyen Trong Tri Kien
        void init();
};

#endif