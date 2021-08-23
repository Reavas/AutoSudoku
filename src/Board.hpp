#include <array>

class Board {
    public:
        Board();
        int8_t getValue(int8_t h_axis, int8_t v_axis);
        int8_t setValue(int8_t h_axis, int8_t v_axis, int8_t value);
    private:
        int8_t boardspace[9][9];
        int8_t Check_Horizontal(int8_t h_axis);
        int8_t Check_Vertical(int8_t v_axis);
        int8_t Check_Box(int8_t h_axis, int8_t v_axis);


};

