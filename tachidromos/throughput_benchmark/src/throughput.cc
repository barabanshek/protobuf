#include<iostream>
#include<thread>
#include<chrono>

#include"reqsim.h"

#define INITIAL_REQUESTS_PER_SECOND 100
#define INCREMENT 100
#define MAX_REQUESTS_PER_SECOND 200
#define DURATION_SECONDS 3

void send_requests(RequestSim &request_sim, int requests_per_second) {
    for (int i = 0; i < requests_per_second; ++i) {
        //request_sim.proto_ser_request(i);
        //request_sim.proto_deser_request(i);
        request_sim.tachidromos_ser_request(i);
        request_sim.tachidromos_deser_request(i);
        std::this_thread::sleep_for(std::chrono::microseconds(1000000 / requests_per_second)); // Sleep to maintain the request rate
    }
}

int main() {
    int requests_per_second = INITIAL_REQUESTS_PER_SECOND;
    while (requests_per_second <= MAX_REQUESTS_PER_SECOND) {
        std::cout << "Sending " << requests_per_second << " requests per second for " << DURATION_SECONDS << " seconds." << std::endl;
        RequestSim request_sim(requests_per_second, 8*4096, 256, nullptr, qpl_path_software);    

        auto start_time = std::chrono::steady_clock::now();
        while (std::chrono::steady_clock::now() - start_time < std::chrono::seconds(DURATION_SECONDS)) {
            send_requests(request_sim, requests_per_second);
            // each send_requests call should take 1 second
            std::cout << "Seconds passed: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start_time).count() << std::endl;
        }

        std::cout << (request_sim.verify_correctness() ? "ALL CORRECT" : "ERROR: DATA MISSMATCH") << std::endl;
        requests_per_second += INCREMENT;
    }

    return 0;
}