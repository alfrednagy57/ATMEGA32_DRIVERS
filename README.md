# Atmega 32 Drivers

Welcome to the Atmega32 Hardware Abstraction Layer (HAL) and Microcontroller Abstraction Layer (MCAL) Drivers repository! This repository provides comprehensive HAL and MCAL drivers for the Atmega32 microcontroller, along with drivers for various peripherals.

# Overview

The Atmega32 HAL and MCAL Drivers repository aims to simplify development for Atmega32 microcontroller-based projects by providing reusable and modular code for handling hardware interfaces and low-level microcontroller operations. Whether you're a beginner or an experienced embedded systems developer, these layers and drivers can help you save time and effort in your projects.

# Features

- ** HAL (Hardware Abstraction Layer): ** 
- ** Abstracts hardware interfaces ** such as LCD, KEYPAD, LM35, MOTOR, etc.
Provides a consistent API for interacting with these peripherals.

- ** MCAL (Microcontroller Abstraction Layer): ** 
- ** Pre-implemented drivers ** for various peripherals commonly found in Atmega32-based systems.
- Includes drivers for UART, SPI, ADC, Timer, etc.

# Additional Benefits
- ** Modular and Reusable Code: ** Designed for easy integration into projects, with a modular code structure that facilitates code reuse and scalability.
- ** Well-documented: ** Extensive documentation and comments are provided throughout the codebase to aid understanding and usage.

# Repository Structure
 The repository is structured as follows:

```

atmega32_HAL_MCAL_Drivers/
│
│
├── Common/
│   ├── Map/
│   │   ├──Map.c
│   │   ├──Map.h
│   │   
│   ├── BitMath.H
│   │
│   ├── StdType.h
│
│
├── HAL/                 # Hardware Abstraction Layer
│   ├── 7_Segments/ 
│   ├── Calc/           
│   ├── DistanceWith_HC_SR04/          
│   ├── Keypad/           
│   ├── Lcd/             
│   ├── LDR/          
│   ├── Led/                   
│   ├── Servo/
│   ├── StepperMotor/
│   ├── TempSensor/          
│
├── MCAL/                # Microcontroller Abstraction Layer
│   ├── ADC/
│   ├── EXTI/     
│   ├── GPIO/       
│   ├── ICU/
│   ├── SPI/
│   ├── SREG/       
│   ├── TIMER0/         
│   ├── TIMER1/         
│   ├── TWI/         
│   ├── UART/  
│   ├── WDT/    
└── README.md            # Repository README file


```