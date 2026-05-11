/*
 * Watch.c
 *
 *  Created on: 2026. 4. 28.
 *
 */
#include "Watch.h"
#include "xil_printf.h"

static uint32_t sec_count = 0;

void Watch_Update(clock_state_t *Clock ){
	static uint32_t prevTimeCounter = 0;
	static uint32_t TimeCounter = 0;

	if(millis() - prevTimeCounter >= 1000){  //turn to ms -> original: 1sec 10count
				prevTimeCounter = millis();
				sec_count++;

				Clock->MSEC = millis() % 1000;
						if(millis() - TimeCounter >= 100 ){
							TimeCounter = millis();

							xil_printf("Time: %02d:%02d:%02d\r\n",Clock->HOUR,Clock->MIN,Clock->SEC);
						}

			Clock->MIN = (sec_count / 60) % 60;
			Clock->SEC = sec_count % 60;


				}

}

void Watch_Display(clock_state_t *Clock){
	FND_DispDigit();

	if((millis() % 1000) < 500){
				FND_SetDot(1);
			}
			else{
				FND_SetDot(0);
			}

	FND_SetNum((Clock->MIN*100) + Clock->SEC);

}


void Watch_Init(){
	FND_init();

}

void Watch_Excute(clock_state_t *Clock){

		FND_DispDigit();

		static uint32_t prevTimeCounter = 0;
		static uint32_t TimeCounter = 0;
		static uint32_t sec_count = 0;

		if((millis() % 1000) < 500){
			FND_SetDot(1);
		}
		else{
			FND_SetDot(0);
		}

		Clock->MSEC = millis() % 1000;
		if(millis() - TimeCounter >= 100 ){
			TimeCounter = millis();

			xil_printf("Time: %02d:%02d:%02d\r\n",Clock->HOUR,Clock->MIN,Clock->SEC);
		}


			if(millis() - prevTimeCounter < 1000){  //turn to ms -> original: 1sec 10count
				return;
			}
			prevTimeCounter = millis();
			sec_count++;



		Clock->MIN = (sec_count / 60) % 60;
		Clock->SEC = sec_count % 60;

		FND_SetNum((Clock->MIN*100) + Clock->SEC);


}





