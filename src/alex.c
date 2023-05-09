#include "ebnn.h"
#include "alex.h"
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

#define TESTS 20

__attribute__ ((section(".ram")))
uint8_t output[TESTS];

__attribute__ ((section(".ram")))
uint8_t labels[TESTS];

int main() {
	for(int j = 0; j < TESTS; j++) {
		output[j] = 0;
	}

	output[0] = 0;

	for(int j = 0; j < TESTS; j++) {
		ebnn_compute(&train_data[784*j], &output[j]);

#ifdef HOST
		int fail = ((uint8_t) train_labels[j]) != output[j];
		printf("actual: %d %s predicted: %d\n", (int) train_labels[j], (fail ? "<>" : "=="), output[j]);
#endif
	}

	for(int j = 0; j < TESTS; j++) {
		labels[j] = (uint8_t) train_labels[j];
	}

	return 0;
}

#ifndef HOST
void done(void) {
  while(1) {
    __asm__("nop");
  }
}

void reset_handler(void) {
    main();
    done();
}

__attribute__ ((section(".vectors")))
vector_table_t vector_table = {
	.initial_sp_value = (unsigned *)0x20002000,
	.reset = reset_handler
};

#endif
