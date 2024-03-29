#include "search_tests.h"
#include <stdlib.h>

int main(void)
{
    int32_t numFailed;
    SRunner *sr  = srunner_create(nearest_neighbor_suite());
    /* CK_NOFORK allows us to attach debugger while running tests
     * https://github.com/vndmtrx/check-cmake-example */
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_NORMAL);
    numFailed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (numFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
