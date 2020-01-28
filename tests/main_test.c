#include "main_test.h"
#include <stdlib.h>

int main(void)
{
    uint32_t numFailed;
    SRunner *sr;

    sr = srunner_create(point_2d_suite());
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_add_suite(sr, sort_suite());

    srunner_run_all(sr, CK_NORMAL);
    numFailed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (numFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}