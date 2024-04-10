#include "PID.h"

PID::PID(float Kp, float Kd, float Ki, float dt, float u_start, float e_start, float u_max, float u_min, float v_max) 
    : _Kp(Kp), _Kd(Kd), _Ki(Ki), _dt(dt), _last_u(u_start), _last_e(e_start), _u_max(u_max), _u_min(u_min), _v_max(v_max) {
    ;
}

float PID::calculate(float r, float y) {
    float e = r - y;
    float de = e - _last_e;

    float P = _Kp * de;

    float I = _Ki * e * _dt;

    float D = _Kd * de/_dt;

    float du = P + I + D;

    if(_last_u + du > _u_max) {
        du = _u_max - _last_u;
    }
    else if(_last_u + du < _u_min) {
        du = _u_min - _last_u;
    }
    else if(du > _v_max * _dt) {
        du = _v_max * _dt;
    }

    float u = _last_u + du;

    _last_e = e;
    _last_u = u;

    return u;
}
