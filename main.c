/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arajaona <arajaona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:55:12 by arajaona          #+#    #+#             */
/*   Updated: 2025/04/10 13:59:37 by arajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_objects	object;

    parse(ac, av[1], &object);
	// object.spheres = calloc(1, sizeof(t_spheres));
	// object.spheres->member = calloc(3, sizeof(t_sphere));
	// object.spheres->nb = 2;
	// object.spheres->index = 0;
	// object.spheres->member[0].sys.origine.x = 20;
	// object.spheres->member[0].sys.origine.y = 50;
	// object.spheres->member[0].sys.origine.z = 50;
	// object.spheres->member[0].color.r = 10;
	// object.spheres->member[0].color.g = 0;
	// object.spheres->member[0].color.b = 255;
	// object.spheres->member[0].diametre = 60;
	// object.spheres->member[1].sys.origine.x = -30;
	// object.spheres->member[1].sys.origine.y = 0;
	// object.spheres->member[1].sys.origine.z = 50;
	// object.spheres->member[1].color.r = 10;
	// object.spheres->member[1].color.g = 0;
	// object.spheres->member[1].color.b = 255;
	// object.spheres->member[1].diametre = 60;
	if (init_data(&data) == -1)
		return (1);
	event(&data);
	render(&data, object);
	mlx_loop(data.mlx);
	return (0);
    // t_objects	sample;

	// parse(ac, av[1], &sample);
	// printf("==================== CAMERA ======================\n");
	// printf("camera viewpoint: [%f %f %f]\n", sample.camera.sys.origine.x ,sample.camera.sys.origine.y ,sample.camera.sys.origine.z);
	// printf("camera normal: [%f %f %f]\n", sample.camera.normal.x ,sample.camera.normal.y ,sample.camera.normal.z);
	// printf("camera field of view : %f\n", sample.camera.fov);
	// printf("\n");
	// printf("\n");
	// printf("==================== LIGHT ======================\n");
	// printf("light point: [%f %f %f]\n", sample.light.sys.origine.x ,sample.light.sys.origine.y ,sample.light.sys.origine.z);
	// printf("light brightness ratio : %f\n", sample.light.brightness_ratio);
	// printf("\n");
	// printf("\n");
	// printf("==================== SPHERE ======================\n");
	// for (int i = 0; i < sample.spheres->nb; i++)
    // {
    //     printf("sphere[%d] center: [%f %f %f]\n", i, sample.spheres->member[i].sys.origine.x ,sample.spheres->member[i].sys.origine.y ,sample.spheres->member[i].sys.origine.z);
    //     printf("sphere[%d] diameter: %f\n", i, sample.spheres->member[i].diametre);
    //     printf("sphere[%d] RGB : [%d %d %d]\n", i, sample.spheres->member[i].color.r ,sample.spheres->member[i].color.g ,sample.spheres->member[i].color.b);
    // }
    // printf("\n");
	// printf("\n");
	// printf("==================== PLANE ======================\n");
	// printf("plane point: [%f %f %f]\n", sample.planes->member->pt.x ,sample.planes->member->pt.y ,sample.planes->member->pt.z);
	// printf("plane normal: [%f %f %f]\n", sample.planes->member->normal.x ,sample.planes->member->normal.y ,sample.planes->member->normal.z);
	// printf("plane RGB : [%d %d %d]\n", sample.planes->member->color.r ,sample.planes->member->color.g ,sample.planes->member->color.b);
	// printf("\n");
	// printf("\n");
	// printf("==================== CYLINDER ======================\n");
	// printf("cylinder center: [%f %f %f]\n", sample.cylindres->member->center.x ,sample.cylindres->member->center.y ,sample.cylindres->member->center.z);
	// printf("cylinder normal: [%f %f %f]\n", sample.cylindres->member->normal.x ,sample.cylindres->member->normal.y ,sample.cylindres->member->normal.z);
	// printf("cylinder diameter: %f\n", sample.cylindres->member->diametre);
	// printf("cylinder height: %f\n", sample.cylindres->member->height);
	// printf("cylinder RGB : [%d %d %d]\n", sample.cylindres->member->color.r ,sample.cylindres->member->color.g ,sample.cylindres->member->color.b);
	// ft_free_objects(&sample);
}