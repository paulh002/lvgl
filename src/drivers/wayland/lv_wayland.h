/**
 * @file lv_wayland.h
 */

#ifndef LV_WAYLAND_H
#define LV_WAYLAND_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "../../lv_conf_internal.h"

#if LV_USE_WAYLAND

#include "lv_wl_keyboard.h"
#include "lv_wl_pointer.h"
#include "lv_wl_touch.h"
#include "lv_wl_window.h"
#include "lv_wl_pointer_axis.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Wrapper around lv_timer_handler
 * @note Must be called in the application run loop instead of the
 * regular lv_timer_handler provided by LVGL
 * @return time till it needs to be run next (in ms)
 */
uint32_t lv_wayland_timer_handler(void);

/**
 * Retrieves the file descriptor of the wayland socket
 */
int lv_wayland_get_fd(void);

void lv_wayland_deinit(void);

lv_result_t lv_wayland_init(void);
void lv_wayland_flush(void);
int lv_wayland_get_display_size(const char *name, int32_t *width, int32_t *height);

/**
 * @brief Check if a monitor is physically attached & active for a given output index
 * @param output_index Index in lv_wl_ctx.physical_outputs array
 * @return true if connected, false otherwise
 */
bool lv_wayland_is_output_connected(uint32_t output_index);

/**
 * @brief Check if a monitor is currently attached by its Wayland output name
 * @param output_name Name advertised by compositor (e.g., "HDMI-A-1", "AOC 27B2H")
 * @return true if connected, false if disconnected or unknown
 */
bool lv_wayland_is_output_connected_by_name(const char *output_name);

/**********************
 *      MACROS
 **********************/

#endif /* LV_USE_WAYLAND */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LV_WAYLAND_H */
