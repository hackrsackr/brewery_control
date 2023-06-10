#pragma once

typedef struct flowmeter_cfg_t
{
  struct flow_cfg
  {
    std::string flowmeter_id;
    uint8_t sensor_pin;
    double calibration_factor;
    double percent_correction_factor;

  } flow;

} flowmeter_cfg_t;

class FlowMeter
{
public:
  std::string flowmeter_id;
  uint8_t sensor_pin;
  double calibration_factor;
  double percent_correction_factor;
  volatile int pulse_count;
  uint16_t total_pulse_count;
  double frequency;
  double flow_rate;
  double total_liters;
  unsigned long total_mLs;
  unsigned long old_time;

  FlowMeter(flowmeter_cfg_t);
  FlowMeter(std::string, uint8_t, double, double);

  // void set_sensor_pin(uint8_t);
  // void set_calibration_factor(double);
  // void set_percent_correction_factor(double);
  // void reset_total();
  double get_frequency();
  double get_flow_rate();
  void run();
};