#include "stdbool.h"
#include "standard_calc.h"

/**
 * Maps the given angle to the range [0,360)
 */
float to_360(float angle) {
	if (angle >= 0) {	// positive
		int factor = (int) angle / 360;
		return angle - (factor * 360);
	} else {		// negative number
		int factor = ((int) angle * -1) / 360;
		return angle + ((factor+1) * 360);
	}
}

/** * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
	float val_360 = to_360(angle);
	if (val_360 >= 180) {
		return val_360-360;
	} else {
		return val_360;
	}
}

/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 * 
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {
    return true;
}
