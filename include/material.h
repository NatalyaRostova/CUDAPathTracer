#ifndef MATERIAL_H_432528432
#define MATERIAL_H_432528432

#include <map>

#include "path_tracing_common.h"

enum MaterialType
{
    Diffuse = 0,
    Plastic,
    Mirror,
    Glass,
    Count
};

#define FUNC_TYPE_DEFINE_MATERIAL                                                                           \
    typedef void (*FuncEvalAttenuationAndCreateRayPtr)(Material & self, Float4 & position, Float4 & normal, \
                                                       Float4 & in_ray_dir, RayPayload & payload)

class Material {
private:
public:
    MaterialType type_;
    Float4 Kd_;
    float refractive_index_;
    float emit_intensity_;
    float smoothness_;
    float reflectivity_;

    __COMMON_GPU_CPU__ Material();

    FUNC_TYPE_DEFINE_MATERIAL;
    FuncEvalAttenuationAndCreateRayPtr EvalAttenuationAndCreateRay;
};
FUNC_TYPE_DEFINE_MATERIAL;
void MaterialMemCpyToGpu(Material *material_host, Material *material_gpu_handle);

#endif  // MATERIAL_H_432528432