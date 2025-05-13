
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "lte.h"

LOG_MODULE_REGISTER(Main);

int main(void)
{
	int err;

	err = modem_init();
	if (err)
	{
		LOG_ERR("Failed to configure the modem");
		return 0;
	}

	err = lte_init();
	if (err)
	{
		LOG_ERR("Failed to intialize LTE");
	}

	LOG_INF("Connected to LTE network");

	return 0;
}
