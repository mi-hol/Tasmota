# EEBUS images for ESP32-S3 with Ethernet (W5500) / EEBUS-Images für ESP32-S3 mit Ethernet (W5500)

## English

Two ready-made images for an **ESP32-S3 with 16 MB flash and PSRAM and a W5500 Ethernet chip** (tested hardware:
Waveshare ESP32-S3-ETH). The two EEBUS drivers exclude each other (same commands), so there is one image for each role:

| File | Role | Driver |
|---|---|---|
| `tinyc32s3-eth-guard.bin` / `.factory.bin` | **Steuerbox** (Energy Guard): gives a Home Manager limits (§ 14a EnWG / § 9 EEG) | `xdrv_126_eebus_guard`, page `/steuerbox` |
| `tinyc32s3-eth-steuve.bin` / `.factory.bin` | **SteuVE** (controllable consumer): takes the limit a Home Manager assigns it and switches consumers by script | `xdrv_128_eebus_steuve`, page `/steuve` |

Both contain TinyC, Ethernet (default `EthType 8` = W5500) and the EEBUS driver. They do **not** contain camera,
Matter or LVGL — the TLS/SHIP handshake needs the heap. No Wi-Fi credentials are built in.

For a Steuerbox and a SteuVE you need **two devices**.

### Set up

1. **Flash.** New device: `.factory.bin` with esptool or a web installer. Device that already runs Tasmota: upload the
   `.bin` (OTA). ⚠️ Coming from another firmware the settings are reset, Wi-Fi included: make a backup first.
2. **Ethernet pins.** *Configure Module* (or the console), for the Waveshare ESP32-S3-ETH (pins as given by the
   manufacturer — check them against your board):

   | GPIO | Function (Tasmota component) | Console |
   |---|---|---|
   | 13 | SPI CLK | `Gpio13 736` |
   | 12 | SPI MISO | `Gpio12 672` |
   | 11 | SPI MOSI | `Gpio11 704` |
   | 14 | ETH MDC (= W5500 chip select) | `Gpio14 5568` |
   | 10 | ETH MDIO (= W5500 interrupt) | `Gpio10 5600` |
   | 9 | ETH POWER (= W5500 reset) | `Gpio9 5536` |

   Console in one line: `Backlog Gpio13 736; Gpio12 672; Gpio11 704; Gpio14 5568; Gpio10 5600; Gpio9 5536; EthType 8`,
   then `Restart 1`. Other W5500 boards: same six functions, other GPIO numbers. After the restart *Information* shows an
   Ethernet address.
3. **Upload the page** to the file system (*Consoles → Manage File System*): `steuerbox.html` (Steuerbox image) or
   `steuve.html` (SteuVE image). Both are attached to this release. Then open `http://<device>/steuerbox` or
   `/steuve`.
4. **Steuerbox:** commands and the pairing are described at the top of `xdrv_126_eebus_guard.ino`; `EEBusScan`,
   `EEBusConnect <ski|idx>`, then confirm the device's SKI at the Home Manager. **SteuVE:** set `EEBusCsTyp wallbox` (the Home Manager it was tested with accepted it under that identity; the default `wp`
   is untested), load the script *SteuVE Verbraucher v004* from the TinyC page (Repository box) into slot 0; description in `xdrv_128_eebus_steuve.md`
   (attached).

Background and discussion: https://www.photovoltaikforum.com/thread/263104-eebus-steuerbox-simulator-auf-tasmota-basis/

⚠️ **Own certificate, own risk.** Whoever reaches the device's SHIP port is accepted (the SKI of the peer comes from
the mDNS scan and is not checked against its certificate). Use it in your own network, not exposed to the Internet.

## Deutsch

Zwei fertige Images für einen **ESP32-S3 mit 16 MB Flash, PSRAM und W5500-Ethernet** (erprobt: Waveshare
ESP32-S3-ETH). Die beiden EEBUS-Treiber schließen sich aus (gleiche Befehle), deshalb gibt es je Rolle ein Image:

| Datei | Rolle | Treiber |
|---|---|---|
| `tinyc32s3-eth-guard.bin` / `.factory.bin` | **Steuerbox** (Energy Guard): gibt einem Home Manager Grenzen vor (§ 14a EnWG / § 9 EEG) | `xdrv_126_eebus_guard`, Seite `/steuerbox` |
| `tinyc32s3-eth-steuve.bin` / `.factory.bin` | **SteuVE** (steuerbare Verbrauchseinrichtung): übernimmt die Grenze, die der Home Manager ihr zuteilt, und schaltet per Skript Verbraucher | `xdrv_128_eebus_steuve`, Seite `/steuve` |

Beide enthalten TinyC, Ethernet (Vorgabe `EthType 8` = W5500) und den EEBUS-Treiber, aber **keine** Kamera, kein
Matter und kein LVGL — der TLS/SHIP-Aufbau braucht den Heap. WLAN-Zugangsdaten sind nicht eingebaut.

Für Steuerbox und SteuVE braucht man **zwei Geräte**.

### Einrichten

1. **Flashen.** Neues Gerät: `.factory.bin` mit esptool oder einem Web-Installer. Gerät mit Tasmota: die `.bin` per
   OTA. ⚠️ Von einer anderen Firmware kommend werden die Einstellungen samt WLAN zurückgesetzt: vorher sichern.
2. **Ethernet-Pins** setzen (*Konfiguration → Gerät konfigurieren* oder Konsole), für das Waveshare ESP32-S3-ETH
   (Belegung laut Hersteller, bitte am eigenen Board prüfen): siehe Tabelle oben. Konsole in einer Zeile:
   `Backlog Gpio13 736; Gpio12 672; Gpio11 704; Gpio14 5568; Gpio10 5600; Gpio9 5536; EthType 8`, danach `Restart 1`.
   Andere W5500-Boards: dieselben sechs Funktionen, andere GPIO-Nummern. Nach dem Neustart zeigt *Information* eine
   Ethernet-Adresse.
3. **Seite hochladen** ins Dateisystem (*Konsolen → Dateisystem verwalten*): `steuerbox.html` (Steuerbox-Image) bzw.
   `steuve.html` (SteuVE-Image), beide hängen an diesem Release. Dann `http://<Gerät>/steuerbox` bzw. `/steuve` öffnen.
4. **Steuerbox:** Befehle und Kopplung stehen am Anfang von `xdrv_126_eebus_guard.ino`; `EEBusScan`,
   `EEBusConnect <ski|idx>`, dann die SKI des Geräts beim Home Manager bestätigen. **SteuVE:** `EEBusCsTyp wallbox` setzen (unter dieser Kennung hat der erprobte Home Manager sie angenommen, die
   Vorgabe `wp` ist ungetestet), auf der TinyC-Seite (Repository-Box) das Skript *SteuVE Verbraucher v004* in Slot 0 laden; Beschreibung in `xdrv_128_eebus_steuve.md`
   (angehängt).

Hintergrund und Diskussion: https://www.photovoltaikforum.com/thread/263104-eebus-steuerbox-simulator-auf-tasmota-basis/

⚠️ **Eigenes Zertifikat, eigenes Risiko.** Wer den SHIP-Port des Geräts erreicht, wird angenommen (die SKI der Gegenstelle
stammt aus dem mDNS-Scan und wird nicht gegen ihr Zertifikat geprüft). Im eigenen Netz betreiben, nicht aus dem Internet erreichbar machen.
