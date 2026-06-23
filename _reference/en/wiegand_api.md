# Wiegand API

API that composes the Wiegand card readers and configures the Wiegand input/output.

- [BS2_SearchWiegandDevices](bs2_searchwieganddevices): Searches Wiegand card readers.

- [BS2_GetWiegandDevices](bs2_getwieganddevices): Retrieves the Wiegand card readers being used.

- [BS2_AddWiegandDevices](bs2_addwieganddevices): Adds Wiegand card readers.

- [BS2_RemoveWiegandDevices](bs2_removewieganddevices): Removes Wiegand card readers.

**CAUTION**

When the SDK is initialized, there are no information about the Wiegand card readers. Therefore, a Wiegand device must be searched or added before controlling. 
