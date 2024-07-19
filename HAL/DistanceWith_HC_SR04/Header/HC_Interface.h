/*
 * HC_Interface.h
 *
 *  Created on: Jun 30, 2024
 *      Author: 20102
 */

#include "../../../HAL/DistanceWith_HC_SR04/Header/HC_Private.h"

#ifndef DISTANCEWITH_HC_SR04_HEADER_HC_INTERFACE_H_
#define DISTANCEWITH_HC_SR04_HEADER_HC_INTERFACE_H_


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * 1. Initialize the ICU driver as required.
 * 2. Setup the ICU call back function.
 * 3. Setup the direction for the trigger pin as output pin through the GPIO driver.
 */
void Ultrasonic_init(void);

/*
 * Description :
 * Send the Trigger pulse to the ultrasonic.
 */
void Ultrasonic_Trigger(void);

/*
 * Description :
 * 1. Send the trigger pulse by using Ultrasonic_Trigger function.
 * 2. Start the measurements by the ICU from this moment.
 */
u16 Ultrasonic_readDistance(void);

/*
 * Description :
 * 1. This is the call back function called by the ICU driver.
 * 2. This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void);



void DisMain();


#endif /* DISTANCEWITH_HC_SR04_HEADER_HC_INTERFACE_H_ */