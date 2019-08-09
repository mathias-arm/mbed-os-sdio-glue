# mbed-os-sdio-glue

# Testing

## Environment

### Boards

- `DISCO_F746NG`
- `LPC55S69_NS`

### mbed-os.lib

All tests were done with `mbed-os.lib` set to
```
https://github.com/ARMmbed/mbed-os/#b81aeff1a3e171c6421984faa2cc18d0e35746c0
```

### sdio-glue.lib

Add `sdio-glue.lib` with the following content:
```
https://github.com/mathias-arm/mbed-os-sdio-glue.git
```

## Tests

### Tests from mbed-os:

I created a new project and copied one of the following files in `mbed-os`
- `features/storage/TESTS/blockdevice/general_block_device/main.cpp`
- `features/storage/TESTS/blockdevice/heap_block_device/main.cpp`
- `features/storage/filesystem/littlefs/TESTS/filesystem/files/main.cpp`

You should remove the call to `GREENTEA_SETUP()`.

Some changes (modified versions exist [there](https://github.com/mathias-arm/mbed-os/tree/sdio-out-of-tree)) or
additional parameters might be required, e.g.:

```
mbed compile -t GCC_ARM -m $TARGET -DMBED_TEST_BLOCKDEVICE=SDIOBlockDevice \
   --app-config sdio-glue/configs/mbed-os-example-filesystem.json
```

### ARMmbed/mbed-os-example-filesystem

Use `sdio-glue/configs/mbed-os-example-filesystem.json` configuration file.

### ARMmbed/mbed-bootloader

Compile `DISCO_F746NG` with:

```
mbed compile -t GCC_ARM -m DISCO_F746NG --profile tiny.json --app-config sdio-glue/configs/mbed-bootloader-stm.json
```

Resulting in `./BUILD/DISCO_F746NG/GCC_ARM-TINY/mbed-bootloader.bin`.

Compile for `LPC55S69_NS`:

```
mbed compile -t GCC_ARM -m LPC55S69_NS --profile tiny.json --app-config sdio-glue/configs/mbed-bootloader-lpc.json
```

Resulting in `./BUILD/LPC55S69_NS/GCC_ARM-TINY/mbed-bootloader.hex`.

### pelion-example-common

[pelion-example-common](https://os.mbed.com/teams/ST/code/pelion-example-common/)
was tested with `DISCO_F746NG`:

```
mbed compile -t GCC_ARM -m DISCO_F746NG --app-config sdio-glue/configs/pelion-example-common.json
```

### ARMmbed/mbed-cloud-client-example

Tested with `LPC55S69_NS` (with ESP8266):

```
mbed compile -t GCC_ARM -m LPC55S69_NS --profile release --app-config sdio-glue/configs/mbed-cloud-client-example.json
```
