
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)
#define LED3_NODE DT_ALIAS(led3)

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec led3 = GPIO_DT_SPEC_GET(LED3_NODE, gpios);

int main(void){
    int ret;

    if(!gpio_is_ready_dt(&led0)){
        return -1;
    }
    ret = gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure_dt(&led2, GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure_dt(&led3, GPIO_OUTPUT_ACTIVE);
    if (ret < 0){
        return ret;
    }

    gpio_pin_set_dt(&led0, 0);
    gpio_pin_set_dt(&led1, 0);
    gpio_pin_set_dt(&led2, 0);
    gpio_pin_set_dt(&led3, 0);


    int state = 0;
    int n_blinks = 6;
    int blink2 = n_blinks * 2;

    while (1) {
        if (state == 0){
            for (int i = 0; i < blink2; i++){
                gpio_pin_toggle_dt(&led0);
                k_msleep(250);
            }      
            state = 1;
        }
        if (state == 1){
            for (int i = 0; i < blink2; i++){
                gpio_pin_toggle_dt(&led1);
                k_msleep(250);
            }      
            state = 2;
        }
        if (state == 2){
            for (int i = 0; i < blink2; i++){
                gpio_pin_toggle_dt(&led2);
                k_msleep(250);
            }      
            state = 3;
        }
        if (state == 3){
            for (int i = 0; i < blink2; i++){
                gpio_pin_toggle_dt(&led3);
                k_msleep(250);
            }      
            state = 0;
        }
        


    }

    return 0;
}