/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */

#pragma once

#include "config.h"

#include "backends/meta-backend-types.h"
#include "meta/meta-shaped-texture.h"
#include "meta/window.h"

G_BEGIN_DECLS

#define META_TYPE_SURFACE_ACTOR (meta_surface_actor_get_type ())
G_DECLARE_DERIVABLE_TYPE (MetaSurfaceActor,
                          meta_surface_actor,
                          META, SURFACE_ACTOR,
                          ClutterActor)

struct _MetaSurfaceActorClass
{
  /*< private >*/
  ClutterActorClass parent_class;

  void     (* process_damage)    (MetaSurfaceActor *actor,
                                  int x, int y, int width, int height);
  gboolean (* is_opaque)         (MetaSurfaceActor *actor);
};

MetaShapedTexture *meta_surface_actor_get_texture (MetaSurfaceActor *self);

void meta_surface_actor_update_area (MetaSurfaceActor *self,
                                     int               x,
                                     int               y,
                                     int               width,
                                     int               height);

gboolean meta_surface_actor_is_obscured (MetaSurfaceActor *self);

gboolean meta_surface_actor_is_effectively_obscured (MetaSurfaceActor *self);

gboolean meta_surface_actor_is_obscured_on_stage_view (MetaSurfaceActor *self,
                                                       ClutterStageView *stage_view,
                                                       float            *unobscurred_fraction);

gboolean meta_surface_actor_contains_rect (MetaSurfaceActor *surface_actor,
                                           MetaRectangle    *rect);

void meta_surface_actor_set_input_region (MetaSurfaceActor *self,
                                          cairo_region_t   *region);
void meta_surface_actor_set_opaque_region (MetaSurfaceActor *self,
                                           cairo_region_t   *region);
cairo_region_t * meta_surface_actor_get_opaque_region (MetaSurfaceActor *self);

void meta_surface_actor_process_damage (MetaSurfaceActor *actor,
                                        int x, int y, int width, int height);

gboolean meta_surface_actor_is_opaque (MetaSurfaceActor *actor);

gboolean meta_surface_actor_is_frozen (MetaSurfaceActor *actor);
void meta_surface_actor_set_frozen (MetaSurfaceActor *actor,
                                    gboolean          frozen);
G_END_DECLS
