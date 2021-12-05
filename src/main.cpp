//
//  main.cpp
//
//  Created by Srimukh Sripada on 03.12.21.
//
#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#include <iostream>
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include "MetalAdder.hpp"

void add_arrays(const float* inA,
                const float* inB,
                float* result,
                int length)
{
    for (int index = 0; index < length ; index++)
    {
        result[index] = inA[index] + inB[index];
    }
}


int main(int argc, const char * argv[]) {
    NS::AutoreleasePool* p_pool = NS::AutoreleasePool::alloc()->init();
    MTL::Device* device = MTL::CreateSystemDefaultDevice();
    MetalAdder* adder = new MetalAdder();
    adder->init_with_device(device);
    adder->prepare_data();
    adder->send_compute_command();

    std::cout << "Execution finished.";
    p_pool->release();
    
    return 0;
}
