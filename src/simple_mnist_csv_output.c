#include "simple_mnist.h"
#include "mnist_data.h"

#include <stdio.h>
#include <stdint.h>

#ifndef HOST
typedef void (*vector_table_entry_t)(void);

typedef struct {
	unsigned int *initial_sp_value; /**< Initial stack pointer value. */
	vector_table_entry_t reset;
	vector_table_entry_t nmi;
	vector_table_entry_t hard_fault;
	vector_table_entry_t memory_manage_fault; /* not in CM0 */
	vector_table_entry_t bus_fault;           /* not in CM0 */
	vector_table_entry_t usage_fault;         /* not in CM0 */
	vector_table_entry_t reserved_x001c[4];
	vector_table_entry_t sv_call;
	vector_table_entry_t debug_monitor;       /* not in CM0 */
	vector_table_entry_t reserved_x0034;
	vector_table_entry_t pend_sv;
	vector_table_entry_t systick;
	vector_table_entry_t irq[0];
} vector_table_t;

extern vector_table_t vector_table;
#endif

#define CLASSIFICATIONS 10
#define TESTS 20

__attribute__ ((section(".ram")))
uint8_t output[TESTS];

__attribute__ ((section(".ram")))
uint8_t labels[TESTS];

__attribute__ ((section(".ram")))
float res_array[TESTS*CLASSIFICATIONS];

int main()
{
	for(int j = 0; j < TESTS; j++) {
		output[j] = 0;
	}
   
  for(int j = 0; j < TESTS; j++) {
    ebnn_compute(&train_data[1*28*28*j], &output[j], &res_array[j*CLASSIFICATIONS]);

#ifdef HOST
	for(int i = 0; i < CLASSIFICATIONS; i++) {
		// test, classification #, labeled, output, output value
		printf("%d,%d,%d,%d,%f\n", j, i, i == (int)train_labels[j], i == output[j], res_array[j*CLASSIFICATIONS + i]);
	}	
#endif
  }

  for(int j = 0; j < TESTS; j++) {
		labels[j] = (uint8_t) train_labels[j];
	}
   
  return 0;
}

#ifndef HOST
void done(void)
{
	while (1)
	{
		__asm__("nop");
	}
}

void reset_handler(void)
{
	main();
	done();
}

__attribute__((section(".vectors")))
vector_table_t vector_table = {
	.initial_sp_value = (unsigned *)0x20002000,
	.reset = reset_handler};

#endif
