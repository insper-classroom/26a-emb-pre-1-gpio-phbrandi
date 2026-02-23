#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;


int main() {
  int LED_R = 0;
  int LED_G = 0;
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {
      if (LED_R == 0) {
        LED_R = 1;
      } else {
        LED_R = 0;
      }
      gpio_put(LED_PIN_R, LED_R);
      while (!gpio_get(BTN_PIN_R)) {
      };
    }
    if (!gpio_get(BTN_PIN_G)) {
      if (LED_G == 0) {
        LED_G = 1;
      } else {
        LED_G = 0;
      }
      gpio_put(LED_PIN_G, LED_G);
      
      while (!gpio_get(BTN_PIN_G)) {
      };
    }
    
  }
}
