#ifndef _DHT_H_
#define _DHT_H_

#include <stdint.h>

typedef enum {
	DHT_OK,
	DHT_IRQ_TIMEOUT,
	DHT_TIMEOUT,
	DHT_RCV_TIMEOUT,
	DHT_DECODE_ERROR,
	DHT_CHECKSUM_ERROR,
} dht_error_t;

typedef struct _dht_sensor_t dht_sensor_t;
struct _dht_sensor_t {
	dht_error_t state;	/* признак ошибки */
	int16_t temperature;	/* temperature*10 */
	uint16_t humidity;		/* humidity*10 */
};


#ifdef __cplusplus
extern "C" {
#endif

/*-----------------------------------------------------------------------------*/
void dht_init(void);
/* temperature in 1/10 deg C, humidity in 1/10 % */
dht_error_t dht_read(int16_t *temperature, uint16_t *humidity);

#ifdef __cplusplus
}
#endif

#endif
