# Hardware Notes

This project is set up for a generic ESP32 development board connected to an SW-420 vibration sensor and a 128x64 SH1106 OLED display.

## Confirmed Firmware Details

The current firmware confirms these details:

- Vibration input pin: `GPIO4`
- Display library: `U8g2`
- Display controller selected in code: `SH1106 128x64`
- Display bus: hardware I2C
- Serial monitor speed: `115200`

## Wiring Summary

| Function | ESP32 Pin | Notes |
| --- | --- | --- |
| Vibration sensor digital output | `GPIO4` | Read with `digitalRead()` |
| OLED SDA | board-dependent | Typical ESP32 default is often `GPIO21` |
| OLED SCL | board-dependent | Typical ESP32 default is often `GPIO22` |
| Power | board-dependent | Verify sensor and OLED voltage requirements |
| Ground | GND | ESP32, sensor, and display must share ground |

## Sensor Notes

The repository uses an `SW-420` style vibration sensor module with a digital output pin.

## OLED Notes

- The code uses the `U8G2_SH1106_128X64_NONAME_F_HW_I2C` constructor.
- The sketch does not explicitly set custom SDA or SCL pins.
- OLED I2C displays commonly use address `0x3C`, but users may select a different address if their module is wired or configured differently.

## Power And Safety Notes

- Check whether the vibration sensor module expects `3.3 V` or `5 V`.
- Confirm that the OLED module is compatible with your ESP32 logic and supply voltage.
- Avoid driving ESP32 input pins with signals above `3.3 V` unless proper level shifting is used.

## Troubleshooting

- If the OLED stays blank, verify I2C wiring, controller compatibility, power, and address.
- If vibration is always detected or never detected, verify the sensor output wiring and threshold adjustment if your module has a potentiometer.
- If the serial monitor shows unreadable text, make sure it is set to `115200` baud.
