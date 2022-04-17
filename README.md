# EspBluetoothPtt
A bluetooth PTT (Push To Talk) button that can run on an ESP32 board

I was looking for a way to control the Zello Android application while it is running in the background. This small sketch created in Arduino Studio and uploaded to a ESP32 development board is enough to make it a virtual PTT button that can be used to control Zello.

Documentation on how to implement a Zello remote button using the SPP (Serial Port Profile) of Bluetooth can be found here: https://support.zellowork.com/hc/en-us/articles/207385198-Zello-PTT-Button-Partner-Technical-Integration

Short answer is here:
* “+PTTS=P” for button going down & “+PTTS=R” for button coming up
