/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:43:32 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/14 17:43:39 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <inttypes.h>

/**
 * @brief Bevy inspired Vec3
 * 
 * A 3-dimensional vector without SIMD support.
 * https://docs.rs/bevy/latest/bevy/prelude/struct.Vec3.html
 */
typedef struct	s_vec3
{
	float x;
	float y;
	float z;
}				t_vec3;

t_vec3  *vec3_new(float x, float y, float z);
void    vec3_free(t_vec3 *point);
t_vec3  *vec3_mul_float(t_vec3 *original, float scale);
void    vec3_mul_float_self(t_vec3 *self, float scale);
t_vec3  *vec3_clone(t_vec3 *original);
uint8_t vec3_eq(t_vec3 *self, t_vec3 *other);
t_vec3  *vec3_splat(float value);

# endif // VEC3_H