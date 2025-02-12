#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12  // GPIO 12 conectado ao LED RGB
#define PWM_FREQUENCY 50
#define PWM_WRAP 20000  // Período de 20ms (50Hz)

void configure_pwm() {
    // Configura o PWM para o servomotor (GPIO 22)
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_clkdiv(slice_num, 125.0f); // Divisor ajustado para frequência de 50Hz
    pwm_set_enabled(slice_num, true);

    // Configura o PWM para o LED RGB (GPIO 12)
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(LED_PIN);
    pwm_set_wrap(slice_num, PWM_WRAP); // Mesmo wrap do servomotor
    pwm_set_clkdiv(slice_num, 125.0f); // Mesmo divisor do servomotor
    pwm_set_enabled(slice_num, true);
}

void set_servo_pulse(uint16_t pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, pulse_width_us);

    // Aplica o mesmo pulso ao LED RGB (GPIO 12)
    slice_num = pwm_gpio_to_slice_num(LED_PIN);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, pulse_width_us);
}

void delay_seconds(int seconds) {
    sleep_ms(seconds * 1000);
}

void smooth_movement() {
    // Movimentação suave de 0° (500 µs) até 180° (2400 µs)
    for (uint16_t pulse = 500; pulse <= 2400; pulse += 5) {
        set_servo_pulse(pulse);
        sleep_ms(10);
    }

    // Movimentação suave de 180° (2400 µs) até 0° (500 µs)
    for (uint16_t pulse = 2400; pulse >= 500; pulse -= 5) {
        set_servo_pulse(pulse);
        sleep_ms(10);
    }
}

int main() {
    stdio_init_all();
    configure_pwm();

    // Posições fixas com espera de 5 segundos
    set_servo_pulse(2400); // 180°
    delay_seconds(5);

    set_servo_pulse(1470); // 90°
    delay_seconds(5);

    set_servo_pulse(500);  // 0°
    delay_seconds(5);

    // Movimentação periódica suave entre 0° e 180°
    while (1) {
        smooth_movement();
    }

    return 0;
}