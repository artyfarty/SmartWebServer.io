# This fork
I migrarated the project to pio, added some build envs and features to suite my needs:
* Automated upload via onstep board (not working yet)
* Restart SWS button

Please don't expect me to maintain this fork forever.

**P.io makes flashing more easy reproducible for tech-savvy person familiar with IDEs, build environments, dependency management etc. 
If you are not, you better use original Howard's version and follow instructions in official wiki.**

# Configuration
This version expects you to create Extended.userconfig.h and Userconfig.h instead of editing VCS-tracked files. Some defines are in pio ini file.

# Flashing
Use any IDE (VScode, CLion) with platform.io plugin, or raw platform.io cli to flash your device. Choose the corresponding build env from pio ini, or create your own.

# OnStep Smart Web Server
This is the WiFi and Ethernet web server for OnStep, it is also sometimes referred to as the "SWS".
The SWS enables OnStep to be controlled from a website and/or by passing commands over IP.
The SWS is known to work from personal computers (using a web browser, ASCOM, or INDI), phones (Android and iOS), tablets, and the wireless Smart Hand Controller.

# Optionally, the SWS can also provide:
Support for encoders where it integrates tightly with OnStep; or if not using Encoders, OnStepX can use those four connections (pins) as general purpose I/O.
There is also support for using the "ACGAM R1 Bluetooth 4.0 Wireless Gamepad" over Bluetooth LE which you can read about here:
https://onstep.groups.io/g/main/wiki/26762

# License
The Smart Web Server is open source free software, licensed under the GPL.

See [LICENSE.txt](./LICENSE.txt) file.

# Primary Author
[Howard Dutton](http://www.stellarjourney.com)
