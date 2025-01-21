/*
 * ring_buffer.h
 *
 *  Created on: Aug 2, 2016
 *      Author: akudlacek
 */


#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


/**************************************************************************************************
*                                             DEFINES
*************************************************^************************************************/
typedef enum
{
	BUFFER_EMPTY,
	BUFFER_HAS_DATA
} ring_buffer_state_t;

typedef struct
{
	ring_buffer_state_t rb_state;
	uint8_t *rb_buffer_array;
	uint16_t rb_buffer_size;
	uint16_t rb_head;
	uint16_t rb_tail;
	uint16_t rb_max_usage;
} ring_buffer_t;


/**************************************************************************************************
*                                            PROTOTYPES
*************************************************^************************************************/
void     ring_buffer_init         (ring_buffer_t * const ring_buffer, uint8_t * const buffer_array, const uint16_t buffer_array_size);
int8_t   ring_buffer_put_data     (ring_buffer_t * const ring_buffer, const uint8_t data_to_put);
int16_t  ring_buffer_get_data     (ring_buffer_t * const ring_buffer);
uint16_t ring_buffer_get_max_usage(ring_buffer_t * const ring_buffer);

#ifdef __cplusplus
}
#endif

#endif /* RING_BUFFER_H_ */
