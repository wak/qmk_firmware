/*
Copyright 2020 sekigon-gonnoc

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string.h>

#include "uart.h"
#include "quantum.h"
#include "matrix.h"
#include "keyboard_quantizer.h"

void matrix_init_custom(void) { uart_init(115200); }

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    return process_packet(current_matrix);
}
