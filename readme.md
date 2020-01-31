# half-kh-hacker's QMK keymap for the HS60 v3 ISO

Ported from `qmk-dz60-half-kh-hacker`.

## Usage

1. Clone the repo to `qmk/keyboards/hs60/v2/iso/keymaps/half-kh-hacker`
2. To build, type `make hs60/v2/is0:half-kh-hacker`
3. Flash as usual.

## Note

Currently, if you want to build QMK with ChibiOS on GCC 9.x, you need to remove the `sp` entries from some inline ASM in `cmsis_gcc.h`
