/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_TIM2_Init(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG(int num){
	switch (num){
		case 0:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 1);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 1);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
			break;
		default:
			HAL_GPIO_WritePin(GPIOB, a_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, b_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, c_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, d_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
			HAL_GPIO_WritePin(GPIOB, f_Pin, 0);
			HAL_GPIO_WritePin(GPIOB, g_Pin, 0);
	}
}

const int MAX_LED_MATRIX = 8;
uint8_t matrix_buffer[8]={0xFF,0x01,0x00,0xEE,0xEE,0x00,0x01,0xFF};
void updateLEDMatrix (int index ){
	switch ( index ){
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15 , 0);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8 , 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (matrix_buffer[0] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (matrix_buffer[0] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (matrix_buffer[0] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (matrix_buffer[0] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (matrix_buffer[0] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (matrix_buffer[0] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (matrix_buffer[0] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (matrix_buffer[0] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
		break ;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8 , 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9 , 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (matrix_buffer[1] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (matrix_buffer[1] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (matrix_buffer[1] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (matrix_buffer[1] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (matrix_buffer[1] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (matrix_buffer[1] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (matrix_buffer[1] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (matrix_buffer[1] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
		break ;
	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9 , 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10 , 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (matrix_buffer[2] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (matrix_buffer[2] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (matrix_buffer[2] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (matrix_buffer[2] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (matrix_buffer[2] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (matrix_buffer[2] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (matrix_buffer[2] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (matrix_buffer[2] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
		break ;
	case 3:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10 , 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11 , 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (matrix_buffer[3] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (matrix_buffer[3] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (matrix_buffer[3] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (matrix_buffer[3] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (matrix_buffer[3] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (matrix_buffer[3] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (matrix_buffer[3] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (matrix_buffer[3] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
		break ;
	case 4:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11 , 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 , 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (matrix_buffer[4] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (matrix_buffer[4] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (matrix_buffer[4] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (matrix_buffer[4] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (matrix_buffer[4] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (matrix_buffer[4] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (matrix_buffer[4] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (matrix_buffer[4] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
		break ;
	case 5:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 , 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13 , 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (matrix_buffer[5] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (matrix_buffer[5] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (matrix_buffer[5] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (matrix_buffer[5] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (matrix_buffer[5] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (matrix_buffer[5] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (matrix_buffer[5] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (matrix_buffer[5] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
		break ;
	case 6:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13 , 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14 , 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (matrix_buffer[6] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (matrix_buffer[6] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (matrix_buffer[6] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (matrix_buffer[6] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (matrix_buffer[6] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (matrix_buffer[6] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (matrix_buffer[6] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (matrix_buffer[6] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
		break ;
	case 7:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14 , 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15 , 1);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (matrix_buffer[7] & 0x01)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (matrix_buffer[7] & 0x02)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (matrix_buffer[7] & 0x04)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, (matrix_buffer[7] & 0x08)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, (matrix_buffer[7] & 0x10)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, (matrix_buffer[7] & 0x20)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, (matrix_buffer[7] & 0x40)? GPIO_PIN_RESET:GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (matrix_buffer[7] & 0x80)? GPIO_PIN_RESET:GPIO_PIN_SET);
		break ;
	default :
		break ;
	}
}
int led_buffer [4] = {1, 2, 5, 4};
void update7SEG ( int index ){
	switch ( index ){
	case 0:
	// Display the first 7 SEG with led_buffer [0]
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
		  display7SEG(led_buffer[0]);
		  break ;
	case 1:
	// Display the second 7 SEG with led_buffer [1]
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
		  display7SEG(led_buffer[1]);
		break ;
	case 2:
	// Display the third 7 SEG with led_buffer [2]
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
		  display7SEG(led_buffer[2]);
		  break ;
	case 3:
	// Display the forth 7 SEG with led_buffer [3]
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
		  display7SEG(led_buffer[3]);
		  break ;
	default :
		break ;
	}
}
void shift_array(uint8_t matrix_buffer[8]){
	uint8_t temp=matrix_buffer[0];
	matrix_buffer[0]=matrix_buffer[1];
	matrix_buffer[1]=matrix_buffer[2];
	matrix_buffer[2]=matrix_buffer[3];
	matrix_buffer[3]=matrix_buffer[4];
	matrix_buffer[4]=matrix_buffer[5];
	matrix_buffer[5]=matrix_buffer[6];
	matrix_buffer[6]=matrix_buffer[7];
	matrix_buffer[07]=temp;
}
int hour,minute,second;
void updateClockBuffer(){
	led_buffer[0]=(hour/10)%10;
	led_buffer[1]=hour%10;
	led_buffer[2]=(minute/10)%10;
	led_buffer[3]=minute%10;
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_TIM2_Init();
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  setTimer0(100);
  setTimer1(39);
  setTimer2(51);
  setTimer3(57);
  hour=12;
  minute=54;
  second=56;
  int index_matrix=0;
  int index_7SEG=0;

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  if(timer0_flag==1){
		  second ++;
		  if ( second >= 60) {
			  second = 0;
			  minute ++;
		  }
		  if ( minute >= 60) {
			  minute = 0;
			  hour ++;
		  }
		  if ( hour >=24) {
			  hour = 0;
		  }
		  updateClockBuffer () ;
		  setTimer0(100);
	  }
	  if(timer1_flag==1){
		  update7SEG(index_7SEG);
		  index_7SEG++;
		  if(index_7SEG>=4){
			  index_7SEG=0;
		  }
		  setTimer1(39);
	  }
	  if(timer2_flag==1){
		  updateLEDMatrix(index_matrix);
		  index_matrix++;
		  if(index_matrix>=8){
			  shift_array(matrix_buffer);
			  index_matrix=0;
		  }
		  setTimer2(51);
	  }
	  if(timer3_flag==1){
		  HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		  setTimer3(57);
	  }
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3|DOT_Pin|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|d_Pin|e_Pin|f_Pin
                          |g_Pin|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA2 PA3 DOT_Pin PA5
                           PA6 PA7 PA8 PA9
                           PA10 PA11 PA12 PA13
                           PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|DOT_Pin|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin PB10
                           PB11 PB12 PB13 PB14
                           PB15 d_Pin e_Pin f_Pin
                           g_Pin PB8 PB9 */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|d_Pin|e_Pin|f_Pin
                          |g_Pin|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim ){
	timerRun();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
