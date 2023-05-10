#include "LinhTinh.h"
#include "TextureManager.h"

#define FRUIRT_FRAME 17
#define FIRST_ROW 1

LinhTinh::LinhTinh(Properties* props) :  Character(props){

    m_Animation = new Animation();

    m_Animation->SetProps(m_TextureID, FIRST_ROW, 50, FRUIRT_FRAME, m_Flip);

}

void LinhTinh::Draw(){
    m_Animation->Draw(m_Transform->X , m_Transform->Y, m_Width, m_Height);

}

void LinhTinh::Update(float dt){
    if (m_IsFruit == true) Clean();
}

void LinhTinh::Clean(){
    TextureManager::GetInstance()->Clean();
}
