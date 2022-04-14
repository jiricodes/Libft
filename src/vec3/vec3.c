/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:11:21 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/14 17:43:07 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

/*
** Bevy inspired Vec3
** 
** A 3-dimensional vector without SIMD support.
** https://docs.rs/bevy/latest/bevy/prelude/struct.Vec3.html
*/

/*
** Constants *******************************************************************
*/

static const t_vec3 g_vec3_zero = {0.0, 0.0, 0.0};
static const t_vec3 g_vec3_one = {1.0, 1.0, 1.0};
static const t_vec3 g_vec3_x = {1.0, 0.0, 0.0};
static const t_vec3 g_vec3_y = {0.0, 1.0, 0.0};
static const t_vec3 g_vec3_z = {0.0, 0.0, 1.0};
static const t_vec3 g_vec3_axes[3] = {{1.0, 0.0, 0.0},
									{0.0, 1.0, 0.0},
									{0.0, 0.0, 1.0}};

/*
** Functions *******************************************************************
*/
t_vec3 *vec3_new(float x, float y, float z) {
	t_vec3 *vec;
	vec = (t_vec3 *)malloc(sizeof(t_vec3));
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

void vec3_free(t_vec3 *vec) {
	free(vec);
}

/*
** Creates a 4D vector from `self` and the given w value.
*/
// t_vec4 *vec3_extend(t_vec3 *self, float w) {
	

// }

/*
** Creates a `Vec2` from the `x` and `y` elements of self, discarding `z`.
*/
// t_vec2 *vec3_truncate(t_vec3 *self) {

// }

// t_vec3 *vec3_cross(t_vec3 *self, t_vec3 *other) {
//	https://en.wikipedia.org/wiki/Cross_product#:~:text=The%20cross%20product%20a%20%C3%97,parallelogram%20that%20the%20vectors%20span.
// }

/**
 * @brief Multiplies the `vec3` with a float and returns new `vec3`
 * 
 * @param original Original vec3
 * @param scale float to multiply vec with
 * @return t_vec3* New multiplied vector
 */
t_vec3 *vec3_mul_float(t_vec3 *original, float scale) {
	return (vec3_new(original->x * scale, original->y * scale, original->z * scale));
}

/**
 * @brief Multiplies the `vec3` within self by the float
 * 
 * @param self Vec3 to multiply
 * @param scale float to multiply with
 */
void	vec3_mul_float_self(t_vec3 *self, float scale) {
	self->x *= scale;
	self->y *= scale;
	self->z *= scale;
}

t_vec3	*vec3_clone(t_vec3 *original) {
	return (vec3_new(original->x, original->y, original->z));
}

uint8_t vec3_eq(t_vec3 *self, t_vec3 *other) {
	return (self->x == other->x && \
			self->y == other->y && \
			self->z == other->z);
}

t_vec3 *vec3_splat(float value) {
	return (vec3_new(value, value, value));
}

t_vec3 *vec3_zero(float value) {
	return (vec3_new(value, value, value));
}