# Issues
## Sonar sensors
- Seems like because of slight-modified timing in interrupt (continuous preempted by those used by RTOS Kernel). The variations in distance measurement when the sensor in dynamic state is larger than my simple HAL project (without FreeRTOS)
- Small glitches (not sure if it's caused by FreeRTOS or not)
=> For this sensor, use Software Timer for triggering is more suitable

# FreeRTOS
## Interrupts
https://mcuoneclipse.com/2016/08/28/arm-cortex-m-interrupts-and-freertos-part-3/
- Project with STM32 + ROS + FreeRTOS: https://github.com/thanhphong98/ros-stm32-base-control/blob/f22d1afc3243c4ea351d87868557a6c8b2e15374/main/main.cpp