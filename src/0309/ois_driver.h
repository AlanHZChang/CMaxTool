/*==========================================================
 Copyright (c) 2015 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
 ===========================================================*/
#ifndef __OIS_DRIVER_H__
#define __OIS_DRIVER_H__

#include "sensor_sdk_common.h"

/*
 * OIS driver version is given by:
 * <Major version>.<Minor version>.<Patch version>
 */
#define OIS_DRIVER_VERSION "1.0.0"
#define OIS_SDK_CAPABILITIES "ENABLE OIS, DISABLE OIS, \
MOVIE MODE, STILL MODE, CENTERING ON, CENTERING ON, \
PAN TILT"

#define MAX_OIS_MOD_NAME_SIZE 32
#define MAX_OIS_NAME_SIZE 32
#define MAX_OIS_REG_SETTINGS 800

enum ois_i2c_operation
{
  OIS_WRITE,
  OIS_POLL,
};

typedef struct _ois_reg_settings
{
  unsigned short reg_addr;
  enum camera_i2c_reg_addr_type addr_type;
  unsigned int reg_data;
  enum camera_i2c_data_type data_type;
  enum ois_i2c_operation i2c_operation;
  unsigned int delay;
} ois_reg_settings_t;

/**
 * _ois_params:
 * @module_name: Module name
 * @ois_name: ois name
 * @i2c_addr: I2C address of slave
 * @data_size: data size
 * Function settings supported:
 * init_settings - initializing register settings
 * enable_ois_settings - enable ois register settings
 * disable_ois_settings - disable ois register settings
 * movie_mode_ois_settings - set movie mode register settings
 * still_mode_ois_setting_size - set still mode register settings
 * centering_on_ois_setting_size - centering on register settings
 * centering_off_ois_setting_size - centering off register settings
 * pantilt_on_ois_settings - pan tilt register settings
 **/
typedef struct _ois_params
{
  char module_name[MAX_OIS_MOD_NAME_SIZE];
  char ois_name[MAX_OIS_NAME_SIZE];
  unsigned int i2c_addr;
  enum camera_i2c_freq_mode i2c_freq_mode;
  unsigned short init_setting_size;
  ois_reg_settings_t init_settings[MAX_OIS_REG_SETTINGS];
  unsigned short enable_ois_setting_size;
  ois_reg_settings_t enable_ois_settings[MAX_OIS_REG_SETTINGS];
  unsigned short disable_ois_setting_size;
  ois_reg_settings_t disable_ois_settings[MAX_OIS_REG_SETTINGS];
  unsigned short movie_mode_ois_setting_size;
  ois_reg_settings_t movie_mode_ois_settings[MAX_OIS_REG_SETTINGS];
  unsigned short still_mode_ois_setting_size;
  ois_reg_settings_t still_mode_ois_settings[MAX_OIS_REG_SETTINGS];
  unsigned short centering_on_ois_setting_size;
  ois_reg_settings_t centering_on_ois_settings[MAX_OIS_REG_SETTINGS];
  unsigned short centering_off_ois_setting_size;
  ois_reg_settings_t centering_off_ois_settings[MAX_OIS_REG_SETTINGS];
  unsigned short pantilt_on_ois_setting_size;
  ois_reg_settings_t pantilt_on_ois_settings[MAX_OIS_REG_SETTINGS];
} ois_params_t;

/**
 * _ois_driver_params:
 * @ois_params: parameters specific to ois
 **/
typedef struct _ois_driver_params
{
  ois_params_t ois_params;
} ois_driver_params_t;

/**
 * _ois_driver_ctrl:
 * @ois_driver_params: ois_driver_params
 **/
typedef struct _ois_driver_ctrl
{
  ois_driver_params_t ois_driver_params;
} ois_driver_ctrl_t;

#endif /* __OIS_DRIVER_H__ */
