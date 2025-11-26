/*
 * command_parser.c
 *
 *  Created on: Nov 14, 2025
 *      Author: nguye
 */
#include "command_parser.h"
#include <string.h>

void command_parser_init(void) {
    parser_state = PARSER_INIT;
    index_buffer = 0;
    memset(buffer, 0, MAX_BUFFER_SIZE);
    buffer_flag = 0;
    flag = CMD_NONE;
}

void command_parser_fsm(void) {
    uint8_t c = temp;
    switch(parser_state) {
    case PARSER_INIT:
        if (c == '!')
        {
            index_buffer = 0;
            buffer[index_buffer++] = c;
            parser_state = PARSER_RECEIVING;
        }
        break;
    case PARSER_RECEIVING:
        if (index_buffer < MAX_BUFFER_SIZE - 1)
        {
             buffer[index_buffer++] = c;
        }

        if (c == '#')
		{
			buffer[index_buffer] = '\0';
			parser_state = PARSER_CHECK_COMMAND;
		}

		if (parser_state != PARSER_CHECK_COMMAND)
		{
			break;
		}
    case PARSER_CHECK_COMMAND:
        if (strcmp((char*)buffer, "!RST#") == 0)
        {
            flag = CMD_RST;
        }
        else if (strcmp((char*)buffer, "!OK#") == 0)
        {
            flag = CMD_OK;
        } else {
            flag = CMD_NONE;
        }
        parser_state = PARSER_INIT;
    	break;
    default:
        parser_state = PARSER_INIT;
        break;
    }
}
