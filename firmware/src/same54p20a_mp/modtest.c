/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>

#include "py/obj.h"
#include "py/mphal.h"
#include "modtest.h"
#include "definitions.h"

extern bool UART_DEBUG_PRINT;
extern bool LED_STATUS_PRINT;

STATIC mp_obj_t test1(void) {
	SYS_CONSOLE_MESSAGE("\r\ntest1 is running and it enables debug logs\r\n");
    UART_DEBUG_PRINT = 1;
    LED_STATUS_PRINT = 1;
    SYS_CONSOLE_MESSAGE("\r\nThe values of those variables are given below,\r\nUART_DEBUG_PRINT = 1\r\nLED_STATUS_PRINT = 1\r\n");
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(test1_obj, test1);

STATIC mp_obj_t test2(void) {
	SYS_CONSOLE_MESSAGE("\r\ntest2 is running and it disables debug logs\r\n");
    UART_DEBUG_PRINT = 0;
    LED_STATUS_PRINT = 0;
    SYS_CONSOLE_MESSAGE("\r\nThe values of those variables are given below,\r\nUART_DEBUG_PRINT = 0\r\nLED_STATUS_PRINT = 0\r\n");   
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(test2_obj, test2);



STATIC const mp_rom_map_elem_t test_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_test) },

    { MP_ROM_QSTR(MP_QSTR_test1), MP_ROM_PTR(&test1_obj) },
    { MP_ROM_QSTR(MP_QSTR_test2), MP_ROM_PTR(&test2_obj) },

};

STATIC MP_DEFINE_CONST_DICT(test_module_globals, test_module_globals_table);

const mp_obj_module_t test_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&test_module_globals,
};
