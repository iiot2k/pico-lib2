
// Copyright 2021 Ocean (iiot2k@gmail.com) 
// All rights reserved.

#include "sys_util.h"
#include "pico/unique_id.h"

int8_t* sys_dbl_str(double val, int32_t prec, int8_t* buf, size_t buflen)
{
    snprintf(buf, buflen, "%.*f", prec, val);
    return buf;
}

int8_t* sys_int_str(int32_t val, int8_t* buf, size_t buflen)
{
    snprintf(buf, buflen, "%d", val);
    return buf;
}

int8_t* sys_uid_str(int8_t* buf, size_t buflen)
{
    pico_unique_board_id_t uid;

    pico_get_unique_board_id(&uid);
    
    snprintf(buf, buflen, "%02X%02X%02X%02X%02X%02X%02X%02X", 
    uid.id[0], uid.id[1], uid.id[2], uid.id[3], uid.id[4], uid.id[5], uid.id[6], uid.id[7]);

    return buf;
}

int8_t* sys_mac_str(int8_t* buf, size_t buflen)
{
    pico_unique_board_id_t uid;

    pico_get_unique_board_id(&uid);
    
    snprintf(buf, buflen, "%02X.%02X.%02X.%02X.%02X.%02X", 
    uid.id[2], uid.id[3], uid.id[4], uid.id[5], uid.id[6], uid.id[7]);

    return buf;
}
