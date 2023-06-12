// pin set
#define VOLTAGE_PIN A3
#define PWM_OUT_PIN 9
#define SENSOR_POWER_PIN 5
#define ADC_PIN A2
#define BUTTON_PIN 8
#define LED_PIN 6

#define LORAWAN_TX 3
#define LORAWAN_RX 4
#define LORAWAN_RST 10

#define DEBUG_OUT_ENABLE 1

#define SOIL_ADC_WATER 694
#define SOIL_ADC_AIR 753
#define SOIL_ADC_UNIT ((SOIL_ADC_WATER - SOIL_ADC_AIR) / 100.0)

#define AT_TIMEOUT 3000

// User must fill out
#define DEVEUI ""
#define APPEUI ""
#define APPKEY ""
// Example AT+CFREQBANDMASK=0002 for US915
#define MASK ""

#define SLEEP_MIN 60
#define SLEEP_CYCLE SLEEP_MIN*7.5

// LAZY FORWARD DECLARATION
void log_init();
void log_out(const char *log);
void read_sensor();
void lorawan_init();
int lorawan_join();
void send_lorawan();
void low_power();
bool aht_init();
void pwn_init();
void log_out_num(const char *log, int num);
void sendData(String command, const int timeout);
int sendData_keyword(String command, const int timeout, String keyword);