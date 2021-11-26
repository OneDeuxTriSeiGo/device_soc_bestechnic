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
#ifndef __REG_SPDIFIP_H_
#define __REG_SPDIFIP_H_

#include "plat_types.h"

#define SPDIFIP_FIFO_DEPTH 8

/* spdif register */
/* enable register */
#define SPDIFIP_ENABLE_REG_REG_OFFSET 0x0
#define SPDIFIP_ENABLE_REG_SPDIF_ENABLE_SHIFT (0)
#define SPDIFIP_ENABLE_REG_SPDIF_ENABLE_MASK ((0x1)<<SPDIFIP_ENABLE_REG_SPDIF_ENABLE_SHIFT)

/* recv block enable register */
#define SPDIFIP_RX_BLOCK_ENABLE_REG_REG_OFFSET 0x4
#define SPDIFIP_RX_BLOCK_ENABLE_REG_ENABLE_SHIFT (0)
#define SPDIFIP_RX_BLOCK_ENABLE_REG_ENABLE_MASK ((0x1)<<SPDIFIP_RX_BLOCK_ENABLE_REG_ENABLE_SHIFT)

/* send block enable register */
#define SPDIFIP_TX_BLOCK_ENABLE_REG_REG_OFFSET 0x8
#define SPDIFIP_TX_BLOCK_ENABLE_REG_ENABLE_SHIFT (0)
#define SPDIFIP_TX_BLOCK_ENABLE_REG_ENABLE_MASK ((0x1)<<SPDIFIP_TX_BLOCK_ENABLE_REG_ENABLE_SHIFT)

/* clk gen enable register */
#define SPDIFIP_CLK_GEN_ENABLE_REG_REG_OFFSET 0xc
#define SPDIFIP_CLK_GEN_ENABLE_REG_ENABLE_SHIFT (0)
#define SPDIFIP_CLK_GEN_ENABLE_REG_ENABLE_MASK ((0x1)<<SPDIFIP_CLK_GEN_ENABLE_REG_ENABLE_SHIFT)

/* clk config register */
#define SPDIFIP_CLK_CFG_REG_OFFSET 0x10
#define SPDIFIP_CLK_CFG_WSS_SHIFT (3)
#define SPDIFIP_CLK_CFG_WSS_MASK ((0x3)<<SPDIFIP_CLK_CFG_WSS_SHIFT)
#define SPDIFIP_CLK_CFG_WSS_VAL_16CYCLE 0
#define SPDIFIP_CLK_CFG_WSS_VAL_24CYCLE 1
#define SPDIFIP_CLK_CFG_WSS_VAL_32CYCLE 2

#define SPDIFIP_CLK_CFG_SCLK_GATE_SHIFT (0)
#define SPDIFIP_CLK_CFG_SCLK_GATE_MASK ((0x7)<<SPDIFIP_CLK_CFG_SCLK_GATE_SHIFT)
#define SPDIFIP_CLK_CFG_SCLK_GATE_VAL_NO_GATE 0
#define SPDIFIP_CLK_CFG_SCLK_GATE_VAL_12_GATE 1
#define SPDIFIP_CLK_CFG_SCLK_GATE_VAL_16_GATE 2
#define SPDIFIP_CLK_CFG_SCLK_GATE_VAL_20_GATE 3
#define SPDIFIP_CLK_CFG_SCLK_GATE_VAL_24_GATE 4

/* recv block fifo reset register */
#define SPDIFIP_RX_BLOCK_FIFO_RESET_REG_OFFSET 0x14
#define SPDIFIP_RX_BLOCK_FIFO_RESET_RESET_SHIFT (0)
#define SPDIFIP_RX_BLOCK_FIFO_RESET_RESET_MASK ((0x1)<<SPDIFIP_RX_BLOCK_FIFO_RESET_RESET_SHIFT)

/* send block fifo reset register */
#define SPDIFIP_TX_BLOCK_FIFO_RESET_REG_OFFSET 0x18
#define SPDIFIP_TX_BLOCK_FIFO_RESET_RESET_SHIFT (0)
#define SPDIFIP_TX_BLOCK_FIFO_RESET_RESET_MASK ((0x1)<<SPDIFIP_TX_BLOCK_FIFO_RESET_RESET_SHIFT)

/* left recv buffer register */
#define SPDIFIP_LEFT_RX_BUFF_REG_OFFSET 0x20

/* left send buffer register */
#define SPDIFIP_LEFT_TX_BUFF_REG_OFFSET 0x20

/* right recv buffer register */
#define SPDIFIP_RIGHT_RX_BUFF_REG_OFFSET 0x24

/* right send buffer register */
#define SPDIFIP_RIGHT_TX_BUFF_REG_OFFSET 0x24

/* channel 0 */
/* recv enable register */
#define SPDIFIP_RX_ENABLE_REG_OFFSET 0x28
#define SPDIFIP_RX_ENABLE_ENABLE_SHIFT (0)
#define SPDIFIP_RX_ENABLE_ENABLE_MASK ((0x1)<<SPDIFIP_RX_ENABLE_ENABLE_SHIFT)

/* send enable register */
#define SPDIFIP_TX_ENABLE_REG_OFFSET 0x2c
#define SPDIFIP_TX_ENABLE_ENABLE_SHIFT (0)
#define SPDIFIP_TX_ENABLE_ENABLE_MASK ((0x1)<<SPDIFIP_TX_ENABLE_ENABLE_SHIFT)

#if 0
/* recv config register */
#define SPDIFIP_RX_CFG_REG_OFFSET 0x30
#define SPDIFIP_RX_CFG_WLEN_SHIFT (0)
#define SPDIFIP_RX_CFG_WLEN_MASK ((0x7)<<SPDIFIP_RX_CFG_WLEN_SHIFT)
#define SPDIFIP_RX_CFG_WLEN_VAL_IGNORE 0
#define SPDIFIP_RX_CFG_WLEN_VAL_12BIT 1
#define SPDIFIP_RX_CFG_WLEN_VAL_16BIT 2
#define SPDIFIP_RX_CFG_WLEN_VAL_20BIT 3
#define SPDIFIP_RX_CFG_WLEN_VAL_24BIT 4
#define SPDIFIP_RX_CFG_WLEN_VAL_32BIT 5

/* send config register */
#define SPDIFIP_TX_CFG_REG_OFFSET 0x34
#define SPDIFIP_TX_CFG_WLEN_SHIFT (0)
#define SPDIFIP_TX_CFG_WLEN_MASK ((0x7)<<SPDIFIP_TX_CFG_WLEN_SHIFT)
#define SPDIFIP_TX_CFG_WLEN_VAL_IGNORE 0
#define SPDIFIP_TX_CFG_WLEN_VAL_12BIT 1
#define SPDIFIP_TX_CFG_WLEN_VAL_16BIT 2
#define SPDIFIP_TX_CFG_WLEN_VAL_20BIT 3
#define SPDIFIP_TX_CFG_WLEN_VAL_24BIT 4
#define SPDIFIP_TX_CFG_WLEN_VAL_32BIT 5
#endif

/* int status register */
#define SPDIFIP_INT_STATUS_REG_OFFSET 0x38
#define SPDIFIP_INT_STATUS_TX_FIFO_OVER_SHIFT (5)
#define SPDIFIP_INT_STATUS_TX_FIFO_OVER_MASK ((0x1)<<SPDIFIP_INT_STATUS_TX_FIFO_OVER_SHIFT)
#define SPDIFIP_INT_STATUS_TX_FIFO_EMPTY_SHIFT (4)
#define SPDIFIP_INT_STATUS_TX_FIFO_EMPTY_MASK ((0x1)<<SPDIFIP_INT_STATUS_TX_FIFO_EMPTY_SHIFT)
#define SPDIFIP_INT_STATUS_RX_FIFO_OVER_SHIFT (1)
#define SPDIFIP_INT_STATUS_RX_FIFO_OVER_MASK ((0x1)<<SPDIFIP_INT_STATUS_RX_FIFO_OVER_SHIFT)
#define SPDIFIP_INT_STATUS_RX_FIFO_DA_SHIFT (0)
#define SPDIFIP_INT_STATUS_RX_FIFO_DA_MASK ((0x1)<<SPDIFIP_INT_STATUS_RX_FIFO_DA_SHIFT)

/* int mask register */
#define SPDIFIP_INT_MASK_REG_OFFSET 0x3c
#define SPDIFIP_INT_MASK_TX_FIFO_OVER_SHIFT (5)
#define SPDIFIP_INT_MASK_TX_FIFO_OVER_MASK ((0x1)<<SPDIFIP_INT_MASK_TX_FIFO_OVER_SHIFT)
#define SPDIFIP_INT_MASK_TX_FIFO_EMPTY_SHIFT (4)
#define SPDIFIP_INT_MASK_TX_FIFO_EMPTY_MASK ((0x1)<<SPDIFIP_INT_MASK_TX_FIFO_EMPTY_SHIFT)
#define SPDIFIP_INT_MASK_RX_FIFO_OVER_SHIFT (1)
#define SPDIFIP_INT_MASK_RX_FIFO_OVER_MASK ((0x1)<<SPDIFIP_INT_MASK_RX_FIFO_OVER_SHIFT)
#define SPDIFIP_INT_MASK_RX_FIFO_DA_SHIFT (0)
#define SPDIFIP_INT_MASK_RX_FIFO_DA_MASK ((0x1)<<SPDIFIP_INT_MASK_RX_FIFO_DA_SHIFT)
#define SPDIFIP_INT_MASK_ALL \
    (SPDIFIP_INT_MASK_TX_FIFO_OVER_MASK|SPDIFIP_INT_MASK_TX_FIFO_EMPTY_MASK|SPDIFIP_INT_MASK_RX_FIFO_OVER_MASK|SPDIFIP_INT_MASK_RX_FIFO_DA_MASK)
#define SPDIFIP_INT_UNMASK_ALL 0

/* clr recv over flow register */
#define SPDIFIP_CLR_RX_OVER_FLOW_REG_OFFSET 0x40
#define SPDIFIP_CLR_RX_OVER_FLOW_CLR_SHIFT (0)
#define SPDIFIP_CLR_RX_OVER_FLOW_CLR_MASK ((0x1)<<SPDIFIP_CLR_RX_OVER_FLOW_CLR_SHIFT)

/* clr send over flow register */
#define SPDIFIP_CLR_TX_OVER_FLOW_REG_OFFSET 0x44
#define SPDIFIP_CLR_TX_OVER_FLOW_CLR_SHIFT (0)
#define SPDIFIP_CLR_TX_OVER_FLOW_CLR_MASK ((0x1)<<SPDIFIP_CLR_TX_OVER_FLOW_CLR_SHIFT)

/* recv fifo config register */
#define SPDIFIP_RX_FIFO_CFG_REG_OFFSET 0x48
#define SPDIFIP_RX_FIFO_CFG_LEVEL_SHIFT (0)
#define SPDIFIP_RX_FIFO_CFG_LEVEL_MASK ((0xf)<<SPDIFIP_RX_FIFO_CFG_LEVEL_SHIFT)

/* send fifo config register */
#define SPDIFIP_TX_FIFO_CFG_REG_OFFSET 0x4c
#define SPDIFIP_TX_FIFO_CFG_LEVEL_SHIFT (0)
#define SPDIFIP_TX_FIFO_CFG_LEVEL_MASK ((0xf)<<SPDIFIP_TX_FIFO_CFG_LEVEL_SHIFT)

/* recv fifo flush register */
#define SPDIFIP_RX_FIFO_FLUSH_REG_OFFSET 0x50
#define SPDIFIP_RX_FIFO_FLUSH_SHIFT (0)
#define SPDIFIP_RX_FIFO_FLUSH_MASK ((0x1)<<SPDIFIP_RX_FIFO_FLUSH_SHIFT)

/* send fifo flush register */
#define SPDIFIP_TX_FIFO_FLUSH_REG_OFFSET 0x54
#define SPDIFIP_TX_FIFO_FLUSH_SHIFT (0)
#define SPDIFIP_TX_FIFO_FLUSH_MASK ((0x1)<<SPDIFIP_TX_FIFO_FLUSH_SHIFT)

/* dma ctrl register */
#define SPDIFIP_DMA_CTRL_REG_OFFSET 0x58
#define SPDIFIP_DMA_CTRL_TX_ENABLE_SHIFT (1)
#define SPDIFIP_DMA_CTRL_TX_ENABLE_MASK ((0x1)<<SPDIFIP_DMA_CTRL_TX_ENABLE_SHIFT)
#define SPDIFIP_DMA_CTRL_RX_ENABLE_SHIFT (0)
#define SPDIFIP_DMA_CTRL_RX_ENABLE_MASK ((0x1)<<SPDIFIP_DMA_CTRL_RX_ENABLE_SHIFT)
/* channel 0 end */

/* recv config register */
#define SPDIFIP_RX_CFG_REG_OFFSET 0x60
#define SPDIFIP_RX_CFG_BLKEN_SHIFT (24)
#define SPDIFIP_RX_CFG_BLKEN_MASK ((0x1)<<SPDIFIP_RX_CFG_BLKEN_SHIFT)
#define SPDIFIP_RX_CFG_FORMAT_SHIFT (20)
#define SPDIFIP_RX_CFG_FORMAT_MASK ((0xf)<<SPDIFIP_RX_CFG_FORMAT_SHIFT)
#define SPDIFIP_RX_CFG_PARLEN_SHIFT (19)
#define SPDIFIP_RX_CFG_PARLEN_MASK ((0x1)<<SPDIFIP_RX_CFG_PARLEN_SHIFT)
#define SPDIFIP_RX_CFG_STATLEN_SHIFT (18)
#define SPDIFIP_RX_CFG_STATLEN_MASK ((0x1)<<SPDIFIP_RX_CFG_STATLEN_SHIFT)
#define SPDIFIP_RX_CFG_USELEN_SHIFT (17)
#define SPDIFIP_RX_CFG_USELEN_MASK ((0x1)<<SPDIFIP_RX_CFG_USELEN_SHIFT)
#define SPDIFIP_RX_CFG_VAlLEN_SHIFT (16)
#define SPDIFIP_RX_CFG_VALLEN_MASK ((0x1)<<SPDIFIP_RX_CFG_VALLEN_SHIFT)
#define SPDIFIP_RX_CFG_VALIDCHK_SHIFT (3)
#define SPDIFIP_RX_CFG_VALIDCHK_MASK ((0x1)<<SPDIFIP_RX_CFG_VALIDCHK_SHIFT)
#define SPDIFIP_RX_CFG_SAMPLEEN_SHIFT (1)
#define SPDIFIP_RX_CFG_SAMPLEEN_MASK ((0x1)<<SPDIFIP_RX_CFG_SAMPLEEN_SHIFT)
#define SPDIFIP_RX_CFG_RXEN_SHIFT (0)
#define SPDIFIP_RX_CFG_RXEN_MASK ((0x1)<<SPDIFIP_RX_CFG_RXEN_SHIFT)

/* recv state register */
#define SPDIFIP_RX_STAT_REG_OFFSET 0x64
#define SPDIFIP_RX_STAT_CHLOCK_SHIFT (31)
#define SPDIFIP_RX_STAT_CHLOCK_MASK ((0x1)<<SPDIFIP_RX_STAT_CHLOCK_SHIFT)
#define SPDIFIP_RX_STAT_CHBEMPH_SHIFT (12)
#define SPDIFIP_RX_STAT_CHBEMPH_MASK ((0x7)<<SPDIFIP_RX_STAT_CHBEMPH_SHIFT)
#define SPDIFIP_RX_STAT_CHBCOPY_SHIFT (10)
#define SPDIFIP_RX_STAT_CHBCOPY_MASK ((0x1)<<SPDIFIP_RX_STAT_CHBCOPY_SHIFT)
#define SPDIFIP_RX_STAT_CHBAUDIO_SHIFT (9)
#define SPDIFIP_RX_STAT_CHBAUDIO_MASK ((0x1)<<SPDIFIP_RX_STAT_CHBAUDIO_SHIFT)
#define SPDIFIP_RX_STAT_CHBPRO_SHIFT (8)
#define SPDIFIP_RX_STAT_CHBPRO_MASK ((0x1)<<SPDIFIP_RX_STAT_CHBPRO_SHIFT)
#define SPDIFIP_RX_STAT_CHAEMPH_SHIFT (4)
#define SPDIFIP_RX_STAT_CHAEMPH_MASK ((0x1)<<SPDIFIP_RX_STAT_CHAEMPH_SHIFT)
#define SPDIFIP_RX_STAT_CHACOPY_SHIFT (2)
#define SPDIFIP_RX_STAT_CHACOPY_MASK ((0x1)<<SPDIFIP_RX_STAT_CHACOPY_SHIFT)
#define SPDIFIP_RX_STAT_CHAAUDIO_SHIFT (1)
#define SPDIFIP_RX_STAT_CHAAUDIO_MASK ((0x1)<<SPDIFIP_RX_STAT_CHAAUDIO_SHIFT)
#define SPDIFIP_RX_STAT_CHAPRO_SHIFT (0)
#define SPDIFIP_RX_STAT_CHAPRO_MASK ((0x1)<<SPDIFIP_RX_STAT_CHAPRO_SHIFT)

/* recv user bit state register */
#define SPDIFIP_RXUSRCHSTCFG_REG_OFFSET 0x68
#define SPDIFIP_RXUSRCHSTCFG_FRAMEINDEX_SHIFT (16)
#define SPDIFIP_RXUSRCHSTCFG_FRAMEINDEX_MASK ((0xff)<<SPDIFIP_RXUSRCHSTCFG_FRAMEINDEX_SHIFT)
#define SPDIFIP_RXUSRCHSTCFG_USRCHNSTSEL_SHIFT (9)
#define SPDIFIP_RXUSRCHSTCFG_USRCHNSTSEL_MASK ((0xff)<<SPDIFIP_RXUSRCHSTCFG_USRCHNSTSEL_SHIFT)
#define SPDIFIP_RXUSRCHSTCFG_CHNSEL_SHIFT (8)
#define SPDIFIP_RXUSRCHSTCFG_CHNSEL_MASK ((0xff)<<SPDIFIP_RXUSRCHSTCFG_CHNSEL_SHIFT)
#define SPDIFIP_RXUSRCHSTCFG_CAPBITLEN_SHIFT (0)
#define SPDIFIP_RXUSRCHSTCFG_CAPBITLEN_MASK ((0xff)<<SPDIFIP_RXUSRCHSTCFG_CAPBITLEN_SHIFT)

/* recv user bit data register */
#define SPDIFIP_RXUSRCHSTDATA_REG_OFFSET 0x6C
#define SPDIFIP_RXUSRCHSTDATA_CAPDATA_SHIFT (0)
#define SPDIFIP_RXUSRCHSTDATA_CAPDATA_MASK ((0xffffffff)<<SPDIFIP_RXUSRCHSTDATA_CAPDATA_SHIFT)

/* send config register */
#define SPDIFIP_TX_CFG_REG_OFFSET 0x78
#define SPDIFIP_TX_CFG_FORMAT_SHIFT (20)
#define SPDIFIP_TX_CFG_FORMAT_MASK ((0xf)<<SPDIFIP_TX_CFG_FORMAT_SHIFT)
#define SPDIFIP_TX_CFG_RATIO_SHIFT (8)
#define SPDIFIP_TX_CFG_RATIO_MASK ((0xff)<<SPDIFIP_TX_CFG_RATIO_SHIFT)
#define SPDIFIP_TX_CFG_USRDATAEN_SHIFT (6)
#define SPDIFIP_TX_CFG_USRDATAEN_MASK ((0x3)<<SPDIFIP_TX_CFG_USRDATAEN_SHIFT)
#define SPDIFIP_TX_CFG_CHSTEN_SHIFT (4)
#define SPDIFIP_TX_CFG_CHSTEN_MASK ((0x3)<<SPDIFIP_TX_CFG_CHSTEN_SHIFT)
#define SPDIFIP_TX_CFG_TXVALID_SHIFT (1)
#define SPDIFIP_TX_CFG_TXVALID_MASK ((0x1)<<SPDIFIP_TX_CFG_TXVALID_SHIFT)
#define SPDIFIP_TX_CFG_TXEN_SHIFT (0)
#define SPDIFIP_TX_CFG_TXEN_MASK ((0x1)<<SPDIFIP_TX_CFG_TXEN_SHIFT)

/* send user bit state register */
#define SPDIFIP_TXUSRCHSTCFG_REG_OFFSET 0x80
#define SPDIFIP_TXUSRCHSTCFG_CHBCHST_SHIFT (24)
#define SPDIFIP_TXUSRCHSTCFG_CHBCHST_MASK ((0xff)<<SPDIFIP_TXUSRCHSTCFG_CHBCHST_SHIFT)
#define SPDIFIP_TXUSRCHSTCFG_CHACHST_SHIFT (16)
#define SPDIFIP_TXUSRCHSTCFG_CHACHST_MASK ((0xff)<<SPDIFIP_TXUSRCHSTCFG_CHACHST_SHIFT)
#define SPDIFIP_TXUSRCHSTCFG_CHBUSRBIT_SHIFT (8)
#define SPDIFIP_TXUSRCHSTCFG_CHBUSRBIT_MASK ((0xff)<<SPDIFIP_TXUSRCHSTCFG_CHBUSRBIT_SHIFT)
#define SPDIFIP_TXUSRCHSTCFG_CHAUSRBIT_SHIFT (0)
#define SPDIFIP_TXUSRCHSTCFG_CHAUSRBIT_MASK ((0xff)<<SPDIFIP_TXUSRCHSTCFG_CHAUSRBIT_SHIFT)

/* rx int status register */
#define SPDIFIP_RXINTSTAT_REG_OFFSET 0xE0
#define SPDIFIP_RXINTSTAT_PARCHBERR_SHIFT (3)
#define SPDIFIP_RXINTSTAT_PARCHBERR_MASK ((0x1)<<SPDIFIP_RXINTSTAT_PARCHBERR_SHIFT)
#define SPDIFIP_RXINTSTAT_PARCHAERR_SHIFT (2)
#define SPDIFIP_RXINTSTAT_PARCHAERR_MASK ((0x1)<<SPDIFIP_RXINTSTAT_PARCHAERR_SHIFT)
#define SPDIFIP_RXINTSTAT_CAPNEW_SHIFT (1)
#define SPDIFIP_RXINTSTAT_CAPNEW_MASK ((0x1)<<SPDIFIP_RXINTSTAT_CAPNEW_SHIFT)
#define SPDIFIP_RXINTSTAT_LOCKED_SHIFT (0)
#define SPDIFIP_RXINTSTAT_LOCKED_MASK ((0x1)<<SPDIFIP_RXINTSTAT_LOCKED_SHIFT)

/* rx int mask register */
#define SPDIFIP_RXINTMASK_REG_OFFSET 0xE4
#define SPDIFIP_RXINTMASK_PARCHBERR_SHIFT (3)
#define SPDIFIP_RXINTMASK_PARCHBERR_MASK ((0x1)<<SPDIFIP_RXINTMASK_PARCHBERR_SHIFT)
#define SPDIFIP_RXINTMASK_PARCHAERR_SHIFT (2)
#define SPDIFIP_RXINTMASK_PARCHAERR_MASK ((0x1)<<SPDIFIP_RXINTMASK_PARCHAERR_SHIFT)
#define SPDIFIP_RXINTMASK_CAPNEW_SHIFT (1)
#define SPDIFIP_RXINTMASK_CAPNEW_MASK ((0x1)<<SPDIFIP_RXINTMASK_CAPNEW_SHIFT)
#define SPDIFIP_RXINTMASK_LOCKED_SHIFT (0)
#define SPDIFIP_RXINTMASK_LOCKED_MASK ((0x1)<<SPDIFIP_RXINTMASK_LOCKED_SHIFT)

/* spdif register end */

#endif /* __REG_SPDIFIP_H_ */
