#pragma once
#include"BaseFunc.h"
#include"Ground.h"
#include"Player.h"
#include"Collider.h"
#include"Saw.h"
#include"Key.h"
#include"Spike.h"
#include"Box.h"
#include"meteorite.h"
#include"bullet.h"
class Map {
public:
    Map();
    ~Map();
    //render
    void loadMap(std::string path);
    void Render();
    void RenderBackground();
    void RenderGrounds();
    void RenderSaw();
    void SpikeRender();
    void RenderBox();
    void RenderMeteorie();
    void RenderBullet();
    //update
    void Update(const Uint32& deltaTime);
    void UpdateSaw(const Uint32& deltaTime);
    void UpdateBox(const Uint32& deltaTime);
    void UpdateMeteorie();
    void UpdateBullet();
    //collider
    void Meteotie_check_Player(Player* player);
    void Ground_Check_Player(Player*player);
    void Wall_check_Player(Player* player);
    void Bullet_check_player(Player* player);
    bool LevelUp = false;
    Key* key;

private:
    
    std::vector<meteorite*>meteorie;
    std::vector<Box*> boxes;
    std::vector<Saw*> saws;
    std::vector<Spike*> spikes;
    std::vector<Bullet*> bullet;
    int width, height;
    Ground** grounds;
    Texture* backGround;
};