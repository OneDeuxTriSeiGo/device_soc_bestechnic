/*
 * Copyright (c) 2021 bestechnic (Shanghai) Technologies CO., LIMITED.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __APP_FLASH_API_H__
#define __APP_FLASH_API_H__

#ifdef __cplusplus
extern "C"{
#endif

/*****************************header include********************************/
#include "norflash_api.h"

/******************************macro defination*****************************/

/******************************type defination******************************/

/****************************function declearation**************************/
/**
 * @brief Register flash module
 * 
 * @param module        flash module ID, @see enum NORFLASH_API_MODULE_ID_T
 * @param baseAddr      Base address of the module
 * @param len           length of the module
 * @param imageHandler  Callback function when flash is flushed
 */
void app_flash_register_module(uint8_t module,
                               uint32_t baseAddr,
                               uint32_t len,
                               uint32_t imageHandler);

/**
 * @brief Flush pending flash operation
 * 
 * NOTE: flash operation is usually pended in order to minimize the physical flash operation,
 * so sometimes, the flash is not changed after you call a flash operation. This function will
 * force the flash controller to execute pended operation.
 * 
 * @param module        flash module, @see enum NORFLASH_API_MODULE_ID_T to get more info
 * @param type          flash operation type, @see enum NORFLASH_API_OPRATION_TYPE to get more info
 */
void app_flash_flush_pending_op(enum NORFLASH_API_MODULE_ID_T module,
                                enum NORFLASH_API_OPRATION_TYPE type);
/**
 * @brief Check flash if is clean.
 *
 * @param addr         flash start address
 * @param flashOffset  length of checking.
 * @return true: is clean; false: is dirty.
 */
bool app_flash_is_clean(uint32_t addr, uint32_t len);

/**
 * @brief Erase the whole sector(4K bytes) according to the incoming flash offset
 * 
 * @param module        flash module
 * @param flashOffset   offset according to the flash module base address
 */
void app_flash_sector_erase(enum NORFLASH_API_MODULE_ID_T module, uint32_t flashOffset);

/**
 * @brief Erase all bolocks(32k bytes or 64k bytes) and sectors in the specified range.
 *  according to the incoming flash offset and length.
 * @param module        flash module
 * @param flashOffset   offset according to the flash module base address
 * @param len           erase length.
 */
void app_flash_erase(enum NORFLASH_API_MODULE_ID_T module, uint32_t flashOffset, uint32_t len);

/**
 * @brief Write data to flash according to incoming flash module and offset
 * 
 * @param module        flash module, @see enum NORFLASH_API_MODULE_ID_T to get more info
 * @param flashOffset   offset according to the flash module base address
 * @param ptr           pointer of data to write
 * @param len           length of data to read
 * @param synWrite      sync/async flag of write operation
 * 
 * NOTE: if syncWrite is true, flash driver will flush the incoming data to flash; if syncWrite
 * is false, the data you write probably will not present in flash immediately, if you read the
 * flash now, you may get unexpected result. So if you want read flash right after write opeation,
 * you should either write flash in sync way(syncWrite is ture) or flush the pending flash operation
 * (call app_flash_flush_pending_op) after write.
 */
void app_flash_program(enum NORFLASH_API_MODULE_ID_T module,
                       uint32_t flashOffset,
                       uint8_t *ptr,
                       uint32_t len,
                       bool synWrite);

/**
 * @brief Read flash according to incoming flash module and offset
 *
 * @param module        flash module, @see enum NORFLASH_API_MODULE_ID_T to get more info
 * @param flashOffset   offset according to the flash module base address
 * @param ptr           pointer of data to read
 * @param len           length of data to read
 */
void app_flash_read(enum NORFLASH_API_MODULE_ID_T module,
                    uint32_t flashOffset,
                    uint8_t *ptr,
                    uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef __APP_FLASH_API_H__ */