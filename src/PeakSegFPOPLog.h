/* -*- compile-command: "R CMD INSTALL .." -*- */

#define ERROR_PENALTY_NOT_FINITE 1
#define ERROR_PENALTY_NEGATIVE 2
#define ERROR_UNABLE_TO_OPEN_BEDGRAPH 3
#define ERROR_NOT_ENOUGH_COLUMNS 4
#define ERROR_NON_INTEGER_DATA 5
#define ERROR_INCONSISTENT_CHROMSTART_CHROMEND 6
#define ERROR_WRITING_COST_FUNCTIONS 7
#define ERROR_WRITING_LOSS_OUTPUT 8
#define ERROR_NO_DATA 9
#define ERROR_PENALTY_NOT_NUMERIC 10
#define ERROR_WRITING_SEGMENTS_OUTPUT 11

int PeakSegFPOP_disk(char *, char *, char *);

