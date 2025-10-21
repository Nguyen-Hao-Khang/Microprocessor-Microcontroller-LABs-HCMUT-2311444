/*
 * led_display.c
 *
 *  Created on: Oct 16, 2025
 *      Author: nguye
 */
#include "main.h"
#include "led_display.h"

// direction = state {0,1,2,3,4}
void displayTrafficLight(int direction)
{
	switch (direction)
	{
		case 0:
			HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, RESET);
			HAL_GPIO_WritePin(NS_YEL_GPIO_Port, NS_YEL_Pin, RESET);
			HAL_GPIO_WritePin(NS_GRE_GPIO_Port, NS_GRE_Pin, RESET);
			HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, RESET);
			HAL_GPIO_WritePin(EW_YEL_GPIO_Port, EW_YEL_Pin, RESET);
			HAL_GPIO_WritePin(EW_GRE_GPIO_Port, EW_GRE_Pin, RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, RESET);
			HAL_GPIO_WritePin(NS_YEL_GPIO_Port, NS_YEL_Pin, RESET);
			HAL_GPIO_WritePin(NS_GRE_GPIO_Port, NS_GRE_Pin, SET);
			HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, SET);
			HAL_GPIO_WritePin(EW_YEL_GPIO_Port, EW_YEL_Pin, RESET);
			HAL_GPIO_WritePin(EW_GRE_GPIO_Port, EW_GRE_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, RESET);
			HAL_GPIO_WritePin(NS_YEL_GPIO_Port, NS_YEL_Pin, SET);
			HAL_GPIO_WritePin(NS_GRE_GPIO_Port, NS_GRE_Pin, RESET);
			HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, SET);
			HAL_GPIO_WritePin(EW_YEL_GPIO_Port, EW_YEL_Pin, RESET);
			HAL_GPIO_WritePin(EW_GRE_GPIO_Port, EW_GRE_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, SET);
			HAL_GPIO_WritePin(NS_YEL_GPIO_Port, NS_YEL_Pin, RESET);
			HAL_GPIO_WritePin(NS_GRE_GPIO_Port, NS_GRE_Pin, RESET);
			HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, RESET);
			HAL_GPIO_WritePin(EW_YEL_GPIO_Port, EW_YEL_Pin, RESET);
			HAL_GPIO_WritePin(EW_GRE_GPIO_Port, EW_GRE_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin(NS_RED_GPIO_Port, NS_RED_Pin, SET);
			HAL_GPIO_WritePin(NS_YEL_GPIO_Port, NS_YEL_Pin, RESET);
			HAL_GPIO_WritePin(NS_GRE_GPIO_Port, NS_GRE_Pin, RESET);
			HAL_GPIO_WritePin(EW_RED_GPIO_Port, EW_RED_Pin, RESET);
			HAL_GPIO_WritePin(EW_YEL_GPIO_Port, EW_YEL_Pin, SET);
			HAL_GPIO_WritePin(EW_GRE_GPIO_Port, EW_GRE_Pin, RESET);
			break;
		default:
			break;
	}
}

void display7SEG(int num)
{
	switch (num)
	{
		case 0:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			  break;
		case 1:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			  break;
		case 2:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			  break;
		case 3:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			  break;
		case 4:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			  break;
		case 5:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			  break;
		case 6:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			  break;
		case 7:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
			  break;
		case 8:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			  break;
		case 9:
			  HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
			  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
			  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
			  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
			  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
			  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
			  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			  break;
		default:
				break;
	}
}



void update7SEG(int index)
{
    // Disable all segment
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
    HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
    HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, SET);
    HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);

    // Update new data for index
    display7SEG(led_buffer[index]);

    // Display current index
    switch (index)
    {
        case 0: HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET); break;
        case 1: HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET); break;
        case 2: HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET); break;
        case 3: HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET); break;
        case 4: HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, RESET); break;
        case 5: HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, RESET); break;
        default: break;
    }
}


void updateLedBuffer(int TR_NS, int TR_EW, int mode)
{
	led_buffer[0] = TR_NS / 10;
	led_buffer[1] = TR_NS % 10;
	led_buffer[2] = TR_EW / 10;
	led_buffer[3] = TR_EW % 10;
	led_buffer[4] = mode / 10;
	led_buffer[5] = mode % 10;
}
