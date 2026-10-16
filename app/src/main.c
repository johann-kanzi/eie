/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 100

void bit_convert(int n);
void led_bits(void);

int bits[] = {0, 0, 0, 0};

int main(void) {
  if (0 > BTN_init()) { 
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }

  
  int count = 0;
  while (1) {

    if (BTN_check_clear_pressed(BTN0))
    {
      count++;
      if (count > 15)
        count = 0;
      bit_convert(count);
    }

    led_bits();


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

void led_bits(void)
{
  if (0 < bits[0])
  {
    LED_set(LED0, LED_ON);
  } 
  else 
  {
    LED_set(LED0, LED_OFF);
  }

  if (0 < bits[1])
  {
    LED_set(LED1, LED_ON);
  } 
  else 
  {
    LED_set(LED1, LED_OFF);
  }

  if (0 < bits[2])
  {
    LED_set(LED2, LED_ON);
  } 
  else 
  {
    LED_set(LED2, LED_OFF);
  }

  if (0 < bits[3])
  {
    LED_set(LED3, LED_ON);
  } 
  else 
  {
    LED_set(LED3, LED_OFF);
  }
}