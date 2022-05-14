/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  p_err = 0.0;
  i_err = 0.0;
  d_err = 0.0;
  dt = 0.0;
  
  kp = Kpi;
  ki = Kii;
  kd = Kdi;
  
  max_lim = output_lim_maxi;
  min_lim = output_lim_mini;
  
  
  
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  if (dt>0){
    d_err = (cte - p_err) /dt;
  }
  else {
    d_err = 0.0;}
  p_err = cte;
  i_err += cte * dt;


}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control;
  control = kp * p_err + ki * i_err + kd * d_err;
  
  if (control > max_lim)
  {
    control = max_lim;
  }
  else if (control < min_lim)
  {
    control = min_lim;
  }
  
    
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  dt = new_delta_time;
  
  return dt;
}