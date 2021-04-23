// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root
// for more information.

#ifndef NOVELRT_EXPERIMENTAL_GRAPHICS_H
#define NOVELRT_EXPERIMENTAL_GRAPHICS_H

/**
 * @brief The experimental Graphics plugin API. Comes with built-in support for the ECS.
 */
namespace NovelRT::Experimental::Graphics
{
    enum class ShaderProgramKind : uint32_t;
    class GraphicsDeviceObject;
    enum class GraphicsResourceCpuAccessKind : uint32_t;
    enum class GraphicsSurfaceKind : uint32_t;
    class IGraphicsSurface;
    class ILLGraphicsDevice;
    class LLGraphicsResource;
    class LLGraphicsBuffer;
    class LLGraphicsTexture;
    class ShaderProgram;
}

//Graphics dependencies
#include <cstdint>
#include <vector>
#include <memory>
#include <optional>
#include <filesystem>
#include <gsl/span>
#include <string>
#include <utility>
#include "../../Graphics/RGBAConfig.h"
#include "../../Maths/GeoVector2F.h"
#include "../../Maths/GeoVector3F.h"
#include "../../Maths/GeoVector4F.h"
#include "../../Maths/GeoMatrix4x4F.h"
#include "../../Graphics/RGBAConfig.h"
#include "../../Utilities/Event.h"

//Graphics types



#include "ShaderProgramKind.h"
#include "EcsDefaultRenderingComponentTypes.h"
#include "EcsDefaultRenderingSystem.h"
#include "GraphicsDeviceObject.h"
#include "GraphicsResourceCpuAccessKind.h"
#include "GraphicsSurfaceKind.h"
#include "IGraphicsSurface.h"
#include "ILLGraphicsDevice.h"
#include "LLGraphicsResource.h"
#include "LLGraphicsBuffer.h"
#include "LLGraphicsResourceViewContainer.h"
#include "LLGraphicsTexture.h"
#include "ShaderProgram.h"

#endif // !NOVELRT_EXPERIMENTAL_GRAPHICS_H
