#ifndef __H_CELLULAR_AUTOMATA_INTERFACE__
#define __H_CELLULAR_AUTOMATA_INTERFACE__

#ifdef __cplusplus
extern "C" {
#endif
void* create_cellular_automata(const int rule_number, const int* initial_cells, const int& cells_amount);
#ifdef __cplusplus
}
#endif

class cellular_automata_interface
{
public:
    static cellular_automata_interface* create(const int rule_number, const int* initial_cells, const int& cells_amount)
    {
        return (cellular_automata_interface*)create_cellular_automata(rule_number, initial_cells, cells_amount);
    }

    virtual void pass_generation() = 0;
    virtual const int return_generated_cells(int* cells_to_return) = 0;
    virtual const int current_generation() = 0;
};
#endif
