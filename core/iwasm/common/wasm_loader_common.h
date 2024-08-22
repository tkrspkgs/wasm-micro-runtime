/*
 * Copyright (C) 2024 Amazon Inc.  All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#ifndef _WASM_LOADER_COMMON_H
#define _WASM_LOADER_COMMON_H

#include "platform_common.h"
#include "../interpreter/wasm.h"

#ifdef __cplusplus
extern "C" {
#endif

bool
wasm_memory_check_flags(const uint8 mem_flag, char *error_buf,
                        uint32 error_buf_size, bool is_aot);

bool
is_valid_value_type(uint8 value_tpye);

bool
is_valid_value_type_for_interpreter(uint8 value_tpye);

bool
is_valid_func_type(const WASMFuncType *func_type);

bool
is_indices_overflow(uint32 import, uint32 other, char *error_buf,
                    uint32 error_buf_size);

bool
read_leb(uint8 **p_buf, const uint8 *buf_end, uint32 maxbits, bool sign,
         uint64 *p_result, char *error_buf, uint32 error_buf_size);

void
wasm_loader_set_error_buf(char *error_buf, uint32 error_buf_size,
                          const char *string, bool is_aot);

#ifdef __cplusplus
}
#endif

#endif /* end of _WASM_LOADER_COMMON_H */
