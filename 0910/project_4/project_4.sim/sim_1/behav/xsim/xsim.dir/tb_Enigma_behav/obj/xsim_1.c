/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2013 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/


#include "iki.h"
#include <string.h>
#include <math.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2013 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/


#include "iki.h"
#include <string.h>
#include <math.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
typedef void (*funcp)(char *, char *);
extern int main(int, char**);
extern void execute_163(char*, char *);
extern void execute_164(char*, char *);
extern void vlog_const_rhs_process_execute_0_fast_no_reg_no_agg(char*, char*, char*);
extern void execute_756(char*, char *);
extern void execute_757(char*, char *);
extern void execute_758(char*, char *);
extern void execute_759(char*, char *);
extern void execute_760(char*, char *);
extern void execute_761(char*, char *);
extern void execute_762(char*, char *);
extern void execute_763(char*, char *);
extern void execute_764(char*, char *);
extern void execute_765(char*, char *);
extern void execute_766(char*, char *);
extern void execute_767(char*, char *);
extern void execute_768(char*, char *);
extern void execute_769(char*, char *);
extern void execute_770(char*, char *);
extern void execute_3(char*, char *);
extern void execute_4(char*, char *);
extern void execute_6(char*, char *);
extern void execute_7(char*, char *);
extern void execute_9(char*, char *);
extern void execute_10(char*, char *);
extern void vlog_simple_process_execute_0_fast_no_reg_no_agg(char*, char*, char*);
extern void execute_170(char*, char *);
extern void execute_171(char*, char *);
extern void execute_172(char*, char *);
extern void execute_173(char*, char *);
extern void execute_174(char*, char *);
extern void execute_196(char*, char *);
extern void execute_198(char*, char *);
extern void execute_199(char*, char *);
extern void execute_200(char*, char *);
extern void execute_201(char*, char *);
extern void execute_202(char*, char *);
extern void execute_250(char*, char *);
extern void execute_251(char*, char *);
extern void execute_299(char*, char *);
extern void execute_203(char*, char *);
extern void execute_204(char*, char *);
extern void execute_205(char*, char *);
extern void execute_304(char*, char *);
extern void execute_305(char*, char *);
extern void execute_306(char*, char *);
extern void execute_307(char*, char *);
extern void execute_308(char*, char *);
extern void execute_410(char*, char *);
extern void execute_411(char*, char *);
extern void execute_412(char*, char *);
extern void execute_413(char*, char *);
extern void execute_414(char*, char *);
extern void execute_436(char*, char *);
extern void execute_460(char*, char *);
extern void execute_461(char*, char *);
extern void execute_462(char*, char *);
extern void execute_463(char*, char *);
extern void execute_464(char*, char *);
extern void execute_493(char*, char *);
extern void execute_494(char*, char *);
extern void execute_495(char*, char *);
extern void execute_496(char*, char *);
extern void execute_497(char*, char *);
extern void execute_599(char*, char *);
extern void execute_600(char*, char *);
extern void execute_601(char*, char *);
extern void execute_602(char*, char *);
extern void execute_603(char*, char *);
extern void execute_705(char*, char *);
extern void execute_706(char*, char *);
extern void execute_707(char*, char *);
extern void execute_708(char*, char *);
extern void execute_709(char*, char *);
extern void execute_166(char*, char *);
extern void execute_167(char*, char *);
extern void execute_168(char*, char *);
extern void execute_169(char*, char *);
extern void execute_771(char*, char *);
extern void execute_772(char*, char *);
extern void execute_773(char*, char *);
extern void execute_774(char*, char *);
extern void execute_775(char*, char *);
extern void execute_776(char*, char *);
extern void vlog_transfunc_eventcallback(char*, char*, unsigned, unsigned, unsigned, char *);
funcp funcTab[84] = {(funcp)execute_163, (funcp)execute_164, (funcp)vlog_const_rhs_process_execute_0_fast_no_reg_no_agg, (funcp)execute_756, (funcp)execute_757, (funcp)execute_758, (funcp)execute_759, (funcp)execute_760, (funcp)execute_761, (funcp)execute_762, (funcp)execute_763, (funcp)execute_764, (funcp)execute_765, (funcp)execute_766, (funcp)execute_767, (funcp)execute_768, (funcp)execute_769, (funcp)execute_770, (funcp)execute_3, (funcp)execute_4, (funcp)execute_6, (funcp)execute_7, (funcp)execute_9, (funcp)execute_10, (funcp)vlog_simple_process_execute_0_fast_no_reg_no_agg, (funcp)execute_170, (funcp)execute_171, (funcp)execute_172, (funcp)execute_173, (funcp)execute_174, (funcp)execute_196, (funcp)execute_198, (funcp)execute_199, (funcp)execute_200, (funcp)execute_201, (funcp)execute_202, (funcp)execute_250, (funcp)execute_251, (funcp)execute_299, (funcp)execute_203, (funcp)execute_204, (funcp)execute_205, (funcp)execute_304, (funcp)execute_305, (funcp)execute_306, (funcp)execute_307, (funcp)execute_308, (funcp)execute_410, (funcp)execute_411, (funcp)execute_412, (funcp)execute_413, (funcp)execute_414, (funcp)execute_436, (funcp)execute_460, (funcp)execute_461, (funcp)execute_462, (funcp)execute_463, (funcp)execute_464, (funcp)execute_493, (funcp)execute_494, (funcp)execute_495, (funcp)execute_496, (funcp)execute_497, (funcp)execute_599, (funcp)execute_600, (funcp)execute_601, (funcp)execute_602, (funcp)execute_603, (funcp)execute_705, (funcp)execute_706, (funcp)execute_707, (funcp)execute_708, (funcp)execute_709, (funcp)execute_166, (funcp)execute_167, (funcp)execute_168, (funcp)execute_169, (funcp)execute_771, (funcp)execute_772, (funcp)execute_773, (funcp)execute_774, (funcp)execute_775, (funcp)execute_776, (funcp)vlog_transfunc_eventcallback};
const int NumRelocateId= 84;

void relocate(char *dp)
{
	iki_relocate(dp, "xsim.dir/tb_Enigma_behav/xsim.reloc",  (void **)funcTab, 84);

	/*Populate the transaction function pointer field in the whole net structure */
}

void sensitize(char *dp)
{
	iki_sensitize(dp, "xsim.dir/tb_Enigma_behav/xsim.reloc");
}

	// Initialize Verilog nets in mixed simulation, for the cases when the value at time 0 should be propagated from the mixed language Vhdl net

void wrapper_func_0(char *dp)

{

}

void simulate(char *dp)
{
		iki_schedule_processes_at_time_zero(dp, "xsim.dir/tb_Enigma_behav/xsim.reloc");
	wrapper_func_0(dp);

	iki_execute_processes();

	// Schedule resolution functions for the multiply driven Verilog nets that have strength
	// Schedule transaction functions for the singly driven Verilog nets that have strength

}
#include "iki_bridge.h"
void relocate(char *);

void sensitize(char *);

void simulate(char *);

extern SYSTEMCLIB_IMP_DLLSPEC void local_register_implicit_channel(int, char*);
extern void implicit_HDL_SCinstatiate();

extern SYSTEMCLIB_IMP_DLLSPEC int xsim_argc_copy ;
extern SYSTEMCLIB_IMP_DLLSPEC char** xsim_argv_copy ;

int main(int argc, char **argv)
{
    iki_heap_initialize("ms", "isimmm", 0, 2147483648) ;
    iki_set_sv_type_file_path_name("xsim.dir/tb_Enigma_behav/xsim.svtype");
    iki_set_crvs_dump_file_path_name("xsim.dir/tb_Enigma_behav/xsim.crvsdump");
    void* design_handle = iki_create_design("xsim.dir/tb_Enigma_behav/xsim.mem", (void *)relocate, (void *)sensitize, (void *)simulate, 0, isimBridge_getWdbWriter(), 0, argc, argv);
     iki_set_rc_trial_count(100);
    (void) design_handle;
    return iki_simulate_design();
}
