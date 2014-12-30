/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/

#ifndef __HAL_PHY_RF_8188E_H__
#define __HAL_PHY_RF_8188E_H__


/*--------------------------Define Parameters-------------------------------*/
#define	IQK_DELAY_TIME_88E		10		//ms
#define	index_mapping_NUM_88E	15
#define AVG_THERMAL_NUM_88E	4

typedef enum _PWRTRACK_CONTROL_METHOD {
	BBSWING,
	TXAGC
} PWRTRACK_METHOD;


void
ODM_TxPwrTrackAdjust88E(
	PDM_ODM_T	pDM_Odm,
	u1Byte		Type,				// 0 = OFDM, 1 = CCK
	pu1Byte		pDirection,			// 1 = +(increase) 2 = -(decrease)
	u32 *		pOutWriteVal		// Tx tracking CCK/OFDM BB swing index adjust
	);


void
odm_TXPowerTrackingCallback_ThermalMeter_8188E(
	IN struct adapter *	Adapter
	);


//1 7.	IQK

void	
PHY_IQCalibrate_8188E(	
	IN struct adapter *	Adapter,
	IN	BOOLEAN 	bReCovery);


//
// LC calibrate
//
void	
PHY_LCCalibrate_8188E(
	IN	struct adapter *	pAdapter
);

//
// AP calibrate
//
void	
PHY_APCalibrate_8188E(		
	IN	struct adapter *	pAdapter,
	IN 	s1Byte		delta);

void	
PHY_DigitalPredistortion_8188E(		IN	struct adapter *	pAdapter);


void
_PHY_SaveADDARegisters(
	IN	struct adapter *	pAdapter,
	IN	u32 *		ADDAReg,
	IN	u32 *		ADDABackup,
	IN	u32		RegisterNum
	);

void
_PHY_PathADDAOn(
	IN	struct adapter *	pAdapter,
	IN	u32 *		ADDAReg,
	IN	BOOLEAN		isPathAOn,
	IN	BOOLEAN		is2T
	);

void
_PHY_MACSettingCalibration(
	IN	struct adapter *	pAdapter,
	IN	u32 *		MACReg,
	IN	u32 *		MACBackup	
	);


void
_PHY_PathAStandBy(
	IN	struct adapter *	pAdapter
	);

								
#endif	// #ifndef __HAL_PHY_RF_8188E_H__

