#ifndef PID_H
#define PID_H

class PID {
    public:
        PID(float Kp, float Kd, float Ki, float dt, float u_start, float e_start, float u_max, float u_min, float v_max);
        float calculate(float r, float y);

    private:
        float _Kp, _Kd, _Ki;
        float _last_e, _last_u, _dt;
        float _u_max, _u_min, _v_max;
};

#endif // PID_H