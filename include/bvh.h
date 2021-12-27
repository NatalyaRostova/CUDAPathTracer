#ifndef PATH_TRACER_BVH_H
#define PATH_TRACER_BVH_H

#include <vector>

#include "object.h"
#include "path_tracing_common.h"

class BVHNode {
private:
public:
    float minx_;
    float miny_;
    float minz_;
    float maxx_;
    float maxy_;
    float maxz_;

    BVHNode *left_son_;
    BVHNode *right_son_;

    bool is_object_;  // 1表示当前bvh结点下有一个物体
    Object *obj_;
};

namespace poca_mus {
    // 根据物体指针数组建立BVH树, 返回根节点GPU Handle, 此操作会改变原数组
    BVHNode *BuildBVH(std::vector<Object *> & objs);

    // 根据物体指针数组更新BVH信息
    void UpdateBVHInfo(std::vector<Object *> & objs);

    // 在GPU中寻找距离光线最近的物体, 若未击中物体则返回nullptr
    __device__ Object *TraceRay(BVHNode * node, Ray & ray, ProceduralPrimitiveAttributes & attr);
}

#endif  // PATH_TRACER_BVH_H