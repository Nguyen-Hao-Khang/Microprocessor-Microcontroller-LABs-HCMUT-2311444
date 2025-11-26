/*
 * command_communication.c
 *
 *  Created on: Nov 14, 2025
 *      Author: nguye
 */
#include "command_communication.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart2;

void send_uart(char *str) {
    HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), 1000);
}

void uart_communication_fsm(void) {
    switch (comm_state) {
    case COMM_INIT:
        comm_state = COMM_IDLE;
        break;
    case COMM_IDLE:
        if (flag == CMD_RST)
        {
            sprintf(last_msg, "\r\n!ADC=%d#", ADC_value);
            send_uart(last_msg);
            timer = HAL_GetTick();
            comm_state = COMM_WAITING;
            flag = CMD_NONE;
        }

        if (flag == CMD_OK)
        {
            flag = CMD_NONE;
        }
        break;
    case COMM_WAITING:
        if (flag == CMD_OK)
        {
            flag = CMD_NONE;
            timer = 0;
            comm_state = COMM_IDLE;
            break;
        }
        else if (HAL_GetTick() - timer >= 3000)
        {
            send_uart(last_msg);
            timer = HAL_GetTick();
        }
        else if (flag == CMD_RST)
        {
            sprintf(last_msg, "\r\n!ADC=%d#", ADC_value);
            send_uart(last_msg);
            timer = HAL_GetTick();
            flag = CMD_NONE;
        }
        break;
    default:
    	break;
    }
}



