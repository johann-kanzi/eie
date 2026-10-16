/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 50

void bit_convert(int n);
void led_bits(int lum);

int bits[] = {0, 0, 0, 0};

int main(void) {
  if (0 > BTN_init()) { 
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }

  
  int count = 0;
  int duty_cycle = 100;

  while (1) {

    if (BTN_check_clear_pressed(BTN0))
    {
      count++;
      if (count > 15)
        count = 0;
      bit_convert(count);
    }

    if (BTN_is_pressed(BTN1))
    {
      duty_cycle += 1;
      if (duty_cycle >= 100)
        duty_cycle = 5;
    }
    led_bits(duty_cycle);

    k_msleep(SLEEP_MS);
  }
  return 0;
}

void bit_convert(int n)
{
  bits[0] = (n >> 0) & 1;
  bits[1] = (n >> 1) & 1;
  bits[2] = (n >> 2) & 1;
  bits[3] = (n >> 3) & 1;
  return;
}

void led_bits(int lum)
{
  if (0 < bits[0])
  {
    LED_pwm(LED0, lum);
  } 
  else 
  {
    LED_set(LED0, LED_OFF);
  }

  if (0 < bits[1])
  {
    LED_pwm(LED1, lum);
  } 
  else 
  {
    LED_set(LED1, LED_OFF);
  }

  if (0 < bits[2])
  {
    LED_pwm(LED2, lum);
  } 
  else 
  {
    LED_set(LED2, LED_OFF);
  }

  if (0 < bits[3])
  {
    LED_pwm(LED3, lum);
  } 
  else 
  {
    LED_set(LED3, LED_OFF);
  }
  return;
}
