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
	// normalize to [0, 360)
	float first_angle_360 = to_360(first_angle);
	float middle_angle_360 = to_360(middle_angle);
	float second_angle_360 = to_360(second_angle);

	// normalize to get angle_a <= angle_b
	float angle_a = second_angle_360;
	float angle_b = first_angle_360;
	if (first_angle_360 <= second_angle_360) {
		angle_a = first_angle_360;
		angle_b = second_angle_360;
	}

	// find reflex region
	float angle_between_a_and_b = angle_b - angle_a;
	bool is_middle_angle_between_a_and_b  = angle_a <= middle_angle_360 
							&& middle_angle_360 <= angle_b;
	if (angle_between_a_and_b == 180) {
		return true;
	} else if (angle_between_a_and_b > 180) { // a -> b area is reflex
		// implicitly, angle_between_a_and_b will always be less than 360
		// since, we normalized at the start
		return !is_middle_angle_between_a_and_b;
	} else {
		return is_middle_angle_between_a_and_b;
	}
}
