import random

# Generate an arbitrary .proto structure.
class NestedMessageGenerator:
    @staticmethod
    def generate_message(num_lines, nestness_depth, nestness_width):
        def gen(ctx, level):
            # Content
            for i in range(num_lines):
                ctx += "  " * level + f'optional int32 f{i+1} = {i+1};\n'

            # Exit
            if level == nestness_depth:
                return ctx

            # DFS
            for i in range(nestness_width):
                ctx += "  " * level + f'message M{level}{i}' + ' {\n'
                ctx = gen(ctx, level + 1)
                ctx += "  " * level + '}\n'
                ctx += "  " * level + f'optional M{level}{i} f{num_lines + 1 + i} = {num_lines + 1 + i};\n'
            return ctx

        message_content = 'syntax = "proto3";\n'
        message_content += 'message M {\n'
        message_content = gen(message_content, 1)
        message_content += '}\n'

        return message_content

    @staticmethod
    def generate_setters(num_lines, nestness_depth, nestness_width):
        def rnd():
            val = 0
            for j in range(random.randint(1, 4)):
                val |= (random.randint(0, 255) << j * 8)
            return val

        def gen(ctx, level, msg_name):
            # Setter
            for i in range(num_lines):
                ctx += f'\t\t{msg_name}->set_f{i+1}({rnd()} + (i * {level}) % 8);\n'

            # DFS
            if level == nestness_depth:
                return ctx
            for i in range(nestness_width):
                ctx = gen(ctx, level + 1, msg_name + f'->mutable_f{num_lines + 1 + i}()')
            return ctx

        return gen("", 1, '(&m)')

    @staticmethod
    def generate_gather_schema(num_lines, nestness_depth, nestness_width):
        def gather_schema_gen(ctx, level, msg_name):
            # DFS
            #ctx += f'\t\tschema.push_back(std::make_tuple(reinterpret_cast<const uint8_t*>({msg_name}), sizeof(*({msg_name}))));\n'
            ctx += f'\t\tgather_schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>({msg_name}), sizeof(*({msg_name}))));\n'
            
            #ctx += f'std::cout << i << \',\' << &messages[i] << std::endl;';
            #ctx += f'std::cout << i << \',\' << reinterpret_cast<unsigned uint8_t*>(&messages[i]) << std::endl;';

            if level == nestness_depth:
                return ctx
            for i in range(nestness_width):
                ctx = gather_schema_gen(ctx, level + 1, msg_name + f'->mutable_f{num_lines + 1 + i}()')
            return ctx

        return gather_schema_gen("", 1, '(&messages[i])')

    @staticmethod
    def generate_scatter_schema(num_lines, nestness_depth, nestness_width):
        def scatter_schema_gen(ctx, level, msg_name):
            # DFS
            #ctx += f'\t\tschema.push_back(std::make_tuple(reinterpret_cast<const uint8_t*>({msg_name}), sizeof(*({msg_name}))));\n'
            ctx += f'\t\tscatter_schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>({msg_name}), sizeof(*({msg_name}))));\n'
            
            #ctx += f'std::cout << i << \',\' << &out_messages[i] << std::endl;';
            #ctx += f'std::cout << i << \',\' << reinterpret_cast<M*>(std::get<0>(schema[0])) << std::endl;';

            if level == nestness_depth:
                return ctx
            for i in range(nestness_width):
                ctx = scatter_schema_gen(ctx, level + 1, msg_name + f'->mutable_f{num_lines + 1 + i}()')
            return ctx

        return scatter_schema_gen("", 1, '(&out_messages[i])')
