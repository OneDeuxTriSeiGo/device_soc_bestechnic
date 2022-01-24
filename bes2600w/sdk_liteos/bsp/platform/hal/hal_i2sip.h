/*
 * Copyright (c) 2021 Bestechnic (Shanghai) Co., Ltd. All rights reserved.
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
#ifndef __HAL_I2SIP_H__
#define __HAL_I2SIP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "plat_types.h"
#include "reg_i2sip.h"
#include "hal_i2s.h"

#define i2sip_read32(b,a) \
     (*(volatile uint32_t *)(b+a))

#define i2sip_write32(v,b,a) \
     ((*(volatile uint32_t *)(b+a)) = v)

static inline void i2sip_w_enable_i2sip(uint32_t reg_base, uint32_t v)
{
    uint32_t val = 0;

    val = i2sip_read32(reg_base, I2SIP_ENABLE_REG_REG_OFFSET);
    if (v)
        val |= I2SIP_ENABLE_REG_I2S_ENABLE_MASK;
    else
        val &= ~I2SIP_ENABLE_REG_I2S_ENABLE_MASK;

    i2sip_write32(val, reg_base, I2SIP_ENABLE_REG_REG_OFFSET);
}
#ifndef CHIP_BEST1000
static inline void i2sip_w_enable_slave_mode(uint32_t reg_base, uint32_t v)
{
    uint32_t val = 0;

    val = i2sip_read32(reg_base, I2SIP_ENABLE_REG_REG_OFFSET);
    if (v)
        val |= I2SIP_ENABLE_REG_SLAVE_MODE_MASK;
    else
        val &= ~I2SIP_ENABLE_REG_SLAVE_MODE_MASK;

    i2sip_write32(val, reg_base, I2SIP_ENABLE_REG_REG_OFFSET);
}
#endif
static inline void i2sip_w_enable_clk_gen(uint32_t reg_base, uint32_t v)
{
    if (v)
        i2sip_write32(1, reg_base, I2SIP_CLK_GEN_ENABLE_REG_REG_OFFSET);
    else
        i2sip_write32(0, reg_base, I2SIP_CLK_GEN_ENABLE_REG_REG_OFFSET);
}
static inline uint32_t i2sip_r_clk_gen_enabled(uint32_t reg_base)
{
    uint32_t v;

    v = i2sip_read32(reg_base, I2SIP_CLK_GEN_ENABLE_REG_REG_OFFSET);
    return !!(v & I2SIP_CLK_GEN_ENABLE_REG_ENABLE_MASK);
}
static inline void i2sip_w_enable_rx_block(uint32_t reg_base, uint32_t v)
{
    if (v)
        i2sip_write32(1, reg_base, I2SIP_RX_BLOCK_ENABLE_REG_REG_OFFSET);
    else
        i2sip_write32(0, reg_base, I2SIP_RX_BLOCK_ENABLE_REG_REG_OFFSET);
}
static inline void i2sip_w_enable_rx_channel(uint32_t reg_base, uint32_t chan, uint32_t v)
{
    if (v)
        i2sip_write32(1, reg_base, I2SIP_RX_ENABLE_REG_OFFSET(chan));
    else
        i2sip_write32(0, reg_base, I2SIP_RX_ENABLE_REG_OFFSET(chan));
}
static inline void i2sip_w_enable_tx_block(uint32_t reg_base, uint32_t v)
{
    if (v)
        i2sip_write32(1, reg_base, I2SIP_TX_BLOCK_ENABLE_REG_REG_OFFSET);
    else
        i2sip_write32(0, reg_base, I2SIP_TX_BLOCK_ENABLE_REG_REG_OFFSET);
}
static inline void i2sip_w_enable_tx_channel(uint32_t reg_base, uint32_t chan, uint32_t v)
{
    if (v)
        i2sip_write32(1, reg_base, I2SIP_TX_ENABLE_REG_OFFSET(chan));
    else
        i2sip_write32(0, reg_base, I2SIP_TX_ENABLE_REG_OFFSET(chan));
}
static inline void i2sip_w_tx_resolution(uint32_t reg_base, uint32_t chan, uint32_t v)
{
    i2sip_write32(v<<I2SIP_TX_CFG_WLEN_SHIFT, reg_base, I2SIP_TX_CFG_REG_OFFSET(chan));
}
static inline void i2sip_w_rx_resolution(uint32_t reg_base, uint32_t chan, uint32_t v)
{
    i2sip_write32(v<<I2SIP_RX_CFG_WLEN_SHIFT, reg_base, I2SIP_RX_CFG_REG_OFFSET(chan));
}
static inline void i2sip_w_clk_cfg_reg(uint32_t reg_base, uint32_t v)
{
    i2sip_write32(v, reg_base, I2SIP_CLK_CFG_REG_OFFSET);
}
static inline void i2sip_w_tx_left_fifo(uint32_t reg_base, uint32_t chan, uint32_t v)
{
    i2sip_write32(v, reg_base, I2SIP_LEFT_TX_BUFF_REG_OFFSET(chan));
}
static inline void i2sip_w_tx_right_fifo(uint32_t reg_base, uint32_t chan, uint32_t v)
{
    i2sip_write32(v, reg_base, I2SIP_RIGHT_TX_BUFF_REG_OFFSET(chan));
}
static inline void i2sip_w_tx_fifo_threshold(uint32_t reg_base, uint32_t chan, uint32_t v)
{
    i2sip_write32(v<<I2SIP_TX_FIFO_CFG_LEVEL_SHIFT, reg_base, I2SIP_TX_FIFO_CFG_REG_OFFSET(chan));
}
static inline void i2sip_w_rx_fifo_threshold(uint32_t reg_base, uint32_t chan, uint32_t v)
{
    i2sip_write32(v<<I2SIP_RX_FIFO_CFG_LEVEL_SHIFT, reg_base, I2SIP_RX_FIFO_CFG_REG_OFFSET(chan));
}
static inline void i2sip_w_tx_fifo_reset(uint32_t reg_base, uint32_t chan)
{
    i2sip_write32(I2SIP_TX_FIFO_FLUSH_MASK, reg_base, I2SIP_TX_FIFO_FLUSH_REG_OFFSET(chan));
}
static inline void i2sip_w_rx_fifo_reset(uint32_t reg_base, uint32_t chan)
{
    i2sip_write32(I2SIP_RX_FIFO_FLUSH_MASK, reg_base, I2SIP_RX_FIFO_FLUSH_REG_OFFSET(chan));
}
static inline uint32_t i2sip_r_int_status(uint32_t reg_base, uint32_t chan)
{
    return i2sip_read32(reg_base, I2SIP_INT_STATUS_REG_OFFSET(chan));
}
static inline void i2sip_w_enable_tx_dma(uint32_t reg_base, uint32_t v)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_DMA_CTRL_REG_OFFSET);
    if (v)
        val |= I2SIP_DMA_CTRL_TX_ENABLE_MASK;
    else
        val &= ~I2SIP_DMA_CTRL_TX_ENABLE_MASK;

    i2sip_write32(val, reg_base, I2SIP_DMA_CTRL_REG_OFFSET);
}
static inline void i2sip_w_enable_rx_dma(uint32_t reg_base, uint32_t v)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_DMA_CTRL_REG_OFFSET);
    if (v)
        val |= I2SIP_DMA_CTRL_RX_ENABLE_MASK;
    else
        val &= ~I2SIP_DMA_CTRL_RX_ENABLE_MASK;

    i2sip_write32(val, reg_base, I2SIP_DMA_CTRL_REG_OFFSET);
}
#ifndef CHIP_BEST1000
static inline void i2sp_w_enable_rx_dma_block(uint32_t reg_base, uint32_t v)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_DMA_CTRL_REG_OFFSET);
    if (v)
        val |= I2SIP_DMA_CTRL_RX_DMA_BLK_EN_MASK;
    else
        val &= ~I2SIP_DMA_CTRL_RX_DMA_BLK_EN_MASK;

    i2sip_write32(val, reg_base, I2SIP_DMA_CTRL_REG_OFFSET);
}
static inline void i2sip_w_rx_dma_blk_size(uint32_t reg_base, uint32_t v)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_DMA_CTRL_REG_OFFSET);
    val = SET_BITFIELD(val, I2SIP_DMA_CTRL_RX_DMA_BLK_SIZE, v);
    i2sip_write32(val, reg_base, I2SIP_DMA_CTRL_REG_OFFSET);
}
#endif

static inline void i2sip_w_tx_sync_enable(uint32_t reg_base, enum HAL_I2S_SYNC_TYPE_T type)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_EN_SEL_OFFSET);
    val = SET_BITFIELD(val, I2SIP_TX_EN_SEL, type);
    i2sip_write32(val, reg_base, I2SIP_EN_SEL_OFFSET);
}

static inline void i2sip_w_tx_sync_disable(uint32_t reg_base)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_EN_SEL_OFFSET);
    val = SET_BITFIELD(val, I2SIP_TX_EN_SEL, HAL_I2S_SYNC_TYPE_NONE);
    i2sip_write32(val, reg_base, I2SIP_EN_SEL_OFFSET);
}

static inline void i2sip_w_rx_sync_enable(uint32_t reg_base, enum HAL_I2S_SYNC_TYPE_T type)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_EN_SEL_OFFSET);
    val = SET_BITFIELD(val, I2SIP_RX_EN_SEL, type);
    i2sip_write32(val, reg_base, I2SIP_EN_SEL_OFFSET);
}

static inline void i2sip_w_rx_sync_disable(uint32_t reg_base)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_EN_SEL_OFFSET);
    val = SET_BITFIELD(val, I2SIP_RX_EN_SEL, HAL_I2S_SYNC_TYPE_NONE);
    i2sip_write32(val, reg_base, I2SIP_EN_SEL_OFFSET);
}

static inline void i2sip_w_clk_sync_enable(uint32_t reg_base, enum HAL_I2S_SYNC_TYPE_T type)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_EN_SEL_OFFSET);
    val = SET_BITFIELD(val, I2SIP_CLK_EN_SEL, type);
#ifndef WIFI_LMAC_TIRIIGER
    val |= I2SIP_TSF_EVENT_SEL;
#endif
    i2sip_write32(val, reg_base, I2SIP_EN_SEL_OFFSET);
}

static inline void i2sip_w_clk_sync_disable(uint32_t reg_base)
{
    uint32_t val = 0;
    val = i2sip_read32(reg_base, I2SIP_EN_SEL_OFFSET);
    val = SET_BITFIELD(val, I2SIP_CLK_EN_SEL, HAL_I2S_SYNC_TYPE_NONE);
    i2sip_write32(val, reg_base, I2SIP_EN_SEL_OFFSET);
}

#ifdef __cplusplus
}
#endif

#endif /* __HAL_I2SIP_H__ */
