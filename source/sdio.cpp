#if COMPONENT_SDIO
#include "SDIOBlockDevice.h"
static SDIOBlockDevice bd;

BlockDevice *BlockDevice::get_default_instance()
{
    return &bd;
}

#endif
