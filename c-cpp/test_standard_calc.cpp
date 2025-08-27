#include "stdio.h"
#include "cutest/CuTest.h"
#include "standard_calc.h"

/**************** Tests for bound_to_180() *******************/
void test_bound_basic1(CuTest *tc) {
    CuAssertDblEquals(tc, 0, bound_to_180(0), 0.0001);
    CuAssertDblEquals(tc, -180, bound_to_180(-180), 0.0001);
    CuAssertDblEquals(tc, -30, bound_to_180(-30), 0.0001);
    CuAssertDblEquals(tc, 60, bound_to_180(60), 0.0001);
    CuAssertDblEquals(tc, 135, bound_to_180(135), 0.0001);
    CuAssertDblEquals(tc, -160, bound_to_180(200), 0.0001);
    CuAssertDblEquals(tc, -180, bound_to_180(180), 0.0001);
    CuAssertDblEquals(tc, -180, bound_to_180(540), 0.0001);

    CuAssertDblEquals(tc, 0.0, bound_to_180(0), 0.0001);
    CuAssertDblEquals(tc, -180.0, bound_to_180(-180), 0.0001);
    CuAssertDblEquals(tc, 179.9999, bound_to_180(179.9999), 0.0001);
    CuAssertDblEquals(tc, -179.9999, bound_to_180(-179.9999), 0.0001);
    CuAssertDblEquals(tc, -179.0, bound_to_180(181), 0.0001);
    CuAssertDblEquals(tc, 170.0, bound_to_180(-190), 0.0001);
    CuAssertDblEquals(tc, -160.0, bound_to_180(200), 0.0001);
    CuAssertDblEquals(tc, 135.0, bound_to_180(135), 0.0001);
    CuAssertDblEquals(tc, -135.0, bound_to_180(225), 0.0001);
    CuAssertDblEquals(tc, -90.0, bound_to_180(270), 0.0001);
    CuAssertDblEquals(tc, 90.0, bound_to_180(-270), 0.0001);
    CuAssertDblEquals(tc, 0.0, bound_to_180(360), 0.0001);
    CuAssertDblEquals(tc, 0.0, bound_to_180(-360), 0.0001);
    CuAssertDblEquals(tc, 10.0, bound_to_180(370), 0.0001);
    CuAssertDblEquals(tc, -10.0, bound_to_180(-370), 0.0001);
    CuAssertDblEquals(tc, -90.0, bound_to_180(990), 0.0001);
    CuAssertDblEquals(tc, 90.0, bound_to_180(-990), 0.0001);
    CuAssertDblEquals(tc, 0.0, bound_to_180(720), 0.0001);
    CuAssertDblEquals(tc, 0.0, bound_to_180(-720), 0.0001);
}

/**************** Tests for is_angle_between() *******************/
void test_between_basic1(CuTest *tc) {
    CuAssertTrue(tc, is_angle_between(0, 1, 2));
}

int main(int argc, char const *argv[]) {
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, test_bound_basic1);
    SUITE_ADD_TEST(suite, test_between_basic1);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    return suite->failCount > 0 ? 1 : 0;
}
