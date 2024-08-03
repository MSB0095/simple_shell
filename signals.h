#ifndef SIGNALS_H
#define SIGNALS_H

#include <signal.h>

/**
 * struct signal_data_s - signal data
 * @signals_received: array of signals received
 *
 * Description: signal data structure that holds an array of signals received.
 */
typedef struct signal_data_s
{
	sig_atomic_t signals_received[NSIG];
} signal_data_t;

void signal_handler(int signal, siginfo_t *info, void *context);
void setup_signal_handlers(signal_data_t *data);

#endif /* SIGNALS_H */
