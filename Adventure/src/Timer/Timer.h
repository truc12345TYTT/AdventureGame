#ifndef TIMER_H
#define TIMER_H

const float TAGET_FPS = 60;
const float TAGET_DELTATIME = 0.5;

class Timer
{
    public:
        static Timer* GetInstance(){return s_Instance = (s_Instance != nullptr)? s_Instance : new Timer(); }

        void Tick();
        inline float GetDeltaTime(){return m_DeltaTime;};

    private:
        Timer(){};
        static Timer* s_Instance;
        float m_DeltaTime;
        float m_LastTime;
};

#endif // TIMER_H
