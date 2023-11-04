#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <input_cpp_file>"
  exit 1
fi

input_file="$1"

# Extract the directory path and base name of the input file
dir_path=$(dirname "$input_file")
base_name=$(basename "$input_file")

# Define the output file path with "filtered" appended
output_file="$dir_path/${base_name%.cpp}_filtered.cpp"

# Use sed to remove everything after the main function and save the result to the output file
sed '/int main(/q' "$input_file" > "$output_file"

# Remove the last two lines from the output file
head -n -2 "$output_file" > "$output_file.tmp"
mv "$output_file.tmp" "$output_file"
