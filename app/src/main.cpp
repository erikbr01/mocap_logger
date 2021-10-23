#include "default_participant.h"
#include "default_subscriber.h"
#include "sub_callback.h"

#include <iostream>



int main() {
// FastDDS objects

// Create participant. Arguments-> Domain id, QOS name
DefaultParticipant dp(0, "mocap_subscriber");

// Create publisher with msg type
DDSSubscriber mocap_sub(MocapPubSubType(), "mocap_pose", dp.participant());


// Initalize mocap_publisher
mocap_sub.init();
//////////////////////////////////////////////////////////

for(;;) {
    mocap_sub.listener.wait_for_data();
    std::cout << "Timestamp: " << sub::st.pose().header().timestamp() << std::endl;
    std::cout << "x: " << sub::st.pose().position().x() << std::endl;
     std::cout << "y: " << sub::st.pose().position().y() << std::endl;
    std::cout << "z: " << sub::st.pose().position().z() << std::endl;


}

}