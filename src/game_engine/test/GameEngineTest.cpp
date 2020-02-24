#include <memory>
#include <future>
#include <chrono>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "GameEngine/GameEngine.hpp"
#include "InputEvent/InputEvent_I.hpp"
#include "GraphicsInterface/Graphics_I.hpp"
#include "GraphicsInterface/Text_I.hpp"

using namespace testing;

class MockInputEvent : public input_event::InputEvent_I
{
public:
    MOCK_METHOD(void, registerCallback, (std::function<void()>, input_event::input_key), (override));
    MOCK_METHOD(void, setExitCallback, (std::function<void()>));
    MOCK_METHOD(void, check, (), (override));
};

class MockGraphics : public Graphics_I
{
public:
    MOCK_METHOD(void, update, (), (override));
    MOCK_METHOD(void, addElement, (std::shared_ptr<Element_I>), (override));
    MOCK_METHOD(void, addImage, (std::shared_ptr<Image_I>), (override));
    MOCK_METHOD(std::shared_ptr<TileMap_I>, createTileMap, (const char *), (override));
    MOCK_METHOD(std::shared_ptr<Text_I>, createText, (const char *, uint8_t), (override));
    MOCK_METHOD(std::shared_ptr<uint32_t>, getWindowWidth, (), (const, override));
    MOCK_METHOD(std::shared_ptr<uint32_t>, getWindowHeight, (), (const, override));
    MOCK_METHOD(void, setResizeEventCallback, (std::function<void(uint32_t, uint32_t)>), (override));
};

class MockText : public Text_I
{
public:
    MOCK_METHOD(void, draw, (), (override));
    MOCK_METHOD(void, setText, (std::string), (override));
    MOCK_METHOD(void, setTextColor, (Color_T), (override));
    MOCK_METHOD(void, setLocation, (TextLocation), (override));
    MOCK_METHOD(void, drawBackground, (bool), (override));
    MOCK_METHOD(void, setBackground, (uint16_t, uint16_t, Color_T), (override));
};

// The fixture for testing class Foo.
class GameEngineTest : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    GameEngineTest()
    {
        // You can do set-up work for each test here.
        _input = std::make_shared<MockInputEvent>();
        _graphics = std::make_shared<MockGraphics>();
    }

    ~GameEngineTest() override
    {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    std::shared_ptr<MockInputEvent> _input;
    std::shared_ptr<MockGraphics> _graphics;
    // std::unique_ptr<game_engine::GameEngine> _engine;
    // game_engine::GameEngine *_engine;
    // game_engine::GameEngine engine = game_engine::GameEngine(nullptr, nullptr);
};

// Tests that Foo does Xyz.
TEST_F(GameEngineTest, Setup)
{
    auto _text = std::make_shared<MockText>();
    // Set escape exit
    EXPECT_CALL(*_input, setExitCallback(_))
        .Times(1);
    // Create background
    EXPECT_CALL(*_graphics, createTileMap(_))
        .Times(1);
    // Add player
    EXPECT_CALL(*_graphics, addElement(_))
        .Times(1);
    // Player movement
    EXPECT_CALL(*_input, registerCallback(_, _))
        .Times(AtLeast(1));
    // Create text
    EXPECT_CALL(*_graphics, createText(_, _))
        .Times(AtMost(2))
        .WillRepeatedly(Return(_text));
    // Text object calls
    EXPECT_CALL(*_text, setText(_))
        .Times(AtLeast(1));
    EXPECT_CALL(*_text, setTextColor(_))
        .Times(AtLeast(1));
    EXPECT_CALL(*_text, setLocation(_))
        .Times(AtLeast(1));
    // Resize event cb
    EXPECT_CALL(*_graphics, setResizeEventCallback(_))
        .Times(AtMost(1));

    game_engine::GameEngine engine(_input, _graphics);
}

TEST_F(GameEngineTest, StartStop)
{
    // game_engine::GameEngine engine(_input, _graphics);

    // EXPECT_CALL(*_graphics, update())
    //     .Times(testing::AtLeast(1));
    // EXPECT_CALL(*_input, check())
    //     .Times(testing::AtLeast(1));

    // auto handle = std::async(&game_engine::GameEngine::start, &engine);

    // using namespace std::chrono_literals;
    // std::this_thread::sleep_for(1s);

    // engine.exit();
    // handle.get();
}