/*
 * rtc_user.c
 *
 *  Created on: 2022. dec. 3.
 *      Author: drCsabesz
 */

#include "main.h"
#include "rtc_user.h"

extern RTC_HandleTypeDef hrtc;

static RTC_TimeTypeDef InitRtcTime =
{
  .Hours = 12,
  .Minutes = 55,
  .Seconds = 0,
  .DayLightSaving = RTC_DAYLIGHTSAVING_NONE,
  .StoreOperation = RTC_STOREOPERATION_RESET
};

static RTC_DateTypeDef InitRtcDate =
{
  .WeekDay = RTC_WEEKDAY_SATURDAY,
  .Month = RTC_MONTH_DECEMBER,
  .Date  = 3,
  .Year  = 2022
};

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
void RTC_UserInit(void)
{
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initialize RTC and set the Time and Date
  */
  if (HAL_RTC_SetTime(&hrtc, &InitRtcTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_RTC_SetDate(&hrtc, &InitRtcDate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
}
