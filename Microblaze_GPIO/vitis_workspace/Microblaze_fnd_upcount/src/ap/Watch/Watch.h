/*
 * Watch.h
 *
 *  Created on: 2026. 4. 28.
 *      Author: kccistc
 */

#ifndef SRC_AP_WATCH_WATCH_H_
#define SRC_AP_WATCH_WATCH_H_
#include "../../driver/FND/FND.h"
#include "../../driver/Button/Button.h"
#include "../../common/common.h"
#include "../UpCounter/UpCounter.h"

typedef struct{
	uint16_t HOUR;
	uint16_t MIN;
	uint16_t SEC;
	uint16_t MSEC;
}clock_state_t;  //struct


void Watch_Init();
void Watch_Excute();
void Watch_Update(clock_state_t *Clock);
void Watch_Display(clock_state_t *Clock);



#endif /* SRC_AP_WATCH_WATCH_H_ */
