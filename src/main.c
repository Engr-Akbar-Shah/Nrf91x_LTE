
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include "lte.h"

LOG_MODULE_REGISTER(Main);

int main(void)
{
	int err;

	err = modem_configure();
	if (err) {
		LOG_ERR("Failed to configure the modem");
		return 0;
	}

	// k_sem_take(&lte_connected, K_FOREVER);

	LOG_INF("Connected to LTE network");
	
	return 0;
}
