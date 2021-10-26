#pragma once
#include "MocapPubSubTypes.h"
#include "sensor_msgs/msgs/Mocap.h"

namespace sub {
cpp_msg::Mocap mocap_msg;
}

inline void DDSSubscriber::SubListener::on_data_available(
    eprosima::fastdds::dds::DataReader *reader) {
  eprosima::fastdds::dds::SampleInfo info;
dds:
  if (reader->take_next_sample(&sub::mocap_msg, &info) == ReturnCode_t::RETCODE_OK) {
    if (info.valid_data) {
      // Protection against race condition using mutex
      std::unique_lock<std::mutex> lock(m);

      // Print your structure data here.
      // ++samples;
    //   std::cout << "Sample received, count=" << std::endl;
    

      new_data = true;
      // std::cout << "subscriber signals data ready for processing\n";
      lock.unlock();
      cv.notify_one();
    }
  }
}
