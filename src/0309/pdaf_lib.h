/*======================================================================
    Copyright (c) 2015-2016 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.
=======================================================================*/

#ifndef _PDAF_LIB_H
#define _PDAF_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_PDAF_WINDOW        200  /*max fixed pdaf window number*/
#define MAX_FLOAT_WINDOW       32   /*max floating pdaf window number*/
#define MAX_CAMIF_PDAF_PIXELS  256  /*max number of pd pixels in a block*/
#define MAXWIDTH               25  /* =8K/256 */
#define MAXHEIGHT              19
#define MAXLENGTH2D            MAXWIDTH * MAXHEIGHT
#define MAXLENGTH1D            256
#define MAX_RESOLUTION_MODES   13


/*
 * pdaf driver version is given by:
 * <Major version>.<Minor version>.<Patch version>
 */
#define PDAF_DRIVER_VERSION "2.0.0"
#define PDAF_SDK_CAPABILITIES "Type 2 and Type 3,\
        CANONICAL, FLIP, MIRROR and crop sensor readout\
        1D, 2D pdaf calibration"

/*pd lib handle*/
typedef void * PD_HANDLE;
/*camif lib handle*/
typedef void * PD_CAMIF_HANDLE;

/* calibration method */
typedef enum pdaf_calibration_version_t {
  CALIBRATION_VERSION_1D,
  CALIBRATION_VERSION_2D,
  /* supporting new calibration tool 80-NV125-1 H (or above) output */
  CALIBRATION_VERSION_UPDATE,
  CALIBRATION_VERSION_MAX = 1023,
}pdaf_calibration_version_t;

/* vendor info*/
typedef enum pdaf_vendor_t {
  QTI = 1,
  EXTERNAL,
  MAX_VENDOR = 1023,
}pdaf_vendor_t;

#define D_PD_LIB_E_OK                          (0)
#define D_PD_LIB_E_NG                          (-1)
#define D_PD_LIB_REGDATA_IS_OK                 (0)
#define D_PD_LIB_REGDATA_IS_NG                 (1)
#define D_PD_LIB_COORD_ERROR                   (-1)

typedef struct
{
    unsigned long         PointNum;
    unsigned long        *p_AnalogGain;
    unsigned long        *p_Confidence;
} DefocusOKNGThrLine_t;

/* Input format for 3rd party lib */
typedef struct
{
    signed long           PhaseDifference;
    unsigned long         ConfidenceLevel;
    unsigned short        XSizeOfImage;
    unsigned short        YSizeOfImage;
    unsigned short        XAddressOfWindowStart;
    unsigned short        YAddressOfWindowStart;
    unsigned short        XAddressOfWindowEnd;
    unsigned short        YAddressOfWindowEnd;
    unsigned short        XKnotNumSlopeOffset;
    unsigned short        YKnotNumSlopeOffset;
    signed long           *p_SlopeData;
    signed long           *p_OffsetData;
    unsigned short        *p_XAddressKnotSlopeOffset;
    unsigned short        *p_YAddressKnotSlopeOffset;
    signed long           AdjCoeffSlope;
    unsigned long         ImagerAnalogGain;
    unsigned short        XKnotNumDefocusOKNG;
    unsigned short        YKnotNumDefocusOKNG;
    DefocusOKNGThrLine_t  *p_DefocusOKNGThrLine;
    unsigned short        *p_XAddressKnotDefocusOKNG;
    unsigned short        *p_YAddressKnotDefocusOKNG;
    unsigned long         DensityOfPhasePix;
} PdLibInputData_t;

/* Output format for 3rd party lib */
typedef struct
{
    signed long           Defocus;
    signed char           DefocusConfidence;
    unsigned long         DefocusConfidenceLevel;
    signed long           PhaseDifference;
} PdLibOutputData_t;

typedef struct
{
    signed int  x;
    signed int  y;
} PdLibPoint_t;

typedef struct
{
    unsigned int        orientation;
    unsigned int        hdr_en;
    unsigned int        hdr_binning;
    unsigned int        x_add_sta_h;
    unsigned int        x_add_sta_l;
    unsigned int        y_add_sta_h;
    unsigned int        y_add_sta_l;
    unsigned int        x_add_end_h;
    unsigned int        x_add_end_l;
    unsigned int        y_add_end_h;
    unsigned int        y_add_end_l;
    unsigned int        x_out_size_h;
    unsigned int        x_out_size_l;
    unsigned int        y_out_size_h;
    unsigned int        y_out_size_l;
    unsigned int        x_evn_inc;
    unsigned int        x_odd_inc;
    unsigned int        y_evn_inc;
    unsigned int        y_odd_inc;
    unsigned int        scale_mode;
    unsigned int        scale_m_h;
    unsigned int        scale_m_l;
    unsigned int        dig_crop_x_offset_h;
    unsigned int        dig_crop_x_offset_l;
    unsigned int        dig_crop_y_offset_h;
    unsigned int        dig_crop_y_offset_l;
    unsigned int        dig_crop_image_width_h;
    unsigned int        dig_crop_image_width_l;
    unsigned int        dig_crop_image_height_h;
    unsigned int        dig_crop_image_height_l;
    unsigned int        binning_mode;
    unsigned int        binning_type;

    unsigned int        pd_offset_x_h;
    unsigned int        pd_offset_x_l;
    unsigned int        pd_offset_y_h;
    unsigned int        pd_offset_y_l;
    unsigned int        pd_area_w_h;
    unsigned int        pd_area_w_l;
    unsigned int        pd_area_h_h;
    unsigned int        pd_area_h_l;
    unsigned int        reg_addr_flex_win[MAX_FLOAT_WINDOW*4*2];
} PdLibSensorRegData_t;

typedef struct
{
    unsigned int        img_orientation_h;
    unsigned int        img_orientation_v;
    unsigned int        hdr_mode_en;
    unsigned int        hdr_reso_redu_h;
    unsigned int        hdr_reso_redu_v;
    unsigned int        x_add_sta;
    unsigned int        y_add_sta;
    unsigned int        x_add_end;
    unsigned int        y_add_end;
    unsigned int        x_out_size;
    unsigned int        y_out_size;
    unsigned int        x_evn_inc;
    unsigned int        x_odd_inc;
    unsigned int        y_evn_inc;
    unsigned int        y_odd_inc;
    unsigned int        scale_mode;
    unsigned int        scale_m;
    unsigned int        dig_crop_x_offset;
    unsigned int        dig_crop_y_offset;
    unsigned int        dig_crop_image_width;
    unsigned int        dig_crop_image_height;
    unsigned int        binning_mode;
    unsigned int        binning_type_h;
    unsigned int        binning_type_v;

    unsigned int        pd_offset_x;
    unsigned int        pd_offset_y;
    unsigned int        pd_area_w;
    unsigned int        pd_area_h;
    unsigned int        flex_win_addr[MAX_FLOAT_WINDOW*4];
} PdLibSensorSetting_t;

/* function return status */
typedef enum PDAF_RET_t{
  PDAF_LIB_OK,
  PDAF_LIB_CONFIG_NOT_SUPPORT,
  PDAF_LIB_MEM_ERR,
  PDAF_LIB_PARAM_ERR,
  PDAF_LIB_ERR,
  PDAF_LIB_ERR_MAX = 1023,
}PDAF_RET_t;

typedef enum sheild_pd_info_t{
  PDAF_LEFT_PIXEL,
  PDAF_RIGHT_PIXEL,
}sheild_pd_info_t;

/*pdaf window types*/
typedef enum pdaf_sw_window_mode_t {
  FLOAT_WINDOW,
  FIXED_GRID_WINDOW,
  WINDOM_MODE_MAX,
}pdaf_sw_window_mode_t;

/*pdaf floating window configure*/
/*each components are defined as a percentage of image size*/
typedef struct{
  float pdaf_address_start_hori;  /*(0-1), percentage of image width*/
  float pdaf_address_start_ver;   /*(0-1), percentage of image height*/
  float pdaf_address_end_hori;    /*(0-1), percentage of image width*/
  float pdaf_address_end_ver;     /*(0-1), percentage of image height*/
}pdaf_af_window_t;

typedef struct{
  /*number of floating windows*/
  unsigned int      pdaf_number_windows;
  pdaf_af_window_t  af_float_window[MAX_FLOAT_WINDOW];
}pdaf_float_window_configure_t;

/*fixed pdaf window configuration*/
/*roi width and roi horizontal offset is defined
  as a percentage of image width*/
/*roi height and roi vertical offset is defined
  as a percentage of image height*/
typedef struct{
  /*window number along horizontal direction*/
  unsigned int     window_number_hori;
  /*window number along vertical direction*/
  unsigned int     window_number_ver;
  pdaf_af_window_t af_fix_window;
}pdaf_fixed_grid_window_configure_t;

/*window configuration */
typedef struct{
  /*Depending on window mode, either fixed window or
    floating window is configured.*/
  pdaf_sw_window_mode_t              pdaf_sw_window_mode;
  pdaf_float_window_configure_t      float_window_configure;
  pdaf_fixed_grid_window_configure_t fixed_grid_window_configure;
}pdaf_window_configure_t;

/*pd pixel location in one block*/
typedef struct{
  int x;
  int y;
  sheild_pd_info_t flag;
}camif_pix_t;

typedef enum pdaf_sensor_orientation_t
{
  PDAF_ORIENTATION_DEFAULT,
  PDAF_ORIENTATION_MIRROR,
  PDAF_ORIENTATION_FLIP,
  PDAF_ORIENTATION_MIRROR_AND_FLIP,
  PDAF_ORIENTATION_MAX,
}pdaf_sensor_orientation_t;

typedef struct{
  int width;
  int height;
}camif_dim_t;

/* camif lib output*/
typedef struct{
  /* pointer to pdaf left images, 16bit per pixel*/
  unsigned short  *p_pdaf_left;
  unsigned int    pdaf_left_buffer_width;       /* width, in pixel*/
  unsigned int    pdaf_left_buffer_stride;      /* stride, in byte*/

  /* pointer to pdaf left images, 16bit per pixel*/
  unsigned short  *p_pdaf_right;
  unsigned int    pdaf_right_buffer_width;      /* width, in pixel*/
  unsigned int    pdaf_right_buffer_stride;     /* stride, in byte*/
  unsigned int    pdaf_buffer_height;           /* height*/
} pdaf_camif_output_data_t;

typedef struct
{
  int             defocus;       /*in DAC range*/
  signed char     df_confidence; /*PD_LIB_E_OK or PD_LIB_E_NG */
  unsigned int    df_conf_level; /*confidence level*/
  float           phase_diff;    /*phase difference*/
} pdaf_lib_defocus_t;/*output data*/

typedef struct {
  unsigned char      *pd_stats;
  unsigned int       x_offset;   /* offset to PD area in full-size image */
  unsigned int       y_offset;
  unsigned int       x_win_num;  /* PD area grid number */
  unsigned int       y_win_num;
  pdaf_lib_defocus_t defocus[MAX_PDAF_WINDOW];
  unsigned int       status;
  void               *eeprom_data;
  int                cur_res;
  float              sensor_real_gain;
} pdaf_params_t;

typedef struct {
  int x;
  int y;
  int w;
  int h;
}rect_t;

typedef enum pdaf_buffer_type_t
{
  PDAF_BUFFER_FLAG_INVALID,
  PDAF_BUFFER_FLAG_SPARSE,  //T3
  PDAF_BUFFER_FLAG_SEQUENTIAL_LINE, //T2
  // for future dual PD
  PDAF_BUFFER_FLAG_INTERLEAVE_CHANNEL,
  PDAF_BUFFER_FLAG_MAX,
}pdaf_buffer_type_t;

/* pdaf buffer data type */
typedef enum pdaf_buffer_data_type_t
{
  PDAF_DATA_TYPE_RAW8,
  /* compressed, [9:2] [9:2] [9:2] [9:2] [1:0][1:0][1:0][1:0] */
  PDAF_DATA_TYPE_RAW10_PACKED,
  PDAF_DATA_TYPE_RAW16,
  /* Q10 format */
  PDAF_DATA_TYPE_RAW10_LSB,
}pdaf_buffer_data_type_t;

typedef struct
{
  /* pdaf pixel number inside of a window */
  unsigned int pix_count;
  /*pixel 2D pos, left_pixel,right_pixel*/
  /* should not contain the offset */
  /* offset should add back for correct skip pattern */
  camif_pix_t  pix_coords[MAX_CAMIF_PDAF_PIXELS];
  uint32_t     pd_offset_horizontal;
  uint32_t     pd_offset_vertical;
  /*pattern window width and height*/
  camif_dim_t block_dim;
}pdaf_block_pattern_t;

typedef struct{
  pdaf_block_pattern_t       block_pattern;
  unsigned int               stride;
  pdaf_buffer_data_type_t    buffer_data_type;
  pdaf_buffer_type_t         buffer_type;
}pdaf_block_pattern_info_t;

typedef struct{
  pdaf_block_pattern_t        block_pattern;
  /* number of PD blocks in x */
  unsigned int                block_count_horizontal;
  /* number of PD blocks in y */
  unsigned int                block_count_vertical;
}pdaf_sensor_native_pattern_info_t;

typedef struct{
  pdaf_block_pattern_t        block_pattern;
  /* insensor cropped */
  rect_t                      crop_region;
  /* number of PD blocks in x */
  unsigned int                block_count_horizontal;
  /* number of PD blocks in y */
  unsigned int                block_count_vertical;
  /* orignal image width in pixel*/
  unsigned int                ori_image_width;
  /* orignal image height in pixel*/
  unsigned int                ori_image_height;
  unsigned int                cur_image_width;
  unsigned int                cur_image_height;
  pdaf_sensor_orientation_t   orientation;
  pdaf_buffer_data_type_t     buffer_data_type;
}pdaf_sensor_native_info_t;

typedef struct{
  /* for T3, camif data pattern*/
  /* for T2, the pd stats pattern */
  pdaf_block_pattern_t    buffer_block_pattern_left;
  /* right vfe camif data pattern, NULL in single VFE*/
  pdaf_block_pattern_t    buffer_block_pattern_right;
  /* data type */
  pdaf_buffer_data_type_t buffer_data_type;
  /* buffer status descriptor */
  pdaf_buffer_type_t      buffer_type;

  /* subsampled image width in pixel*/
  unsigned int  camif_left_buffer_width;
  /* subsampled image stride in byte*/
  unsigned int  camif_left_buffer_stride;
  /* subsampled image width in pixel*/
  unsigned int  camif_right_buffer_width;
  /* subsampled image stride in byte*/
  unsigned int  camif_right_buffer_stride;
  /* subsampled image height*/
  unsigned int  camif_buffer_height;
  /* overlap in pixel for dual vfe in the original image*/
  /* before subsampling*/
  /* set zero in single vfe */
  unsigned int image_overlap;
  /* horizontal offset in pixel for right image in dual vfe */
  /* set zero in single vfe */
  unsigned int right_image_offset;
}pdaf_data_buffer_info_t;

typedef struct{
 void                    *pdaf_gain_ptr;
 pdaf_data_buffer_info_t *isp_config;
}pdaf_init_info_t;

/*configure parameter*/
typedef struct
{
  pdaf_vendor_t                     vendor_id;
  unsigned char                     stats_dt;
  pdaf_sensor_native_pattern_info_t sensor_native_pattern_info[MAX_RESOLUTION_MODES];
  pdaf_sensor_orientation_t         orientation;
  pdaf_block_pattern_info_t         buffer_block_pattern_info[MAX_RESOLUTION_MODES];
  unsigned int                      black_level;
  pdaf_calibration_version_t        cali_version;
  pdaf_window_configure_t           window_configure;
  int                               defocus_confidence_th;
  /*reserved*/
  void                             *p_tunnable;
} pdaf_lib_t;

#endif
