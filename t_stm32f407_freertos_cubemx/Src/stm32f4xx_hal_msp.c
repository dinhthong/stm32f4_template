/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32f4xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */
extern DMA_HandleTypeDef hdma_usart1_tx, hdma_usart2_tx;
/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/
  /* PendSV_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(PendSV_IRQn, 15, 0);

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/*
 * Special note that on STM32discovery board: PA9 is connected to external hardware module. Therefore,
 * if it's configured as USART1 alternate function probably cause non-working result in most cases
 * */
void HAL_UART_MspInit(UART_HandleTypeDef *huart) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    if (huart->Instance == USART1) {

        /* Peripheral clock enable */
        __HAL_RCC_USART1_CLK_ENABLE();

//        __HAL_RCC_GPIOA_CLK_ENABLE();
//        /**USART6 GPIO Configuration
//        PC6     ------> USART6_TX
//        PC7     ------> USART6_RX
//        */
//        GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
//        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//        GPIO_InitStruct.Pull = GPIO_NOPULL;
//        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//        GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
//        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        __HAL_RCC_GPIOB_CLK_ENABLE();
        /**USART6 GPIO Configuration
        PC6     ------> USART6_TX
        PC7     ------> USART6_RX
        */
        GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
        /* USART6 DMA Init */
        /* USART6_TX Init */
        hdma_usart1_tx.Instance = DMA2_Stream7;
        hdma_usart1_tx.Init.Channel = DMA_CHANNEL_4;
        hdma_usart1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
        hdma_usart1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
        hdma_usart1_tx.Init.MemInc = DMA_MINC_ENABLE;
        hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
        hdma_usart1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
        hdma_usart1_tx.Init.Mode = DMA_NORMAL;
        hdma_usart1_tx.Init.Priority = DMA_PRIORITY_LOW;
        hdma_usart1_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
        if (HAL_DMA_Init(&hdma_usart1_tx) != HAL_OK) {
            Error_Handler();
        }

        __HAL_LINKDMA(huart, hdmatx, hdma_usart1_tx);

        /* USART6 interrupt Init */
        HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
        HAL_NVIC_EnableIRQ(USART1_IRQn);
        /* USER CODE BEGIN USART6_MspInit 1 */

        /* USER CODE END USART6_MspInit 1 */
    } else if(huart->Instance==USART2)
    {
    /* USER CODE BEGIN USART2_MspInit 0 */

    /* USER CODE END USART2_MspInit 0 */
      /* Peripheral clock enable */
      __HAL_RCC_USART2_CLK_ENABLE();

      __HAL_RCC_GPIOA_CLK_ENABLE();
      /**USART2 GPIO Configuration
      PA2     ------> USART2_TX
      PA3     ------> USART2_RX
      */
      GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
      GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

      /* USART2 DMA Init */
      /* USART2_TX Init */
      hdma_usart2_tx.Instance = DMA1_Stream6;
      hdma_usart2_tx.Init.Channel = DMA_CHANNEL_4;
      hdma_usart2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
      hdma_usart2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
      hdma_usart2_tx.Init.MemInc = DMA_MINC_ENABLE;
      hdma_usart2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
      hdma_usart2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
      hdma_usart2_tx.Init.Mode = DMA_NORMAL;
      hdma_usart2_tx.Init.Priority = DMA_PRIORITY_LOW;
      hdma_usart2_tx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
      if (HAL_DMA_Init(&hdma_usart2_tx) != HAL_OK)
      {
        Error_Handler();
      }

      __HAL_LINKDMA(huart,hdmatx,hdma_usart2_tx);

      /* USART2 interrupt Init */
      HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
      HAL_NVIC_EnableIRQ(USART2_IRQn);
    /* USER CODE BEGIN USART2_MspInit 1 */

    /* USER CODE END USART2_MspInit 1 */
    }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
