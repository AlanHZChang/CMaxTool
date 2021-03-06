/* imx219_ms3_lib.h
 *
 * DESCRIPTION
 * Auto-Generated by Sensor Driver Generator tool
 *
 * Copyright (c) 2014-2015 Qualcomm Technologies, Inc. All Rights Reserved.
 *
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef __IMX219_MS3_LIB_H__
#define __IMX219_MS3_LIB_H__

#include "sensor_lib.h"
#define SENSOR_MODEL "imx219_ms3"

#define START_REG_ARRAY \
{ \
  {0x0100, 0x01, 0x0A}, \
}

#define STOP_REG_ARRAY \
{ \
  {0x0100, 0x00, 0x00}, \
}

#define GROUPON_REG_ARRAY \
{ \
  {0x0150, 0x01, 0x00}, \
}

#define GROUPOFF_REG_ARRAY \
{ \
  {0x0150, 0x00, 0x00}, \
}

#define INIT0_REG_ARRAY \
{ \
  {0x0103, 0x01, 0}, \
}

#define RES0_REG_ARRAY \
{ \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x0C, 0}, \
  {0x300A, 0xFF, 0}, \
  {0x300B, 0xFF, 0}, \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x09, 0}, \
  {0x0114, 0x03, 0}, \
  {0x0128, 0x00, 0}, \
  {0x012A, 0x18, 0}, \
  {0x012B, 0x00, 0}, \
  {0x0160, 0x09, 0}, \
  {0x0161, 0xCA, 0}, \
  {0x0162, 0x0D, 0}, \
  {0x0163, 0x78, 0}, \
  {0x0164, 0x00, 0}, \
  {0x0165, 0x08, 0}, \
  {0x0166, 0x0C, 0}, \
  {0x0167, 0xC7, 0}, \
  {0x0168, 0x00, 0}, \
  {0x0169, 0x08, 0}, \
  {0x016A, 0x09, 0}, \
  {0x016B, 0x97, 0}, \
  {0x016C, 0x0C, 0}, \
  {0x016D, 0xC0, 0}, \
  {0x016E, 0x09, 0}, \
  {0x016F, 0x90, 0}, \
  {0x0170, 0x01, 0}, \
  {0x0171, 0x01, 0}, \
  {0x0174, 0x00, 0}, \
  {0x0175, 0x00, 0}, \
  {0x018C, 0x0A, 0}, \
  {0x018D, 0x0A, 0}, \
  {0x0301, 0x05, 0}, \
  {0x0303, 0x01, 0}, \
  {0x0304, 0x03, 0}, \
  {0x0305, 0x03, 0}, \
  {0x0306, 0x00, 0}, \
  {0x0307, 0x51, 0}, \
  {0x0309, 0x0A, 0}, \
  {0x030B, 0x01, 0}, \
  {0x030C, 0x00, 0}, \
  {0x030D, 0x54, 0}, \
  {0x455E, 0x00, 0}, \
  {0x471E, 0x4B, 0}, \
  {0x4767, 0x0F, 0}, \
  {0x4750, 0x14, 0}, \
  {0x4540, 0x00, 0}, \
  {0x47B4, 0x14, 0}, \
  {0x4713, 0x30, 0}, \
  {0x478B, 0x10, 0}, \
  {0x478F, 0x10, 0}, \
  {0x4793, 0x10, 0}, \
  {0x4797, 0x0E, 0}, \
  {0x479B, 0x0E, 0}, \
}

#define RES1_REG_ARRAY \
{ \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x0C, 0}, \
  {0x300A, 0xFF, 0}, \
  {0x300B, 0xFF, 0}, \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x09, 0}, \
  {0x0114, 0x03, 0}, \
  {0x0128, 0x00, 0}, \
  {0x012A, 0x18, 0}, \
  {0x012B, 0x00, 0}, \
  {0x0160, 0x09, 0}, \
  {0x0161, 0xCA, 0}, \
  {0x0162, 0x0D, 0}, \
  {0x0163, 0x78, 0}, \
  {0x0164, 0x00, 0}, \
  {0x0165, 0x08, 0}, \
  {0x0166, 0x0C, 0}, \
  {0x0167, 0xC7, 0}, \
  {0x0168, 0x00, 0}, \
  {0x0169, 0x08, 0}, \
  {0x016A, 0x09, 0}, \
  {0x016B, 0x97, 0}, \
  {0x016C, 0x06, 0}, \
  {0x016D, 0x60, 0}, \
  {0x016E, 0x04, 0}, \
  {0x016F, 0xC8, 0}, \
  {0x0170, 0x01, 0}, \
  {0x0171, 0x01, 0}, \
  {0x0174, 0x01, 0}, \
  {0x0175, 0x01, 0}, \
  {0x018C, 0x0A, 0}, \
  {0x018D, 0x0A, 0}, \
  {0x0301, 0x05, 0}, \
  {0x0303, 0x01, 0}, \
  {0x0304, 0x03, 0}, \
  {0x0305, 0x03, 0}, \
  {0x0306, 0x00, 0}, \
  {0x0307, 0x51, 0}, \
  {0x0309, 0x0A, 0}, \
  {0x030B, 0x01, 0}, \
  {0x030C, 0x00, 0}, \
  {0x030D, 0x54, 0}, \
  {0x455E, 0x00, 0}, \
  {0x471E, 0x4B, 0}, \
  {0x4767, 0x0F, 0}, \
  {0x4750, 0x14, 0}, \
  {0x4540, 0x00, 0}, \
  {0x47B4, 0x14, 0}, \
  {0x4713, 0x30, 0}, \
  {0x478B, 0x10, 0}, \
  {0x478F, 0x10, 0}, \
  {0x4793, 0x10, 0}, \
  {0x4797, 0x0E, 0}, \
  {0x479B, 0x0E, 0}, \
}

#define RES2_REG_ARRAY \
{ \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x0C, 0}, \
  {0x300A, 0xFF, 0}, \
  {0x300B, 0xFF, 0}, \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x09, 0}, \
  {0x0114, 0x03, 0}, \
  {0x0128, 0x00, 0}, \
  {0x012A, 0x18, 0}, \
  {0x012B, 0x00, 0}, \
  {0x0160, 0x04, 0}, \
  {0x0161, 0xE5, 0}, \
  {0x0162, 0x0D, 0}, \
  {0x0163, 0x78, 0}, \
  {0x0164, 0x00, 0}, \
  {0x0165, 0x00, 0}, \
  {0x0166, 0x0C, 0}, \
  {0x0167, 0xCF, 0}, \
  {0x0168, 0x01, 0}, \
  {0x0169, 0x34, 0}, \
  {0x016A, 0x08, 0}, \
  {0x016B, 0x6B, 0}, \
  {0x016C, 0x06, 0}, \
  {0x016D, 0x68, 0}, \
  {0x016E, 0x03, 0}, \
  {0x016F, 0x9C, 0}, \
  {0x0170, 0x01, 0}, \
  {0x0171, 0x01, 0}, \
  {0x0174, 0x01, 0}, \
  {0x0175, 0x01, 0}, \
  {0x018C, 0x0A, 0}, \
  {0x018D, 0x0A, 0}, \
  {0x0301, 0x05, 0}, \
  {0x0303, 0x01, 0}, \
  {0x0304, 0x03, 0}, \
  {0x0305, 0x03, 0}, \
  {0x0306, 0x00, 0}, \
  {0x0307, 0x51, 0}, \
  {0x0309, 0x0A, 0}, \
  {0x030B, 0x01, 0}, \
  {0x030C, 0x00, 0}, \
  {0x030D, 0x54, 0}, \
  {0x455E, 0x00, 0}, \
  {0x471E, 0x4B, 0}, \
  {0x4767, 0x0F, 0}, \
  {0x4750, 0x14, 0}, \
  {0x4540, 0x00, 0}, \
  {0x47B4, 0x14, 0}, \
  {0x4713, 0x30, 0}, \
  {0x478B, 0x10, 0}, \
  {0x478F, 0x10, 0}, \
  {0x4793, 0x10, 0}, \
  {0x4797, 0x0E, 0}, \
  {0x479B, 0x0E, 0}, \
}

#define RES3_REG_ARRAY \
{ \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x0C, 0}, \
  {0x300A, 0xFF, 0}, \
  {0x300B, 0xFF, 0}, \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x09, 0}, \
  {0x0114, 0x03, 0}, \
  {0x0128, 0x00, 0}, \
  {0x012A, 0x18, 0}, \
  {0x012B, 0x00, 0}, \
  {0x0160, 0x03, 0}, \
  {0x0161, 0x29, 0}, \
  {0x0162, 0x0D, 0}, \
  {0x0163, 0xE8, 0}, \
  {0x0164, 0x00, 0}, \
  {0x0165, 0x00, 0}, \
  {0x0166, 0x0C, 0}, \
  {0x0167, 0xCF, 0}, \
  {0x0168, 0x01, 0}, \
  {0x0169, 0x34, 0}, \
  {0x016A, 0x08, 0}, \
  {0x016B, 0x6B, 0}, \
  {0x016C, 0x06, 0}, \
  {0x016D, 0x68, 0}, \
  {0x016E, 0x03, 0}, \
  {0x016F, 0x9C, 0}, \
  {0x0170, 0x01, 0}, \
  {0x0171, 0x01, 0}, \
  {0x0174, 0x03, 0}, \
  {0x0175, 0x03, 0}, \
  {0x018C, 0x0A, 0}, \
  {0x018D, 0x0A, 0}, \
  {0x0301, 0x05, 0}, \
  {0x0303, 0x01, 0}, \
  {0x0304, 0x03, 0}, \
  {0x0305, 0x03, 0}, \
  {0x0306, 0x00, 0}, \
  {0x0307, 0x51, 0}, \
  {0x0309, 0x0A, 0}, \
  {0x030B, 0x01, 0}, \
  {0x030C, 0x00, 0}, \
  {0x030D, 0x54, 0}, \
  {0x455E, 0x00, 0}, \
  {0x471E, 0x4B, 0}, \
  {0x4767, 0x0F, 0}, \
  {0x4750, 0x14, 0}, \
  {0x4540, 0x00, 0}, \
  {0x47B4, 0x14, 0}, \
  {0x4713, 0x30, 0}, \
  {0x478B, 0x10, 0}, \
  {0x478F, 0x10, 0}, \
  {0x4793, 0x10, 0}, \
  {0x4797, 0x0E, 0}, \
  {0x479B, 0x0E, 0}, \
}

#define RES4_REG_ARRAY \
{ \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x0C, 0}, \
  {0x300A, 0xFF, 0}, \
  {0x300B, 0xFF, 0}, \
  {0x30EB, 0x05, 0}, \
  {0x30EB, 0x09, 0}, \
  {0x0114, 0x03, 0}, \
  {0x0128, 0x00, 0}, \
  {0x012A, 0x18, 0}, \
  {0x012B, 0x00, 0}, \
  {0x0160, 0x02, 0}, \
  {0x0161, 0x5F, 0}, \
  {0x0162, 0x0D, 0}, \
  {0x0163, 0xE8, 0}, \
  {0x0164, 0x00, 0}, \
  {0x0165, 0x00, 0}, \
  {0x0166, 0x0C, 0}, \
  {0x0167, 0xCF, 0}, \
  {0x0168, 0x01, 0}, \
  {0x0169, 0x34, 0}, \
  {0x016A, 0x08, 0}, \
  {0x016B, 0x6B, 0}, \
  {0x016C, 0x06, 0}, \
  {0x016D, 0x68, 0}, \
  {0x016E, 0x03, 0}, \
  {0x016F, 0x9C, 0}, \
  {0x0170, 0x01, 0}, \
  {0x0171, 0x01, 0}, \
  {0x0174, 0x03, 0}, \
  {0x0175, 0x03, 0}, \
  {0x018C, 0x0A, 0}, \
  {0x018D, 0x0A, 0}, \
  {0x0301, 0x05, 0}, \
  {0x0303, 0x01, 0}, \
  {0x0304, 0x03, 0}, \
  {0x0305, 0x03, 0}, \
  {0x0306, 0x00, 0}, \
  {0x0307, 0x51, 0}, \
  {0x0309, 0x0A, 0}, \
  {0x030B, 0x01, 0}, \
  {0x030C, 0x00, 0}, \
  {0x030D, 0x54, 0}, \
  {0x455E, 0x00, 0}, \
  {0x471E, 0x4B, 0}, \
  {0x4767, 0x0F, 0}, \
  {0x4750, 0x14, 0}, \
  {0x4540, 0x00, 0}, \
  {0x47B4, 0x14, 0}, \
  {0x4713, 0x30, 0}, \
  {0x478B, 0x10, 0}, \
  {0x478F, 0x10, 0}, \
  {0x4793, 0x10, 0}, \
  {0x4797, 0x0E, 0}, \
  {0x479B, 0x0E, 0}, \
}

static sensor_lib_t sensor_lib_ptr =
{
  .sensor_slave_info =
  {
    .sensor_name = SENSOR_MODEL,
    .slave_addr = 0x20,
    .i2c_freq_mode = SENSOR_I2C_MODE_FAST,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .sensor_id_info =
    {
      .sensor_id_reg_addr = 0x0000,
      .sensor_id = 0x0219,
    },
    .power_setting_array =
    {
      .power_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VANA, //GPIO 22
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VIO, //GPIO 23
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VANA, //GPIO 22
          .config_val = GPIO_OUT_HIGH,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VIO, //GPIO 23
          .config_val = GPIO_OUT_HIGH,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 24000000,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_HIGH,
          .delay = 12,
        },
      },
      .size = 8,
      .power_down_setting_a =
      {
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_RESET,
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_CLK,
          .seq_val = CAMERA_MCLK,
          .config_val = 0,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VIO, //GPIO 23
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
        {
          .seq_type = CAMERA_POW_SEQ_VREG,
          .seq_val = CAMERA_VDIG,
          .config_val = 0,
          .delay = 0,
        },
        {
          .seq_type = CAMERA_POW_SEQ_GPIO,
          .seq_val = CAMERA_GPIO_VANA, //GPIO 22
          .config_val = GPIO_OUT_LOW,
          .delay = 1,
        },
      },
      .size_down = 5,
    },
  },
  .sensor_output =
  {
    .output_format = SENSOR_BAYER,
    .connection_mode = SENSOR_MIPI_CSI,
    .raw_output = SENSOR_10_BIT_DIRECT,
    .filter_arrangement = SENSOR_RGGB,
  },
  .output_reg_addr =
  {
    .x_output = 0x016C,
    .y_output = 0x016E,
    .line_length_pclk = 0x0162,
    .frame_length_lines = 0x0160,
  },
  .exp_gain_info =
  {
    .coarse_int_time_addr = 0x015A,
    .global_gain_addr = 0x0157,
    .vert_offset = 10,
  },
  .aec_info =
  {
    .min_gain = 1.0,
    .max_gain = 8.0,
    .max_analog_gain = 8.0,
    .max_linecount = 26880,
  },
  .sensor_num_frame_skip = 2,
  .sensor_num_HDR_frame_skip = 2,
  .sensor_max_pipeline_frame_delay = 2,
  .sensor_property =
  {
    .pix_size = 1.4,
    .sensing_method = SENSOR_SMETHOD_ONE_CHIP_COLOR_AREA_SENSOR,
    .crop_factor = 1.33,
  },
  .pixel_array_size_info =
  {
    .active_array_size =
    {
      .width = 3280,
      .height = 2464,
    },
    .left_dummy = 0,
    .right_dummy = 0,
    .top_dummy = 0,
    .bottom_dummy = 0,
  },
  .color_level_info =
  {
    .white_level = 1023,
    .r_pedestal = 0x40,  /* 10bit value */
    .gr_pedestal = 0x40, /* 10bit value */
    .gb_pedestal = 0x40, /* 10bit value */
    .b_pedestal = 0x40,  /* 10bit value */
  },
  .sensor_stream_info_array =
  {
    .sensor_stream_info =
    {
      {
        .vc_cfg_size = 2,
        .vc_cfg =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
          {
            .cid = 1,
            .dt = 0x35,
            .decode_format = CSI_DECODE_8BIT
          },
        },
        .pix_data_fmt =
        {
          SENSOR_BAYER,
          SENSOR_META,
        },
      },
      {
        .vc_cfg_size = 1,
        .vc_cfg =
        {
          {
            .cid = 1,
            .dt = 0x35,
            .decode_format = CSI_DECODE_8BIT
          },
        },
        .pix_data_fmt =
        {
          SENSOR_META,
        },
      },
    },
    .size = 2,              /* uint16_t */
  },
  .start_settings =
  {
    .reg_setting_a = START_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .stop_settings =
  {
    .reg_setting_a = STOP_REG_ARRAY,
    .addr_type = CAMERA_I2C_WORD_ADDR,
    .data_type = CAMERA_I2C_BYTE_DATA,
    .delay = 0,
  },
  .groupon_settings =
  {
    .reg_setting_a = {},
    .addr_type = 0,
    .data_type = 0,
    .delay = 0,
  },
  .groupoff_settings =
  {
    .reg_setting_a = {},
    .addr_type = 0,
    .data_type = 0,
    .delay = 0,
  },
  .embedded_data_enable_settings =
  {
    .reg_setting_a = {},
    .addr_type = 0,
    .data_type = 0,
    .delay = 0,
  },
  .embedded_data_disable_settings =
  {
    .reg_setting_a = {},
    .addr_type = 0,
    .data_type = 0,
    .delay = 0,
  },
  .test_pattern_info =
  {
    .test_pattern_settings =
    {
      {
        .mode = SENSOR_TEST_PATTERN_OFF,
        .settings =
        {
          .reg_setting_a =
          {
            {0x0600, 0x0000, 0x00},
          },
          .size = 1,
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        }
      },
      {
        .mode = SENSOR_TEST_PATTERN_SOLID_COLOR,
        .settings =
        {
          .reg_setting_a =
          {
            {0x0600, 0x0001, 0x00},
          },
          .size = 1,
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_COLOR_BARS,
        .settings =
        {
          .reg_setting_a =
          {
            {0x0600, 0x0002, 0x00},
          },
          .size = 1,
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_COLOR_BARS_FADE_TO_GRAY,
        .settings =
        {
          .reg_setting_a =
          {
            {0x0600, 0x0003, 0x00},
          },
          .size = 1,
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
      {
        .mode = SENSOR_TEST_PATTERN_PN9,
        .settings =
        {
          .reg_setting_a =
          {
            {0x0600, 0x0004, 0x00},
          },
          .size = 1,
          .addr_type = CAMERA_I2C_WORD_ADDR,
          .data_type = CAMERA_I2C_WORD_DATA,
          .delay = 0,
        },
      },
    },
    .size = 5,
    .solid_mode_addr =
    {
      .r_addr = 0x0602,
      .gr_addr = 0x0604,
      .gb_addr = 0x0606,
      .b_addr = 0x0608,
    },
  },
  .init_settings_array =
  {
    .reg_settings =
    {
      {
        .reg_setting_a = INIT0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
    },
    .size = 1,
  },
  .res_settings_array =
  {
    .reg_settings =
    {
      /* Res 0 */
      {
        .reg_setting_a = RES0_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 1 */
      {
        .reg_setting_a = RES1_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 2 */
      {
        .reg_setting_a = RES2_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 3 */
      {
        .reg_setting_a = RES3_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
      /* Res 4 */
      {
        .reg_setting_a = RES4_REG_ARRAY,
        .addr_type = CAMERA_I2C_WORD_ADDR,
        .data_type = CAMERA_I2C_BYTE_DATA,
        .delay = 0,
      },
    },
    .size = 5,
  },
  .out_info_array =
  {
    .out_info =
    {
      {/* 30 fps full size settings */
        .x_output = 3264,
        .y_output = 2448,
        .line_length_pclk = 3448,
        .frame_length_lines = 2506,
        .vt_pixel_clk = 259200000,
        .op_pixel_clk = 268800000,
        .binning_factor = 1,
        .max_fps = 30.0,
        .min_fps = 7.5,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 1.000,
        .is_pdaf_supported = 0,
      },

      {/* 30 fps qtr size settings */
        .x_output = 1632,
        .y_output = 1224,
        .line_length_pclk = 3448,
        .frame_length_lines = 2506,
        .vt_pixel_clk = 259200000,
        .op_pixel_clk = 268800000,
        .binning_factor = 1,
        .max_fps = 30.0,
        .min_fps = 7.5,
        .mode = SENSOR_DEFAULT_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 1.000,
        .is_pdaf_supported = 0,
      },


      {/* 60 fps settings */
        .x_output = 1640,
        .y_output = 924,
        .line_length_pclk = 3448,
        .frame_length_lines = 1253,
        .vt_pixel_clk = 259200000,
        .op_pixel_clk = 268800000,
        .binning_factor = 1,
        .max_fps = 60.0,
        .min_fps = 7.5,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 1.000,
        .is_pdaf_supported = 0,
      },

      {/* 90 fps settings */
        .x_output = 1640,
        .y_output = 924,
        .line_length_pclk = 3560,
        .frame_length_lines = 809,
        .vt_pixel_clk = 259200000,
        .op_pixel_clk = 268800000,
        .binning_factor = 1,
        .max_fps = 90.0,
        .min_fps = 7.5,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 1.000,
        .is_pdaf_supported = 0,
      },

      {/* 120 fps settings */
        .x_output = 1640,
        .y_output = 924,
        .line_length_pclk = 3560,
        .frame_length_lines = 607,
        .vt_pixel_clk = 259200000,
        .op_pixel_clk = 268800000,
        .binning_factor = 1,
        .max_fps = 120.0,
        .min_fps = 7.5,
        .mode = SENSOR_HFR_MODE,
        .offset_x = 0,
        .offset_y = 0,
        .scale_factor = 1.000,
        .is_pdaf_supported = 0,
      },
    },
    .size = 5,
  },
  .csi_params =
  {
    .lane_cnt = 4,
    .settle_cnt = 0x14,
    .is_csi_3phase = 0,
  },
  .csid_lut_params_array =
  {
    .lut_params =
    {
      /* Res 0 */
      {
        .num_cid = 2,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
          {
            .cid = 1,
            .dt = CSI_EMBED_DATA,
            .decode_format = CSI_DECODE_8BIT
          },
        },
      },
      /* Res 1 */
      {
        .num_cid = 2,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
          {
            .cid = 1,
            .dt = CSI_EMBED_DATA,
            .decode_format = CSI_DECODE_8BIT
          },
        },
      },
      /* Res 2 */
      {
        .num_cid = 2,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
          {
            .cid = 1,
            .dt = CSI_EMBED_DATA,
            .decode_format = CSI_DECODE_8BIT
          },
        },
      },
      /* Res 3 */
      {
        .num_cid = 2,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
          {
            .cid = 1,
            .dt = CSI_EMBED_DATA,
            .decode_format = CSI_DECODE_8BIT
          },
        },
      },
      /* Res 4 */
      {
        .num_cid = 2,
        .vc_cfg_a =
        {
          {
            .cid = 0,
            .dt = CSI_RAW10,
            .decode_format = CSI_DECODE_10BIT
          },
          {
            .cid = 1,
            .dt = CSI_EMBED_DATA,
            .decode_format = CSI_DECODE_8BIT
          },
        },
      },

    },
    .size = 5,
  },
  .crop_params_array =
  {
    .crop_params =
    {
      /* Res 0 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 1 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 2 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 3 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
      /* Res 4 */
      {
        .top_crop = 0,
        .bottom_crop = 0,
        .left_crop = 0,
        .right_crop = 0,
      },
    },
    .size = 5,
  },
  .exposure_func_table =
  {
    .sensor_calculate_exposure = sensor_calculate_exposure,
    .sensor_fill_exposure_array = sensor_fill_exposure_array,
  },
  .meta_data_out_info_array =
  {
    .meta_data_out_info =
    {
      {
        .width = 0,
        .height = 0,
        .stats_type = 0,
      },
    },
    .size = 0,
  },
  .sensor_capability = 0,
  .awb_func_table =
  {
    .sensor_fill_awb_array = 0,
    .awb_table_size = 0,
  },
  .rolloff_config =
  {
    .enable = FALSE,
    .full_size_info =
    {
      .full_size_width = 0,
      .full_size_height = 0,
      .full_size_left_crop = 0,
      .full_size_top_crop = 0,
    },
  },
  .adc_readout_time = 0,
  .sensor_num_fast_aec_frame_skip = 0,
  .noise_coeff = {
    .gradient_S = 3.738032e-06,
    .offset_S = 3.651935e-04,
    .gradient_O = 4.499952e-07,
    .offset_O = -2.968624e-04,
  },
};

#endif
