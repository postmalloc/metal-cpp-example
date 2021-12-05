//
//  MetalAdder.hpp
//  metalnet
//
//  Created by Srimukh Sripada on 04.12.21.
//

#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>

class MetalAdder{
public:
    MTL::Device* m_device;
    MTL::ComputePipelineState *m_add_function_pso;
    MTL::CommandQueue *m_command_queue;
    
    MTL::Buffer *m_buffer_A;
    MTL::Buffer *m_buffer_B;
    MTL::Buffer *m_buffer_result;
    
    void init_with_device(MTL::Device*);
    void prepare_data();
    void send_compute_command();
private:
    void generate_random_float_data(MTL::Buffer* buffer);
    void encode_add_command(MTL::ComputeCommandEncoder* compute_encoder);
    void verify_results();
};
