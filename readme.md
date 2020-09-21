# half-kh-hacker's QMK keymap for the HS60 v3 ISO

Ported from `qmk-dz60-half-kh-hacker`.

## Usage

1. Clone the repo to `qmk/keyboards/hs60/v2/iso/keymaps/half-kh-hacker`
2. To build, type `make hs60/v2/iso:half-kh-hacker` (or just `qmk compile`)
3. Flash as usual.

## Notes

- Currently, if you want to build QMK with ChibiOS on GCC 9.x, you need to remove the `sp` entries from some inline ASM in `cmsis_gcc.h`
- To support the custom backlighting, you have to make a few changes to `wt_rgb_backlight.c`:

```diff
@@ -1837,6 +1837,8 @@ void backlight_effect_indicators(void)
     }
 }
 
+#include "../hs60/v2/iso/keymaps/half-kh-hacker/backlighting/user_bl.h"
+
 #if !defined(RGB_BACKLIGHT_HS60) && !defined(RGB_BACKLIGHT_NK65)
```

```diff
@@ -1928,6 +1930,9 @@ static void gpt_backlight_timer_task(GPTDriver *gptp)
         case 10:
             backlight_effect_cycle_radial2();
             break;
+        case 11:
+            backlight_effect_user();
+            break;
         default:
             backlight_effect_all_off();
             break;
```
