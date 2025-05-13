# DEV_HUB_Nrf91_LTE

## Overview

This project provides a modular implementation of LTE modem handling for the Nordic nRF91 Series using the nRF Connect SDK. It includes:

- LTE and modem initialization/deinitialization  
- Retrieval of modem information (IMEI, ICCID, Firmware Version)  
- Event-driven LTE network registration monitoring  
- Support for LTE features such as PSM, eDRX, RRC, and modem sleep events  

---

## Project Structure

```DEV_HUB_Nrf91_LTE/
├── src/
│ └── main.c # Application entry point
├── components/
│ └── lte/
│ ├── lte.c # LTE and modem logic
│ └── lte.h # API declarations
├── prj.conf # Project configuration for Zephyr
├── CMakeLists.txt # Build system definition
├── README.md # You're here!
```
---

## Requirements

- nRF Connect SDK: v2.8.0 or later  
- Board: Nordic nRF9160 DK or compatible  
- Toolchain: Zephyr toolchain (`west`, `cmake`, `ninja`)  

---

## Features

- LTE connection using `lte_lc_connect_async()`
- LTE event handling via `lte_handler()`
- Modem info retrieval:
  - IMEI using `get_modem_info_imei`
  - ICCID using `get_modem_info_iccid`
  - Firmware version using `get_modem_info_fw_version`
- Optional support for:
  - PSM (Power Saving Mode)
  - eDRX (Extended Discontinuous Reception)
  - RRC Idle/Connected modes
- Modular component design

---

## Integration Instructions

To use the LTE component in your own nRF Connect SDK project:

1. Copy the `lte` folder from the `components/` directory into your own project's `components/` directory.

2. Add the following to your project's `CMakeLists.txt` to include the LTE component:

```cmake
# Add the component LTE
target_sources(app PRIVATE
    components/lte/lte.c)

target_include_directories(app
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/components/lte)
```

3. Configure `prj.conf`

```conf
CONFIG_NRF_MODEM_LIB=y
CONFIG_MODEM_INFO=y
CONFIG_NRF_MODEM_LIB_ON_FAULT_RESET_MODEM=y
CONFIG_LTE_LINK_CONTROL=y
CONFIG_LTE_NETWORK_MODE_LTE_M=y
```