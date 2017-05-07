/* sensor_dbg.h
 *
 * Copyright (c) 2012-2014 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef __SENSOR_DBG_H__
#define __SENSOR_DBG_H__

#undef SLOG_HIGH
#undef SLOG_LOW
#undef SERR
#undef SLOW
#undef SHIGH

/* This is used only for static logging by chromatix and sensor libs. For dynamic
 * logging, sensor_debug.h is used */

/* Enable SLOG_HIGH to print SERR and SHIGH */
#define SLOG_HIGH

/* Enable SLOG_LOW to print all log levels - SERR, SLOW and SHIGH */
//#define SLOG_LOW

#ifdef _ANDROID_
  #undef LOG_NIDEBUG
  #undef LOG_TAG
  #define LOG_NIDEBUG 0
  #define LOG_TAG "mm-camera-sensor"
  #include <utils/Log.h>
  #include <cutils/properties.h>
  #if defined(SLOG_LOW)
    #define SERR(fmt, args...) \
      ALOGE("%s:%d " fmt "\n", __func__, __LINE__, ##args)
    #define SLOW(fmt, args...) \
      ALOGD("%s:%d " fmt "\n", __func__, __LINE__, ##args)
    #define SHIGH(fmt, args...) \
      ALOGI("%s:%d " fmt "\n", __func__, __LINE__, ##args)
  #elif defined(SLOG_HIGH)
    #define SERR(fmt, args...) \
      ALOGE("%s:%d " fmt "\n", __func__, __LINE__, ##args)
    #define SLOW(fmt, args...) do{}while(0)
    #define SHIGH(fmt, args...) \
      ALOGI("%s:%d " fmt "\n", __func__, __LINE__, ##args)
  #else
    #define SERR(fmt, args...) \
      ALOGE("%s:%d " fmt "\n", __func__, __LINE__, ##args)
    #define SLOW(fmt, args...) do{}while(0)
    #define SHIGH(fmt, args...) do{}while(0)
  #endif
#else
  #include <stdio.h>
  #if defined(SLOG_LOW)
    #define SERR(fmt, args...) fprintf(stderr, fmt, ##args)
    #define SLOW(fmt, args...) fprintf(stderr, fmt, ##args)
    #define SHIGH(fmt, args...) fprintf(stderr, fmt, ##args)
  #elif defined(SLOG_HIGH)
    #define SERR(fmt, args...) fprintf(stderr, fmt, ##args)
    #define SLOW(fmt, args...) do{}while(0)
    #define SHIGH(fmt, args...) fprintf(stderr, fmt, ##args)
  #else
    #define SERR(fmt, args...) fprintf(stderr, fmt, ##args)
    #define SLOW(fmt, args...) do{}while(0)
    #define SHIGH(fmt, args...) do{}while(0)
  #endif
#endif

#endif /* __SENSOR_DBG_H__ */
