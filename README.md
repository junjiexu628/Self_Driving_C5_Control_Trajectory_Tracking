# Control and Trajectory Tracking for Autonomous Vehicle

# Proportional-Integral-Derivative (PID)

In this project, I will apply the skills that have acquired in this course to design a PID controller to perform vehicle trajectory tracking. Given a trajectory as an array of locations, and a simulation environment, I will design and code a PID controller and test its efficiency on the CARLA simulator used in the industry.

## Add the plots to your report and explain them (describe what you see)
- First show the CARLA simulator environment and the ego vehicle situation on three critical positions.
- ![environment](https://github.com/junjiexu628/Self_Driving_C5_Control_Trajectory_Tracking/blob/main/images/task1.png)
- ![goal01](https://github.com/junjiexu628/Self_Driving_C5_Control_Trajectory_Tracking/blob/main/images/goal_01.png)
- ![goal02](https://github.com/junjiexu628/Self_Driving_C5_Control_Trajectory_Tracking/blob/main/images/goal_02.png)
- ![goal03](https://github.com/junjiexu628/Self_Driving_C5_Control_Trajectory_Tracking/blob/main/images/goal_03.png)
- Then show the steer error and throttle error plots
- ![steer error](https://github.com/junjiexu628/Self_Driving_C5_Control_Trajectory_Tracking/blob/main/images/final_steer.png)
- ![throttle error](https://github.com/junjiexu628/Self_Driving_C5_Control_Trajectory_Tracking/blob/main/images/final_throttle.png)
- From the plot of the steer error, the curve in blue is the measured steer error between the ego vehicle yaw and referenced yaw( There are three methods to choose the reference yaw. 1,The last two points of the path; 2, the ego vehicle and the last point of the path; 3, the ego vehicle and the closest point of the path. Option 3 is the best by testing the performance). The curve in orange is the steer error output. These are the consequence of implementing the steer PID control. The average of the steer error output is less than the measured error. And also the output curve is a little bit smooth than the measured error. We can see a little oscillation at the beginning.
- From the plot of the throttle error, the curve in blue is the measured velocity error between the ego vehicle and referenced vehicle(The last point of the path is applied. And also the average velocity of the all point of the path is another option for implementing, but I don't test this. I think that the steer control is much significant in this scenario than the throttle control with the three cars need to be avoid). After making the throttle PID control, the throttle error output is much smooth and becomes lower. There is a little oscillation from the curves and also from the animation at the beginning. The brake curve is zero in most of the time.

## What is the effect of the PID according to the plots, how each part of the PID affects the control command?
- PID is combined for Proportional, Intergral and Derivative. 
- Proportional parameter makes the cross track error(CTE) proportional decrease to minimize it. When Kp is above the range, the controller will be out of work. We call it takes action at the present.
- Intergral parameter makes the all past error into the consideration, and in avoid of the steady- state error. Another aspect to consider is the saturation of the intergral control. We set the cutoff line to avoid this. It involves all the past error into the controller. Too big Ki cause the overshoot, too small Ki makes too long to reach the trajectory.
- Derivative parameter is the change rate of the CTE. Suitable Kd will make the controller quickly reach the trajecotory. Derivative can enlarge the high frequency noise, so filtered derivative will be used. Too big Kd makes the overdamped situation, and too small Kd causes the underdamped situation. We call it make the controller at the prediction. 

## How would you design a way to automatically tune the PID parameters?
- In the course the Twiddle is a way to automatically tune the PID parameter. But Twiddle may be not easy to implement into the real self-driving vehicle. The traditional way to use the system identification method. Measure the reaction signal of the hardware or real prototype, make the mathmatical representation to get the similar the output signal. Then we can tune the representation model instead according to root locus plot.

## PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?
- Pros: PID controller is simple and easy to implement. Its application doesn't need too much knowledge inside the control system. We just tune the parameters of PID. 
- Cons: PID controller is based on the feedback of the error, so it causes the delay of the control, its action is based the past situation. So in reality the steer control is not normal to implement the PID control. In addition, tuning the perfect parameters for PID controller is not easy.

## (Optional) What would you do to improve the PID controller?
- Try and error is the traditional way. But it will take too much time. Maybe system identification is another way to make the nonlinear representation of the model. Or make the nonlinear model to represent on the linear model.

## Summary
- Tuning the PID is not easy in this project. A approach is to tune the proportional parameter till not overshoot, setting the ki and kd to zero. Then decrease around 10% of the proportional value and add derivative parameter till not overshoot. Finally fine tune the kp, kd and ki. This is not perfect but can work not too badly.

## Overview
- Four months studying is finally over, diving into this course day and night. These course are good startpoint to understand the process of the autonomous vehicle development. Go deeper for next action.

## Acknowledgement
- All mentors in Udacity and all students on the knowledge platform, your answers and support gives me great help. Appreciate all of you.
