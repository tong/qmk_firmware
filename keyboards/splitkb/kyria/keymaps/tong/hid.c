#ifdef RAW_ENABLE

#include <stdio.h>
#include "kyria.h"
//#include "raw_hid.h"
#include "hid.h"
#include "encoder.h"

/*
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
*/

// char    raw_hid_buf[32]        = {};
uint8_t command_id;
uint8_t raw_hid_bytes_received = 0;
void    raw_hid_receive(uint8_t *data, uint8_t length) {
    raw_hid_bytes_received += length;
    uint8_t *command_id   = &(data[0]);
    uint8_t *command_data = &(data[1]);
    switch (*command_id) {
        case id_get_keyboard_value:
            switch (command_data[0]) {
                case id_uptime: {
                    uint32_t value  = timer_read32();
                    command_data[1] = (value >> 24) & 0xFF;
                    command_data[2] = (value >> 16) & 0xFF;
                    command_data[3] = (value >> 8) & 0xFF;
                    command_data[4] = value & 0xFF;
                    break;
                }
                case id_encoder_mode: {
                    // TODO let select encoder index to return
                    command_data[1] = encoder_get_mode(true);
                    break;
                }
                default: {
                    *command_id = 0x00; // id_unhandled;
                    // command_id[0] = 0x11; //id_unhandled;
                    command_data[0] = 0xfe;
                }
            }
        default:
            command_id[0] = id_unhandled;
            //*command_id = id_unhandled;
            // command_data[0] = id_error;
            // command_data[1] = id_unknown_command;
    }
    raw_hid_send(data, length);
}

#endif

