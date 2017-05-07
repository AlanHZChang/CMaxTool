/* sensor_debug.h
 *
 * Copyright (c) 2012-2014 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef __SENSOR_DEBUG_H__
#define __SENSOR_DEBUG_H__

#undef SLOG_HIGH
#undef SLOG_LOW
#undef SERR
#undef SLOW
#undef SHIGH

/* Find Max*/
#define SMAX(x,y) (((x)>(y)) ? (x) : (y))

/* Find array size*/
#define S_ARRAYSIZE(x) (sizeof(x) / sizeof((x)[0]))

/* Enable SLOG_HIGH to print SERR and SHIGH */
#define SLOG_HIGH

/* Enable SLOG_LOW to print all log levels - SERR, SLOW and SHIGH */
//#define SLOG_LOW

/* ------- change this macro to enable mutex debugging for deadlock --------*/
#define SENSOR_DEBUG_MUTEX    0

typedef enum {
    SENSOR_DBG_ERR    = 0,
    SENSOR_DBG_HIGH   = 1,
    SENSOR_DBG_LOW    = 2,
    SENSOR_DBG_MAX
} sensor_debug_level_t;

typedef struct {
  int32_t g_dbg_level;
  int32_t s_dbg_level;
} sensor_global_map_t;

extern volatile int32_t sensor_debug_level;
extern volatile int32_t fih_use_al6010_sensor;

void module_sensor_setLoglevel(void);

#ifdef _ANDROID_
  #undef LOG_NIDEBUG
  #undef LOG_TAG
  #define LOG_NIDEBUG 0
  #define LOG_TAG "mm-camera-sensor"
  #include <utils/Log.h>
  #include <cutils/properties.h>

  #define SERR(fmt, args...) \
    ALOGE("%s:%d" fmt"\n", __func__, __LINE__, ##args)
  #define SHIGH(fmt, args...) \
    ALOGI_IF(sensor_debug_level >= SENSOR_DBG_HIGH, "%s:%d" fmt"\n", __func__, __LINE__, ##args)
  #define SLOW(fmt, args...) \
    ALOGD_IF(sensor_debug_level >= SENSOR_DBG_LOW, "%s:%d" fmt"\n", __func__, __LINE__, ##args)
#else
  #include <stdio.h>
  #if defined(SLOW_DEBUG)
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

#if (SENSOR_DEBUG_MUTEX == 1)
  #define PTHREAD_MUTEX_LOCK(m) do { \
    SHIGH("[sensor_mutex_log] before pthread_mutex_lock(%p)\n", m); \
    pthread_mutex_lock(m); \
    SHIGH("[sensor_mutex_log] after pthread_mutex_lock(%p)\n", m); \
  } while(0)

  #define PTHREAD_MUTEX_UNLOCK(m) do { \
    SHIGH("[sensor_mutex_log] before pthread_mutex_unlock(%p)\n", m); \
    pthread_mutex_unlock(m); \
    SHIGH("[sensor_mutex_log] after pthread_mutex_unlock(%p)\n", m); \
  } while(0)
#else
  #define PTHREAD_MUTEX_LOCK(m)   pthread_mutex_lock(m)
  #define PTHREAD_MUTEX_UNLOCK(m) pthread_mutex_unlock(m)
#endif

#endif /* __SENSOR_DBG_H__ */
