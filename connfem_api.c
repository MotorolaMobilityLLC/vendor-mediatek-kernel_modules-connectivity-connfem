// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#include "connfem_internal.h"

/*******************************************************************************
 *								M A C R O S
 ******************************************************************************/


/*******************************************************************************
 *							D A T A   T Y P E S
 ******************************************************************************/


/*******************************************************************************
 *				  F U N C T I O N   D E C L A R A T I O N S
 ******************************************************************************/


/*******************************************************************************
 *						   P U B L I C   D A T A
 ******************************************************************************/

/*******************************************************************************
 *						  P R I V A T E   D A T A
 ******************************************************************************/

/*******************************************************************************
 *							 F U N C T I O N S
 ******************************************************************************/

bool connfem_is_available(enum connfem_type fem_type)
{
	bool ret = false;

	switch (fem_type) {
	case CONNFEM_TYPE_EPAELNA:
		ret = connfem_is_epaelna_available();
		break;
	default:
		pr_info("%s, unknown fem_type: %d", __func__, fem_type);
		break;
	}

	return ret;
}
EXPORT_SYMBOL(connfem_is_available);

int connfem_epaelna_get_fem_info(struct connfem_epaelna_fem_info *fem_info)
{
	int ret = 0;

	if (!fem_info) {
		ret = -EFAULT;
		pr_info("%s para is NULL", __func__);
	} else {
		ret = _connfem_epaelna_get_fem_info(fem_info);
	}

	return ret;
}
EXPORT_SYMBOL(connfem_epaelna_get_fem_info);

int connfem_epaelna_get_pin_info(struct connfem_epaelna_pin_info *pin_info)
{
	int ret = 0;

	return ret;
}
EXPORT_SYMBOL(connfem_epaelna_get_pin_info);

int connfem_epaelna_get_flags(enum connfem_subsys subsys, void *flags)
{
	int ret = 0;

	return ret;
}
EXPORT_SYMBOL(connfem_epaelna_get_flags);

int connfem_get_info(enum connfem_type fem_type, enum connfem_subsys subsys,
					 void *data)
{
	int ret = 0;

	switch (fem_type) {
	case CONNFEM_TYPE_EPAELNA:
		switch (subsys) {
		case CONNFEM_SUBSYS_WIFI:
			break;
		case CONNFEM_SUBSYS_BT:
			break;
		default:
			pr_info("%s, unknown subsys: %d",
					 __func__, subsys);
			break;
		}
		break;
	default:
		pr_info("%s, unknown fem_type: %d", __func__, fem_type);
		break;
	}

	return ret;
}
EXPORT_SYMBOL(connfem_get_info);
