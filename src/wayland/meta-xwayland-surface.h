/*
 * Copyright (C) 2013 Intel Corporation
 * Copyright (C) 2013-2019 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "meta/types.h"
#include "wayland/meta-wayland-actor-surface.h"

#define META_TYPE_XWAYLAND_SURFACE (meta_xwayland_surface_get_type ())
G_DECLARE_FINAL_TYPE (MetaXwaylandSurface,
                      meta_xwayland_surface,
                      META, XWAYLAND_SURFACE,
                      MetaWaylandActorSurface)

void
meta_xwayland_surface_associate_with_window (MetaXwaylandSurface *xwayland_surface,
                                             MetaWindow          *window);
