/* imx219_ms3_lib.c
 *
 * Copyright (c) 2013-2015 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#include <stdio.h>
#include <string.h>
#include "debug_lib.h"
#include "imx219_ms3_lib.h"

/*===========================================================================
 * FUNCTION    - sensor_real_to_register_gain -
 *
 * DESCRIPTION:
 *==========================================================================*/
static unsigned int sensor_real_to_register_gain(float gain)
{
  unsigned int reg_gain;
  if (gain < 1.0)
    gain = 1.0;
  if (gain > 8.0)
    gain = 8.0;
  reg_gain = (unsigned int)(256.0 - 256.0 / gain);

  return reg_gain;
}

/*===========================================================================
 * FUNCTION    - sensor_register_to_real_gain -
 *
 * DESCRIPTION:
 *==========================================================================*/
static float sensor_register_to_real_gain(unsigned int reg_gain)
{
  float gain;
  if (reg_gain > 240)
    reg_gain = 240;
  gain = 256.0 / (256.0 - reg_gain);
  return gain;
}

/*===========================================================================
 * FUNCTION    - sensor_calculate_exposure -
 *
 * DESCRIPTION:
 *==========================================================================*/
static int sensor_calculate_exposure(float real_gain,
  unsigned int line_count, sensor_exposure_info_t *exp_info,
  __attribute__((unused)) float s_real_gain)
{
  if (!exp_info) {
    return -1;
  }
  exp_info->reg_gain = sensor_real_to_register_gain(real_gain);
  exp_info->sensor_real_gain = sensor_register_to_real_gain(exp_info->reg_gain);
  exp_info->digital_gain = real_gain / exp_info->sensor_real_gain;
  exp_info->line_count = line_count;
  exp_info->sensor_digital_gain = 0x1;
  return 0;
}

/*===========================================================================
 * FUNCTION    - sensor_fill_exposure_array -
 *
 * DESCRIPTION:
 *==========================================================================*/
static int sensor_fill_exposure_array(unsigned int gain,
  __attribute__((unused)) unsigned int digital_gain, unsigned int line,
  unsigned int fl_lines, __attribute__((unused)) int luma_avg,
  __attribute__((unused)) unsigned int fgain,
  struct camera_i2c_reg_setting* reg_setting,
  __attribute__((unused)) unsigned int s_gain,
  __attribute__((unused)) int s_linecount,
  __attribute__((unused)) int is_hdr_enabled) {

  unsigned short reg_count = 0;
  unsigned short i = 0;

  if (!reg_setting) {
    return -1;
  }

  for (i = 0; i < sensor_lib_ptr.groupon_settings.size; i++) {
    reg_setting->reg_setting[reg_count].reg_addr =
      sensor_lib_ptr.groupon_settings.reg_setting_a[i].reg_addr;
    reg_setting->reg_setting[reg_count].reg_data =
      sensor_lib_ptr.groupon_settings.reg_setting_a[i].reg_data;
    reg_count = reg_count + 1;
  }

  reg_setting->reg_setting[reg_count].reg_addr =
    sensor_lib_ptr.output_reg_addr.frame_length_lines;
  reg_setting->reg_setting[reg_count].reg_data = (fl_lines & 0x0000FF00) >> 8;
  reg_setting->reg_setting[reg_count].delay = 0;
  reg_count = reg_count + 1;

  reg_setting->reg_setting[reg_count].reg_addr =
    sensor_lib_ptr.output_reg_addr.frame_length_lines + 1;
  reg_setting->reg_setting[reg_count].reg_data = (fl_lines & 0x000000FF);
  reg_setting->reg_setting[reg_count].delay = 0;
  reg_count = reg_count + 1;

  reg_setting->reg_setting[reg_count].reg_addr =
    sensor_lib_ptr.exp_gain_info.coarse_int_time_addr;
  reg_setting->reg_setting[reg_count].reg_data = (line & 0x0000FF00) >> 8;
  reg_setting->reg_setting[reg_count].delay = 0;
  reg_count = reg_count + 1;

  reg_setting->reg_setting[reg_count].reg_addr =
    sensor_lib_ptr.exp_gain_info.coarse_int_time_addr + 1;
  reg_setting->reg_setting[reg_count].reg_data = (line & 0x000000FF);
  reg_setting->reg_setting[reg_count].delay = 0;
  reg_count = reg_count + 1;

#if 0//Fihtdc, remark
  reg_setting->reg_setting[reg_count].reg_addr =
      sensor_lib_ptr.exp_gain_info.global_gain_addr;
  reg_setting->reg_setting[reg_count].reg_data = (gain & 0x0000FF00) >> 8;
  reg_setting->reg_setting[reg_count].delay = 0;
  reg_count = reg_count + 1;

  reg_setting->reg_setting[reg_count].reg_addr =
      sensor_lib_ptr.exp_gain_info.global_gain_addr + 1;
  reg_setting->reg_setting[reg_count].reg_data = (gain & 0x000000FF);
  reg_setting->reg_setting[reg_count].delay = 0;
  reg_count = reg_count + 1;
#else
  SERR("[Imx219_lib] gain = 0x%x}", gain);
#endif

  for (i = 0; i < sensor_lib_ptr.groupoff_settings.size; i++) {
    reg_setting->reg_setting[reg_count].reg_addr =
      sensor_lib_ptr.groupoff_settings.reg_setting_a[i].reg_addr;
    reg_setting->reg_setting[reg_count].reg_data =
      sensor_lib_ptr.groupoff_settings.reg_setting_a[i].reg_data;
    reg_count = reg_count + 1;
  }

  reg_setting->size = reg_count;
  reg_setting->addr_type = CAMERA_I2C_WORD_ADDR;
  reg_setting->data_type = CAMERA_I2C_BYTE_DATA;
  reg_setting->delay = 0;
  return 0;
}

/*===========================================================================
 * FUNCTION    - sensor_open_lib -
 *
 * DESCRIPTION:
 *==========================================================================*/
void *sensor_open_lib(void)
{
  return &sensor_lib_ptr;
}
