#include "cellular_automata_interface.h"

#include <iostream>
#include <memory>

void simple_output_util(int* array, const int array_size)
{
    std::cout << "---------------" << std::endl;
    for (int i = 0; i < array_size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << "---------------" << std::endl;
}

int main()
{
    int my_cells_size = 5;
    int my_cells[my_cells_size] = { 0, 0, 1, 0, 0 };
    std::unique_ptr<cellular_automata_interface> ca =
            std::unique_ptr<cellular_automata_interface>(cellular_automata_interface::create(110, my_cells, my_cells_size));
    simple_output_util(my_cells, my_cells_size);

    while (ca->current_generation() < 15)
    {
        ca->pass_generation();
        ca->return_generated_cells(my_cells);
        simple_output_util(my_cells, my_cells_size);
    }
    return 0;
}
