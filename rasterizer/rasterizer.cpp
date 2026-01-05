#include "rasterizer.h"

namespace software_rasterizer
{

Rasterizer::Rasterizer(unsigned int width, unsigned int height)
    : m_framebuffer(width, height),
      m_options{ {0, 0, static_cast<float>(width), static_cast<float>(height)}, true, false }
{
    m_framebuffer.clear(RGBA8(0, 0, 0, 0));
}

DefaultFramebuffer &Rasterizer::framebuffer()
{
    return m_framebuffer;
}

Rasterizer::Options& Rasterizer::options()
{
    return m_options;
}

}
