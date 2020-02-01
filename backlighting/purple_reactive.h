#pragma once

void backlight_effect_user(void) {
  for (int i = 0; i < BACKLIGHT_LED_COUNT; i++) {
    uint16_t hit_time = g_key_hit[i];
    if (hit_time < 3) {
      hit_time = 0;
    } else {
      hit_time = hit_time - 3;
    }

    hit_time *= 20;
    if (hit_time > 255) hit_time = 255;

    uint8_t brightness = 255 - hit_time;
    HSV hsv = { .h = 191, .s = 214, .v = brightness };
    RGB rgb = hsv_to_rgb(hsv);
    backlight_set_color(i, rgb.r, rgb.g, rgb.b);
  }
}
