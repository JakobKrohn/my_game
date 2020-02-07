#ifndef COMPONENTS_SPRITE_HPP
#define COMPONENTS_SPRITE_HPP

#include "GraphicsInterface/Element_I.hpp"
#include "Drawable/Drawable.hpp"
#include "Sprite_I.hpp"

namespace components
{

class Sprite : public Element_I, public Sprite_I
{
public:
    explicit Sprite(std::vector<std::shared_ptr<Drawable>> drawables);
    explicit Sprite(double sizeConstant);
    ~Sprite();

    // Element_I
    std::vector<std::shared_ptr<Image_I>> getAllImages();
    std::vector<const char *> getAllAssets() const;
    double getSizeConstant() const;
    uint getCurrentIndex();
    // void resizeEvent(uint32_t windowWidth, uint32_t windowHeight);

    // Sprite_I
    void setState(sprite_state state);
    sprite_state getState() const;
    void setIdleAssets(std::vector<const char *> &&assets);
    void setAttackAssets(std::vector<const char *> &&assets);
    void setMovingAssets(std::vector<const char *> &&assets);
    void setReloadAssets(std::vector<const char *> &&assets);
    void setFiringAssets(std::vector<const char *> &&assets);

private:
    std::vector<std::shared_ptr<Drawable>> m_drawables;
    
    // std::optional?
    std::vector<std::vector<const char *>> m_assets;
    // std::vector<const char*> m_idleAssets;
    // std::vector<const char*> m_attackAssets;
    // std::vector<const char*> m_movingAssets;
    // std::vector<const char*> m_reloadAssets;
    // std::vector<const char*> m_firingAssets;
    sprite_state m_state;
    const double m_sizeConstant;

    void setAssetsAt(unsigned int index, std::vector<const char *> &&assets);
};

} // namespace components

#endif // COMPONENTS_SPRITE_HPP