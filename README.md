# WiFiDirectLegacyAPPlus
This is a copy of the Windows sample that allows 'soft AP' support on Windows 10 through the WiFi Direct interfaces.

## NOTE NOTE NOTE

**Passphrase must be at least 8 characters !?**
Otherwise you will get a message saying "Advertisement aborted, unknown reason"


This means the driver need not have "Hosted networks supported" or "Soft AP" supported.
The driver must support Wi-Fi Direct, as shown when running:
`netsh wlan show wirelesscapabilities`

The code in this repo was taken from here: https://github.com/microsoft/Windows-classic-samples/tree/master/Samples/WiFiDirectLegacyAP opened in VS 2019 16.7 and rebuilt with recommended upgrade of the project (target runtime version was updated).

The Release page has binaries for x64.
Those require the corresponding VS++ runtime version 14.1 (VS 2019 runtime).
Runtime updates can be downloaded from the "Other Tools and Frameworks" section here: https://visualstudio.microsoft.com/downloads/
The same runtime update files are also documented and linked here: https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads

The above oriniginal code was slightly extended to allow a non interactive operation mode.


Running the program gives these options:

1.) Default AP Mode
~~~~~~~~~~~~~~~~~~~~
PS D:\Test> .\WiFiDirectLegacyAPPlus.exe 
Starts app with default parameters "ssid testAP" and "pass 12345678"


2.) Parameter AP Mode
~~~~~~~~~~~~~~~~~~~~~~
PS D:\Test> .\WiFiDirectLegacyAPPlus.exe paramSSID paramPASS 
Starts app with command line parameters "ssid paramSSID" and "pass paramPASS"


3.) Interactive Mode
~~~~~~~~~~~~~~~~~~~~~
PS D:\Test> .\WiFiDirectLegacyAPPlus.exe interactive   

>?
Wi-Fi Direct Legacy AP Interactive Usage:
-----------------------------------------
start             : Start the legacy AP to accept connections
stop              : Stop the legacy AP
ssid <ssid>       : Configure the SSID before starting the legacy AP
pass <passphrase> : Configure the passphrase before starting the legacy AP
autoaccept <0|1>  : Configure the legacy AP to accept connections (default) or prompt the user
quit|exit         : Exit

>                                                                                                                       
```

