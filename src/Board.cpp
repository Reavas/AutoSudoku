#include "Board.hpp"










/* Check_Horizontal
    This method will check to see if the boardspace is correct on the horizontal axis for the specific row.
    Parameters h_axis - the row number to check
    Returns -1 if invalid row number
             0 if duplicate number used
             1 if row has no duplicates
             2 if row is complete
*/
int8_t Board::Check_Horizontal(int8_t h_axis)
{
    bool check[9] = {false};
    bool complete = true;
    int8_t value;
    // Check to see if h_axis is valid
    if (h_axis < 0 || h_axis > 8)
        return -1;
    // Loop through the columns of this row
    for (int c = 0; c < 9; c++)
    {
        // Get the value of that space
        value = boardspace[h_axis][c];
        // Check if value is set. If it isn't move to the next
        if (value == 0)
            complete = false;
            continue;
        // Adjust value for the check
        value--;
        // Check if the value has been used
        if (check[value] == false)
            check[value] = true;
        // Return if we found a duplicate
        else 
            return 0;
    }
    // Check if we completed the row
    if (complete == true)
        return 2;
    else
        return 1;
}

/* Check_Vertical
    This method will check to see if the boardspace is correct on the vertical axis for the specific column.
    Parameters v_axis - the 
    Returns -1 if invalid column number
             0 if duplicate number used
             1 if column has no duplicates
             2 if column is complete
*/
int8_t Board::Check_Vertical(int8_t v_axis)
{
    bool check[9] = {false};
    bool complete = true;
    int8_t value;
    // Check to see if v_axis is valid
    if (v_axis < 0 || v_axis > 8)
        return -1;
    // Loop through the columns of this row
    for (int c = 0; c < 9; c++)
    {
        // Get the value of that space
        value = boardspace[c][v_axis];
        // Check if value is set. If it isn't move to the next
        if (value == 0)
            complete = false;
            continue;
        // Adjust value for the check
        value--;
        // Check if the value has been used
        if (check[value] == false)
            check[value] = true;
        // Return if we found a duplicate
        else 
            return 0;
    }
    // Check if we completed the row
    if (complete == true)
        return 2;
    else
        return 1;
}

/* Check_Block
    This method will check to see if the boardspace is correct on the block for this index
    Parameters v_axis - the 
    Returns -1 if invalid column/row number
             0 if duplicate number used
             1 if block has no duplicates
             2 if block is complete
*/
int8_t Check_Block(int8_t h_axis, int8_t v_axis)
{
    bool check[9] = {false};
    bool complete = true;
    int8_t value;
    
    // Check to see if h_axis is valid
    if (h_axis < 0 || h_axis > 8)
        return -1;

    // Check to see if v_axis is valid
    if (v_axis < 0 || v_axis > 8)
        return -1;

    // Grab the correct block
    h_axis = h_axis / 3;
    v_axis = v_axis / 3;

    // Loop through the rows
    for (int x = 0; x < 3; x++)
    {
        // Loop throw the columns
        for (int y = 0; y < 3; y++)
        {
            // Get the value of that space
            value = boardspace[x + (h_axis * 3)][y + (v_axis * 3)];
            // Check if value is set. If it isn't move to the next
            if (value == 0)
                complete = false;
                continue;
            // Adjust value for the check
            value--;
            // Check if the value has been used
            if (check[value] == false)
                check[value] = true;
            // Return if we found a duplicate
            else 
                return 0;
        }
    }
}