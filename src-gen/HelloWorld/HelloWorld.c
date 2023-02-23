// Code generated by the Lingua Franca compiler from:
// file://Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf
#define LOG_LEVEL 2
#define TARGET_FILES_DIRECTORY "/Users/ra/DENSO/repos/lf-workshop/src-gen/HelloWorld"
#include "include/api/api.h"
#include "core/reactor.h"
#include "core/reactor_common.h"
#include "core/threaded/scheduler.h"
#include "core/mixed_radix.h"
#include "core/port.h"
int lf_reactor_c_main(int argc, const char* argv[]);
int main(int argc, const char* argv[]) {
    return lf_reactor_c_main(argc, argv);
}
const char* _lf_default_argv[] = { "dummy", "-o", "10", "sec" };
void _lf_set_default_command_line_options() {
        default_argc = 4;
        default_argv = _lf_default_argv;
}
// =============== START reactor class HelloWorld
typedef struct {
    struct self_base_t base;
    #line 8 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    reaction_t _lf__reaction_0;
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    trigger_t _lf__t;
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    reaction_t* _lf__t_reactions[1];
} helloworld_main_self_t;
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void helloworld_mainreaction_function_0(void* instance_args) {
    helloworld_main_self_t* self = (helloworld_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    #line 9 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    printf("Hello World\n");
}
#include "include/api/set_undef.h"
helloworld_main_self_t* new_HelloWorld() {
    helloworld_main_self_t* self = (helloworld_main_self_t*)_lf_new_reactor(sizeof(helloworld_main_self_t));
    #line 8 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__reaction_0.number = 0;
    #line 8 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__reaction_0.function = helloworld_mainreaction_function_0;
    #line 8 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__reaction_0.self = self;
    #line 8 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 8 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 8 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__reaction_0.name = "?";
    #line 8 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__t.last = NULL;
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_0;
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    #ifdef FEDERATED
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 7 "/Users/ra/DENSO/repos/lf-workshop/src/HelloWorld.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    return self;
}
// =============== END reactor class HelloWorld
// Array of pointers to timer triggers to be scheduled in _lf_initialize_timers().
trigger_t* _lf_timer_triggers[1];
int _lf_timer_triggers_size = 1;
// Array of pointers to startup triggers.
reaction_t** _lf_startup_reactions = NULL;
int _lf_startup_reactions_size = 0;
// Array of pointers to shutdown triggers.
reaction_t** _lf_shutdown_reactions = NULL;
int _lf_shutdown_reactions_size = 0;
// Array of pointers to reset triggers.
reaction_t** _lf_reset_reactions = NULL;
int _lf_reset_reactions_size = 0;
void _lf_initialize_trigger_objects() {
    // Initialize the _lf_clock
    lf_initialize_clock();
    int _lf_startup_reactions_count = 0;
    SUPPRESS_UNUSED_WARNING(_lf_startup_reactions_count);
    int _lf_shutdown_reactions_count = 0;
    SUPPRESS_UNUSED_WARNING(_lf_shutdown_reactions_count);
    int _lf_reset_reactions_count = 0;
    SUPPRESS_UNUSED_WARNING(_lf_reset_reactions_count);
    int _lf_timer_triggers_count = 0;
    SUPPRESS_UNUSED_WARNING(_lf_timer_triggers_count);
    int _lf_tokens_with_ref_count_count = 0;
    SUPPRESS_UNUSED_WARNING(_lf_tokens_with_ref_count_count);
    int bank_index;
    SUPPRESS_UNUSED_WARNING(bank_index);
    helloworld_main_self_t* helloworld_main_self[1];
    SUPPRESS_UNUSED_WARNING(helloworld_main_self);
    // ***** Start initializing HelloWorld of class HelloWorld
    helloworld_main_self[0] = new_HelloWorld();
    bank_index = 0; SUPPRESS_UNUSED_WARNING(bank_index);
    // Initializing timer HelloWorld.t.
    helloworld_main_self[0]->_lf__t.offset = SEC(1);
    helloworld_main_self[0]->_lf__t.period = SEC(1);
    _lf_timer_triggers[_lf_timer_triggers_count++] = &helloworld_main_self[0]->_lf__t;
    helloworld_main_self[0]->_lf__t.mode = NULL;
    helloworld_main_self[0]->_lf__reaction_0.deadline = NEVER;
    //***** End initializing HelloWorld
    // **** Start deferred initialize for HelloWorld
    {
        // Total number of outputs (single ports and multiport channels)
        // produced by reaction_0 of HelloWorld.
        helloworld_main_self[0]->_lf__reaction_0.num_outputs = 0;
        {
            int count = 0; SUPPRESS_UNUSED_WARNING(count);
        }
        
        // ** End initialization for reaction 0 of HelloWorld
    }
    // **** End of deferred initialize for HelloWorld
    // **** Start non-nested deferred initialize for HelloWorld
    // **** End of non-nested deferred initialize for HelloWorld
    // Connect inputs and outputs for reactor HelloWorld.
    // Set reaction priorities for ReactorInstance HelloWorld
    {
        helloworld_main_self[0]->_lf__reaction_0.chain_id = 1;
        // index is the OR of level 0 and 
        // deadline 9223372036854775807 shifted left 16 bits.
        helloworld_main_self[0]->_lf__reaction_0.index = 0xffffffffffff0000LL;
    }
    // Initialize the scheduler
    size_t num_reactions_per_level[1] = 
        {1};
    sched_params_t sched_params = (sched_params_t) {
                            .num_reactions_per_level = &num_reactions_per_level[0],
                            .num_reactions_per_level_size = (size_t) 1};
    lf_sched_init(
        (size_t)_lf_number_of_workers,
        &sched_params
    );
    #ifdef EXECUTABLE_PREAMBLE
    _lf_executable_preamble();
    #endif
    #ifdef FEDERATED
    initialize_triggers_for_federate();
    #endif // FEDERATED
}
void _lf_trigger_startup_reactions() {}
void _lf_initialize_timers() {
    for (int i = 0; i < _lf_timer_triggers_size; i++) {
        if (_lf_timer_triggers[i] != NULL) {
            _lf_initialize_timer(_lf_timer_triggers[i]);
        }
    }
}
void logical_tag_complete(tag_t tag_to_send) {
#ifdef FEDERATED_CENTRALIZED
        _lf_logical_tag_complete(tag_to_send);
#endif // FEDERATED_CENTRALIZED

}
bool _lf_trigger_shutdown_reactions() {
    return false;
}
#ifndef FEDERATED
void terminate_execution() {}
#endif