/*
  user_config_override.h  –  VORLAGE fuer EEBUS Steuerbox / SteuVE
  Waveshare ESP32-S3-ETH (W5500-Ethernet, SD-Karte), Fork gemu2015/Sonoff-Tasmota, Zweig universal

  Testgeraete: Steuerbox und SteuVE dienen dazu, die EEBUS-Kommunikation mit einem HEMS zu pruefen.
  Nicht zertifiziert, kein Ersatz fuer die Steuerbox des Messstellenbetreibers, nicht fuer den
  regulaeren Betrieb.

  Benutzung:
   1. Diese Datei als  tasmota/user_config_override.h  ablegen (wird von git ignoriert).
   2. Unten GENAU EIN Geraet waehlen: EEBUS_STEUERBOX  oder  EEBUS_STEUVE.
   3. Abschnitt "EIGENE DATEN" ausfuellen (WLAN optional, Ethernet laeuft ohne).
   4. In platformio_override.ini das passende Env eintragen (siehe zweite Vorlage) und bauen.
   5. Nach dem Flashen die Seite steuerbox.html bzw. steuve.html ins Dateisystem laden.
*/
//
#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_
//
#warning **** user_config_override.h: Using Settings from this File ****
//
//################################################################################
//-- alle undef's (raeumt die Vorgaben aus my_user_config.h ab) --
//################################################################################
#undef APP_TIMEZONE
#undef CFG_HOLDER
#undef DEVICE_NAME
#ifdef USE_ETHERNET
#undef ETH_TYPE
#undef ETH_ADDRESS
#undef ETH_CLKMODE
#endif
#undef FALLBACK_MODULE
#undef FRIENDLY_NAME
#undef JPEG_PICTS
#undef LARGE_ARRAYS
#undef LATITUDE
#undef LONGITUDE
#undef MAXFILT
#undef MAXSVARS
#undef MAXVARS
#undef METER_DEF_SIZE
#undef MODBUS_DEBUG
#undef MQTT_CLIENT_ID
#undef MQTT_HOST
#undef MQTT_PASS
#undef MQTT_PORT
#undef MQTT_TOPIC
#undef MQTT_USE
#undef MQTT_USER
#undef MY_LANGUAGE
#undef NO_USE_SML_DECRYPT
#undef PROJECT
#undef PW_FTP
#undef SCRIPT_FULL_WEBPAGE
#undef SCRIPT_LARGE_VNBUFF
#undef SET_ESP32_STACK_SIZE
#undef SHELLY_FW_UPGRADE
#undef SML_MAX_VARS
#undef SML_SRCBSIZE
#undef STA_PASS1
#undef STA_PASS2
#undef STA_SSID1
#undef STA_SSID2
#undef USE_FTP
#undef USER_FTP
#undef SUPPORT_MQTT_EVENT
#undef TCP_CLIENT_SECURE
#undef TELE_PERIOD
#undef UFSYS_SIZE
#undef USE_AC_ZERO_CROSS_DIMMER
#undef USE_ADC
#undef USE_ADC_VCC
#undef USE_ADE7953
#undef USE_APDS9960
#undef USE_ARILUX_RF
#undef USE_ARMTRONIX_DIMMERS
#undef USE_AUTOCONF
#undef USE_BERRY
#undef USE_BH1750
#undef USE_BL0940
#undef USE_BL094XX
#undef USE_BLE09XX
#undef USE_BME280
#undef USE_BME680
#undef USE_BMP
#undef USE_BP1658CJ
#undef USE_BP5758D
#undef USE_BUZZER
#undef USE_COUNTER
#undef USE_CSE7766
#undef USE_DEEPSLEEP
#undef USE_DEVICE_GROUPS
#undef USE_DHT
#undef USE_DISCOVERY
#undef USE_DISPLAY
#undef USE_DISPLAY_LCD
#undef USE_DISPLAY_MATRIX
#undef USE_DISPLAY_MODES1TO5
#undef USE_DISPLAY_SEVENSEG
#undef USE_DISPLAY_SSD1306
#undef USE_DOMOTICZ
#undef USE_DS1820
#undef USE_DS18B20
#undef USE_DS18x20
#undef USE_DS18x20_LEGACY
#undef USE_ELECTRIQ_MOODL
#undef USE_EMULATION
#undef USE_EMULATION_HUE
#undef USE_EMULATION_WEMO
#undef USE_ENERGY_MARGIN_DETECTION
#undef USE_ENERGY_POWER_LIMIT
#undef USE_ENERGY_SENSOR
#undef USE_ESP32MAIL
#undef USE_ETHERNET
#undef USE_EXS_DIMMER
#undef USE_FEXTRACT
#undef USE_GOOGLE_CHARTS
#undef USE_GPIO_VIEWER
#undef USE_GPS
#undef USE_HM10
#undef USE_HOME_ASSISTANT
#undef USE_HTU
#undef USE_HX711
#undef USE_I2C
#undef USE_IBEACON
#undef USE_IMPROV
#undef USE_IR_RECEIVE
#undef USE_IR_REMOTE
#undef USE_IR_REMOTE_FULL
#undef USE_KNX
#undef USE_KNX_IP_WEBSERVER
#undef USE_KNX_WEB_MENU
#undef USE_LIGHT
#undef USE_LM75AD
#undef USE_LVGL
#undef USE_MCP230xx
#undef USE_MCP23XXX_DRV
#undef USE_MCP39F501
#undef USE_MHZ19
#undef USE_MI_ESP32
#undef USE_MLX90614
#undef USE_MODBUS_BRIDGE
#undef USE_MODBUS_BRIDGE_TCP
#undef USE_MP3_PLAYER
#undef USE_MQTT_AZURE_DPS_PRESHAREDKEY
#undef USE_MQTT_AZURE_DPS_SCOPEID
#undef USE_MQTT_AZURE_IOT
#undef USE_MQTT_TLS
#undef USE_MY92X1
#undef USE_NOVA_SDS
#undef USE_OPENTHERM
#undef USE_PCA9685
#undef USE_PING
#undef USE_PMS5003
#undef USE_PN532_HSU
#undef USE_PN532_I2C
#undef USE_PS_16_DZ
#undef USE_PWM_DIMMER
#undef USE_PZEM_AC
#undef USE_PZEM_DC
#undef USE_PZEM004T
#undef USE_PZEM2
#undef USE_RC_SWITCH
#undef USE_RF_FLASH
#undef USE_RTC_CHIPS
#undef USE_RULES
#undef USE_SCD30
#undef USE_SCRIPT
#undef USE_SCRIPT_JSON_EXPORT
#undef USE_SCRIPT_SUB_COMMAND
#undef USE_SCRIPT_TIMER
#undef USE_SCRIPT_WEB_DISPLAY
#undef USE_SENDMAIL
#undef USE_SENSEAIR
#undef USE_SERIAL_BRIDGE
#undef USE_SGP30
#undef USE_SHELLY_DIMMER
#undef USE_SHT
#undef USE_SHT3X
#undef USE_SHUTTER
#undef USE_SM16716
#undef USE_SM2135
#undef USE_SM2335
#undef USE_SML_TCP
#undef USE_SML_TCP_IP_STR
#undef USE_SML_TCP_SECURE
#undef USE_SONOFF_D1
#undef USE_SONOFF_IFAN
#undef USE_SONOFF_RF
#undef USE_SONOFF_SC
#undef USE_SPS0
#undef USE_SR04
#undef USE_TASMOTA_DISCOVERY
#undef USE_TELEINFO
#undef USE_TINYC
#undef USE_TINYC_IDE
#undef USE_TIMERS
#undef USE_TIMERS_WEBINTERFACE
#undef USE_TLS
#undef USE_TUYA_DIMMER
#undef USE_TUYA_MCU
#undef USE_TX20_WIND_SENSOR
#undef USE_UFILESYS
#undef USE_UNIVERSAL_TOUCH
#undef USE_UNIVERSAL_DISPLAY
#undef USE_WEBCLIENT_HTTPS
#undef USE_WEBSEND_RESPONSE
#undef USE_WS2812
#undef USE_WS2812_FORCE_NEOPIXELBUS
//
//
//################################################################################
//-- Geraet waehlen: GENAU EINES aktivieren --
//################################################################################
//
// #define EEBUS_STEUERBOX          // Steuerbox (Treiber xdrv_126), Seite /steuerbox
// #define EEBUS_STEUVE          // steuerbare Verbrauchseinrichtung (Treiber xdrv_128), Seite /steuve
//
//################################################################################
//
#if defined(EEBUS_STEUERBOX) && defined(EEBUS_STEUVE)
  #error "Nur EIN Geraet waehlen: EEBUS_STEUERBOX oder EEBUS_STEUVE"
#endif
//
//################################################################################
//-- EIGENE DATEN – hier anpassen --
//################################################################################
#define LATITUDE            0.0           // eigener Standort (fuer Sonnenauf-/-untergang), optional
#define LONGITUDE           0.0
#define APP_TIMEZONE        99            // 99 = Sommer-/Winterzeit nach Tasmota-Regeln (Mitteleuropa)
#define MY_LANGUAGE         de_DE
#define PROJECT             ""
//
// WLAN (optional – das Geraet laeuft ueber Ethernet; leer lassen = kein WLAN)
#define STA_SSID1           ""
#define STA_PASS1           ""
#define STA_SSID2           ""
#define STA_PASS2           ""
//
// MQTT aus (bei Bedarf eintragen)
#define MQTT_USE            false
#define MQTT_HOST           ""
#define MQTT_PORT           1883
#define MQTT_USER           ""
#define MQTT_PASS           ""
#define MQTT_CLIENT_ID      "eebus_%06X"
#define MQTT_TOPIC          "eebus_%06X"
//
#define TELE_PERIOD         60
//
//################################################################################
//-- gemeinsam fuer Steuerbox und SteuVE --
//################################################################################
#define USE_TINYC
#define USE_TINYC_IDE
//
// ⚠️ ZWINGEND fuer SHIP (EEBUS): erst damit sendet die TLS-Bibliothek (tls_mini) das eigene
// Zertifikat der Box (br_ssl_client_set_single_ec). Fehlt es, bricht die Gegenstelle den Aufbau mit
// "handshake_failure" ab – in der Konsole:  "tls connect err=296".
// Ab universal-Commit 4a0e5944c setzt my_user_config.h beides selbst (USE_EEBUS_GUARD/USE_EEBUS_STEUVE);
// die zwei Zeilen bleiben hier fuer aeltere Staende stehen und schaden nicht.
#define USE_MQTT_CLIENT_CERT
//
// gegenseitiges TLS mit ECDSA-Signatur braucht mehr Stack (12 KB -> Absturz beim Signieren)
#define SET_ESP32_STACK_SIZE (24 * 1024)
//
// TinyC
#undef TC_VM_TASK_STACK
#define TC_VM_TASK_STACK      16384
#define TC_MAX_HEAP           32768
#define TC_MAX_HEAP_HANDLES   256
#define USE_WEBCLIENT_HTTPS
#define USE_WEBSEND_RESPONSE
//
// SML (Zaehler lesen, optional)
#define USE_SML_M
#define USE_SML_TCP
#define USE_SML_SCRIPT_CMD
#define NO_USE_SML_DECRYPT
#define SML_MAX_VARS        40
#define METER_DEF_SIZE      8000
#define SML_SRCBSIZE        512
//
// Dateisystem + SD-Karte (Seiten, Protokolle)
#define USE_SDCARD
#define USE_UFILESYS
#define USE_FEXTRACT
#define UFSYS_SIZE          40000
//
#define USE_TASMOTA_DISCOVERY
#define USE_I2C
//
// Ethernet W5500 (Waveshare ESP32-S3-ETH)
#define USE_ETHERNET
#define ETH_TYPE            8       // 8 = W5500
#define ETH_ADDRESS         1       // SPI-Modus
#define ETH_CLKMODE         0       // fuer SPI ohne Bedeutung
//
// Pins laut Hersteller-Wiki, auf zwei Geraeten bestaetigt:
//   W5500: RST=GPIO9, INT=GPIO10, MOSI=GPIO11, MISO=GPIO12, SCLK=GPIO13, CS=GPIO14
//   SD-Karte (eigener SPI-Bus): CS=GPIO4, MISO=GPIO5, MOSI=GPIO6, SCLK=GPIO7
#define USER_TEMPLATE     "{\"NAME\":\"Waveshare ESP32-S3-ETH\",\"GPIO\":[0,0,0,0,6721,673,705,737,0,5536,5600,704,672,736,5568,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":1}"
#define FALLBACK_MODULE   USER_MODULE
#define MODULE            USER_MODULE
//
//################################################################################
//-- je Geraet --
//################################################################################
#ifdef EEBUS_STEUERBOX
  #define CFG_HOLDER        4627          // eigener Wert -> frische Grundeinstellungen beim ersten Start
  #define DEVICE_NAME       "eebus-Steuerbox"
  #define FRIENDLY_NAME     "Steuerbox"
  #define USE_EEBUS_GUARD                 // Treiber xdrv_126
#endif
//
#ifdef EEBUS_STEUVE
  #define CFG_HOLDER        4628
  #define DEVICE_NAME       "eebus-SteuVE"
  #define FRIENDLY_NAME     "SteuVE"
  #define USE_EEBUS_STEUVE                // Treiber xdrv_128 – NICHT zusammen mit USE_EEBUS_GUARD
#endif
//
#endif  // _USER_CONFIG_OVERRIDE_H_
