#include "cellular_automata_impl.h"

#include <string.h>
#include <algorithm>
#include <bitset>

namespace
{
    static const int get_rule(const int rule_number, const int index) // invert is completed here
    {
        std::string binary = std::bitset<8>(rule_number).to_string();
        std::vector<int> rule;
        for (int i = 0, end = binary.size(); i < end; i++)
        {
            auto val = binary.at(i);
            rule.push_back(std::atoi(&val));
        }
        std::reverse(rule.begin(), rule.end()); // reverse the order because of conversion to decimal
        return rule.at(index);
    }

    static const int apply_rule(const int rule_number, const int& l, const int& m, const int& r)
    {
        const int decimal_value = l*4 + m*2 + r; // left*2^2 + mid*2^1 + right*2^0
        return get_rule(rule_number, decimal_value);
    }
}

void* create_cellular_automata(const int rule_number, const int* initial_cells, const int& cells_amount)
{
    const int RULES_AMOUNT = 256;
    if (rule_number < 0 || rule_number >= RULES_AMOUNT) return nullptr;
    return new simple_cellular_automata(rule_number, initial_cells, cells_amount);
}

simple_cellular_automata::simple_cellular_automata(const int rule_number, const int* initial_cells, const int& cells_amount) :
    m_rule_number(rule_number),
    m_cells_amount(cells_amount),
    m_generation(0)
{
    m_cells.assign(m_cells_amount, 0);
    if (initial_cells)
    {
        memcpy(m_cells.data(), initial_cells, m_cells_amount * sizeof(int));
    }
}

void simple_cellular_automata::pass_generation()
{
    std::lock_guard<std::mutex> data_guard(m_data_mutex);
    for (int i = 0; i < m_cells_amount; i++)
    {
        // applying torus concept
        const int left = m_cells[(i+m_cells_amount-1)%m_cells_amount];
        const int mid = m_cells[i];
        const int right = m_cells[(i+1)%m_cells_amount];
        m_cells[i] = apply_rule(m_rule_number, left, mid, right);
    }
    m_generation++;
}

const int simple_cellular_automata::return_generated_cells(int* cells_to_return)
{
    std::lock_guard<std::mutex> data_guard(m_data_mutex);
    memcpy(cells_to_return, m_cells.data(), m_cells_amount * sizeof(int));
    return m_cells_amount;
}

const int simple_cellular_automata::current_generation()
{
    std::lock_guard<std::mutex> data_guard(m_data_mutex);
    return m_generation;
}
