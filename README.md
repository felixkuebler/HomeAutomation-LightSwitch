# Introduction
Due to the growing demand of iot devices for home automation this project presents an cheap, easy to use and "open source" alternative to brand Products such as Phillips Hue. Based on the ESP8266-12E, a small WiFi enabled chipset, these devices can be retrofitted in a variety of devices such as light switches, motor controllers and more.

Each home automation node will access your local wifi network and is configurable through a webpage hosted locally on the device itsself. Your network needs to provide a [mqtt](https://pagefault.blog/2017/03/02/using-local-mqtt-broker-for-cloud-and-interprocess-communication/) broker to enable communication between nodes thus enabling its full functionality. An easy to use webinterface as well as a mqtt broker is provided by [Openhab](https://www.openhab.org/).

# Light Switch
The light switch module is an small embedded device that can be integrated in your 220 VAC power grid without any special adaptations. Powered by the [HLK-PM01](http://www.hlktech.net/product_detail.php?ProId=54) this module provides two digital inputs as well as two solid state relay outputs. Each input and output can be assigned and modified individually via the local web interface. Due to its small form factor it can easily be fitted behind any flush-mounted box with a min. depth of 41mm.

![[light switch render]](Hardware/Electronics/Render/LightSwitch_3D.jpg)
![[light switch render]](Hardware/Mechanics/Render/LightSwitch_3D.jpg)

The current versions can be found here:
* [Version 1.0](../../tree/Version1.0)

# License
This work is property of Felix Kübler and is licensed under the
<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">Creative Commons Attribution-NonCommercial 4.0 International License</a>.
