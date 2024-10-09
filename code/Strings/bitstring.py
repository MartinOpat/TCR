def add_element(bit_string, index):
    return bit_string | (1 << index)
def remove_element(bit_string, index):
    return bit_string & ~(1 << index)
def contains_element(bit_string, index):
    return (bit_string & (1 << index)) != 0

