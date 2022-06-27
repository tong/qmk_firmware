#pragma once

#include "raw_hid.h"

enum raw_command_id {
    id_get_protocol_version = 0x01,
    id_get_keyboard_value   = 0x02,
    id_set_keyboard_value   = 0x03,
    // id_error                = 0xFF,
    id_unhandled = 0xff,
};

enum raw_keyboard_value_id {
    id_uptime         = 0x01,
    id_layout_options = 0x02,
    id_encoder_mode   = 0x03,
    // id_oled_mode
};

enum raw_error {
    id_unknown_command = 0x01,
};
