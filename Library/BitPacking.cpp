namespace bit_packing {

    using MaskType = int; 

    struct BitwiseConfig {
        int array_len;
        int number_of_states;  // 2 => 0 / 1, 3 => 0 / 1 / 2, 4 => 0 / 1 / 2 / 3

        BitwiseConfig(int N, int num_of_states)
            : array_len(N), number_of_states(num_of_states) {}
        
        int max_key_value() const {
            return array_len * number_of_states - 1;
        }
    };
    
    //  Returns state of arr[index]
    static MaskType extract_state(MaskType mask, int index, const BitwiseConfig& config) {
        int bits_per_state = 0;
        int temp = config.number_of_states - 1;
        while (temp > 0) {
            temp >>= 1;
            bits_per_state++;
        }
        int shift = index * bits_per_state;
        return (mask >> shift) & ((MaskType(1) << bits_per_state) - 1);
    }
    
    // Sets state of arr[index] = new_state
    static MaskType update_state(MaskType mask, int index, MaskType new_state, const BitwiseConfig& config) {
        int bits_per_state = 0;
        int temp = config.number_of_states - 1;
        while (temp > 0) {
            temp >>= 1;
            bits_per_state++;
        }
        int shift = index * bits_per_state;
        MaskType clear_mask = ~(((MaskType(1) << bits_per_state) - 1) << shift);
        return (mask & clear_mask) | (new_state << shift);
    }
};

using namespace bit_packing;