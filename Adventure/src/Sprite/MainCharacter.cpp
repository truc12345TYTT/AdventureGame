#include "MainCharacter.h"
#include "TextureManager.h"
#include "Inputs.h"
#include "Camera.h"

#include <iostream>

#define FRAME_IDE 11
#define FRAME_DOUBLE_JUMP 6
#define FRAME_FALL 1
#define FRAME_HIT 7
#define FRAME_JUMP 1
#define FRAME_RUN 12
#define FARME_WALL_JUMP 5

#define FIRST_ROW 1

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

#define NUM_ROW 45
#define NUM_COL 80

#define JUMP_SIZE 64

#define FORCE_JUMP 9.9

MainCharacter::MainCharacter(Properties* props) :  Character(props){

    m_Animation = new Animation();
    m_RigidBody = new RigidBody();

    float px = props->X + props->Width/2;
    float py = props->Y + props->Height/2;
    m_Origin = new Point(px, py);

    m_Animation->SetProps(m_TextureID, FIRST_ROW, 50, FRAME_IDE, m_Flip);
    m_JumpMusic = Mix_LoadWAV("Music/mixkit-player-jumping-in-a-video-game-2043.wav");
    if (m_JumpMusic == nullptr) std::cout << Mix_GetError();

}


void MainCharacter::Draw(){

    m_Animation->Draw(m_Transform->X , m_Transform->Y, m_Width, m_Height);
}

void MainCharacter::Action(float dt){
    //std::cout << m_IsMoveDown;
    if (m_IsMoveDown){
        m_RigidBody->ApplyForceY(DOWN);
        float Move = m_RigidBody->GetPosition().Y;
        if (Move < 0) Move = 0;

        int row = int((GetOrigin()->Y + Camera::GetInstance()->GetPosition().Y + Move)/16);
        int col = int((GetOrigin()->X + Camera::GetInstance()->GetPosition().X)/16);
        SetIsMove();

        if (m_IsMoveDown && m_TileValue[row][col] == 0) {m_Transform->Y += Move;}
        m_Animation->SetProps("player_fall", FIRST_ROW, 50, FRAME_FALL, m_Flip);
    }

   // std::cout << "Check : " << Inputs::GetInstance()->GetKeyDown(SDL_SCANCODE_W) << std::endl;

    if (m_IsGrounded == true) m_IsJumping = false;

        if (Inputs::GetInstance()->GetKeyDown(SDL_SCANCODE_A)){
            std::cout << "GET KEY A!\n";
            m_RigidBody->ApplyForceX(LEFT*5);
            float Move = m_RigidBody->GetPosition().X;
            m_Flip = SDL_FLIP_HORIZONTAL;
            if (Move > 0) Move = -5;
            std::cout << "LEFT: " << Move << std::endl;
            int row = int((GetOrigin()->Y + Camera::GetInstance()->GetPosition().Y)/16);
            int col = int((GetOrigin()->X + Camera::GetInstance()->GetPosition().X + Move)/16);
            SetIsMove();

            if (m_IsMoveLeft && m_TileValue[row][col] == 0) m_Transform->X += Move;
            m_Animation->SetProps("player_run", FIRST_ROW, 50, FRAME_RUN, m_Flip);
        }

        if (Inputs::GetInstance()->GetKeyDown(SDL_SCANCODE_D)){
            m_RigidBody->ApplyForceX(RIGHT*5);
            std::cout << "GET KEY A!\n";
            float Move = m_RigidBody->GetPosition().X;
            m_Flip = SDL_FLIP_NONE;
            if (Move < 0) Move = 5;
            std::cout << "RIGHT: " << Move << std::endl;
            int row = int((GetOrigin()->Y + Camera::GetInstance()->GetPosition().Y)/16);
            int col = int((GetOrigin()->X + Camera::GetInstance()->GetPosition().X + Move)/16);
            SetIsMove();

            if (m_IsMoveRight && m_TileValue[row][col] == 0) m_Transform->X += Move;
            m_Animation->SetProps("player_run", FIRST_ROW, 50, FRAME_RUN, m_Flip);
        }

}

void MainCharacter::Update(float dt){
    m_Animation->SetProps("player", FIRST_ROW, 50, FRAME_IDE, m_Flip);
    SetIsMove();
    m_RigidBody->Update(dt);

    Action(dt);

    m_Origin->X = m_Transform->X + m_Width/2;
    m_Origin->Y = m_Transform->Y + m_Height/2;

    m_IsMoveUp = true;
    m_IsMoveDown = true;
    m_IsMoveLeft = true;
    m_IsMoveRight = true;

    m_Animation->Update();
}

void MainCharacter::Clean(){

    TextureManager::GetInstance()->Clean();
}
bool MainCharacter::GetIsJumping(){
    if (m_IsGrounded == true){
        if (Inputs::GetInstance()->GetKeyDown(SDL_SCANCODE_W)){
            m_IsJumping = true;
            m_RigidBody->ApplyForceY(UP*FORCE_JUMP);

            int row = int((GetOrigin()->Y + Camera::GetInstance()->GetPosition().Y - 50)/16);
            int col = int((GetOrigin()->X + Camera::GetInstance()->GetPosition().X)/16);
            SetIsMove();
           // m_Animation->SetProps("player_jump", FIRST_ROW, 50, FRAME_JUMP, m_Flip);
            if (m_IsMoveUp && m_TileValue[row][col] == 0){
                Mix_PlayChannel(-1, m_JumpMusic, 1);
                m_IsGrounded = false;
                return true;
            }
        }
    }
    return false;
}

void MainCharacter::Die()
{
    m_Die++;
    m_Animation->SetProps("player_hit", FIRST_ROW, 50, FRAME_HIT, m_Flip);
}


