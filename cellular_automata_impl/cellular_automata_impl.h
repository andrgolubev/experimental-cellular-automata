#pragma once

#include "cellular_automata_interface.h"

#include <string>
#include <vector>
#include <mutex>

class simple_cellular_automata : public cellular_automata_interface
{
public:
    simple_cellular_automata(const int rule_number, const int* initial_cells, const int& cells_amount);
    virtual void pass_generation();
    virtual const int return_generated_cells(int* cells_to_return);
    virtual const int current_generation();
private:
    std::vector<int> m_cells; /**< cells members can either be 0 or 1 */
    const int m_cells_amount;
    int m_generation;
    const int m_rule_number;

    std::mutex m_data_mutex;
};
