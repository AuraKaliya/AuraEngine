#pragma once
#include <QMetaType>
namespace AuraUI {
//==================================相机方向====================================
enum class AuraOpenGLCameraDirection{
    Forward,
    Backward,
    Up,
    Down,
    Right,
    Left
};
//==================================相机方向====================================

//==================================初始化策略====================================
enum class InitStratagy{
    PositionOnly,
    PositionLink,
    PositionColor,
    PositionNormal,
    PositionDirectionColor
};
//==================================初始化策略====================================

//==================================几何体类型====================================
enum class GeometryType{
    None,
    Line,
    Cube,
    Column,
    Torus,
};
//==================================几何体类型====================================

//==================================绘制策略====================================
enum class ModelDrawStratagy:int
{
    Point=0,
    Line=1,
    Triangle=2,
};


//==================================绘制策略====================================

//==================================模型渲染策略====================================
enum class ModelRenderStratagy:int
{
    None=0 ,
    RenderNormal= 1,
    RenderSelect= 1<<1,
    RenderLine = 1<<2,
    RenderPoint= 1<<3,
};
// 定义类型转换运算符
inline ModelRenderStratagy operator|(ModelRenderStratagy lhs, ModelRenderStratagy rhs)
{
    return static_cast<ModelRenderStratagy>(
        static_cast<int>(lhs) | static_cast<int>(rhs)
    );
}
inline ModelRenderStratagy& operator|=(ModelRenderStratagy& lhs, ModelRenderStratagy rhs)
{
    lhs = lhs | rhs;
    return lhs;
}
// 定义按位与运算符
inline bool operator&(ModelRenderStratagy lhs, ModelRenderStratagy rhs)
{
    return static_cast<int>(lhs) & static_cast<int>(rhs);
}
//==================================模型渲染策略====================================end


//==================================模型位置更新策略====================================end
enum class ModelPositionUpdateStratagy
{
    Set,
    Add,
};

enum class ModelBoundingBoxType
{
    AABB,
    OBB,
};
//==================================模型位置更新策略====================================end




}//AuraUI
Q_DECLARE_METATYPE(AuraUI::ModelRenderStratagy)
Q_DECLARE_METATYPE(AuraUI::ModelDrawStratagy)

