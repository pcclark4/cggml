#include "main_test.h"
#include <stdlib.h>

int main(void)
{
    int32_t numFailed;
    SRunner *sr;

    sr = srunner_create(point_2_suite());
    /* CK_NOFORK allows us to attach debugger while running tests
     * https://github.com/vndmtrx/check-cmake-example */
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_add_suite(sr, point_3_suite());
    srunner_add_suite(sr, sort_suite());

    srunner_run_all(sr, CK_VERBOSE);
    numFailed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (numFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
